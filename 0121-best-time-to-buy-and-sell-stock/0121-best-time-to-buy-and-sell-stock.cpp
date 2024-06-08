// BruteForce

// class Solution {
// public:
//     int maxDiff = 0;
//     void checkDiff(vector<int>& prices, int curr, int index){
//         for(int i=index; i<prices.size()-1; i++){
//             if(prices[i+1] < curr){
//                 continue;
//             }
//             int diff = prices[i+1] - curr;
//             if(diff > maxDiff){
//                 maxDiff = diff;
//             }
//         }
//     }

//     int maxProfit(vector<int>& prices) {
//         int curr;
//         for(int i=0; i<prices.size(); i++){
//             curr = prices[i];
//             checkDiff(prices, curr, i);
//         }
//         return maxDiff;

//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minEle = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            minEle = min(prices[i], minEle);
            maxProfit = max(maxProfit, prices[i] - minEle);
        }
        return maxProfit;
    }
};