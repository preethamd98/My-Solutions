class Solution {
public:
    int xorOperation(int n, int start) {
        int value = 0;
        for(int i=0;i<n;i++){
            value ^= start + 2*i;
        }
        return value;
    }
};
