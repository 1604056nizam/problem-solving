class Solution {
public:
    int maximumGap(vector<int>& nums) {
        map<int, int> numsMap;

        for(auto num: nums) {
            numsMap[num] = num;
        }
        int maxDifference = 0 , prevValue;

        for(auto it = numsMap.begin(); it != numsMap.end(); it++) {
            if(it == numsMap.begin()) {
                prevValue = it->second;
                continue;
            }

            maxDifference = max(it->second - prevValue, maxDifference);
            prevValue = it->second;
        }
        return maxDifference;
    }
};