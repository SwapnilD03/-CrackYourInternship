class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j,int currColor ,int color){
        if(color==currColor){
            return;
        }

        if(i<0 || j<0 || i==image.size() || j==image[0].size() || image[i][j]!=currColor){
            return;
        }

        image[i][j]=color;

        dfs(image,i-1,j,currColor,color);
        dfs(image,i+1,j,currColor,color);
        dfs(image,i,j-1,currColor,color);
        dfs(image,i,j+1,currColor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int currColor=image[sr][sc];
        dfs(image,sr,sc,currColor,color);
        return image;
    }
};
