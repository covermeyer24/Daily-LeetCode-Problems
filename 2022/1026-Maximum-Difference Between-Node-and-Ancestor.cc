int maxAncestorDiff(TreeNode* root) {
        int currMin = 1e6, currMax = -1, res = -1;
        
        recurse(root, currMin, currMax, res);
        
        return res;
        
           //Brute Force
//         vector<int> list;
//         int res = -1;
        
//         recurse(root, list, res);
        
//         return res;
    }
    
    void recurse(TreeNode *root, int currMin, int currMax, int& res) {
        if (!root) return;
        
        //Set the current min and max value
        currMin = min(currMin, root->val);
        currMax = max(currMax, root->val);
        
        //Once the recursion reaches a leaf node then compute the difference between the min and max value found in the path
        if (!root->left && !root->right) {
            res = max(abs(currMin - currMax), res);
            return;
        }
        
        //Preorder traversal
        recurse(root->left, currMin, currMax, res);
        recurse(root->right, currMin, currMax, res);
        
    }
    
       //Brute Force
//     void recurse(TreeNode *root, vector<int>& list, int& res) {
//         if (!root) return;
        
//         for (auto i : list) {
//             if (abs(i - root->val) > res) res = abs(i - root->val);
//         }
        
//         list.push_back(root->val);
        
//         recurse(root->left, list, res);
//         recurse(root->right, list, res);
        
//         list.pop_back();
//     }
