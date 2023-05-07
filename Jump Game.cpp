class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int maximum = nums[0];
        vector<int> dp(n);
        if(n==1) return true; 

        for(int i=0; i < n-1; i++){
            if(i+nums[i] >= n-1){
                return true;
            }else{
                dp[i] = max(i+nums[i], maximum);
                if(dp[i] == 0 || i == dp[i]) return false;
                maximum = dp[i];
            }
        }
        return false;
        
    }
};