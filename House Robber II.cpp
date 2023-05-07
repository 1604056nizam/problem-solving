class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        int resultOne=0, resultTwo=0;
        vector<int> dp(n+5,0), arrayOne, arrayTwo;

        if(n <= 0) return 0;
        if(n ==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);



        arrayOne.push_back(nums[0]);
        for(int i=1; i < n-1; i++){
            arrayOne.push_back(nums[i]);
            arrayTwo.push_back(nums[i]);
        }
        arrayTwo.push_back(nums[n-1]);
        dp[0] = 0;
        dp[1] = arrayOne[0];

        for(int i = 2; i<= arrayOne.size(); i++){
            dp[i] = max(arrayOne[i-1]+ dp[i-2], dp[i-1]);
        }
        resultOne = dp[arrayOne.size()];
        dp[1]= arrayTwo[0];

        for(int i = 2; i< n; i++){
            dp[i] = max(arrayTwo[i-1]+ dp[i-2], dp[i-1]);
        }
        resultTwo = dp[arrayTwo.size()];
        
        return max(resultOne, resultTwo);

        
    }
};