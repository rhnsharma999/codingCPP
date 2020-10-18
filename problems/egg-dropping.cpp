#include <bits/stdc++.h>
using namespace std;


int memo[101][101];

// n is floors
// k is number of eggs

int superEggDrop(int n,int k) {
    if(n == 1 || n == 0) return n;
    if(k == 1) return n;
    
    
    if(memo[n][k] != INT_MAX) return memo[n][k];
    
   
    for(int i = 1; i <= n;i++){
        memo[n][k] = min(
                memo[n][k],
                1 + max(
                    superEggDrop(i - 1, k - 1),
                    superEggDrop(n - i , k)
                    )
            );
    }
    return memo[n][k];
}
    
int main() {
    int t;
    cin >>t;
    while(t--){
        for(int i = 0; i <= 100;i++) for(int j = 0;j <= 100;j++) memo[i][j] = INT_MAX;
        int n,k;
        cin >>k >>n;
        cout <<superEggDrop(n,k) <<endl;
    }
	//code
	return 0;
}


//////////////////////////////////// ITERATIVE  //////////////////////////////////////////////////////


#include <bits/stdc++.h>
using namespace std;


int memo[101][101];
int superEggDrop(int n,int k) {
    int dp[n + 1][k + 1];
    
    dp[0][0] = 0;
    for(int i = 1; i <= n;i++){
        dp[i][1] = i;
        dp[i][0] = 0;
    }
    for(int i = 1; i <= k;i++){
        dp[1][i] = 1;
        dp[0][i] = 0;
    }
    for(int i = 2;i <= n;i++){
        for(int j = 2;j <= k;j++){
            dp[i][j] = INT_MAX;
            for(int x = 1; x <= i;x++){
                dp[i][j] = min(
                    dp[i][j],
                    1 + max(
                        dp[x - 1][j - 1],
                        dp[i - x][j]
                        )
                    );
            }
           // cout <<dp[i][j] <<" ";
            
        }
        //cout <<endl;
    }
    
    return dp[n][k];
}
    
int main() {
    int t;
    cin >>t;
    while(t--){
        for(int i = 0; i <= 100;i++) for(int j = 0;j <= 100;j++) memo[i][j] = INT_MAX;
        int n,k;
        cin >>k >>n;
        cout <<superEggDrop(n,k) <<endl;
    }
	//code
	return 0;
}