class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> unMap;
        int currentNum, currentStreak, longestStreak = 0;

        for (int i = 0; i < nums.size(); i++) {
            unMap[nums[i]] = true;
        }

        for (auto& i : unMap) {
            if (!unMap[i.first - 1]) {
                currentNum = i.first;
                currentStreak = 1;
                while (unMap[currentNum + 1]) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};