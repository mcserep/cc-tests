#include <stddef.h>


////////////////


struct IntWrap
{
	int value;
	IntWrap(int value) : value(value) {}
	IntWrap(const IntWrap& other) : value(other.value) {}
	~IntWrap() {}
};

IntWrap glob(0);


IntWrap test_lambda_lifetime()
{
    IntWrap L = []() -> IntWrap {
        IntWrap X = 0;
        return X;
    }();
    return L;
}

IntWrap test_scope_hiding()
{
  IntWrap X = 1;
  {
    IntWrap X = 2;
    return X;
  }
}


////////////////


class dummy_array final
{
private:
	size_t _size;
	int* _array;
	
public:
	size_t size() const { return _size; }
	int& at(size_t index) { return _array[index]; }
	int at(size_t index) const { return _array[index]; }
	
public:
	dummy_array(size_t size = 0) :
		_size(size), _array(new int[size])
	{}
	dummy_array(const dummy_array&) = delete;
	dummy_array(dummy_array&& other) :
		_size(other._size), _array(other._array)
	{ other._array = nullptr; }
	
	~dummy_array()
	{
		if (_array != nullptr)
			delete[] _array;
	}
	
	dummy_array& operator=(const dummy_array&) = delete;
	dummy_array& operator=(dummy_array&& other)
	{
		_size = other._size;
		_array = other._array;
		other._array = nullptr;
		return *this;
	}
};

struct point2
{
	int x;
	int y;
	
	point2(int x, int y) : x(x), y(y) {}
	point2() : point2(0, 0) {}
	
	virtual ~point2() = default;
};

struct point3 : point2
{
	int z;
	
	point3(int x, int y, int z) : point2(x, y), z(z) {}
	point3() : point3(0, 0, 0) {}
	
	virtual ~point3() = default;
};


struct vector2
{
	point2 start;
	point2 end;
	
	vector2(point2 start, point2 end) : start(start), end(end) {}
	~vector2() {}// explicit user-defined dtor
};

struct vector3
{
	point3 start;
	point3 end;
	
	vector3(point3 start, point3 end) : start(start), end(end) {}
	// implicit dtor
};

struct weird_vector : vector3
{
	point2 sthg;
	
	weird_vector(point3 a, point3 b, point2 c) :
		vector3(a, b), sthg(c) {}
	~weird_vector() = default;// explicit defaulted dtor
};


class dummy_error_code
{
private:
	int code;
	
public:
	dummy_error_code(int code = 0) : code(code) {}
	~dummy_error_code() = default;
	
public:
	explicit operator int() const { return code; }
	explicit operator bool() const { return code == 0; }
};


void test_alloc_stack_simple()
{
	point3 p(1, 2, 3);
}

void test_alloc_stack_scopes()
{
	point2 p2(5, 12);
	{
		{
			p2.x *= 2;
		}
		point3 p3(3, -7, -1);
		{
			--p2.y;
			p3.z += 4;		
		}
	}
}

void test_alloc_stack_special()
{
	if (dummy_error_code ec1 = dummy_error_code(42))
	{
	
	}
	
	int i = 0;
	for (dummy_error_code ec2(69); i < 5; ++i)
	{
	
	}
	
	int j = 1;
	++j;
}

void test_alloc_heap_simple()
{
	dummy_array* ptr1 = new dummy_array(2);
	delete ptr1;
	
	dummy_array* array1 = new dummy_array[3];
	delete[] array1;
	
	
	point2* ptr2 = new point2(3, -1);
	delete ptr2;
	
	point2* array2 = new point2[4];
	delete[] array2;
	
	
	point3* ptr3 = new point3(3, -1, 2);
	delete ptr3;
	
	point3* array3 = new point3[4];
	delete[] array3;
}

void test_alloc_heap_polymorphic()
{	
	point2* poly = new point3(1, 2, 3);
	delete poly;
}

void test_alloc_mixed_indirect()
{
	point2 p2a(-1, -2);
	point2 p2b(3, 4);
	
	point3 p3a(-1, -2, -3);
	point3 p3b(4, 5, 6);

	vector2 v2_s(p2a, p2b);
	vector3 v3_s(p3a, p3b);
	
	vector2* v2_h = new vector2(p2a, p2b);
	vector3* v3_h = new vector3(p3a, p3b);
	
	delete v2_h;
	delete v3_h;
}


////////////////


int main()
{
	return 0;
}

