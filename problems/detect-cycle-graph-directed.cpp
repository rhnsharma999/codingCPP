#include <vector>
#include <iostream>
using namespace std;


bool visited[1001];
bool rec[1001];


// key here is to maintain a recursion stack. 
// If a node is encountered which is visited but also is in the recursion stack, 
// then a backward path exists indicating a cycle. 

bool dfs(int start, vector<int> adj[]){
    visited[start] = true;
    rec[start] = true;
    for(int i= 0; i < adj[start].size();i++){
        if(!visited[adj[start][i]]){
            bool ans = dfs(adj[start][i], adj);
            if(ans) return ans;
        }
        else{
            if(rec[adj[start][i]]) return true;
        }
    }
    rec[start] = false;
    return false;
}

/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool isCyclic(int V, vector<int> adj[])
{
    memset(visited, false, sizeof(visited));
    memset(rec, false, sizeof(rec));
    
    for(int i = 0; i< V;i++){
        if(!visited[i]){
            if(dfs(i, adj)) return true;
        }
    }
    return false;
}