struct Cell {
    int row;
    int col;
};

class Solution {
public:
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if (grid[r][c] == '1'){
                    bfs(grid,r,c);
                    islands++;
                }
            }
        }

        return islands;
    }

    void bfs(vector<vector<char>>& grid, int r, int c){
        queue<Cell> q;
        grid[r][c] = '0';
        Cell cells = {r, c};
        q.push(cells);

        while (!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.row;
            int col = node.col;

            for(int i = 0; i < 4; i++){
                int nr = row + direction[i][0];
                int nc = col + direction[i][1];

                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc <= grid[0].size() && grid[nr][nc] == '1'){
                    Cell newCell = {nr, nc};
                    q.push(newCell);
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
