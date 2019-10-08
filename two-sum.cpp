#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> diff_to_target_2_nums_index_map;
    for (auto i = 0; i < nums.size(); i++) {
      const auto nums_i = nums[i];
      const auto diff_index = target - nums_i;
      const auto it = diff_to_target_2_nums_index_map.find(diff_index);
      if (it != diff_to_target_2_nums_index_map.end()) {
        return {it->second, static_cast<int>(i)};
      }
      diff_to_target_2_nums_index_map[nums_i] = i;
    }
    return {};
  }
};

auto compare = [](const auto &result, const auto &expected, const auto &nums) {
  const auto cmp =
      equal(begin(result), end(result), begin(expected), end(expected));

  if (!cmp) {
    cout << "Fail!" << endl;
    cout << "nums: ";
    copy(begin(nums), end(nums), ostream_iterator<int>{cout, ", "});
    cout << endl;

    cout << "expected: ";
    copy(begin(expected), end(expected), ostream_iterator<int>{cout, ", "});
    cout << endl;

    cout << "result: ";
    copy(begin(result), end(result), ostream_iterator<int>{cout, ", "});
    cout << endl;
  }
  assert(cmp);
};

int main(int, char **) {

  {
    vector nums = {2, 7, 11, 15};
    const int target = {9};

    const auto result = Solution().twoSum(nums, target);
    const vector expected = {0, 1};

    compare(result, expected, nums);
  }

  {
    vector nums = {2, 11, 7, 15};
    const int target = {9};

    const auto result = Solution().twoSum(nums, target);
    const vector expected = {0, 2};

    compare(result, expected, nums);
  }

  return 0;
}
