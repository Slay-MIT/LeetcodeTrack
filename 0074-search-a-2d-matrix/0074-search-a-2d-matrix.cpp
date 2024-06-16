class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            for(int j=col-1; j>=0; j--){
                if(matrix[i][j] == target){
                    return true;
                }
                else if(matrix[i][j] > target){
                    continue;
                }
                else if(matrix[i][j] < target){
                    i++;
                    break;
                }
            }
        }return false;
    }
};