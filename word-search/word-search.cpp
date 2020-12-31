class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int wordChar, vector<vector<bool>>& visited) {
        if(wordChar == word.size())
            return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || word[wordChar] != board[i][j]){
            return false;
        }
            
        visited[i][j] = true;
        
        bool res =  dfs(board, i+1, j, word, wordChar+1, visited) || dfs(board, i, j+1, word, wordChar+1, visited) 
            || dfs(board, i-1, j, word, wordChar+1, visited) || dfs(board, i, j-1, word, wordChar+1, visited);
        if(res){
            return true;
        }
        visited[i][j] = false;
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, i, j, word, 0, visited))
                        return true;
                }
            }
        }
        return false;
        
        
    }
};
