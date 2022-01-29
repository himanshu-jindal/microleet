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
    vector<int> inorderTraversal(TreeNode* root) {
 	

        //solution from book
        
	stack<TreeNode*> s1;
        vector<int> result;
        
        while(1){
            
            
            while(root){
                
                s1.push(root);
                root = root->left;
                
            }
            
            
            if(!s1.empty()){
                
                root = s1.top();
                s1.pop();
                result.push_back(root->val);
                
                // till this part of code, we have traversed left part and root part, 
                // right is pending, so traverse that now
                root = root->right;
                
            }
            else
                break;
                
        }
        
        return result;
        
    }
};
