/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function*/
int maxLen(int a[],int n)
{
    int ans = 0;
    map<int,int> s;
    int sum;
    sum = a[0];
    s[sum] = 0;
    for(int i = 1; i < n; i++){
        sum += a[i];
        if(sum == 0) ans = max(ans, i + 1);
        if(s.find(sum) != s.end()){
            int j = s[sum];
            ans = max(ans, i - j);
        }
        else s[sum] = i;
    }
    return ans;
}