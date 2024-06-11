class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int, int> mp;
        vector<int> rest;
        vector<int> res;

        for (auto it : arr2) {
            mp[it] = 0;
        }

        sort(arr1.begin(), arr1.end());

        for (auto it1 : arr1) {
            if (mp.find(it1) != mp.end()) {
                mp[it1]++;
            } else {
                rest.push_back(it1);
            }
        }

        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < mp[arr2[i]]; j++) {
                res.push_back(arr2[i]);
            }
        }

        for (auto it3 : rest) {
            res.push_back(it3);
        }

        return res;
    }
};