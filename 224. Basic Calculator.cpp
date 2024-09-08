class Solution {
public:
    int calculate(string s) {

        stack<int> keepTrack;
        int sum = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                sum = sum + num * sign;
                i--;
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                keepTrack.push(sum);
                keepTrack.push(sign);
                sum = 0;
                sign = 1;
            } else if (s[i] == ')') {
                sum = keepTrack.top() * sum;
                keepTrack.pop();
                sum += keepTrack.top();
                keepTrack.pop();
            }
        }

        return sum;
    }
};