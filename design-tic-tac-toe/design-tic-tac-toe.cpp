class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<int> rows;
    vector<int> cols;
    int diag1 = 0;
    int diag2 = 0;
    int size = 0;
    TicTacToe(int n) {
        rows.resize(n,0);
        cols.resize(n,0);
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int winner = player;
        if(player==2){player=-1;}
        if(row == col){diag1 += player;}
        if(row + col == size - 1){diag2+=player;}
        rows[row]+=player;
        cols[col]+=player;
        if(abs(rows[row])==size || abs(cols[col])==size || abs(diag1)==size || abs(diag2)==size){
            return winner;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */