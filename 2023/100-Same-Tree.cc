bool isSameTree(TreeNode* p, TreeNode* q) {
        //Recursion
//         if (!p && !q) return true;
//         if ((!p && q) || (p && !q) || (p->val != q->val)) return false;
        
//         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
        //BFS Iterative
        queue<TreeNode *> q1, q2;
        q1.push(p);
        q2.push(q);
        
        while (!q1.empty() || !q2.empty()) {
            auto q1Node = q1.front();
            q1.pop();
            
            auto q2Node = q2.front();
            q2.pop();
            
            if (!q1Node && !q2Node) continue;
            if ((!q1Node || !q2Node) || q1Node->val != q2Node->val) return false;
            
            q1.push(q1Node->left);
            q1.push(q1Node->right);
            
            q2.push(q2Node->left);
            q2.push(q2Node->right);
        }
        
        return true;
    }
