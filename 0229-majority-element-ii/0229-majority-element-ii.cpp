class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto ele:mp){
            if(ele.second > (nums.size()/3)){
                ans.push_back(ele.first);
            }
        }
        return ans;
    }
};