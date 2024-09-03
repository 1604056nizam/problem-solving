class Solution {
public:
    void helperFunction(int start, int k, int n, vector<vector<int>>& result, vector<int>& subResult) {
        if(subResult.size() == k && n == 0) {
            result.push_back(subResult);
        }

        for(int i = start; i<= 9; i++) {
            subResult.push_back(i);
            helperFunction(i+1, k, n - i, result, subResult);
            subResult.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> result;
        vector<int> subResult;

        helperFunction(1, k, n, result, subResult);
        return result;
        
    }
};