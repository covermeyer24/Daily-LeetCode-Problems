bool halvesAreAlike(string s) {
        int count = 0;
    
        //Checks how many vowels are in the left half of the string
        for (int i = 0; i < s.size() / 2; i++) {
            if (isVowel(s[i])) count++;
        }
        
        //Checks how many vowels are in the right half of the string
        for (int i = s.size() / 2; i < s.size(); i++) {
            if (isVowel(s[i])) count--;
        }
        
        //If the count is zero then the string halves have the same amount of vowels
        return !count;
    }
    
    //Takes in character to check if it is a vowel
    bool isVowel(char& c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || 
           c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false;
    }
