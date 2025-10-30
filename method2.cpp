#include<iostream>
#include<vector>
using namespace std;

// memoisation
pair<int, int> maxSubArray(vector<int>& nums, int index){
    pair <int, int> ans;
    if(index == nums.size() - 1){
        ans.first = nums[nums.size() - 1];
        ans.second = nums[nums.size() - 1];
        return ans;
    }
    pair <int, int> smallAns = maxSubArray(nums, index + 1);
    int sum = max(nums[index] + smallAns.first, nums[index]);
    int maxSum = max(smallAns.second, sum);
    
    ans.first = sum;
    ans.second = maxSum;
    return ans;
}
int maxSubArray(vector<int>& nums) {
    int index = 0;
    return maxSubArray(nums, index).second;
}