
// link : https://leetcode.com/problems/knight-dialer/submissions/


#define MOD 1000000007
class Solution {
public:
    
    
    vector<vector<int>> moves{ {4, 6}, {8, 6}, {7, 9}, {8, 4}, {3, 9, 0}, {}, {1,7,0}, {2, 6}, 
                              {1, 3}, {2,4}};
    int solve(int num,int n,int memo[10001][500]){
        if(n == 0) return 0;
        if(n == 1) return moves[num].size();
    
        if(memo[n][num] != -1) return memo[n][num];
        int ans = 0;
        for(auto i : moves[num]){
            ans += solve(i, n - 1, memo); 
            ans %= MOD;
        }
        memo[n][num] = ans%MOD;
        return memo[n][num] ;
    }
    int knightDialer(int N) {
        int arr[10001][500];
        memset(arr, -1, sizeof(arr[0][0]) * 10001 * 500);
        if(N == 1) return 10;
        int ans = 0;
        for(int i = 0; i <= 9;i++){
            ans += solve(i, N - 1, arr);
            ans %= MOD;
        }
        return ans % MOD;
    }
};