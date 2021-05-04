//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution {
public:
    int ki;
    void findK(int* ans, int *cur, TreeNode* root){
        if(root == nullptr)
            return;
        findK(ans, cur, root->left);
        *cur = (*cur)+1;
        if((*cur) == ki){
            (*ans) = root->val;
            return;
        }
        findK(ans, cur, root->right);        
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int cur = 0;
        ki = k;
        findK(&ans, &cur, root);
        return ans;
    }
};
