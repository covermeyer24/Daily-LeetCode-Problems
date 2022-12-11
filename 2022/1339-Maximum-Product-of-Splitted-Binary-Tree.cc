int maxProduct(TreeNode* root) {
        long long sum = 0;
        
        //Get the total sum of the tree
        recurse(root, sum);
        
        int mod = 1e9 + 7;
        long long currSum = 0, res = -1;
        
        recurseRes(root, currSum, sum, res);
        
        return res % mod;
    }
    
    void recurse(TreeNode *root, long long& sum) {
        if (!root) return;
        sum += root->val;
        recurse(root->left, sum);
        recurse(root->right, sum);
    }
    
    int recurseRes(TreeNode *root, long long currSum, long long sum, long long& res) {
        if (!root) return 0;
        
        //Postorder Traversal
        int left = recurseRes(root->left, currSum, sum, res);
        int right = recurseRes(root->right, currSum, sum, res);
        
        //Current subtree sum
        currSum += root->val + left + right;
        
        // currSum += root->val;
        
        //Check for the greatest subtree sum
        res = max(res, currSum * (sum - currSum));
        
        
        // if (!(root->left && root->right)) {
        //     res = max(res, currSum * (sum - currSum));
        // }
        
        // cout << root->val << ' ' << currSum << ' ' << res << endl;
        
        // recurseRes(root->left, currSum, sum, res);
        // recurseRes(root->right, currSum, sum, res);
        
        return currSum;
    }
