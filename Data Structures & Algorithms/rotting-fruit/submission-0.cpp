struct Cell{
    int row;
    int col;
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Cell> q;
        int time = 0;
        int fresh = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == 1){
                    fresh++;
                }
                if (grid[r][c] == 2){
                    Cell curr = {r, c};
                    q.push(curr);
                }
            }
        }

        while (!q.empty() && fresh > 0){
            int size = q.size();
            for (int i = 0; i < size; i++){
                Cell c = q.front();
                q.pop();

                for (const auto& d : directions){
                    int row = c.row + d.first;
                    int col = c.col + d.second;

                    if (row >= 0 && row < grid.size() && 
                        col >= 0 && col < grid[0].size() && 
                        grid[row][col] == 1){
                            grid[row][col] = 2;
                            Cell update = {row, col};
                            q.push(update);
                            fresh--;
                    }
                }
            }
            time++;
        }

        if (fresh == 0){
            return time;
        }

        return -1;
    }
};
