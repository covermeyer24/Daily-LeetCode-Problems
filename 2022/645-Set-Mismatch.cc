vector<int> findErrorNums(vector<int>& nums) {
    //First attempt using a map
//         unordered_map<int, int> map;
//         vector<int> res(2);
        
//         for (auto i : nums) {
//             map[i]++;
//         }
        
//         for (int i = 0; i < nums.size(); i++) {
//             if (!map[i + 1]) {
//                 res[1] = i + 1;
//             } else if (map[i + 1] == 2) {
//                 res[0] = i + 1;
//             }
//         }
        
//         return res;
        
        //Second attempt using an array
        vector<int> map(nums.size() + 1);
        vector<int> res(2);
        
        //Get the frequency of every number in nums
        for (auto i : nums) {
            map[i]++;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            //If one of the number frequencies is 0 then it is the missing number
            if (!map[i + 1]) {
                res[1] = i + 1;
            } else if (map[i + 1] == 2) { //If one of the number frequency is 2 then it is the duplicated number
                res[0] = i + 1;
            }
        }
        
        return res;
}
