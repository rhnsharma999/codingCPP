#include <bits/stdc++.h>
using namespace std;


void solve(int arr[], int n,int x){
    unordered_map<int,int> s;
    s[arr[0]] = 0;
    int sum = arr[0];
    
    for(int i = 1; i < n;i++){
       // cout <<sum-x <<" " <<endl;
        sum += arr[i];
        if((sum - x) == 0){
            cout <<"1 " << i + 1 <<endl;
            return;
        }
        if(s.count(sum - x) > 0){
            cout <<s[sum - x] + 1 + 1 <<" " <<i + 1 <<endl;
            return;
        }
        else{
            s[sum] = i;
        }
    }
    cout <<"-1\n";
}

int main() {
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        int arr[n];
        int x;
        cin >>x;
        for(int i = 0; i < n;i++) cin >>arr[i];
        
        
        solve(arr, n, x);
        
        
        
    }
	//code
	return 0;
}