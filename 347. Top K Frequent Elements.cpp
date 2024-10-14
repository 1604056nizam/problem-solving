class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        int highestFreq = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(!frequency[nums[i]]) {
                frequency[nums[i]] = 0;
            }
            frequency[nums[i]]++;
            highestFreq = max(highestFreq, frequency[nums[i]]);
        }

        vector<vector<int>> bucket(highestFreq);
        vector<int> result;

        for(auto& num: frequency) {
            bucket[num.second - 1].push_back(num.first);
        }

        for(int i = bucket.size() - 1; i >= 0 && k > 0; i--) {
            if(bucket[i].size()) {
                for(int j = 0; j < bucket[i].size(); j++) {
                    k--;
                    result.push_back(bucket[i][j]);
                }
            }
        }

        return result;


    }
};