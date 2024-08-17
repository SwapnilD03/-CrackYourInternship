class NumMatrix {
public:
    vector<vector<int>> tree;
    int N, M;

    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        N = matrix.size();
        M = matrix[0].size();
        tree.resize(4 * N, vector<int>(4 * M, 0));
        build(matrix, 0, N - 1, 0,M-1,0,0);
    }

    void build(vector<vector<int>>& matrix, int row1, int row2, int col1, int col2, int nodeRow, int nodeCol) {
        if (row1 > row2 || col1 > col2) return;

        // Base Case: Leaf Node
        if (row1 == row2 && col1 == col2) {
            tree[nodeRow][nodeCol] = matrix[row1][col1];
            return;
        }

        // Recursively build four quadrants
        int midRow = row1 + (row2 - row1) / 2;
        int midCol = col1 + (col2 - col1) / 2;

        build(matrix, row1, midRow, col1, midCol, 2 * nodeRow+1 , 2 * nodeCol+1 ); 
        build(matrix, row1, midRow, midCol + 1, col2, 2 * nodeRow+1, 2 * nodeCol + 2); 
        build(matrix, midRow + 1, row2, col1, midCol, 2 * nodeRow + 2, 2 * nodeCol+1 ); 
        build(matrix, midRow + 1, row2, midCol + 1, col2, 2 * nodeRow + 2, 2 * nodeCol + 2); 
      
        tree[nodeRow][nodeCol] = tree[2 * nodeRow+1][2 * nodeCol+1] + tree[2 * nodeRow+1][2 * nodeCol+2]
                               + tree[2 * nodeRow + 2][2 * nodeCol+1] + tree[2 * nodeRow + 2][2 * nodeCol + 2];
    }

    int query(int nodeRow, int nodeCol, int row1, int row2, int col1, int col2, int queryRow1, int queryRow2, int queryCol1, int queryCol2) {
        
        if (row1 > queryRow2 || row2 < queryRow1 || col1 > queryCol2 || col2 < queryCol1) {
            return 0;
        }

       
        if (row1 >= queryRow1 && row2 <= queryRow2 && col1 >= queryCol1 && col2 <= queryCol2) {
            return tree[nodeRow][nodeCol];
        }

        
        int midRow = row1 + (row2 - row1) / 2;
        int midCol = col1 + (col2 - col1) / 2;

        int topLeft = query(2 * nodeRow+1, 2 * nodeCol + 1, row1, midRow, col1, midCol, queryRow1, queryRow2, queryCol1, queryCol2);
        int topRight = query(2 * nodeRow+1, 2 * nodeCol + 2, row1, midRow, midCol + 1, col2, queryRow1, queryRow2, queryCol1, queryCol2);
        int bottomLeft = query(2 * nodeRow + 2, 2 * nodeCol + 1, midRow + 1, row2, col1, midCol, queryRow1, queryRow2, queryCol1, queryCol2);
        int bottomRight = query(2 * nodeRow + 2, 2 * nodeCol + 2, midRow + 1, row2, midCol + 1, col2, queryRow1, queryRow2, queryCol1, queryCol2);

        
        return topLeft + topRight + bottomLeft + bottomRight;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (N == 0 || M == 0) return 0;
        return query(0,0, 0, N - 1, 0, M - 1, row1, row2, col1, col2);
    }
};

