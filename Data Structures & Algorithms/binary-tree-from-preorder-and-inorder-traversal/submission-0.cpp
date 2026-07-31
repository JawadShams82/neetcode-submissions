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

    TreeNode* build(vector<int>& preorder,
                    vector<int>& inorder) {

        if (preorder.empty() || inorder.empty())
            return nullptr;

        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        int mid = 0;

        while (inorder[mid] != rootVal)
            mid++;

        vector<int> leftInorder(
            inorder.begin(),
            inorder.begin() + mid
        );

        vector<int> rightInorder(
            inorder.begin() + mid + 1,
            inorder.end()
        );

        vector<int> leftPreorder(
            preorder.begin() + 1,
            preorder.begin() + 1 + leftInorder.size()
        );

        vector<int> rightPreorder(
            preorder.begin() + 1 + leftInorder.size(),
            preorder.end()
        );

        root->left = build(leftPreorder, leftInorder);
        root->right = build(rightPreorder, rightInorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        return build(preorder, inorder);
    }
};