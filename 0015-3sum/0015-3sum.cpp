class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){

            //to deal with duplicates, we simply skip if two consecutive were the same
            if(i!=0 && nums[i]==nums[i-1]) continue;
            
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    j++;
                    k--;
                    
                    //skipping dupes
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};