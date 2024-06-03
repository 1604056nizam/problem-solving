class Solution {
public:
    vector<int> subResult;
    vector<int> getRow(int rowIndex) {
        rowIndex = rowIndex+1;
        int arr[rowIndex][rowIndex];
        for (int i = 0; i < rowIndex; i++) {
            for (int j = 0; j < rowIndex; j++) {
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
            if(i == rowIndex-1) return subResult;
            subResult.clear();
        }
        return subResult;
    }
};