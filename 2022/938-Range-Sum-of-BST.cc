int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        
        //If the value lies in the range
        if (root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + 
                rangeSumBST(root->right, low, high);
            // int total = root->val + rangeSumBST(root->left, low, high);
            // return total + rangeSumBST(root->right, low, high);
        } else if (root->val <= low) { // If the value is less then low then only check the right side
            return rangeSumBST(root->right, low, high);
        } else if (root->val >= high) { // If the value is more then high then only check the left side
            return rangeSumBST(root->left, low, high);
        }
        
        return 0;
    }
