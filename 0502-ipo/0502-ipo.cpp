class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        std::vector<std::pair<int, int>> projects(n);

        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }

        // Sort projects by capital required
        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;
        int i = 0;

        while (k--) {
            // Push all projects that can be started with current capital into the maxHeap
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                ++i;
            }

            // If no projects can be started, break the loop
            if (maxHeap.empty()) break;

            // Take the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};