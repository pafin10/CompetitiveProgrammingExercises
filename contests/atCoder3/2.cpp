#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>
#include <string>

#define endl "\n"
#define ll long long
#define it(i, n) for(int i = 0; i<n; i++)
using namespace std;

int main() {
    // ifstream cin("2.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s; 
    set<string> subs;  
    int ln = s.length();
    it(i, ln) {
        for (int j = 0; j <= ln; j++) {
            if (s.substr(i, j) != "")
                subs.insert(s.substr(i, j));
        }
    }
    cout<<subs.size()<<endl;
	return 0;
}