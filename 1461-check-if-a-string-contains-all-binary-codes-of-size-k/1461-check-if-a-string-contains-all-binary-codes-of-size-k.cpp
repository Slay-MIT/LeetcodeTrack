class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> substring_set;
        for(int i=0 ;i+k <= s.size(); i++){
            substring_set.insert(s.substr(i,k)); //substr(pos,len)
        }
        return substring_set.size() == pow(2,k);
    }
};