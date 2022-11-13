string reverseWords(string s) {
        stack<string> stack;
        
        string temp;
        for (auto& c : s) {
            //If the character is a space push the current word into the stack
            //If the current word has already been pushed then just continue
            //If the character is not a space then add it to the current word
            if (c ==' ') {
                if (temp != "") stack.push(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        
        //Push the final word onto the stack if there were no ending spaces
        if (temp != "") stack.push(temp);
        
        string res;
        while (!stack.empty()) {
            //Iterate through the stack to create the final reverse word string
            res += stack.top();
            stack.pop();
            res += ' ';
        }
        
        //Remove the last space
        res.erase(res.size() - 1);
        return res;
    }
