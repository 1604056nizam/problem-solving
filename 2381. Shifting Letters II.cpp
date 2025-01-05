class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diffArray(s.size(), 0);

        for(int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if(direction == 1) {
                diffArray[start] += 1;
                if(end + 1 < s.size()) {
                    diffArray[end + 1] -= 1;
                }
            } else {
                diffArray[start] -= 1;
                if(end + 1 < s.size()) {
                    diffArray[end + 1] += 1;
                }
            }
        }

        int totalShifts = 0;
    
        for(int i = 0; i< diffArray.size(); i++) {

            totalShifts += diffArray[i];
            totalShifts = (totalShifts % 26 + 26) % 26;
        

            s[i] = 'a' + (s[i] - 'a' + totalShifts) % 26;
        }

        return s;
    }
};