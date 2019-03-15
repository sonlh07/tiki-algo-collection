class Solution {
public:
    int lmax[20002];
    int lmin[20002];
    int cnt[20002];
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int n = A.size();
        int j = 0;
        int cur = 1;
        cnt[A[0]] = 1;
        memset(lmin, -1, sizeof(lmin));
        memset(lmax, -1, sizeof(lmax));
        // min
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                int val = A[i - 1];
                cnt[val]--;
                if (cnt[val] == 0)
                    cur--;
            }
            while (cur < K && j + 1 < n) {
                int val = A[j + 1];
                cnt[val]++;
                if (cnt[val] == 1) cur++;
                j++;
            }
            if (cur < K) break;
            lmin[i] = j;
        }
        // max
        memset(cnt, 0, sizeof(cnt));
        cnt[A[0]] = 1;
        cur = 1;
        j = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                int val = A[i - 1];
                cnt[val]--;
                if (cnt[val] == 0)
                    cur--;
            }
            while (cur <= K && j + 1 < n) {
                int val = A[j + 1];
                cnt[val]++;
                if (cnt[val] == 1) cur++;
                j++;
                if (cur > K) {
                    j--;
                    cnt[val]--;
                    cur--;
                    break;
                }
            }
            if (cur < K) break;
            lmax[i] = j;
        }
        int ret = 0;
        for (int i = 0; i < n; i++)
            if (lmin[i] != -1 && lmax[i] != -1) {
                ret += (lmax[i] - lmin[i] + 1);
                //cout << "i = " << i <<": min = " << lmin[i] << " max = " << lmax[i] << "\n";
            }
        return ret;
    }
};
