class Solution {
public:
    bool judgeSquareSum(int c) {
        int num = c;
        int root = sqrt(c);
        for(int i=0; i<=root; i++){
            if(pow(i,2) + pow(root, 2) == num){
                return true;
            }
        }
        return false;
    }
};