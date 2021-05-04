/**
 every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
 https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
 */
class Solution {
public:
    vector<int> sum;
    void helper(TreeNode* cur, int* pos){        
        if(cur == nullptr)
            return;
        helper(cur->left, pos);
        sum[(*pos)++] = cur->val;
        helper(cur->right, pos);
    }    
    void updateT(TreeNode* cur, int* pos){
        if(cur == nullptr)
            return;
        updateT(cur->left, pos);
        cur->val = sum[(*pos)++];
        updateT(cur->right, pos);
    }
    TreeNode* bstToGst(TreeNode* root) {
        sum.resize(105);
        fill(sum.begin(), sum.end(), 0);
        int p = 0;
        helper(root, &p);
        for(int i = 100; i>= 0; i--){
            sum[i] = sum[i+1]+sum[i];            
        }
        p = 0;
        updateT(root, &p);
        return root;
    }
    
    
};
