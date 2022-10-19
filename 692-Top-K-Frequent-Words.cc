vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> map;
        
        for (auto s : words) {
            map[s]++;
        }
        
        vector<pair<string, int>> res;
        
        for (auto p : map) {
            res.push_back(p);
        }
        
        sort(res.begin(), res.end(), compare);
        
        res.erase(res.begin() + k, res.end());
        
        vector<string> ans(res.size());
        
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = res[i].first;
        }
        
        return ans;
    }
    
    static bool compare(pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        
        return a.second > b.second;
    }
