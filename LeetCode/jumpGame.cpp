//https://leetcode.com/submissions/detail/469239743/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int s = nums.size();
    if(s == 0 || s == 1)
        return true;
    int i = 0;
    int maxP = nums[0]; // 9, 11, 13
    //s = 5

    while( i <  s && maxP >= i && maxP < s){
        maxP = max( maxP, i+nums[i]); 
        i++;
    }
    
    if(maxP >= s-1)
        return true;
    else
        return false;
    }
};
