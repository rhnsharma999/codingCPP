#include <bits/stdc++.h>
using namespace std;


// int solve(int arr[], int n){
//     if(n <= 0) return 0;
    
//     int ans = INT_MIN;
    
//     for(int i = 0;i < n;i++){
//         ans = max(ans, arr[i] + solve(arr, n - i - 1));
//     }
//     return ans;
// }
int solve(int arr[], int n){
    int dp[n + 1];
    dp[0] = 0;
    
    for(int i = 1; i <= n;i++){
        dp[i] = INT_MIN;
        for(int j = 0; j < i;j++){
            dp[i] = max(dp[i], arr[j] + dp[i - j - 1]);
        }
    }
    return dp[n];
}
int main() {
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        int arr[n];
        for(int i = 0; i < n;i++){
            cin >>arr[i];
        }
        cout << solve(arr, n) <<endl;
    }
	//code
	return 0;
}