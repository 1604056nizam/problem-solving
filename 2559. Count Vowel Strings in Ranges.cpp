class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        char vowels[5] = {'a', 'e', 'i', 'o','u'};
        map<char, int> vowelMap;
        vector<int> result, countArray(words.size(), 0);
        int l, r, subAns = 0;
        string word;

        for(auto ch: vowels) {
            vowelMap[ch] = 1;
        }

        int prevAns = 0;
        for(int i = 0; i < words.size(); i++) {
            word = words[i];

            if(vowelMap[word[0]] && vowelMap[word[word.size() - 1]]) {
                countArray[i] = prevAns + 1;
                prevAns = countArray[i];
            } else {
                countArray[i] = prevAns;
            }

        }

        for(int i = 0; i < queries.size(); i++) {
           int l = queries[i][0];
           int r = queries[i][1];
          

           if(l - 1 >= 0) {
            result.push_back(countArray[r] - countArray[l - 1]);
           } else {
            result.push_back(countArray[r] - 0);
           }
        }

        return result;
    }
};