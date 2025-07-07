/**
 * https://leetcode.cn/problems/house-robber-ii/description/
 *
 * @File:   house_robberII.cpp
 * @Author: Lao Zhang samuelzhang77@outlook.com
 * @Date:   2025-06-02
 *
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        // 不偷最后一间
        int rob1 = robLinear(nums, 0, n - 2);
        // 不偷第一间
        int rob2 = robLinear(nums, 1, n - 1);

        return max(rob1, rob2);
    }

private:
    // 辅助函数：计算线性数组 nums[start..end] 的最大偷窃金额
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.rob(nums) << endl;
    return 0;
}
