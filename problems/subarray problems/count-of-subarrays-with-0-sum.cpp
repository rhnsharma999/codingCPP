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
        
        if(n == 1 && arr[0] == 0) {
            cout <<"1" <<endl;
            continue;
        } 
        
        unordered_map<int,vector<int>> s;
        
        int sum = 0;
        sum = arr[0];
        s[sum].push_back(0);
        
        int count = sum == 0 ? 1 : 0;
        for(int i = 1; i < n;i++){
            sum += arr[i];
            if(sum == 0) count++;
            if(s.find(sum) != s.end()){
                count += s[sum].size();
                s[sum].push_back(i);
            }
            else{
                s[sum].push_back(i);
            }
            
        }
        
        cout <<count <<endl;
     
        
    }
	//code
	return 0;
}