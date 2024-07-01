class Solution {
public:

    bool testOdd(int element, int &count){
        if(element%2){
            count++;
            return true;
        }
        return false;
    }

    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(int i=0; i<arr.size(); i++){
            
            if(testOdd(arr[i], count) == false){
                count = 0;
                continue;
            }

            if(count == 3){
                return true;
                
            }
        }
        return false;
    }
};