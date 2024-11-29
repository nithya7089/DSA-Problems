class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0] > 1 && grid[0][1] > 1) return -1;

        const int n = grid.size(), m = grid[0].size();
        const int d[5] = {0, 1, 0, -1, 0};
        vector<int> time(n * m, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.emplace(0, 0);
        time[0] = 0;

        while (!pq.empty()) {
            auto [t, ij] = pq.top();
            pq.pop();
            int i = ij / m, j = ij % m;

            if (i == n - 1 && j == m - 1) return t;

            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (r < 0 || r >= n || s < 0 || s >= m) continue;

                int w = ((grid[r][s] - t) & 1) ? 0 : 1;
                int nextTime = max(t + 1, grid[r][s] + w);

                int rs = r * m + s;
                if (nextTime < time[rs]) {
                    time[rs] = nextTime;
                    pq.emplace(nextTime, rs);
                }
            }
        }

        return -1;
    }
};
