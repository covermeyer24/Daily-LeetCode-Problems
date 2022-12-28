int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> queue(piles.begin(), piles.end());
        int total = accumulate(piles.begin(), piles.end(), 0);
        
        while (k) {
            int temp = queue.top();
            queue.pop();
            
            //Subtract the removed stones from the total
            total -= temp / 2;
            
            //Push the new amount of stones for that pile
            queue.push((temp + 1) / 2);
            k--;
        }
        
        return total;
        
//         int res = 0;
        
//         while (!queue.empty()) {
//             res += queue.top();
//             queue.pop();
//         }
        
//         return res;
    }
