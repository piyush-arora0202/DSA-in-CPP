#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Problem: Valid Palindrome
// Approach: Two Pointers
// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    if (sol.isPalindrome(s))
        cout << "It is a palindrome";
    else
        cout << "It is NOT a palindrome";

    return 0;
}