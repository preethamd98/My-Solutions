class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
     sort(arr.begin(),arr.end());
     int diff1 = arr[1] - arr[0];
     bool flag1 = true;
     bool flag2 = true;
     for(int i=1;i<arr.size();i++){
         if(arr[i] - arr[i-1] != diff1){flag1=false; break;}
     }
    sort(arr.begin(), arr.end(), greater<int>());
    int diff2 = arr[1] - arr[0];
    for(int i=1;i<arr.size();i++){
         if(arr[i] - arr[i-1] != diff1){flag2 = false;break;}
    }
        return (flag1 or flag2);
    
    }
};
