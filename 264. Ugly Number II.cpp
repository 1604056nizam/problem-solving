class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums(n);
        uglyNums[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int next2 = 2, next3 = 3, next5 = 5;
        int num;

        for (int i = 1; i < n; i++) {
            num = min({next2, next3, next5});
            uglyNums[i] = num;
            if (num == next2) {
                i2++;
                next2 = uglyNums[i2] * 2;
            }
            if (num == next3) {
                i3++;
                next3 = uglyNums[i3] * 3;
            }
            if (num == next5) {
                i5++;
                next5 = uglyNums[i5] * 5;
            }
        }
        return uglyNums[n-1];
    }
};