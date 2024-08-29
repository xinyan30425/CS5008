/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//binary tree: the minimum difference will be between two adjacent nodes in the sorted order
int minDiffInBST(struct TreeNode* root){
    struct TreeNode* prev = NULL;
    int min_diff = INT_MAX;

    //helper function handels the tree traversal and updates the variable accordingly
    void minDiffInBSTHelper(struct TreeNode* node) {
        if (node == NULL) {
            return;
        }

        // In-order traversal of the BST traverse the left subtree first
        minDiffInBSTHelper(node->left);

        // If there's a previous node, update the minimum difference
        if (prev != NULL) {
            int diff = node->val - prev->val;
            if (diff < min_diff) {
                min_diff = diff;
            }
        }

        // Set the current node as the previous node for the next iteration
        prev = node;

        // Continue in-order traversal traverse the right subtree
        minDiffInBSTHelper(node->right);
    }

    minDiffInBSTHelper(root);
    return min_diff;
}
