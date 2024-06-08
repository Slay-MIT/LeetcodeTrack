class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        vector<int> curr = intervals[0];

        for(auto it: intervals){
            if(curr[1] >= it[0]){
                curr[1] = max(curr[1], it[1]);
            }
            else{
                merged.push_back(curr);
                curr = it;
            }
        }

        merged.push_back(curr);
        return merged;
    }
};
