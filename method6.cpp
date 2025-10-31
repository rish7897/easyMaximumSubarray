#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    // divide and concor
    int maxSubArray(vector<int>& nums, int start, int end){
        if(start == end){
            return nums[start];
        }
        if(start > end){
            return 0;
        }
        int mid = start + (end - start) / 2;
        int leftMaxSubArray = maxSubArray(nums, start, mid - 1);
        int rightMaxSubArray = maxSubArray(nums, mid + 1, end);

        int leftSum = 0;
        int maxLeftSum = 0;
        for(int i = mid - 1; i >= start; i--){
            leftSum += nums[i];
            if(maxLeftSum < leftSum){
                maxLeftSum = leftSum;
            }
        }
        int rightSum = 0;
        int maxRightSum = 0;
        for(int i = mid + 1; i <= end; i++){
            rightSum += nums[i];
            if(maxRightSum < rightSum){
                maxRightSum = rightSum;
            }
        }
        return max(max(leftMaxSubArray, rightMaxSubArray), nums[mid] + maxLeftSum + maxRightSum);
    }
    int maxSubArray(vector<int>& nums) {
        int ans =  maxSubArray(nums, 0, nums.size() - 1);
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(maxi < nums[i]){
                maxi = nums[i];
            }
        }
        if(maxi <= 0){
            return maxi;
        }
        return ans;
    }
};