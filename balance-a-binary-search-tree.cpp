//balance-a-binary-search-tree

/*Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.*/

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
    vector<TreeNode*> inorder;
    void findInorder(TreeNode* root){
        if(root == NULL){
            return ;
        }
        findInorder(root->left);
        inorder.push_back(root);
        findInorder(root->right);
    }

    TreeNode* buildTree(int start,int end) {
        if(start>end){
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode* root = inorder[mid];
        root->left = buildTree(start,mid-1);
        root->right = buildTree(mid+1,end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        findInorder(root);
        int n = inorder.size();
        root = buildTree(0,n-1);
        return root;
    }
};
