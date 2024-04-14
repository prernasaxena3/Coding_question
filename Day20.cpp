// 404 - leetcode SUM OF LEFT LEAVES
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
#include <iostream>
using namespace std;
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
    int sum = 0;
    if (root->left && !root->left->left && !root->left->right) {
      // Check if left child is a leaf node
      sum += root->left->val;
    }
    sum += sumOfLeftLeaves(root->left);  // Recursively traverse left subtree
    sum += sumOfLeftLeaves(root->right); // Recursively traverse right subtree
    return sum;
    }
};