class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        int maxTime = 0;
        double idle = 0;
        
        for (auto it : customers) {
            maxTime = max(maxTime, it[0]) + it[1];
            idle += maxTime - it[0];
        }
        return (idle/customers.size());
    }
};