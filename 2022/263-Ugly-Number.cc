bool isUgly(int n) {
        //Checks for zero, and negative numbers
        if (n <= 0) return false;
        
        while (n != 1) {
            //Checks for factor by 2, then 3, then 5 until either the there isn't
            // anymore 2, 3, 5 factors which returns false or the resulting number is 1
            // which returns true
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 3 == 0) {
                n /= 3;
            } else if (n % 5 == 0) {
                n /= 5;
            } else {
                return false;
            }
        }
        
        return true;
    }
