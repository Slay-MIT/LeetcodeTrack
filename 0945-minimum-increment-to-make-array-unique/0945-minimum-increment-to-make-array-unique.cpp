class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int minInc = 0;
        for(int i=1; i<nums.size(); i++){
            int curr = nums[i];
            //note: we do curr '<=' cuz when you add value to the numbers to inc.
            //their value, they might end up being smaller than their pred.
            //for example, 1,1,2,2,3,7 becomes 1,2,3,2,7 after 2 iterations
            //clearly, the curr(2) is smaller than predecessor(3) here.
            if(curr <= nums[i-1]){
                nums[i] = nums[i-1] + 1;
                minInc += (nums [i] - curr);
            }
        }
        return minInc;
    }
};