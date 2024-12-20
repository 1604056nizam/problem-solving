
//https://www.geeksforgeeks.org/problems/subset-sums2234/1
class Solution {
  public:
  
    //recursive function(arr, subArray, sum, currentIndex)
    //base case
    //currentIndex == arr.size-> result.push_back(sum)
    
    
    //push back subArray arr[currentINdex]
    //taken recursive call-> sum + arr[currentIndex]
    //pop back
    //not taken recursive call with sum
    
    vector<int> result;
    
    void recursiveFunction(vector<int>& arr, int sum, int currentIndex) {
        if(currentIndex == arr.size()) {
            result.push_back(sum);
            return;
        }
        
        recursiveFunction(arr, sum + arr[currentIndex], currentIndex + 1);
        recursiveFunction(arr, sum, currentIndex + 1);
        return;
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        recursiveFunction(arr, 0, 0);
        
        return result;
    }
};