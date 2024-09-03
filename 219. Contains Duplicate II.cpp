class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> keepIndex;

        for(int i = 0; i< nums.size(); i++) {

            if(keepIndex[nums[i]]) {
                if(abs(keepIndex[nums[i]] - i - 1) <= k) {
                    return true;
                }
            }
            keepIndex[nums[i]] = i + 1;
        }

        return false;


    }
};