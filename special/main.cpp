#include <vector>


////////////////


void dummy_rbf1()
{
  std::vector<int> v;
  for (int i : v){}
}

void dummy_rbf5()
{
  std::vector<int> v1, v2, v3, v4, v5;
  for (int i1 : v1){}
  for (int i2 : v2){}
  for (int i3 : v3){}
  for (int i4 : v4){}
  for (int i5 : v5){}
}


////////////////


class HiddenMembersTest
{
	bool mem0;
	int mem1;
	short mem2;
	
	HiddenMembersTest(){}
	
	void f() {}
};


////////////////


class SpecialClass
{
private:
	const volatile int cvi = 7;
	mutable char mc = 'a';
	
	static long sl;
	static constexpr const char* scccp = "hello";
	
protected:
	SpecialClass() noexcept(false) {}
	
public:
	int something() const noexcept(true)
	{
		int sum = 0;
		int vals[] = {2,3,5,7};
		for (int val : vals)
			sum += val;
		return sum;
	}
	
	static constexpr int anything() noexcept
	{ return 42; }
	
	constexpr const long anything2() const noexcept(noexcept(anything))
	{ return anything() + (long)69420; }
};
long SpecialClass::sl = 7;


////////////////


int main()
{
	return 0;
}

