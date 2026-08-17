class Solution {
public:
    int ans = 0;

    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftPath = 0;
        int rightPath = 0;

        if (root->left != NULL && root->left->val == root->val)
            leftPath = left + 1;

        if (root->right != NULL && root->right->val == root->val)
            rightPath = right + 1;

        // Path passing through current node
        ans = max(ans, leftPath + rightPath);

        // Return only one direction to parent
        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};