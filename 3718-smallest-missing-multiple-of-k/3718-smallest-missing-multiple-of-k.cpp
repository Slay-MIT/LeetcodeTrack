class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> exists(nums.begin(), nums.end());
        int result = k;
        while(exists.count(result) != 0){
            result+=k;
        }

        return result;
    }
};