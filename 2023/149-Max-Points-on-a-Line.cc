int maxPoints(vector<vector<int>>& points) {
        //Help from
        // https://leetcode.com/problems/max-points-on-a-line/discuss/3016390/C%2B%2BEasyoror-BEATS-99-ororExplanation
        
        if (points.size() == 1) return 1;
        
        int res = 1;
        
        for (int i = 0; i < points.size(); i++) {
            //Map is used to keep track of frequency of slopes between a set point
            // and the points ahead of it in the vector
            unordered_map<double, int> map;
            int undefined = 1;
            
            for (int j = i + 1; j < points.size(); j++) {
                //Same x coord == undefined slope
                if (points[i][0] == points[j][0]) undefined++;
                else map[((double) points[i][1] - points[j][1]) 
                         / ((double) points[i][0] - points[j][0]) ]++;
            }
            
            //Finds the greatest slope frequency
            for (auto& slope : map) {
                undefined = max(slope.second + 1, undefined);
            }
            
            res = max(undefined, res);
        }
        
        return res;
    }
