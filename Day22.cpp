//question - 623 leetcode- Add one Row to Tree
#include<iostream>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //at root depth
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        //traversing to level depth-1
        return traverse(root,val,depth,1);
    }
    TreeNode* traverse(TreeNode* node, int val,int depth , int currdepth){
        //base case
        if(!node){
            return NULL;
        }
        if(currdepth == depth -1){
            TreeNode* newLeft = new TreeNode(val);
            newLeft->left = node->left;
            node->left = newLeft;
            
            TreeNode* newRight = new TreeNode(val);
            newRight->right = node->right;
            node->right = newRight;
        }else{
            //Recursively traversing left and right subtree
            node->left = traverse(node->left,val,depth,currdepth+1);
            node->right = traverse(node->right, val,depth,currdepth+1);
        }
        return node;
    }
};