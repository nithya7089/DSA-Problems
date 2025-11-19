class Solution {
private:
    int n;
    vector<vector<string>> res;
    vector<bool> col, rdiag, ldiag;
    void dfs(vector<string>& board , int row){
        if(row == n) return res.push_back(board);
        for(int c = 0; c < n; ++c){
            if(!col[c] && !rdiag[row + c] && !ldiag[row + n - 1 - c]){
                col[c] = rdiag[row + c] = ldiag[row + n - 1 - c] = true;
                board[row][c] = 'Q';
                dfs(board , row + 1);
                board[row][c] = '.';
                col[c] = rdiag[row + c] = ldiag[row + n - 1 - c] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        if(n == 1) return {{"Q"}};
        if(n < 4) return res;
        col.assign(n , false);
        rdiag.assign(2 * n - 1, false);
        ldiag.assign(2 * n - 1, false);
        vector<string> board(n , string(n , '.'));
        dfs(board , 0);
        return res;
    }
};