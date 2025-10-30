#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums, int index) {
    if(index == nums.size() - 1){
        return nums[index];
    }
    int profit = maxSubArray(nums, index + 1);
    nums[index] = max(nums[index], nums[index] + nums[index + 1]);
    return max(profit, nums[index]);
}
int maxSubArray(vector<int>& nums) {
    return maxSubArray(nums, 0);
}