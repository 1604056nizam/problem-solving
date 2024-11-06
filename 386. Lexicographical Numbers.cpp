class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int current = 1;
        vector<int> result;

        for(int i = 0; i < n; i++) {
            result.push_back(current);
            if(current * 10 <= n) {
                current *= 10;
            } else {
                while(current % 10 == 9 || current + 1 > n) {
                    current = current /10;
                }
                current++;
            }
        }
        return result;
    }
};