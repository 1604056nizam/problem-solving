class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int lastSign = 1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                num *= lastSign;
                st.push(num);
            } else if (s[i] == '+')
                lastSign = 1;
            else if (s[i] == '-')
                lastSign = -1;
            else if (s[i] == '*') {
                int num = 0;
                i += 1;
                lastSign = 1;
                while (i < s.size() && !(s[i] >= '0' && s[i] <= '9')) {
                    if (s[i] == '-') {
                        lastSign = -1;
                    }
                    i++;
                }
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                num *= lastSign;
                int nextItem = st.top() * num;
                st.pop();
                st.push(nextItem);
            } else if (s[i] == '/') {
                int num = 0;
                i += 1;
                lastSign = 1;
                while (i < s.size() && !(s[i] >= '0' && s[i] <= '9')) {
                    if (s[i] == '-') {
                        lastSign = -1;
                    }
                    i++;
                }
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                num *= lastSign;
                int nextItem = st.top() / num;
                st.pop();
                st.push(nextItem);
            }
        }
        if (st.empty())
            return 0;

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};