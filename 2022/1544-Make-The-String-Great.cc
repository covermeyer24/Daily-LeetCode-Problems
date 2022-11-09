string makeGood(string s) {
        if (s.size() == 1) return s;
        bool changed = true;
        
        while (changed && s.size()) {
            changed = false;
            for (int i = 0; i < s.size() - 1; i++) {
                //If the adjacent chars are a pair delete them and run the loop again
                if (abs(s[i] - s[i + 1]) == 32) {
                    changed  = true;
                    s.erase(i, 2);
                    break;
                }
            }
        }
        
        return s;
    }
