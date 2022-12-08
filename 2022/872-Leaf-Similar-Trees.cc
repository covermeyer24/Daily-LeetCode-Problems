bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1, leafs2;
        
        //Find the leafs of the first, and second tree
        recurse(root1, leafs1);
        recurse(root2, leafs2);
        
        return leafs1 == leafs2;
    }
    
    void recurse(TreeNode* root, vector<int>& leaf) {
        if (!root) return;
        if (!root->left && !root->right) leaf.push_back(root->val);
        
        recurse(root->left, leaf);
        recurse(root->right, leaf);
    }
