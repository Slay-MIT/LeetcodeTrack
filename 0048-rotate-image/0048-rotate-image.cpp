class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //matrix transpose
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //as each row is a reverse of the transpose of the matrix
        for(int i=0; i<matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        for(auto it: matrix){
            for(auto ele: it){
                cout<<ele<<' ';
            }
            cout<<'\n';
        }
    }
};