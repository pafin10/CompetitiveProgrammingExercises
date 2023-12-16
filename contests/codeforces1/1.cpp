#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        string s; cin>>s; int cnt = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0' && s[i-1] == '0') continue;
            else if (s[i] == '0') cnt+= 10 - (s[i-1] - '0');
            else if (s[i-1] == '0') cnt+= 10 - (s[i] - '0');
            else cnt+= abs((s[i] - '0') - (s[i-1] - '0'));
        }
        int add = s[0] - '0' -1;
        if (add < 0) add = 9;
        cout<<cnt+4+add<<endl;
    }

    return 0;
}


