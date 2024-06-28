class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> mp;

        for (int i = 0; i < roads.size(); i++) {
            for (int j = 0; j < roads[i].size(); j++) {
                mp[roads[i][j]]++;
            }
        }
        vector<int> deg(n,0);

        for(auto it: mp){
            deg[it.first] = it.second;
        }
        sort(deg.begin(), deg.end());
        

        long long imp = 1;
        long long total = 0;
        for(auto it: deg){
            it *= imp;
            total += it;
            imp++;
        }
        return total;

    }
};