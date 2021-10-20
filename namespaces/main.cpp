namespace N {}
void f()
{
  using namespace N;
}

namespace MyNamespace
{
  void g() {}
}

using namespace MyNamespace;
using MyNamespace::g;

int main()
{
}

