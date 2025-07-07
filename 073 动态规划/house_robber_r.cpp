/**
 * https://leetcode.cn/problems/house-robber/
 *
 * @File:   house_robber.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-02
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // 需要注意输入数组的长度
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
       }
       return prev1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << s.rob(nums) << endl;
    return 0;
}
