/*
Binary Array Sorting

Given a binary array A[] of size N. The task is to arrange the array in
increasing order.

Note: The binary array contains only 0  and 1.

Example 1:

Input:
N = 5
A[] = {1,0,1,1,0}
Output: 0 0 1 1 1

Example 2:

Input:
N = 10
A[] = {1,0,1,1,1,1,1,0,0,0}
Output: 0 0 0 0 1 1 1 1 1 1

Your Task:
Complete the function SortBinaryArray() which takes given array as input and
returns the sorted array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Challenge: Try doing it in one pass.

Constraints:
1 <= N <= 106
0 <= A[i] <= 1
*/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// binArray is an array that consists only 0s and 1s
// return sorted binary array
class Solution {
public:
  vector<int> SortBinaryArray(vector<int> binArray) {
    // Your code goes here
    int c = 0;
    for (int i = 0; i < binArray.size(); i++) {
      if (binArray[i] != 1) {
        int temp = binArray[i];
        binArray[i] = binArray[c];
        binArray[c] = temp;
        c++;
      }
    }
    return binArray;
  }
};

// { Driver Code Starts.
int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> binArray(n);

    for (int i = 0; i < n; i++)
      cin >> binArray[i];
    Solution ob;
    vector<int> result = ob.SortBinaryArray(binArray);
    for (int i = 0; i < n; i++)
      cout << result[i] << " ";

    cout << endl;
  }
  return 0;
}
// } Driver Code Ends