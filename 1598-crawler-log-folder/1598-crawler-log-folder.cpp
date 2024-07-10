class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for(int i=0; i<logs.size(); i++){
            if(logs[i].compare("../")==0 && count==0){
                continue;
            }
            if(logs[i].compare("./") == 0){
                continue;
            }
            else if(logs[i].compare("../") == 0 && count!=0){
                count--;
            }
            else{
                count++;
            }
        }
        return count;

    }
};