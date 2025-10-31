#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums,int index, bool creatingSubArr, vector<vector<int>> &maxSubArrays) {
        if(maxSubArrays[index][creatingSubArr] != INT_MIN){
            return maxSubArrays[index][creatingSubArr];
        }

        if(index == nums.size()){
            if(creatingSubArr){
                return 0;
            }else{
                return INT_MIN;
            }
        }
        
        int ans;
        if(creatingSubArr){
            ans =  max(0, nums[index] + maxSubArray(nums, index + 1, true, maxSubArrays));
        }else{
            ans =  max(nums[index] + maxSubArray(nums, index + 1, true, maxSubArrays), maxSubArray(nums, index + 1, false, maxSubArrays));   
        }
        
        maxSubArrays[index][creatingSubArr] = ans;
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        vector<int> temp(2, INT_MIN);
        vector<vector<int>> maxSubArrays(nums.size() + 1, temp);
        return maxSubArray(nums, 0, false, maxSubArrays);
    }
};