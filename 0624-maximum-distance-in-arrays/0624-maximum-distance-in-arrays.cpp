class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // Initialize variables to keep track of the maximum distance
        int maxDist = 0;
        
        // Initialize min and max from the first array
        int minElement = arrays[0].front();
        int maxElement = arrays[0].back();
        
        // Start iterating from the second array
        for (int i = 1; i < arrays.size(); i++) {
            // Calculate possible distances using current minElement and maxElement
            int currentMin = arrays[i].front();
            int currentMax = arrays[i].back();
            
            // Compare with the minimum and maximum of previous arrays
            maxDist = max(maxDist, abs(currentMax - minElement));
            maxDist = max(maxDist, abs(maxElement - currentMin));
            
            // Update minElement and maxElement
            minElement = min(minElement, currentMin);
            maxElement = max(maxElement, currentMax);
        }
        
        return maxDist;
    }
};
