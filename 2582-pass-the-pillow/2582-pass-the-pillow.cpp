class Solution {
public:
    int passThePillow(int n, int time) {
        int count = 1;
        bool flag = false;
        while(time != 0){
            time--;
            if(count == n){
                flag = true;
            }
            else if(count == 1){
                flag = false;
            }
            
            if(flag){
                count--;
            }
            else{
                count++;
            }
        }
        return count;
    }
};