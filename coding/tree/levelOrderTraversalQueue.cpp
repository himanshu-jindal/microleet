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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // level order traversal using queue
        // some people use null marker to identify a level end, in some cases this can also be       useful so keep this idea also in mind
        
        queue<TreeNode*> q1;
        vector<vector<int>> result;
        
        if(root)
            q1.push(root);
        
        while(!q1.empty()){
            
            int size = q1.size();
            vector<int> temp;
            
            for(int i=0; i<size; i++){
                
                TreeNode* node = q1.front();
                q1.pop();
                temp.push_back(node->val);
                
                if(node->left)
                    q1.push(node->left);
                
                if(node->right)
                    q1.push(node->right);
                
            }
            
            result.push_back(temp);
            
            
        }
        
        return result;
        
    }
};
