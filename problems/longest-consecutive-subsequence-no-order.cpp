#include <iostream>
#include <unordered_map>


// https://www.geeksforgeeks.org/longest-consecutive-subsequence/
using namespace std;

int main() {
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        int arr[n];
        unordered_map<int,int> s;
        for(int i = 0; i < n;i++){
            cin >>arr[i];
            s[arr[i]] = 1;
        }
        int ans = INT_MIN;
        for(int i = 0; i < n;i++){
            if(s.find(arr[i] - 1) == s.end()){
                int j = arr[i];
                while(s.find(j) != s.end()){
                    j++;
                    ans = max(ans, j - arr[i]);
                }
            }
        }
        cout <<ans <<endl;
    }
	//code
	return 0;
}