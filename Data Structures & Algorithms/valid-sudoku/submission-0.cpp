class Solution {
public:
    bool checkBox(int r, int c, vector<vector<char>>& board) {
        vector<bool> visited(9, false);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (board[i][j] == '.')
                    continue;
                if (visited[board[i][j] - '0'])
                    return false;
                visited[board[i][j] - '0'] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // check each row
        for (int i = 0; i < 9; i++) {
            vector<bool> visited(9, false);
            // check each col
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (visited[board[i][j] - '0'])
                    return false;
                visited[board[i][j] - '0'] = true;
            }
        }
        // check each col
        for (int i = 0; i < 9; i++) {
            vector<bool> visited(9, false);
            // check each row
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;
                if (visited[board[j][i] - '0'])
                    return false;
                visited[board[j][i] - '0'] = true;
            }
        }
        // check for each box
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!checkBox(i, j, board))
                    return false;
            }
        }

        return true;
    }
};