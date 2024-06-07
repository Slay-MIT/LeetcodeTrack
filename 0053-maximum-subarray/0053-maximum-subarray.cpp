class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int sum = 0;
        int neg = 0;
        for(auto it: nums){
            if(it < 0){
                neg+=1;
            }
        }
        //to handle negative only arrays
        if(neg == nums.size()){
            sort(nums.begin(), nums.end());
            return nums[nums.size() - 1];
        }
        //to handle mixed arrays
        for(auto it: nums){
            sum+=it;

            //if subarray has negative sum then biggest sum cannot be this, so reset 
            if(sum<0){
                sum = 0;
            }
            if(sum > max){
                max = sum;
            }
        }
        return max;
    }
};