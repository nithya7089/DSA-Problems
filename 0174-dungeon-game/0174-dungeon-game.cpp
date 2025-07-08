class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int r = d.size() -1;
        int c = d[0].size() - 1;
        d[r][c] = 1 - min(0,d[r][c]);
        for(int i = r;i>=0;i--){
            for(int j = c;j>=0;j--){
                if(i==r && j==c) continue;
                int next = 400000001;
                if(i!=r) next = min(next,d[i+1][j]);
                if(j!=c) next = min(next,d[i][j+1]);
                d[i][j] = max(1,next-d[i][j]);
            }
        }

        return d[0][0];
    }
};