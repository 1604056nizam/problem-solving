class Solution {
public:
    vector<vector<int>> result;
    vector<int> subResult;
    vector<vector<int>> generate(int numRows) {
        int arr[numRows][numRows];
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numRows; j++) {
                if (j == 0) {
                    arr[i][j] = 1;
                    subResult.push_back(arr[i][j]);
                    continue;
                } else if (j <= i) {
                    arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j] + arr[i - 1][j - 1]);
                    subResult.push_back(arr[i][j]);
                    continue;
                } else {
                    arr[i][j] = 0;
                }
            }
            result.push_back(subResult);
            subResult.clear();
        }
        return result;
    }
};