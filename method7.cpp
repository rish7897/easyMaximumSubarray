#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums, vector<int>& pre, vector<int>& suf, int start, int end){
        if(start == end){
            return nums[start];
        }
        
        int mid = start + (end - start) / 2;
        int leftMaxSubArray = maxSubArray(nums, pre, suf, start, mid);
        int rightMaxSubArray = maxSubArray(nums, pre, suf, mid + 1, end);
        return max({leftMaxSubArray, rightMaxSubArray, pre[mid] + suf[mid + 1]});
    }
    int maxSubArray(vector<int>& nums) {
        vector<int>pre(nums);
        vector<int>suf(nums);
        for(int i = 1; i < nums.size(); i++){
            pre[i] = max(pre[i - 1] + nums[i], nums[i]);
        }
        for(int i = nums.size() - 2; i >= 0; i--){
            suf[i] = max(nums[i], nums[i] + suf[i + 1]);
        }
        return maxSubArray(nums, pre, suf, 0, nums.size() - 1);
    }
};