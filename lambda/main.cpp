////////////////


void lambda_test_empty()
{
	auto lam = [](){};
}

void lambda_test_simple()
{
	auto lam = [](int n) { return 2*n; };
}

void lambda_test_byval_byref()
{	
	int v = 2;
	int r = 3;
	auto lam = [v, &r](int i) mutable
	{
		int as[] {1,2,3,4};
		for (int a : as)
			v += i*a;
		r = v;
	};
}

void lambda_test_byval_all()
{
	auto lam = [=](long a)
	{
		return [=](long b)
		{ return a + b; };
	};
}

void lambda_test_nested()
{
	long step = 1;
	auto lam = [&](long arg) -> long
	{
		struct multiplier
		{
			long step;
			
			multiplier(long step = 1) : step(step) {}
			
			long operator()(long arg) const
			{
				return [this, m=arg](long limit) mutable
				{
					long res = 1;
					while (m > limit)
					{
						res *= m;
						m -= step;
					}
					return res;
				}(1);
			}
		};
		
		multiplier m(step);
		return m(arg);
	};
	long fact5 = lam(5);
}


////////////////


int main()
{
	return 0;
}

