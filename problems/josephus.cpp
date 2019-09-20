/*
Let me explained it in another way:

There are n people in a circle, and people counts from 1 to k, and the person who count k will be eliminated. And we keep this process until there is only 1 person left in the circle.

Let's first number position of these n people: 0, 1, 2, ..., n-1. You notice that we change number from [1,2...n] to [0,1,...n-1], this is because of module operation. Likewise, people will now count from 0 to k-1, and the person who count k-1 will be eliminated.

The first person to be eliminated is in position (k-1)%n. After the first person has been eliminated, the circle now has only n-1 people left. One key discovery is that the last person who is finally eliminated(we call him lucky guy) is the same one to be eliminated in n-1 people circle!

Now we begin eliminate the second person:

Since (k-1)%n is the position that the first person got eliminated, then k%n must be the 0-th position for this round.

So we can number accordingly in the following table:

Position in first round ----------Position in second round
k%n ----------------------------- 0
k%n+1 -------------------------- 1
k%n+2 -------------------------- 2

....

Let's assume the lucky guy in the first round in position: f(n, k).
Then the same lucky guy in the second round in position: f(n-1, k)

So, based on the table, we know the lucky guy in second round who is in position f(n-1, k), must be in position k%n+f(n-1,k) in the first round.

Position in first round ----------Position in second round
k%n ----------------------------- 0
k%n+1 -------------------------- 1
k%n+2 -------------------------- 2
...

k%n+f(n-1,k) ------------------- f(n-1,k)

So, we know f(n,k) = k%n + f(n-1,k), to avoid over the range, we make it f(n,k) = (k%n + f(n-1,k)) % n = (k + f(n-1,k)) %n

Based on this equation, we can write recursion approach and dynamic programming approach:
*/

#include <iostream>
using namespace std;
// Josephus Problem
 
int helper(int n,int k) {
	if(n==1)
		return 0;
	return (k + helper(n-1, k)) % n;
}
 
int josephusRecursion(int n, int k) {
	return helper(n, k) + 1;
}
 
int josephusIteration(int n, int k) {
	int result = 0;		// when n = 1
    for(int i = 2; i <= n; i++) 
    {  
        result = (result + k) % i;  
    }
    return result+1;  
}
 
int main() {
	int n,k;
	cin>>n>>k;
	cout<<"Josephus result : "<<josephusRecursion(n,k)<<endl;
	cout<<"Josephus result : "<<josephusIteration(n,k)<<endl;
	return 0;
}