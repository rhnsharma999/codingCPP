#include <bits/stdc++.h>
using namespace std;




int solve(int n, int k){
   // n == 0 || n == 1 return n;
   // k == 1 return n;
   int dp[n + 1][k + 1];
   dp[0][0] = 0;
   
   
   for(int i = 1; i <= n; i++) dp[i][1] = 1;
   for(int i = 1; i <= k; i++){
       dp[0][i] = 0;
       dp[1][i] = 1;
   }
   
   for(int i = 1; i <= n;i++){
       for(int j = 1; j <= k;j++){
           if(j == 1) dp[i][j] = i;
           else if(i == 0 || i == 1) dp[i][j] = i;
           else{
               int ans = INT_MAX;
               for(int x = 1; x <= i; x++){
                   ans = min(ans, 1 + max(dp[x - 1][j - 1], dp[i - x][j]));
               }
               dp[i][j] = ans;
           }
       }
   }
   return dp[n][k];
}

    
int main() {
    int t;
    cin >>t;
    while(t--){
        int n,k;
        cin >>k >> n;
        //cout <<n <<" " <<k <<endl;
        cout <<solve(n,k) <<endl;
    }
	//code
	return 0;
}