#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    // maxSubArrays' ith array's 0th index denotes maxSubArray before and 1st index denots maxSubArray till ith index and still adding
    // 0th index value is max of prev 0th index val(its maxSum before prev index) and prev 1st index val(till prev maxSum)
    //1st index val = max prev maxSum+  curr val(maxSubArray till prev index and still adding) and curr val(no maxSubArr till now now starting to create)
    int maxSubArray(vector<int>& nums) {
        vector<int>temp(2, INT_MIN);
        vector<vector<int> > maxSubArrays(nums.size(), temp);
        maxSubArrays[0][0] = 0;
        maxSubArrays[0][1] = nums[0];
        int maxi = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxSubArrays[i][0] = max(maxSubArrays[i-1][1], maxSubArrays[i-1][0]);
            maxSubArrays[i][1] = max(maxSubArrays[i-1][1] + nums[i], nums[i]);
            if(maxi < nums[i]){
                maxi = nums[i];
            }
        }
        if(maxi <= 0){
            return maxi;
        }
        return max(maxSubArrays[nums.size() - 1][false], maxSubArrays[nums.size() - 1][true]);
    }
};