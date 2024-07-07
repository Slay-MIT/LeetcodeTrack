class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int sum = 0;
        //will keep running until we can no longer exchange bottles
        while(ans >= numExchange){

            sum += numExchange;
            
            //numExchange number of bottles consumed
            ans -= numExchange;
            
            //adding 1 because we consumed one full batch of bottles at once which can be
            //exchanged for a new bottle
            ans++;
        }
        
        //add the remaining bottles(which were less than numExchange)
        return sum + ans;
    }
};