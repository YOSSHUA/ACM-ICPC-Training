/*
https://leetcode.com/problems/min-cost-climbing-stairs/
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return f(dp, cost, cost.size(),0);
    }
    int f(vector<int>& dp,vector<int>& cost, int n, int index){
        if(index >= n)
            return 0;
        if(dp[index] == -1){
            if(index + 1 < n){
                dp[index]= min(cost[index]+f(dp,cost,n, index+1), 
                               cost[index+1]+f(dp,cost,n, index+2));
            }else{
                dp[index]= 0;
                
            }
        }
        return dp[index];
    }
};
