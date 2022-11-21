int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //Queue to hold the status, holds y, x coords and current steps
        queue<pair<pair<int, int>, int>> queue;
        vector<vector<int>> seen(maze.size(), vector<int>(maze[0].size(), 0));
        queue.push({{entrance[0], entrance[1]}, 0});
        
        while (!queue.empty()) {
            int y = queue.front().first.first;
            int x = queue.front().first.second;
            int steps = queue.front().second;
            queue.pop();
            
            //If coords are off the maze or already visited or a wall continue
            if (y < 0 || y >= maze.size() || x < 0 || x >= maze[0].size() || seen[y][x] || maze[y][x] == '+') continue;
            
            //If the coords are on the egde of the maze
            if (x == 0 || x == maze[0].size() - 1 || y == 0 || y == maze.size() - 1) {
                //Checks to make sure that this is not the entrance, if not return current steps
                if (x != entrance[1] || y != entrance[0]) return steps;
            }
            
            //Add coords to visited
            seen[y][x] = 1;
            
            //Push down
            queue.push({{y - 1, x}, steps + 1});
            
            //Push up
            queue.push({{y + 1, x}, steps + 1});
            
            //Push left
            queue.push({{y, x - 1}, steps + 1});
            
            //Push right
            queue.push({{y, x + 1}, steps + 1});
        }
        
        return -1;
    }
