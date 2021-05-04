class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {        
        int n = nums.size(); 
        if(n == 0)
            return 0;
        int lis[n];
        int ans = 1;
        for(int i = 0; i < n; i++)
            lis[i] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && lis[i] < lis[j]+1){
                    lis[i] = lis[j] + 1;
                    ans =  max(ans, lis[i]);
                }
            }
        }                
        return ans;
    }
};
