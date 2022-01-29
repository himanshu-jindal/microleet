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
    vector<int> postorderTraversal(TreeNode* root) {
        
 	// preorder->     	root left right
	// postorder->          left right root
	// modified preorder->  root right left
	
	
	// now, modified preorder and postorder are reverse of each other
	// not actual postorder, but result is same
        vector<int> result; 
        if(!root)
            return result;
    
        
        stack<TreeNode*> s1;
        s1.push(root);
        
        while(!s1.empty()){
            
            root = s1.top();
            s1.pop();
            result.push_back(root->val);
            
            if(root->left)
                s1.push(root->left);
            
            if(root->right)
                s1.push(root->right);
            
            
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
