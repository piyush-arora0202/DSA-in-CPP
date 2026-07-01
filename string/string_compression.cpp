// // String Compression (LeetCode 443)
// // Pattern: Two pointers (read & write) + group counting
// // Time: O(n)
// // Space: O(1)

// #include <vector>
// #include <string>
// using namespace std;

// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         int n = chars.size();
//         int idx = 0;

//         for (int i = 0; i < n; i++) {
//             char ch = chars[i];
//             int count = 0;   // fixed spelling

//             // count same characters
//             while (i < n && chars[i] == ch) {
//                 count++;
//                 i++;
//             }

//             // store character
//             chars[idx++] = ch;

//             // store frequency if > 1
//             if (count > 1) {
//                 string str = to_string(count);

//                 for (char dig : str) {
//                     chars[idx++] = dig;   // removed dig++
//                 }
//             }

//             i--;   // adjust because for loop will increment
//         }

//         chars.resize(idx);
//         return idx;
//     }
// };
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            chars[idx++] = ch;

            if (count > 1) {
                string str = to_string(count);
                for (char dig : str) {
                    chars[idx++] = dig;
                }
            }

            i--;
        }

        chars.resize(idx);
        return idx;
    }
};

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    vector<char> chars(input.begin(), input.end());

    Solution obj;
    int newLength = obj.compress(chars);

    cout << "Compressed Output: ";
    for (char c : chars) {
        cout << c;
    }

    cout << "\nNew Length: " << newLength;

    return 0;
}