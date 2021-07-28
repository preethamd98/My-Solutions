class Solution {
public:
    vector<vector<int>> generateMatrix(int N) {
        int m = N;
        int n = N;
        
        int up = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;
        
        int counter = 1;
        vector<vector<int>> matrix(m,vector<int>(n,0));
        
        while(counter <= m*n){
            for(int i=left;i<=right and counter <= m*n;i++){
                matrix[up][i] = counter;
                counter++;
            }
            for(int i=up+1;i<=down-1 and counter <= m*n;i++){
                matrix[i][right] = counter;
                counter++;
            }
            for(int i=right;i>=left and counter <= m*n;i--){
                matrix[down][i] = counter;
                 counter++;
            }
            for(int i=down-1;i>=up+1 and counter <= m*n;i--){
                 matrix[i][left] = counter;
                 counter++;
            }
            
            up++;
            left++;
            down--;
            right--;
        }
        return matrix;
    }
};