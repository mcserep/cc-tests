#include <iostream>
#include <vector>

std::vector<int> produce(int n)
{
  std::vector<int> v;
  v.reserve(n);
  for (int i = 1; i <= n; ++i)
  {
    v.push_back(i);
  }

  return v;
}

struct Producer
{
  std::vector<int> produce(int n)
  {
    return ::produce(n);
  }
};

int main()
{
  int nums1[4] = { 1, 2, 3, 4 };
  for (int i : nums1)
    std::cout << i << ", ";
  std::cout << std::endl;

  int nums2[3] = { 5, 6, 7 };
  for (int i : nums2)
    std::cout << i << ", ";
  std::cout << std::endl;

  std::vector<int> nums3 = { 8, 9, 10 };
  for (int i : nums3)
    std::cout << i << ", ";
  std::cout << std::endl;

  for (int i : produce(7))
    std::cout << i << ", ";
  std::cout << std::endl;

  Producer p;
  for (int i : p.produce(6))
    std::cout << i << ", ";
  std::cout << std::endl;

  return 0;
}
