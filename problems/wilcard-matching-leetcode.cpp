
// https://leetcode.com/submissions/detail/259554757/
class Solution {
public:
    
    bool isMatch(string s, string p) {
         bool dp[p.size() + 1][s.size() + 1];
        
        dp[0][0] = true;
        
//         for(int i = 1;i <= s.size();i++) dp[0][i] = false;
//         for(int i = 1;i <= p.size();i++) {
//             if(p[i - 1] == '*') dp[i][0] = dp[i - 1][0];
//             else dp[i][0] = false;
            
//         }
        for(int i = 0; i <= p.size();i++){
            for(int j = 0; j <= s.size();j++){
                if(i == 0 && j == 0) dp[i][j] = true;
                else if(i == 0){
                    dp[i][j] = false;
                }
                else if(j == 0){
                    if(p[i - 1] == '*') dp[i][j] = dp[i - 1][j];
                    else dp[i][j] = false;
                }
                else if(s[j - 1] == p[i - 1]) dp[i][j] = dp[i - 1][j - 1];
                else{
                    if(p[i - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                    else if(p[i - 1] == '*') dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                    else dp[i][j] = false;
                }
            }
        }
        
        return dp[p.size()][s.size()];
        
    }
};