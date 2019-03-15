class Solution {
public:
    map<long long, int> M;
    vector<long long> c;
    int T[100002];
    
    void update(int x, int pos) {
        while (x < 100002) {
            T[x] = max(T[x], pos);
            x = x + (x & (x ^ (x - 1)));
        }
    }
    
    int get(int x) {
        int ret = -1;
        while (x > 0) {
            ret = max(ret, T[x]);
            x = x - (x & (x ^ (x - 1)));
        }
        return ret;
    }
    
    int shortestSubarray(vector<int>& A, int K) {
        memset(T, -1, sizeof(T));
        int n = A.size();
        vector<long long> sum(n + 1);
        sum[0] = 0;
        
        c.push_back(0);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + A[i];
            c.push_back(sum[i + 1]);
            c.push_back(sum[i + 1] - K);
        }
        
        sort(c.begin(), c.end());
        int cnt = 1;
        for (int i = 0; i < c.size(); i++) {
            M[c[i]] = cnt;
            if (i + 1 < c.size() && c[i] < c[i + 1]) cnt++;
        }
        
        update(M[0], 0);
        
        int inf = 1000000001;
        int ret = inf;
        
        for (int i = 1; i <= n; i++) {
            int query = M[sum[i] - K];
            int upd = M[sum[i]];
            
            int pos = get(query);
            if (pos != -1) {
                ret = min(ret, i - pos);
            }
            
            update(upd, i);
        }
        
        if (ret == inf) {
            return -1;
        }        
        return ret;
    }
};
