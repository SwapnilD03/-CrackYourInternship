class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int m=matrix.size();
        int n=matrix[0].size();
        int a1=0,b1=0,a2=m-1,b2=n-1;
        while(a1<=a2 && b1<=b2){
            for(int j=b1;j<=b2;j++){
                spiral.push_back(matrix[a1][j]);
            }
            a1++;

            for(int k=a1;k<=a2;k++){
                spiral.push_back(matrix[k][b2]);
            }
            b2--;
            if(a1<=a2){
            for(int l=b2;l>=b1;l--){
                spiral.push_back(matrix[a2][l]);
            }
            a2--;
            }

            if(b1<=b2){
            for(int p=a2;p>=a1;p--){
                spiral.push_back(matrix[p][b1]);
            }
            b1++;
            }

        }

        return spiral;
    
    }
};
