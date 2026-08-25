class Solution {
public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();

        // Convert -1 to INF
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == -1)
                    mat[i][j] = 1e9;

                if (i == j)
                    mat[i][j] = 0;
            }
        }

        // Floyd-Warshall Algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    mat[i][j] = min(mat[i][j],
                                    mat[i][via] + mat[via][j]);
                }
            }
        }

        // Convert INF back to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 1e9)
                    mat[i][j] = -1;
            }
        }
    }
};
