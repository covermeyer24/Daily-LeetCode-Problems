string removeDuplicates(string s) {
        vector<char> stack;
        int i = 1;
        
        stack.push_back(s[0]);
        
        while (i < s.size()) {
            if (!stack.empty() && stack.back() == s[i]) {
                //Remove the duplicate char from the stack
                stack.pop_back();
            } else {
                //Add the current char to the stack
                stack.push_back(s[i]);
            }
            i++;
        }
        string res(stack.begin(), stack.end());
    
        return res;
    }
