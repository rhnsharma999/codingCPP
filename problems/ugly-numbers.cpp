#include <vector>
#include <iostream>
using namespace std;

class Precomp {
    public:
    int arr[1691];
    Precomp(){
        int i1=0,i2=0,i5=0;
        //int arr[1690];
        
        arr[0] = 1;
        for(int i = 1; i < 1690;i++){
            arr[i] = min(arr[i1] * 2, min(arr[i2] * 3, arr[i5] * 5));
            if(arr[i] == arr[i1] * 2) i1++;
            if(arr[i] == arr[i2] * 3) i2++;
            if(arr[i] == arr[i5] * 5) i5++;
        }
    }
};

class Solution {
    Precomp p;
public:
    int nthUglyNumber(int n) { 
        return p.arr[ n - 1];
    }
};