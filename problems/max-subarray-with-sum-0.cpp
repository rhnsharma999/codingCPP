

// https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/ 
int maxLen(int a[],int n)
{
    map<int,int> s;
    int ans = INT_MIN;
    
    int sum = a[0];
    s[sum] = 0;
    if(sum == 0) ans = 1;
    for(int i = 1; i < n;i++){
        sum += a[i];
        if(sum == 0) ans = max(ans, i + 1);
        if(s.find(sum) != s.end()) ans = max(ans, i - s[sum]);
        else{
            s[sum] = i;
        }
    }
    
    return ans == INT_MIN ? 0 : ans;
}