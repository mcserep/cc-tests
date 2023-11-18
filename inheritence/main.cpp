////////////////


class pure_base_class
{
public:
	virtual ~pure_base_class() {}
	
	virtual bool some_predicate(void* ptr) const = 0;
};

class pure_derived_class : public virtual pure_base_class
{
public:
	virtual int some_function(int arg) const = 0;
};


class base_class
{
public:
	virtual ~base_class() = default;

	void non_virtual_method() {}
	virtual void virtual_method() {}
	virtual void abstract_method() = 0;
	
protected:
	void secret_function();
};

class derived_class1 : public virtual base_class
{
public:
	~derived_class1() {} // implicit override, implicit virtual
	
	void non_virtual_method() {} // plain hiding
	void virtual_method() override {}// explicit override, implicit virtual
	virtual void abstract_method() override {} // explicit override, explicit virtual
	
	using base_class::secret_function;// accessibility promotion
};

class derived_class2 : public virtual base_class
{
public:
	~derived_class2() = default;
	
	void virtual_method() override {}// different override
	
	using base_class::secret_function;// accessibility promotion
};


class very_derived_class final : public derived_class1, public derived_class2, public pure_derived_class
{
public:
	~very_derived_class() {}// should call all base class dtors
	
	virtual void virtual_method() override// disambiguation, explicit override
	{
		derived_class1::virtual_method();
		derived_class2::virtual_method();
	}
	
	virtual bool some_predicate(void* ptr) const override final// explicitly final
	{ return ptr == nullptr; }
	virtual int some_function(int arg) const override// implicitly final
	{ return 2 * arg + 1; }
};


////////////////


int main()
{
	return 0;
}

