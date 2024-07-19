class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> res;
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        vector<int> minRow;
        vector<int> maxCol;

        for (auto it : matrix) {
            minRow.push_back(*min_element(it.begin(), it.end()));
        }

        for (int i = 0; i < matrix[0].size(); i++) {
            maxNum = INT_MIN;
            for (int j = 0; j < matrix.size(); j++) {
                maxNum = max(maxNum, matrix[j][i]);
            }
            maxCol.push_back(maxNum);
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};