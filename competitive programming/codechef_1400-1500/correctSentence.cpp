#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ifstream cin("correctSentence.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    cin.ignore(); // Consume the newline character after t

    while (t--) {
        int k;
        cin >> k;
        bool chef = true;
        for (int i = 0; i < k; i++) {
            if (!chef)
                break;
            string line;
            getline(cin, line);

            istringstream iss(line);
            string s;
            while (iss >> s) {
                int len = s.length();
                char one = s[0];

                // Check the first character of the string
                if (!((('a' <= one) && (one <= 'm')) || (('N' <= one) && (one <= 'Z')))) {
                    chef = false;
                    break;
                }

                // Check the rest of the characters in the string
                for (int j = 1; j < len; j++) {
                    if (!((('a' <= one) && (one <= 'm')) && (('a' <= s[j]) && (s[j] <= 'm')) ||
                          (('N' <= one) && (one <= 'Z')) && (('N' <= s[j]) && (s[j] <= 'Z')))) {
                        chef = false;
                        break;  
                    }
                }
            }
        }
        if (chef)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
