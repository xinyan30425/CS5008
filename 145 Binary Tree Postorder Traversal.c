/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    
    //allocate memory for the result array
    int* result =(int*) malloc (1000 * sizeof(int));
    *returnSize =0;

    void postorderHelper(struct TreeNode* node){
        if(node ==NULL){
            return;
        }
        //traverse the left subtree
        postorderHelper(node->left);

        //traverse the right subtree
        postorderHelper(node->right);

        //add current node's value into the result array
        result[(*returnSize)++] = node->val;
    }

    postorderHelper(root);
    return result;
}