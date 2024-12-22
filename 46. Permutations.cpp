class Solution {
public:
    vector<vector<int>> result;

    void generatePermuteRecursively(vector<int>& nums,int currentIndex, vector<bool>& marker, vector<int>& subResult) {
        if(subResult.size() == nums.size()) {
            result.push_back(subResult);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!marker[i]) {
                subResult.push_back(nums[i]);
                marker[i] = true;
                generatePermuteRecursively(nums, i, marker, subResult);
                subResult.pop_back();
                marker[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> marker(nums.size(), false);
        vector<int>subResult;
        generatePermuteRecursively(nums, 0, marker, subResult);

        return result;
    }
};