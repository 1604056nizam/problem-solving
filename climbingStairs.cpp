class Solution {
public:

    int arr[50] = {0};
    int climbStairs(int n) {
        if(arr[n]) return arr[n];
        if(n==1) return arr[n] = 1;
        if(n==2) return arr[n] = 2;
        if(n==3) return arr[n] = 3;

        return arr[n]= climbStairs(n-1) + climbStairs(n-2);

        
    }
};