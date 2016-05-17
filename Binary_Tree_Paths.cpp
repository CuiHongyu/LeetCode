/* 问题：
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void getDfsPaths(vector<string>& result, TreeNode* node, string strpath) {
        if(!node->left && !node->right){
            result.push_back(strpath);
            return ;
        }
        if(node->left)
            getDfsPaths(result, node->left, strpath+"->"+to_string(node->left->val));
        if(node->right)
            getDfsPaths(result, node->right, strpath+"->"+to_string(node->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(!root) 
            return ret;
        
        getDfsPaths(ret, root, to_string(root->val));
        return ret;
    }
};
