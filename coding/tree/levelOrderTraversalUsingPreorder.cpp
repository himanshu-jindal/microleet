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
    vector<vector<int>> result;
    
    
    void helper(TreeNode* root, int depth){
        
        if(root == NULL)
            return;
        
        if(result.size() == depth)
            result.push_back(vector<int>());
        
        result[depth].push_back(root->val);
        
        helper(root->left, depth+1);
        helper(root->right, depth+1);   
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
	// actually this is preorder traversal. but it generates required output
	// if we would have to store result in vector not in vector<vector>, then this method won't work
	// we will have to use level order traversal using queue
	
        helper(root, 0);
        return result;
        
    }
};
