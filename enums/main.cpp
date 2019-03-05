#include <iostream>

#include "definitions.h"

int main()
{
  Day d = Day::Friday;
  std::cout << "d = " << static_cast<int>(d) << std::endl;
  d = Day::Sunday;
  std::cout << "d = " << static_cast<int>(d) << std::endl;
  
  int p = Readable;
  std::cout << "p = " << p << std::endl;
  p |= Executable;  
  std::cout << "p = " << p << std::endl;
  
  return 0;
}
