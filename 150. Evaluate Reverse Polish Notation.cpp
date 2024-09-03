class Solution {
public:
    int evaluate(int first, int second, string operation) {
        if (operation == "+") 
            return first + second;
        if (operation == "-")
            return first - second;
        if (operation == "*")
            return first * second;
        if (operation == "/")
            return first / second;

        return 0;
    }

    bool isNumber(const string& s) {
        if (s.empty()) return false;
        if (s[0] == '-' && s.size() > 1) return all_of(s.begin() + 1, s.end(), ::isdigit);
        return all_of(s.begin(), s.end(), ::isdigit);
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> parsedResult;
        int result = 0, topMost, secondTopMost;
        bool firstOperationDone = false;

        for (int i = 0; i < tokens.size(); i++) {
            if (isNumber(tokens[i])) {
                parsedResult.push(stoi(tokens[i]));
                continue;
            }

            topMost = parsedResult.top();
            parsedResult.pop();
            secondTopMost = parsedResult.top();
            parsedResult.pop();

            result = evaluate(secondTopMost, topMost, tokens[i]);
            parsedResult.push(result);
        }

        return parsedResult.top();
    }
};