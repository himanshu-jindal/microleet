/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
    // iterative preorder traversal using stack DS
        
        
        stack<TreeNode*> s1;
        if(root)
            s1.push(root);
        vector<int> v1;
        TreeNode* temp;

        
        while(!s1.empty()){
            
            temp = s1.top();
            s1.pop();
            v1.push_back(temp->val);
            
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
              
        }
        
        return v1;
    }
};
