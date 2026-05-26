class Solution {
public:
    bool isValidRowCol(const vector<vector<char>>& board, int r, bool row) {
        set<int> n;
        for(int i = 0; i < 9; i++) {
            char c = row ? board[r][i] : board[i][r];
            if(c != '.'){
                if(n.find(c) != n.end()) {
                    return false;
                }
                n.insert(c);
            }
        }
        return true;
    }
    bool isValidSquare(const vector<vector<char>>& board, int i, int j) {
        set<int> n;
        for(int ii=i; ii<=i+2; ii++) {
            for(int jj=j; jj<=j+2; jj++){
                char c = board[ii][jj];
                if(c != '.') {
                    if(n.find(c) != n.end()){
                        return false;
                    }
                    n.insert(c);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            if(!isValidRowCol(board,i,true))
                return false;
            if(!isValidRowCol(board,i,false))
                return false;
        }
        for(int i=0;i<9;i+=3) {
            for(int j=0;j<9;j+=3){
                if(!isValidSquare(board,i,j))
                    return false;
            }
        }
        return true;
    }
};
