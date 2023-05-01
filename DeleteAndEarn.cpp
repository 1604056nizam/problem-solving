class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> hashTable(10001);
        int maxVal = 0;
        for(int i=0; i< nums.size(); i++){
            hashTable[nums[i]] += nums[i];
            if(nums[i] >= maxVal) maxVal= i;
        }
        int dp;
        int prev1=0, prev2=0;
        for(int it: hashTable){
            dp = max(prev1, prev2+it);
            prev2= prev1;
            prev1 = dp;
        }
        return prev1;


    }
};