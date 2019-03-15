class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st;
        int n = s.size();
        vector<int> f(n + 1);
        for (int i = 0; i < n; i++) f[i] = -1;
        
        int top = 0;
        
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(') {
                st.push_back(i);
                top++;
            }
        else {
            if (top > 0) {
                f[st[top - 1]] = i;
                st.pop_back();
                top--;
            }
        }
        
        int bg = 0;
        int l = -1;
        int r = -1;
        
        int ans = 0;
        while(true) {
            while (bg < n && f[bg] == -1) bg++;
            if (bg == n) break;
            
            if (l == -1) {
                l = bg;
                r = f[bg];
                ans = max(ans, r - l + 1);
            }
            else {
                // merge
                if (r + 1 == bg) {
                    r = f[bg];
                    ans = max(ans, r - l + 1);
                }
                else {
                    l = bg;
                    r = f[bg];
                    ans = max(ans, r - l + 1);
                }
            }
            
            bg = f[bg] + 1;
        }
        
        
        return ans;
    }
};
