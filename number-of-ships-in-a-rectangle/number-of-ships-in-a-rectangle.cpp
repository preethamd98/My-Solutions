/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */
​
class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        
    if((topRight[0]<bottomLeft[0] or topRight[1]<bottomLeft[1]) or !sea.hasShips(topRight, bottomLeft)){return 0;}
        if(topRight[0] == bottomLeft[0] and topRight[1] == bottomLeft[1]){
            return sea.hasShips(topRight, bottomLeft);
        }
        else {
            int midX = (topRight[0] + bottomLeft[0]) / 2;
            int midY = (topRight[1] + bottomLeft[1]) / 2;
            // ([(midX, midY), (bottomLeft)], 
            //  [(topRightX, midY), (midX, bottomLeftY)],
            //  [(topRight), (midX, midY)],
            //  [(midX, topRightY), (bottomLeftX, midY)])
//             cout<<"BLOCK-1"<<"{"<<midX<<","<<midY<<"}"<<"{"<<bottomLeft[0]<<","<<bottomLeft[1]<<"}"<<endl;
//             cout<<"BLOCK-2"<<"{"<<topRight[0]<<","<<midY<<"}"<<"{"<<midX+1<<","<<bottomLeft[1]<<"}"<<endl;
//             cout<<"BLOCK-3"<<"{"<<topRight[0]<<","<<topRight[1]<<"}"<<"{"<<midX+1<<","<<midY+1<<"}"<<endl;
//             cout<<"BLOCK-4"<<"{"<<midX<<","<<topRight[1]<<"}"<<"{"<<bottomLeft[0]<<","<<midY+1<<"}"<<endl;
            
            
            
            return countShips(sea, {midX, midY}, bottomLeft) +
                    countShips(sea, {topRight[0], midY}, {midX+1, bottomLeft[1]}) + countShips(sea, topRight, {midX+1, midY+1}) + countShips(sea, {midX, topRight[1]}, {bottomLeft[0], midY+1});
        }
    }
};
