int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int, vector<int>, greater<int>> queue;
        
        for (int i = 0; i < capacity.size(); i++) {
            //Push the remaining rocks into the priority queue
            queue.push(capacity[i] - rocks[i]);
        }
        
        int res = 0;
        
        
        //While there are still additional rocks to fill up the bags
        while (additionalRocks >= queue.top() && !queue.empty()) {
            additionalRocks -= queue.top();
            queue.pop();
            res++;
        }
        
        return res;
    }
