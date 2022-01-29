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
        
        stack<TreeNode*> s1;
        vector<int> result;
        TreeNode* prev;
        
        do{
            
            while(root){
                
                s1.push(root);
                root = root->left;
                
            }
            
            while(root == NULL && !s1.empty()){
                
                root = s1.top();
                
                if(root->right == NULL || root->right == prev){
                    s1.pop();
                    result.push_back(root->val);
                    prev = root;
                    root = NULL;
                       
                }
                else
                    root = root->right;
                
                
            }
            
        }while(!s1.empty());
        
            
        return result;
        
    }
};
