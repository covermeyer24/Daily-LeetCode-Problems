int uniquePathsIII(vector<vector<int>>& grid) {
        //First Hard Problem Without Help
        
        int res = 0, total = 0, y = 0, x = 0;
        vector<vector<int>> seen(grid.size(), vector<int>(grid[0].size()));
        
        //Find the starting square and how many empty squares
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!grid[i][j]) {
                    total++;
                } else if (grid[i][j] == 1) {
                    y = i;
                    x = j;
                }
            }
        }
        
        recurse(x, y, grid, seen, res, total, 0);
        
        return res;
    }
    
    void recurse(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& seen, int& res, int total, int spaces) {
        if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || seen[y][x] || grid[y][x] == -1) {
            return;
        }
        
        //If the square is empty increment the seen amount of empty squares
        if (!grid[y][x]) {
            spaces++;
        }
        
        //If this is the ending square and the total seen empty squares is equal to
        // the total number of empty squares then increment the result
        if (grid[y][x] == 2) {
            if (spaces == total) {
                res++;
            }
            return;
        }
        
        //Make the the square seen for continuing paths
        seen[y][x] = 1;
        
        //DFS
        recurse(x + 1, y, grid, seen, res, total, spaces);
        recurse(x - 1, y, grid, seen, res, total, spaces);
        recurse(x, y + 1, grid, seen, res, total, spaces);
        recurse(x, y - 1, grid, seen, res, total, spaces);
        
        //Backtrack
        seen[y][x] = 0;
    }
