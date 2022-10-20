    string numString = to_string(num);
        
        reverse(numString.begin(), numString.end());
        
        string res = "";
        
        for (int i = 0; i < numString.size(); i++) {
            //Ones
            if (i == 0) {
                if (numString[i] == '4') {
                    res += "VI";
                    continue;
                } else if (numString[i] == '9') {
                    res += "XI";
                    continue;
                }
                
                int h = numString[i] - '0';
                
                if (h < 5) h += 5;
                
                for (int j = 0; j < h - 5; j++) {
                    res += 'I';
                }
                
                if (numString[i] - '0' >= 5) res += 'V';
            } else if (i == 1) { //Tens
                if (numString[i] == '4') {
                    res += "LX";
                    continue;
                } else if (numString[i] == '9') {
                    res += "CX";
                    continue;
                }
                
                int h = numString[i] - '0';
                
                if (h < 5) h += 5;
                
                for (int j = 0; j < h - 5; j++) {
                    res += 'X';
                }
                
                if (numString[i] - '0' >= 5) res += 'L';
            } else if (i == 2) { //Hundreds
                if (numString[i] == '4') {
                    res += "DC";
                    continue;
                } else if (numString[i] == '9') {
                    res += "MC";
                    continue;
                }
                
                int h = numString[i] - '0';
                
                if (h < 5) h += 5;
                
                for (int j = 0; j < h - 5; j++) {
                    res += 'C';
                }
                
                if (numString[i] - '0' >= 5) res += 'D';
            } else if (i == 3) { //Thousands
                for (int j = 0; j < numString[i] - '0'; j++) {
                    res += 'M';
                }
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
