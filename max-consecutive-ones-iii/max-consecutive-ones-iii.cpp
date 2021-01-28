class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        // int i = 0;
        int j = 0;
        int count = 0;
        int size = A.size();
        int windowLength = INT_MIN;
        for(int i=0;i<size;i++){
            if(A[i]==0){count++;}
            while(count > K){
                if(A[j]==0){
                    count--;
                }
                j++;
            }
            windowLength = max(windowLength,i-j+1);
        }
        return windowLength;
    }
};