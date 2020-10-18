#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        
        
        int arr[n];
        for(int i = 0; i < n;i++) cin >>arr[i];
        
        if(n < 4){
            cout <<"-1\n";
            continue;
        }
        else if(n == 4){
            cout <<(arr[1] - arr[0] + arr[3] - arr[2]) <<endl;
            continue;
        }
        int a[n + 1], b[n], c[n - 1], d[n - 2];
        
        a[n] = b[n - 1] = c[n - 2] = d[n - 3] = INT_MIN;
        
        for(int i = n - 1; i >= 0;i--) a[i] = max(arr[i], a[i + 1]);
        for(int i = n - 2; i >= 0;i--) b[i] = max(a[i] - arr[i], b[i + 1]);
        for(int i = n - 3;i >= 0; i--) c[i] = max(b[i] + arr[i], c[i + 1]);
        for(int i = n - 4;i >= 0; i--) d[i] = max(c[i] - arr[i], d[i + 1]);
        
        cout <<d[0] <<endl;
    }
	//code
	return 0;
}