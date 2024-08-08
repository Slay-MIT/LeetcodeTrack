class Solution {
public:
    void findSub(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums, int index) {
        // Add the current subset to the result
        res.push_back(sub);

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;
            // Include the current number in the subset
            sub.push_back(nums[i]);
            // Recurse with the next index
            findSub(res, sub, nums, i + 1);
            // Backtrack by removing the last number added
            sub.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        // Sort the array to handle duplicates
        sort(nums.begin(), nums.end());
        // Start the recursive process
        findSub(res, sub, nums, 0);
        return res;
    }
};
