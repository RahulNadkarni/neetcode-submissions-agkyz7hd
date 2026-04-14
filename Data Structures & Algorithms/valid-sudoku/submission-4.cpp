class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row; 
        unordered_map<int, unordered_set<char>> col; 
        map<pair<int,int>, unordered_set<char>> grid;


        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue; 
                }
                if (row[i].count(board[i][j])){
                    return false; 
                }
                if (col[j].count(board[i][j])) {
                    return false; 
                }
                pair<int, int> square = {i/3,j/3}; 
                if (grid[square].count(board[i][j])) {
                    return false; 
                }
                row[i].insert(board[i][j]); 
                col[j].insert(board[i][j]); 
                grid[square].insert(board[i][j]); 
            }
        }
        return true; 
    
    }
};
