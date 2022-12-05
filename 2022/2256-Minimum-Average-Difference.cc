int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size(), low = INT_MAX, index = -1;
        long long right = 0, left = 0;
        
        if (n == 1) return 0;
        
        //Add up the total sum of the array
        for (auto i : nums) {
            right += i;
        }
        
        //Create the left sum and the right sum for averaging
        right -= nums[0];
        left += nums[0];
        
        //For indexes 0 through n - 2
        for (int i = 0; i < n - 1; i++) {
            //Compute average difference
            int temp = abs(left / (i + 1) - right / (n - i - 1));
            
            //If this is the lowest average difference, then save the index
            if (temp < low) {
                index = i;
                low = temp;
            }
            
            //Update the left and right sum
            left += nums[i + 1];
            right -= nums[i + 1];
        }
        
        //For computing the last index with no right sum
        int temp = abs(left / n);
        if (temp < low) {
            index = n - 1;
        }
        
        return index;
    }
