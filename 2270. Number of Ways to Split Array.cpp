class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long prevSum = 0;
        int result = 0;
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        for (int i = 0; i < prefixSum.size(); i++) {
            prefixSum[i] = (prevSum + nums[i]);
            prevSum = prefixSum[i];
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (prefixSum[i] >= (prefixSum[n - 1] - prefixSum[i])) {
                result += 1;
            }
        }

        return result;
    }
};