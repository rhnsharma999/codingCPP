#include <iostream>
using namespace std;

int main() {
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >>arr[i];
        
        int dp[n][n];
        
        for(int gap = 0; gap < n; gap++){
            for(int i = 0; i < n; i++){
                int j = i + gap;
                if(j >= n) break;
                
                if(i == j) dp[i][j] = arr[i];
                else if((i + 1) == j) dp[i][j] = max(arr[i], arr[j]);
                else{
                    int x = dp[i + 2][j];
                    int y = dp[i + 1][j - 1];
                    int z = dp[i][j - 2];
                    
                    dp[i][j] = max(arr[i] + min(x,y), arr[j] + min(y,z));
                }
            }
        }
        cout <<dp[0][n - 1] <<endl;
    }
	//code
	return 0;
}