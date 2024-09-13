class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*
        Approach DP: 
        1. initialize cache vector to -1;
        2. in each element we will store how much square lem can be contructed with this 0/1 value.
        3. If it has 0, we can't make any square with this as this could not be included anywhere.
        4. If its 1, then the minimum out of 3 position is checked. top, left and diagonal and added 1 to it. 
        5. Minimum is taken as this ensures the most possible square that can be made. 
        */

        
        vector<vector<int>> cache(matrix.size(),
                                  vector<int>(matrix[0].size(), -1));
        int maxSquareLen = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {

                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    cache[i][j] = matrix[i][j] - '0';
                } else {
                    cache[i][j] = min({cache[i - 1][j], cache[i - 1][j - 1], cache[i][j - 1]}) +  1;
                }

                maxSquareLen = max(maxSquareLen, cache[i][j]);
            }
        }

        return maxSquareLen * maxSquareLen;
    }
};