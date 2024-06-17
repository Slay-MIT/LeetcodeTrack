class Solution {
public:
    double myPow(double x, int n) {
        int num = abs(n);
        double res = x;
        if(n==0 || x==1){
            return 1.0;
        }
        while(num>2){
            num--;
            res*=x;
        }
        if(n<0){
            return 1/(res*x);
        }
        return res*x;
    }
};