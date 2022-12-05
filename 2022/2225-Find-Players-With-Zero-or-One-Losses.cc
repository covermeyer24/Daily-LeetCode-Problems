vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // set<int> losers;
        // set<int> dlosers;
        map<int, pair<int, int>> map;
        // set<int> winner;
        vector<vector<int>> res;
        vector<int> winners;
        vector<int> oneLoser;
        
        for (auto vec : matches) {
            int win = vec[0];
            int lose = vec[1];
            
            // winner.push(win);
            map[lose].first++;
            map[win].second++;
        }
        
        for (auto i : map) {
            if (i.second.first == 0 && i.second.second != 0) {
                winners.push_back(i.first);
            } else if (i.second.first == 1) {
                oneLoser.push_back(i.first);
            }
        }
        
        res.push_back(winners);
        res.push_back(oneLoser);
        
        return res;
    }
