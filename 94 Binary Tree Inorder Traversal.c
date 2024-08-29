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
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    //allocate memory to the result array
    int* result =(int*) malloc (1000 *sizeof(int));
    *returnSize =0;

    void inorderHelper(struct TreeNode* node){
        if (node == NULL){
            return;
        }

        //traverse the left subtree
        inorderHelper(node->left);

        //process the current node
        result[(*returnSize)++] = node-> val;

        //traverse the right subtree
        inorderHelper(node->right);
    }

    inorderHelper(root);
    return result;

}