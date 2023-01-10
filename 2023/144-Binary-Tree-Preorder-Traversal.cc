vector<int> preorderTraversal(TreeNode* root) {
        //Recursion
        vector<int> res;
        
        recurse(root, res);
        
        return res;
    }
    
    void recurse(TreeNode* root, vector<int>& res) {
        if (!root) return;
        
        res.push_back(root->val);
        
        recurse(root->left, res);
        recurse(root->right, res);
    }
