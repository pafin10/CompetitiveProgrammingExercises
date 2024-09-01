#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <fstream>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main()
{

    //ifstream cin("1.txt");

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin>>s;
    string ans = "Yes";
    bool start = false, mid = false; 
    int n = s.length();
    if (s[0] != '<' || s[n-1] != '>') ans = "No";
    else {
        for (int i = 1; i < n-1; i++) {
            if (s[i] != '=') {
                ans = "No";
                break;
            }
        }
    }
    cout<<ans<<endl;

	return 0;
}

