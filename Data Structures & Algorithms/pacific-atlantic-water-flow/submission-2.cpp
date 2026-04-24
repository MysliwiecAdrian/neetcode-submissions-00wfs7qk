class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<int> > res;


        //  heights = [
            // [4,2,7,3,4],
            // [7,4,6,4,7],
            // [6,3,5,3,6]
            // ]
        // pacific [
        //   [T, T, T, T, T]
        //   [             ]
        //]

        // atlantic [
        //   [F, F, T, F, T]
        //]
        
        vector<vector<bool> > pacific(ROWS, vector<bool>(COLS, false));
        vector<vector<bool> > atlantic(ROWS, vector<bool>(COLS, false));
        vector<vector<bool> > visited(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; r++){
            dfs(r, 0, heights, pacific, visited);
        }

        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; r++){
            dfs(r, COLS - 1, heights, atlantic, visited);
        }

        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; c++){
            dfs(0, c, heights, pacific, visited);
        }

        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; c++){
            dfs(ROWS - 1, c, heights, atlantic, visited);
        }

        for (int r = 0; r < ROWS; r++){
            for (int c = 0; c < COLS; c++){
                if (pacific[r][c] && atlantic[r][c]){
                    res.push_back({r,c});
                }
            }
        }

        return res;
    }

    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean, vector<vector<bool> >& visited){          
        ocean[r][c] = true;
        visited[r][c] = true;

        if (r < heights.size() - 1 && heights[r + 1][c] >= heights[r][c] && visited[r + 1][c] == false){
            dfs(r + 1, c, heights, ocean, visited);
        }
        if(r >= 1 && heights[r - 1][c] >= heights[r][c] && visited[r - 1][c] == false){
            dfs(r - 1, c, heights, ocean, visited);
        }
        if (c < heights[0].size() - 1 && heights[r][c + 1] >= heights[r][c] && visited[r][c + 1] == false){
            dfs(r, c + 1, heights, ocean, visited);
        }
        if (c >= 1 && heights[r][c - 1] >= heights[r][c] && visited[r][c - 1] == false){
            dfs(r, c - 1, heights, ocean, visited);
        }

    }
};
