class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, preSum = 0;
        map<int,int> mpp;
        mpp[0] = 1;
        for(auto it: nums){
            preSum += it;
            
            count += mpp[preSum - k];

            mpp[preSum]++;

        }
        return count;
    }
};