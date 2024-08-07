class Solution {
public:

    void calcSum(vector<vector<int>>& res, vector<int> sub, vector<int>& candidates, int target, int index){
        if(target == 0){
            res.push_back(sub);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            
            //checking for duplicates in the same recursion call
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            
            if(candidates[i] > target){
                break;
            }

            sub.push_back(candidates[i]);
            calcSum(res, sub, candidates, target - candidates[i], i+1);
            sub.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>sub;
        sort(candidates.begin(), candidates.end());
        calcSum(res, sub, candidates, target, 0);
        return res;
    }
};