int numSquares(int n) {
        queue<pair<int, int>> queue;
        set<int> seen;
        int steps = 0;
        
        //Push every number that is n - a perfect square into the queue
        for (int i = sqrt(n); i >= 1; i--) {
            queue.push({n - (i * i), steps + 1});
        }
        
        while (!queue.empty()) {
            int tempN = queue.front().first;
            int tempSteps = queue.front().second;
            queue.pop();
            
            //If the number has already been seen continue
            if (!seen.insert(tempN).second) continue;
            
            //If the number of perfect square needed is found return it
            if (tempN == 0) return tempSteps;
            
            //Push every number that is n - a perfect square into the queue
            for (int i = sqrt(n); i >= 1; i--) {
                queue.push({tempN - (i * i), tempSteps + 1});
            }
        }
        return 1;
    }
