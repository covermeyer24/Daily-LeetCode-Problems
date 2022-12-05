vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // set<int> losers;
        // set<int> dlosers;
        
        //map layout [team #, [losses, wins]]
        map<int, pair<int, int>> map;
        // set<int> winner;
        vector<vector<int>> res;
        vector<int> winners;
        vector<int> oneLoser;
        
        //Goes through the matches array
        for (auto vec : matches) {
            int win = vec[0];
            int lose = vec[1];
            
            // winner.push(win);
                
            //Increases the losing teams loss counter, and increases the winning teams win counter
            map[lose].first++;
            map[win].second++;
        }
        
        for (auto i : map) {
            
            //If the team's losses is zero, and the team's wins are not zero, add it to the winners array
            if (i.second.first == 0 && i.second.second != 0) {
                winners.push_back(i.first);
            } else if (i.second.first == 1) { //If the team only has one loss, add it to the losers array
                oneLoser.push_back(i.first);
            }
        }
        
        //Push the two arrays back into the return array
        res.push_back(winners);
        res.push_back(oneLoser);
        
        return res;
    }
