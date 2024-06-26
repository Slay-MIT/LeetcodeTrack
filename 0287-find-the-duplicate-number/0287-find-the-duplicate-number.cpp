class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n =  nums.size();
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it : mp){
            if(it.second > 1){
                return it.first;
            }
            else continue;
        }
        return 1;
    }
};