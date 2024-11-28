#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

bool hasDuplicate(std::vector<int> &nums) {
  std::unordered_map<int, bool> m;

  for (size_t i = 0; i < nums.size(); i++) {
    if (m.count(nums[i]) > 0)
      return true;
    m[nums[i]] = true;
  }

  return false;
}

int main() {
  std::vector<int> nums = {1, 2, 4, 4, 5};
  std::cout << std::boolalpha << hasDuplicate(nums) << std::endl;
  return 0;
}