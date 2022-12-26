bool canJump(vector<int>& nums) {
        int jumpLen = nums[0];
        
        //Edge cases, already at last index, and starting with 0 jumps
        if (nums.size() == 1) return true;
        if (!jumpLen) return false;
        
        for (int i = 1; i < nums.size() - 1; i++) {
            //Take a jump
            jumpLen--;
            
            //If you can't jump anymore and landed on a 0 space
            if (!nums[i] && !jumpLen) {
                return false;
            }
            
            //If you landed on a space that allows more jumps
            if (jumpLen < nums[i]) {
                jumpLen = nums[i];
            }
        }
        
        //If you have more than 0 jumps left return true
        return jumpLen;
    }
