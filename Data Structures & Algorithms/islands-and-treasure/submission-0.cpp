struct Cell {
    int row;
    int col;
};

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        queue<Cell> q;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0){
                    Cell newc = {i,j};
                    q.push(newc);
                }
            }
        }

        while (!q.empty()){
            int row = q.front().row;
            int col = q.front().col;
            q.pop();

            for (int i = 0; i < 4; i++){
                int r = row + directions[i][0];
                int c = col + directions[i][1];

                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != INT_MAX){
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;
                Cell updatec = {r,c};
                q.push(updatec);
            }
        }
    }
};
