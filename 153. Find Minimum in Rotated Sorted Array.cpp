class Solution {
public:
    int minimumValue;
    int helperFunc(vector<int> & nums, int left, int right) {
        int mid = left + (right-left)/2;

        if(nums[left] <= nums[mid] && nums[mid +1] <= nums[right]) {
            return min(minimumValue, min(nums[left], nums[mid + 1]));
        }

        if(nums[left] > nums[mid]) {
            return helperFunc(nums, left, mid);
        }

        return helperFunc(nums, mid + 1 , right);
    }

    int findMin(vector<int>& nums) {
        if(nums.size() == 1 || nums[0] < nums[nums.size()-1]) return nums[0];
       
        minimumValue = nums[0];
        return helperFunc(nums, 0, nums.size()-1); 
    }
};