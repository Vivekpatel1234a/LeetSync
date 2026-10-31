class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        q.push({0, {0, 1}});
        dist[0][1] = 0;
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int weight = it.first;
            int node = it.second.first;
            int freq = it.second.second;
            if (weight > dist[node][freq])
                continue;
            if (node == n - 1) {
                return weight;
            }
            for (auto e : adj[node]) {
                int newfreq;
                int ngbnode = e.first;
                int w = e.second;
                if (labels[node] == labels[ngbnode]) {
                    newfreq = freq + 1;
                } else {
                    newfreq = 1;
                }
                if(newfreq<=k && weight+w<dist[ngbnode][newfreq]){
                    dist[ngbnode][newfreq]=weight+w;
                    q.push({dist[ngbnode][newfreq],{ngbnode,newfreq}});
                }
            }
        }
            if (q.empty())
                return -1;
            return 0;
        }
    };