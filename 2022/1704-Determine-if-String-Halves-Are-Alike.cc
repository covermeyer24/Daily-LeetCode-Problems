bool halvesAreAlike(string s) {
        int count = 0;
        
        for (int i = 0; i < s.size() / 2; i++) {
            if (isVowel(s[i])) count++;
        }
        
        for (int i = s.size() / 2; i < s.size(); i++) {
            if (isVowel(s[i])) count--;
        }
        
        return !count;
    }
    
    bool isVowel(char& c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || 
           c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
