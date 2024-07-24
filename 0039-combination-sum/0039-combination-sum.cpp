class Solution {
public:
    void calcSum(vector<vector<int>>& res, vector<int>& candidates, int target, int index, vector<int>& sub){
        if(target == 0){
            res.push_back(sub);
            return;
        }
        for(int i = index; i<candidates.size(); i++){
            if(candidates[i] > target){
                break;
            }

            sub.push_back(candidates[i]);
            //note how we are not incrementing i as duplicate elements are allowed
            calcSum(res, candidates, target  - candidates[i], i, sub);
            sub.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>sub;
        calcSum(res, candidates, target, 0, sub);
        return res;
    }
};