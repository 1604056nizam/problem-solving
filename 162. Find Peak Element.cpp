class Solution {
public:
    int helperFunc(vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2;
        if (mid == 0 && nums[mid] > nums[mid + 1]) {
            return mid;
        }

        if (mid == nums.size() - 1 && nums[mid] > nums[mid - 1]) {
            return mid;
        }

        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
            return mid;
        }

        if(nums[mid + 1] > nums[mid]) return helperFunc(nums, mid +1 , right);

        return helperFunc(nums, left, mid-1);



    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        return helperFunc(nums, 0, nums.size()-1);
    }
};