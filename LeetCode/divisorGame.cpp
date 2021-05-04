/*
https://leetcode.com/problems/divisor-game/
*/
class Solution {
public:
    bool divisorGame(int N) {
        short dp[1005];
        dp[1] = 0;
        dp[2] = 1;        
        for(int i = 3; i <= N; i++){
            dp[i] = 0;
            for(int j = 1; j*j <= i ; j++){
                /// I should divide i and I will take j if the next movement
                /// is false(0) because that means that
                /// the other player will lose.                
                if(i%j == 0 && dp[i-j] == 0){
                    dp[i] = 1;
                }
            }                
        }
        return dp[N] == 1;
    }
    
};
