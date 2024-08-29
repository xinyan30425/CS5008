/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int min(int a, int b){
    return a<b ? a:b;
}

int minDepth(struct TreeNode* root){
    //if tree is empty, m in depth is 0
    if (root == NULL){
        return 0;
    }

    //if current node is a leaf node, min depth is 1
    if(root ->left == NULL && root ->right == NULL){
        return 1;
    }

    if (root->left == NULL){
        return minDepth(root->right)+1;
    }

    if (root->right == NULL){
        return minDepth(root->left)+1;
    }

    //if both left and right subtrees exist
    int left_depth = minDepth(root->left);
    int right_depth = minDepth(root->right);

    return min(left_depth, right_depth) + 1;

}