bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        unordered_set<int> set;
        
        for (auto i : arr) map[i]++;
        
        for (auto i : map) {
            if (!set.insert(i.second).second) return false;
        }
        
        return true;
        
//         vector<int> map(2000);
//         vector<int> set(2000);
        
//         for (auto i : arr) {
//             map[i + 1000]++;
//         }
        
//         for (auto i : map) {
//             if (!i) continue;
//             if (set[i]) return false;
//             set[i]++;
//         }
        
//         return true;
    }
