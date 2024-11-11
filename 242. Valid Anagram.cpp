class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        int temp;
        for(int i = 0; i < s.size(); i++) {
            temp = (s[i] - 'a');
            arr[temp] = arr[temp] + 1;
        }

        for(int i = 0 ; i < t.size(); i++) {
            temp = (t[i] - 'a');
            arr[temp] = arr[temp] - 1;
            if(arr[temp] < 0) return false;
        }

        for(int i = 0 ; i < 26; i++) {
            if(arr[i]) {
                return false;
            }
        }

        return true;
    }
};