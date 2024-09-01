#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
#include <map>
#include <set>

using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    // ERROR: wrong answer Token parameter [name=countercase] equals to "b", 
    // doesn't correspond to pattern "[a-b]{2,2}" (test case 140) ???
    // greedy, construct countercase !
    // ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, k, m; cin>>n>>k>>m;
        string s; cin>>s;
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        set<char> letters(alphabet.begin(), alphabet.begin() + k);
        string sub = ""; int last = 0; bool found = false;
        map<char, int> freq;
        for (int i = 0; i < k; i++) {
            freq[alphabet[i]] = 0;
        }
        // EDGE CASE: MORE LETTERS THAN STRING LENGTH
        if (k > m) {
            cout << "NO" << endl;
            for (int i = 0; i < m; i++) {
                letters.erase(s[i]);
            }
            cout << *letters.begin() << endl;
            continue;
        }

        for (int i = 0; i < m; i++) {
            freq[s[i]]++;
            if (letters.size() == 1) {
                auto it = letters.find(s[i]);
                if (it != letters.end()) {
                    sub += s[i];
                    last = i;
                    if (sub.size() == n) {
                        found = true;
                        break;
                    }
                    letters = set<char>(alphabet.begin(), alphabet.begin() + k);
                }
            } 
            else {
                letters.erase(s[i]);
            }
        }
        // EDGE CASE: MISSING LETTERS IN STRING
        bool cont = false;
        for (const auto& pair: freq) {
            if (pair.second == 0) {
                cont = true;
                cout << "NO" << endl;
                cout << pair.first << endl;
                break;
            }
        }
        if (cont) continue;
        
        if (found) {
            cout << "YES" << endl;
            continue;
        }
        else {
            cout << "NO" << endl;
            letters = set<char>(alphabet.begin(), alphabet.begin() + k);
            for (int i = last + 1; i < m; i++) {
                letters.erase(s[i]);
            }
            sub += *letters.begin();
            cout << sub << endl;
        }
    }
    return 0;
}