class Solution {
public:
    void floodfill(vector<vector<char>>& board, int i, int j, int numRow, int numCol, char target, char newChar){
        if (i<0 || i >= numRow){return;}
        if (j<0 || j >= numCol){return;}
        if (board[i][j] != target){return;}
        board[i][j] = newChar;
        floodfill(board,i+1,j,numRow,numCol,target,newChar);
        floodfill(board,i,j+1,numRow,numCol,target,newChar);
        floodfill(board,i-1,j,numRow,numCol,target,newChar);
        floodfill(board,i,j-1,numRow,numCol,target,newChar);
        return;
    }   
    
    void solve(vector<vector<char>>& board) {
        int numRow = board.size();
        int numCol = board[0].size();
        for (int j = 0; j < numRow; j++){
            if (board[j][0] == 'O'){
                floodfill(board,j,0,numRow,numCol,'O','-');
            }
            if (board[j][numCol-1] == 'O'){
                floodfill(board,j,numCol-1,numRow,numCol,'O','-');
            }
        }
        for (int j = 0; j < numCol; j++){
            if (board[0][j] == 'O'){
                floodfill(board,0,j,numRow,numCol,'O','-');
            }
            if (board[numRow-1][j] == 'O'){
                floodfill(board,numRow-1,j,numRow,numCol,'O','-');
            }
        }
        for (int j = 0 ; j < numRow; j++){
            for (int k = 0; k < numCol; k++){
                if (board[j][k] == 'O'){
                    board[j][k] = 'X';
                }
                if (board[j][k] == '-'){
                    board[j][k] = 'O';
                }
            }
        }
        return;
    }
};