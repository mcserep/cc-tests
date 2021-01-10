#include <iostream>

int doubleit(int a)
{
  return 2 * a;
}

struct Test {
  int field;

  Test() : field(0)
  { }

  int method()
  {
    return this->field;
  }

  int method2(int (*op)(int))
  {
    return op(this->field);
  }

  typedef int(Test::*method3)();

private:
  int _tripleit()
  {
    return 3 * field;
  }
};

int main()
{
  Test obj;
  obj.field = 42;
  std::cout << obj.method() << std::endl;
  std::cout << obj.method2(doubleit) << std::endl;

  Test *p = &obj;
  p->field = 100;
  std::cout << p->method() << std::endl;
  std::cout << p->method2(doubleit) << std::endl;

  int (*fp)(int);
  fp = doubleit;
  std::cout << obj.method2(fp) << std::endl;
  std::cout << p->method2(fp) << std::endl;

  Test::method3 fp2 = &Test::method;
  std::cout << (obj.*fp2)() << std::endl;
  std::cout << (p->*fp2)() << std::endl;

  return 0;
}
