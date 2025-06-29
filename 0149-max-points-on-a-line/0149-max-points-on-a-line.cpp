class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        if (p.size() <= 2) {
            return p.size();
        }

        int max = 2;

        for (int i = 0; i < p.size() - 2; i++) {
            for (int j = i + 1; j < p.size() - 1; j++) {
                int n = 2;

                for (int k = j + 1; k < p.size(); k++) {
                    if ((p[k][1] - p[j][1]) * (p[j][0] - p[i][0]) ==
                        (p[j][1] - p[i][1]) * (p[k][0] - p[j][0])) {
                        n++;
                    }
                }

                max = std::max(max, n);
            }
        }

        return max;
    }
};