class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        if (nums.length < 2) return false;
        for (int i = 0; i < nums.length - 1; i++)
            if (nums[i] == 0 && nums[i + 1] == 0) return true;
        if (k < 0) k = -k;
        if (k == 0) return false;
        
        HashMap<Integer, Integer> s = new HashMap<>();
        s.put(0, 0);
        int sum = nums[0];
        int last = sum;
        
        for (int i = 1; i < nums.length; i++) {
            sum = (sum + nums[i]) % k;
            if (s.containsKey(sum)) {
                return true;
            }
            s.put(last, 0);
            last = sum;
        }
        return false;
    }
}
