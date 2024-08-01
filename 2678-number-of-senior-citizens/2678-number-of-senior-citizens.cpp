class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto it: details){
            if(stoi(it.substr(11,2)) > 60){
                count++;
            }
        }
        return count;
    }
};