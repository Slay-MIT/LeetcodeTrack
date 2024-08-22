class Solution {
public:

    bool isPalindrome(string s, int l, int r){
        while(l<r){
            //checking whether a palindrome or not in that range
            if(s[l++]!=s[r--]){
                return false;
            }
        }
        return true;
    }
    void createSub(string A, vector<string>& subset, vector<vector<string>>& res, int index){
        if(index == A.length()){
            res.push_back(subset);
            return;
        }
        for(int i = index; i < A.length(); i++){
            if(isPalindrome(A, index, i)){

                //pick
                subset.push_back(A.substr(index, i-index+1));
                createSub(A, subset, res, i+1);

                //not pick
                subset.pop_back();
            }
            
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> subset;
        vector<vector<string>> res;
        int index = 0;
        createSub(s, subset, res, index);
        return res;
    }
};