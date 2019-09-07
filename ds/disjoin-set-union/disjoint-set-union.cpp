#include <iostream>
#include <map>
#include <vector>
using namespace std;

int arr[10001];
int _size[10001];
int n;

int root(int x){ // gets the root
    int i = x;
    while(arr[i] != i) i = arr[i];
    return i;
}
int dsUnion(int a,int b){ // union operation
    int rootA = root(a);
    int rootB = root(b);

    if(_size[rootA] >= _size[rootB]){
        arr[rootB] = arr[rootA];
        _size[rootA] += _size[rootB];
    }
    else{
        arr[rootA] = arr[rootB];
        _size[rootB] += _size[rootA];
    }


    return 0;
}

void printArray(){
    for(int i = 0; i < n;i++) cout <<arr[i] <<" ";
    cout <<endl;
}

bool isConnected(int a,int b){ // union find
    if(a <0 || a >= n || b < 0 || b >= n) return false;
    return (root(a) == root(b));
}
int main(){
  
    cin >>n;
    for(int i = 0; i < n;i++){
        cin >>arr[i];
        _size[i] = 1;
    }

    int a,x,y;
    while(true){
        cout <<"Enter Operation:\n1)Enter 1 x y for Find\n2)Enter 2 x y for union\n3)Enter 3 for printArray\n";
        cin >>a;
        if(a == 3){
            printArray();
        }
        else if(a == 1){
            cin >>x >>y;
            cout <<(isConnected(x,y) ? "yes\n" :"no\n");
        } 
        else{
            cin >>x >>y;
            dsUnion(x,y);
            printArray();
        }
    }
    

    return 0;
}