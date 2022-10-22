bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         multimap<int, int> myMap;
        
//         //Go through the entire array and mark every position of every number
//         for (int i = 0; i < nums.size(); i++) {
//             myMap.insert(pair<int, int>(nums[i], i));
//         }
        
//         for (int i = 0; i < nums.size(); i++) {
//             //Get a current number
//             int temp = nums[i];
            
//             //Get every number equal to it in the arry
//             auto ret = myMap.equal_range(temp);
            
//             for (auto it = ret.first; it != ret.second; it++) {
//                 //Go through and compare every position to find one that works
//                 if (it->second != i && abs(it->second - i) <= k) {
//                     return true;
//                 }
//             }
//         }
        
//         return false;
        
        //More Optimal
        unordered_map<int, int> myMap;
        
        for (int i = 0; i < nums.size(); i++) {
            //If the number is in the map and i - the latest postion is less than or equal to k return true
            if (myMap.find(nums[i]) != myMap.end() && i - myMap[nums[i]] <= k) {
                return true;
            }
            
            //Upates the position of the number in the map
            myMap[nums[i]] = i;
        }
        
        return false;
    }
