class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        for(auto it: target){
            if(find(arr.begin(), arr.end(), it)!=arr.end()){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};