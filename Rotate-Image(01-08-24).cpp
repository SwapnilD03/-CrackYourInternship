class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        int leftCol=0,rightCol=n-1;

        while(leftCol<rightCol){
            for(int i=0;i<n;i++){
                swap(matrix[i][leftCol],matrix[i][rightCol]);
            }
            leftCol++;rightCol--;
        }
    }
};
