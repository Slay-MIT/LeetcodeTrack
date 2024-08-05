class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> countMap;
        
        // Step 1: Count occurrences of each string
        for (const string& str : arr) {
            countMap[str]++;
        }
        
        // Step 2: Find the k-th distinct string
        for (const string& str : arr) {
            if (countMap[str] == 1) {
                k--;
                if (k == 0) {
                    return str;
                }
            }
        }
        
        // If there is no k-th distinct string, return an empty string
        return "";
    }
};
