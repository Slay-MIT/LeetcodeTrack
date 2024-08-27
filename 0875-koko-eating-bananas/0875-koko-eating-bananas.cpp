class Solution {
public:
    long calcHours(vector<int>& piles, int hours){
        
        long total = 0;
        //finding total number of hours for each pile at eating speed of (int hours)
        for(auto it: piles){
            total += ceil((double)(it)/(double)(hours));
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        //Binary Search While loop, runs from 1 to maxElement of piles
        while(low <= high){
            int mid = (high + low)/2;

            long totalHours = calcHours(piles, mid);
            
            //this means that we can try and use smaller numbers to get a smaller totalHours
            if(totalHours <= h){
                ans = totalHours;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        //returning low as the correct answer as when you draw the binary search line, you will notice
        //that low is always at the correct spot while high is in the incorrect spot (high passes low) 
        return low;
    }
};