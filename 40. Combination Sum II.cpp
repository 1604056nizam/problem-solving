class Solution {
public:
    //base cases target == 0 -> add
    //target < 0  || currentIndex > arr.size() return;
    //loop from currentIndex + 1 to arr.size()
    //if( i > currentIndex && arr[i] == arr[i -1]) comtinue
    //jodi target > 0 break
    //pick one, recursive call
    //pop out

    set<vector<int>> resultSet;
    void combinationSum(int currentIndex, vector<int>& candidates, int target, vector<int>& subResult) {

        if(target == 0) {
            resultSet.insert(subResult);
            return;
        }

        for(int i = currentIndex; i < candidates.size(); i++) {
            if(i != currentIndex && candidates[i] == candidates[i -1]) continue;

            if(candidates[i] > target) break;

            subResult.push_back(candidates[i]);
            combinationSum(i + 1, candidates, target - candidates[i], subResult);

            subResult.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>subResult;
        sort(candidates.begin(), candidates.end());

        combinationSum(0, candidates, target, subResult);

        vector<vector<int>> result;

        for(auto& vec: resultSet) {
            result.push_back(vec);
        }

        return result;
    }
};