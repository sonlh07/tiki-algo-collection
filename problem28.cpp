#include <bits/stdc++.h>
using namespace std;

class ReconstructNumber {
    public:
    int dp[2002][12];
    
    bool can_jump(int x, int y, char cmp) {
    	if (cmp == '=') return (x == y);
        if (cmp == '<') return (x < y);
        if (cmp == '>') return (x > y);
        return x != y;
    }
    
	string smallest(string comparisons) {
        int n = comparisons.size();
        memset(dp, false, sizeof(dp));
        for (int i = 0; i <= 9; i++) {
        	dp[n][i] = true;
        }
        for (int i = n - 1; i >= 0; i--) {
        	int cmp = 0;
            if (comparisons[i] == '>') cmp = 1;
            if (comparisons[i] == '<') cmp = 2;
            if (comparisons[i] == '!') cmp = 3;
            
            for (int j = 0; j < 10; j++) {
                if (cmp == 0) {
                	dp[i][j] = dp[i + 1][j];    
                }
                
                if (cmp == 1) {
                	for (int k = j - 1; k >= 0; k--)
                        dp[i][j] |= dp[i + 1][k];
                }
                
                if (cmp == 2) {
                    for (int k = j + 1; k < 10; k++)
                        dp[i][j] |= dp[i + 1][k];
                }
                
                if (cmp == 3) {
                	for (int k = 0; k < 10; k++)
                        if (k != j)
                        	dp[i][j] |= dp[i + 1][k];
                }
            }
        }
        
        string res = "";
        for (int i = 1; i < 10; i++)
            if (dp[0][i]) {
            	res = res + char(i + '0');
            	int mask = i;
            	for (int j = 1; j <= n; j++)
                    for (int k = 0; k < 10; k++) {
                    	if (dp[j][k] && can_jump(mask, k, comparisons[j - 1])) {
                        	mask = k;
                            res = res + char(k + '0');
                            break;
                        }
                	}
            	break;
            }
        return res;
    }

}

int main() { };
