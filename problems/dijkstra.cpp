// used for this : https://leetcode.com/problems/network-delay-time/submissions/

#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)
class Comparator {
    public:
    bool operator()(pair<int,int> &a, pair<int,int> &b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    
    int solve(vector<pi> adj[101], int n,int k){
        vector<int> dis(n + 1, INT_MAX);
        priority_queue<pi, vector<pi>, Comparator> s;
        
        vector<bool> visited(n + 1, false);
        
        dis[k] = 0;
        s.push(mp(k, 0));
        
        while(!s.empty()){
            auto top = s.top();
            s.pop();
            
            int node = top.first;
            
            if(visited[node]) continue;
            visited[node] = true;
            
            for(auto neighbour : adj[node]){
                 
                auto node_id = neighbour.first;
                auto w = neighbour.second;
              
                if(dis[node_id] > dis[node] + w) 
                {
                    dis[node_id] = dis[node] + w;
                    s.push(mp(node_id, dis[node] + w));
                }
            }
            
        }
        int chota = INT_MIN;
        for(int i = 1; i <= n;i++) chota = max(chota, dis[i]);
        
        return chota == INT_MAX ? -1 : chota;
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<pi> adj[101];
        for(auto i : times){
            adj[i[0]].push_back(mp(i[1], i[2]));
        }
   
        return solve(adj, N, K);
    }
};