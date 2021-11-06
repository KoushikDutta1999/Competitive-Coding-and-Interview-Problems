/*
3Sum
Medium

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:

Input: nums = []
Output: []

Example 3:

Input: nums = [0]
Output: []

Constraints:
0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> v;
    if (nums.size() < 3)
      return v;
    int i, j, k;

    sort(nums.begin(), nums.end());

    for (i = 0; i < nums.size() - 2; i++) {
      j = i + 1;
      k = nums.size() - 1;
      if (nums[i] > 0)
        break;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      while (j < k) {
        if (nums[j] + nums[i] > 0)
          break;
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          j++;
          continue;
        }

        if (nums[i] + nums[j] + nums[k] > 0)
          k--;
        else if (nums[i] + nums[j] + nums[k] < 0)
          j++;
        else {
          v.push_back(vector<int>{nums[i], nums[j], nums[k]});
          j++;
          k--;
        }
      }
    }
    return v;
  }
};