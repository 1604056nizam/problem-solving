class Solution {
public:
    int rob(vector<int>& nums) {
        int sizeNums = nums.size();
        vector<int > maxTk(sizeNums, 0);

        if(sizeNums == 1) return nums[0];
        maxTk[0] = (nums[0]);
        maxTk[1] = max(nums[1],nums[0]);
        int currentMax = nums[0];
        for(int i=2; i < sizeNums; i++){
            if(maxTk[i-2] + nums[i] > maxTk[i-1]){
                maxTk[i] = (maxTk[i-2]+ nums[i]);
            }else{
                maxTk[i] = (maxTk[i-1]);
            }
        }
        return maxTk[maxTk.size()-1];        
    }
};