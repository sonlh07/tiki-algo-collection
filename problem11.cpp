class Solution {
    
    class Manachar {
    int n;
    int[] d; //Radius of odd palindromes
    int[] e; //Radius of even palindromes
    int build(String s) {
        n = s.length();
        d = new int[n]; 
        e = new int[n];
        
        int res = 0;
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            int k = (i > r) ? 1 : Math.min(d[l + r - i], r - i) + 1;
            while (i - k >= 0 && i + k < n && s.charAt(i - k) == s.charAt(i + k)) k++;
            d[i] = --k;
            res = Math.max(res, k + k + 1);
            if (r < i + k) {
                l = i - k;
                r = i + k;
            }
        }
        l = 0; r = -1;
        for (int i = 0; i < n; ++i) {
            int k = (i > r) ? 1 : Math.min(e[l + r - i + 1], r - i + 1) + 1;
            while (i - k >= 0 && i + k - 1 < n && s.charAt(i - k) == s.charAt(i + k - 1)) k++;
            e[i] = --k;
            res = Math.max(res, k + k);
            if (r < i + k - 1) {
                l = i - k;
                r = i + k - 1;
            }
        }
        return res;
    }
}
    
    
    
    public String longestPalindrome(String s) {
        if (s.length() == 0)
            return "";
        Manachar mnc = new Manachar();
        int mxLen = mnc.build(s);
        
        // odd
        for (int i = 0; i < mnc.n; i++) {
            if ( mnc.d[i] * 2 + 1 == mxLen ) {
                int bg = i - mnc.d[i];
                return s.substring(bg, bg + mxLen);
            } 
        }
        // even
        for (int i = 0; i < mnc.n; i++) {

            if (mnc.e[i] * 2 == mxLen) {
                int bg = i - mnc.e[i];
                return s.substring(bg, bg + mxLen);
            }
        }
        return "";
    }
}
