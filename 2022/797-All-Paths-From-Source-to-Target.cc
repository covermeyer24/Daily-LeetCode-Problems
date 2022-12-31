vector<vector<int>> res;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        int end = graph.size() - 1;
        recurse(0, end, path, graph);
        return res;
    }
    
    void recurse(int curr, int end, vector<int>& path, vector<vector<int>>& graph) {
        //If the end is reached push the completed path
        if (curr == end) {
            path.push_back(end);
            res.push_back(path);
            path.pop_back();
            return;
        }
        
        //Push the current node into the path
        path.push_back(curr);
        
        for (auto i : graph[curr]) {
            //DFS through every connected node
            recurse(i, end, path, graph);
        }
        
        //Backtrack
        path.pop_back();
    }
