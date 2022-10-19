vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> map;
        
        //Gets the frequency of the words in the array
        for (auto s : words) {
            map[s]++;
        }
        
        vector<pair<string, int>> res;
        
        //Pushes the word and its frequency into a new array
        for (auto p : map) {
            res.push_back(p);
        }
        
        //Sorts the array based on the frequency of the words.  (Decending)
        sort(res.begin(), res.end(), compare);
        
        //Erases the not needed words from the array
        res.erase(res.begin() + k, res.end());
        
        vector<string> ans(res.size());
        
        //Takes the pair vector and addes just the words into a string vector to be returned
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = res[i].first;
        }
        
        return ans;
    }
    
    //Custom compare function that sorts decreasingly and in times of a tie, it will sort lexigraphically.
    static bool compare(pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        
        return a.second > b.second;
    }
