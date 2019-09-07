#include <vector>
#include <iostream>
using namespace std;

bool visited[10001];


// the key here is to just pass a parent to the next recursion call.
// if an already visited node is encountered which is also not a parent, then there is a cycle.
bool dfs(int start,int parent, vector<int> graph[]){
   
    visited[start] = true;
    
    for(int i = 0; i < graph[start].size();i++){
        if(!visited[graph[start][i]]){
            bool ans = dfs(graph[start][i], start, graph);
            if(ans) return true;
        }
        else{
            if(graph[start][i] != parent){
                return true;
            }
        }
    }
   
    
    return false;
}

/*This is a function problem.You only need to complete the function given below*/
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

bool isCyclic(vector<int> adj[], int V)
{

    memset(visited, false, sizeof(visited));
    for(int i = 0; i < V;i++){
        if(!visited[i]) {
            if(dfs(i, -1, adj)) return true;
        }
    }
    return false;
   
   
}