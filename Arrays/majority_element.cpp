// Time Complexity: O(n^2)
// Space Complexity: O(1)
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int freq = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                freq++;
            }
        }

        if (freq > n / 2) {
            cout << "Majority element is: " << arr[i];
            return 0;
        }
    }
    cout << "No majority element found";
    return 0;
}