class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> st;
        int n = nums.size();
        int ret = n - 1;
        vector<int> dp(n);
        dp[n - 1] = 0;
        st.push_back(n - 1);
        int top = 1;
        
        for (int i = n - 2; i >= 0; i--) {
            int limit = min(n - 1, i + nums[i]);
            int l = 0;
            int r = top - 1;
            
            int rs = n + 2;
            
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (st[mid] <= limit) {
                    //cout << "add mid => " << mid << "\n";
                    rs = dp[st[mid]];
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            dp[i] = rs + 1;
            while (top > 0 && dp[st[top - 1]] >= dp[i]) {
                st.pop_back();
                top--;
            }
                
            top++;
            st.push_back(i);
            
            ret = min(ret, dp[i] + i);
            //cout << "dp[ " << i << " ] = " <<  dp[i] << "\n";
        }
        
        return ret;
    }
};

