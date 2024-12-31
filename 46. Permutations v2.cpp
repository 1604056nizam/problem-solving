class Solution {
public:
    vector<vector<int>> result;

    void generatePermutations(vector<int>& nums, int currentIndex) {

        if(currentIndex == nums.size()) {
            result.push_back(nums);
            return;
        }

        for(int i = currentIndex; i < nums.size(); i++) {
            swap(nums[i], nums[currentIndex]);
            generatePermutations(nums, currentIndex + 1);
            swap(nums[i], nums[currentIndex]);
        }

    }


    vector<vector<int>> permute(vector<int>& nums) {
        generatePermutations(nums, 0);

        return result;
    }
};