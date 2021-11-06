/*
Add Binary
Easy

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
  string addBinary(string a, string b) {
    int n1 = a.length();
    int n2 = b.length();
    string res = "";
    int i = n1 - 1, j = n2 - 1;
    int c = 0;

    while (i >= 0 && j >= 0) {
      int x = a[i] - '0';
      int y = b[j] - '0';
      int sum = x ^ (y ^ c);
      c = x & y | (c & (x ^ y));
      string t = to_string(sum);
      res = t + res;
      i--;
      j--;
    }
    while (i >= 0) {
      int x = a[i] - '0';
      int sum = x ^ c;
      c = x & c;
      res = to_string(sum) + res;
      i--;
    }
    while (j >= 0) {
      int x = b[j] - '0';
      int sum = x ^ c;
      c = x & c;
      res = to_string(sum) + res;
      j--;
    }
    if (c != 0) {
      res = to_string(c) + res;
    }
    return res;
  }
};