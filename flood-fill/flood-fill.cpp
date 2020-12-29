class Solution {
public:
    void dfs(int oldColor,int newColor,vector<vector<int>>& image,int x,int y){
    if(x<0 or x>=image.size() or y<0 or y>=image[0].size() or image[x][y]==newColor or image[x][y]!=oldColor){return;}
    image[x][y] = newColor;
    dfs(oldColor,newColor,image,x+1,y);
    dfs(oldColor,newColor,image,x,y+1);
    dfs(oldColor,newColor,image,x-1,y);
    dfs(oldColor,newColor,image,x,y-1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image[sr][sc],newColor,image,sr,sc);
        return image;
    }
};
