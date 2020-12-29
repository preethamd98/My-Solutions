class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool changed = false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j+2<board[0].size();j++){
                int val = abs(board[i][j]);
                if(val > 0 and (abs(board[i][j+1])==val) and (abs(board[i][j+2]) == val)){
                       board[i][j] = -val;
                       board[i][j+1] = -val;
                       board[i][j+2] = -val;
                       changed = true;
                }
            }
        }
        
        for(int j=0;j<board[0].size();j++){
            for(int i=0;i+2<board.size();i++){
                int val = abs(board[i][j]);
                if(val > 0 and (abs(board[i+1][j])== val) and (abs(board[i+2][j]) == val)){
                   board[i][j] = -val;
                  board[i+1][j] = -val;
                board[i+2][j] = -val;
                    changed = true;
                }
            }
        }
        
        for(int j = 0; j < board[0].size(); j++){
            int writeHead = board.size()-1;
            for(int i = board.size()-1; i >= 0; i--) {
                if(board[i][j] > 0){
                    board[writeHead--][j] = board[i][j];
                }
            }
            while(writeHead >= 0) {
                board[writeHead--][j] = 0;
            }
        }
        
        if(changed) {
            return candyCrush(board);
        }
        return board;
    }
};
