class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        int zero = mp[0];
        int one = mp[1];
        int two = mp[2];

        for (int i = 0; i < nums.size(); i++) {
            if (zero != 0) {
                nums[i] = 0;
                zero--;
            } else if (one != 0) {
                nums[i] = 1;
                one--;
            } else {
                nums[i] = 2;
                two--;
            }
        }
        for (auto it : nums) {
            cout << it;
        }
    }
};