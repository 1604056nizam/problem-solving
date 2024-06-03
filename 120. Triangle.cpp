class Solution {
public:
    vector<vector<int>> result;

    int minimize(vector<vector<int>>& triangle, int row, int column) {

        if (row == triangle.size() - 1)
            return triangle[row][column];

        if (result[row][column] != INT_MAX)
            return result[row][column];

        int left = minimize(triangle, row + 1, column);
        int right = minimize(triangle, row + 1, column + 1);

        result[row][column] = triangle[row][column] + min(left, right);

        return result[row][column];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        result = vector<vector<int>>(triangle.size(), vector<int>(triangle.size(), INT_MAX));
        return minimize(triangle, 0, 0);
    }
};