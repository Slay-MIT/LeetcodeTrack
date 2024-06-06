class Solution {
public:

    vector<int> createVector(vector<int>& v, int i){
        vector<int> x;
        x.push_back(1);
        for(int j=2; j<=i; j++){
            x.push_back(v[j-1] + v[j-2]);
        }
        x.push_back(1);
        return x;
    } 

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> res;
        vector<int> v;

        v.push_back(1);
        res.push_back(v);

        if(numRows == 1){
            return res;
        }

        v.push_back(1);
        res.push_back(v);

        if(numRows == 2){
            return res;
        }


        for(int i=2; i<numRows; i++){
            v = createVector(v, i);
            res.push_back(v);
        }
        
        return res;
    }
};