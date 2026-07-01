#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSame(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        // frequency of s1
        for (char c : s1)
            freq1[c - 'a']++;

        int window = s1.length();

        // first window
        for (int i = 0; i < window; i++)
            freq2[s2[i] - 'a']++;

        if (isSame(freq1, freq2)) return true;

        // slide window
        for (int i = window; i < s2.length(); i++) {

            freq2[s2[i] - 'a']++;                 // add new char
            freq2[s2[i - window] - 'a']--;        // remove old char

            if (isSame(freq1, freq2))
                return true;
        }

        return false;
    }
};

int main() {
    Solution sol;
    cout << sol.checkInclusion("ab", "eidbaooo");
}
