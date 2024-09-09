class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size() == 0) {
            return result;
        }
            
        string subResult;
        int lastNum;
        int tempIndex;

        for (int i = 0; i < nums.size(); i++) {
            subResult = to_string(nums[i]);
            lastNum = nums[i];

            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] - 1 == lastNum) {
                    tempIndex = j;
                    lastNum = nums[j];
                    continue;
                }
                break;
            }
            if (lastNum == nums[i]) {
                result.push_back(subResult);
            } else {
                subResult += "->" + to_string(lastNum);
                result.push_back(subResult);
                i = tempIndex;
            }
        }
        return result;
    }
};