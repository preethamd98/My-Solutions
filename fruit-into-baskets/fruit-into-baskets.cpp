class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> basket;
        int start = 0;
        int size = fruits.size();
        int length = INT_MIN;
        for(int end=0;end<size;end++){
            basket[fruits[end]]++;
            while(start<size and basket.size()>2){
                basket[fruits[start]]--;
                if(basket[fruits[start]]==0){basket.erase(fruits[start]);}
                start++;
            }
            length = max(length,end-start+1);
        }
        return length;
    }
};