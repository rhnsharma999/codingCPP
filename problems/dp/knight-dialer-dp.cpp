

// link : https://leetcode.com/problems/knight-dialer/submissions/
#define MOD 1000000007
class Solution {
public:
    
    
    vector<vector<int>> moves{ {4, 6}, {8, 6}, {7, 9}, {8, 4}, {3, 9, 0}, {}, {1,7,0}, {2, 6}, 
                              {1, 3}, {2,4}};

    int knightDialer(int N) {
        int dp[N + 1][10];
        
        for(int i = 0; i <= N;i++){
            for(int j = 0; j <= 9;j++){
                if(i == 0) dp[i][j] = 0;
                else if (i == 1) dp[i][j] = 1;
                else{
                    dp[i][j] = 0;
                    for(auto move : moves[j]){
                        dp[i][j] += dp[i - 1][move];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        
       int ans = 0;
        for(int i = 0; i <= 9;i++){
            ans += dp[N][i];
            ans %= MOD;
        }
        return ans;
            
           
  
        //return 0;
    }
};