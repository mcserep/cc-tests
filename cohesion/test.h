class included_class
{
	int field1;
	bool field2;
	
	void method1() { field1 = 0; }
	bool method2() const { return field2; }
};

template<typename T>
class included_template_class
{
	T field1;
	T field2;
	
	const T& method1() const { return field1; }
	const T& method2() const { return field2; }
};

template<>
class included_template_class<bool>
{
	long long field1;
	
	const long long& method1() const { return field1; }
};

