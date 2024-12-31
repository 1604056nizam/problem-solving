class Solution {
public:

    //sort the nums
    //recursive Function(arr, subResult, currentIndex)
    // loop throught the reuslt
    //if not equal to currentIndex and arr[i] == arr[i - 1] continue
    //push the number into the subresult
    // call the recursive (taken)
    // pop out 
    // call the recursive (not taken)

    vector<vector<int>> result;

    void subsetsWithoutDuplicates(vector<int>& nums, vector<int>& subResult, int currentIndex) {
        
        result.push_back(subResult);
        
        for(int i = currentIndex; i < nums.size(); i++) {
            if (i != currentIndex && nums[i] == nums [i -1]) {
                continue;
            }
            subResult.push_back(nums[i]);
            subsetsWithoutDuplicates(nums, subResult, i + 1);

            subResult.pop_back();
    
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> subResult;
        subsetsWithoutDuplicates(nums, subResult, 0);

        return result;
    }
};