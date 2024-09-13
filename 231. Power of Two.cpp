class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int result = log(n) / log(2);
        
        if(static_cast<double> (n) == pow(2, result)) {
            return true;
        }
        return false;
        
    }
};