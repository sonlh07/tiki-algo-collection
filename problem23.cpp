class Solution {
public:
    vector<vector<int> > lab;
    map<int, int> mapping;
    
    vector<int> adj[555];
    bool visited[555];
    int des[555];
    int qu[555];
    int inf = 1000000001;
    int m;
    bool isDes[555];
    
    int bfs(int fr) {

        if (isDes[fr]) return 0;
        
        for (int i = 0; i < m; i++) {
            des[i] = inf;
            visited[i] = false;
        }
        des[fr] = 0;
        int l = 1;
        int r = 1;
        visited[fr] = true;
        qu[l] = fr;
        
        while (l <= r) {
            int u = qu[l]; l++;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (visited[v] == false) {

                    visited[v] = true;
                    des[v] = des[u] + 1;
                    
                    r++;
                    qu[r] = v;
                    
                    if (isDes[v])
                        return des[v];
                    
                }
            }
        }
        return inf;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        memset(isDes, false, sizeof(isDes));
        int cnt = 0;
        set<int> has;
        
        m = routes.size();
        for (int i = 0; i < m; i++) {
            has.clear();
            int n = routes[i].size();
            for (int j = 0; j < n; j++) {
                int station = routes[i][j];
                if (has.count(station)) continue;
                has.insert(station);
                
                if (mapping.count(station)) {
                    int id = mapping[station];
                    lab[id].push_back(i);
                } else {
                    mapping[station] = cnt++;
                    lab.push_back(vector<int>());
                    lab[cnt - 1].push_back(i);
                }
            }
        }
        
        
        for (int i = 0; i < lab.size(); i++) {
                int n = lab[i].size();
                for (int j = 0; j < n; j++)
                    for (int k = j + 1; k < n; k++) {
                        int u = lab[i][j];
                        int v = lab[i][k];
                        
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                    }
            }
        int ret = inf;
        
        if (!mapping.count(S) || !mapping.count(T))
            return -1;
        
        int ids = mapping[S];
        int idt = mapping[T];
        for (int i = 0; i < lab[idt].size(); i++) {
            isDes[lab[idt][i]] = true;
        }
        
        for (int i = 0; i < lab[ids].size(); i++) {
                int dist = bfs(lab[ids][i]);
                ret = min(ret, dist);
            }
        
        if (ret != inf) return (ret + 1);
        else
            return -1;
    }
};
