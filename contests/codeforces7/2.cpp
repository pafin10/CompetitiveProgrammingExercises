#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[])
{
    ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        int n; cin>>n; 
        vector<int> a(n);        
        it(i, n) cin>>a[i];
        
        string out = ""; 
        map<char, int> cnts;
        for (char letter = 'a'; letter <= 'z'; ++letter) cnts.insert(make_pair(letter, 0));
        int ln = 26;

        it(i, n) {
            for (char j = 'a'; j <= 'z'; ++j) {
                if (a[i] == cnts[j]) {
                    out += j;
                    cnts[j]++;
                    break;
                }
            }
        }

        cout<<out<<endl;
    }
	return 0;
}