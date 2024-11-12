#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back

int main(int argc, char const *argv[]) {
    // ifstream cin("binaryPath.txt"); 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(2);
        it(i, 0, 2) cin >> s[i];

        int min_down = 0, max_down = n-1;
        for (int i = n-1; i>=1; i--) {
            if (s[0][i] == '1' && s[1][i-1] == '0') {
                max_down = i-1;
            }
        }
        it(i,0,max_down+1) {
            if (s[0][i+1] == '0' && s[1][i] == '1') {
                min_down = i+1;
            }
        }
        
        it(i,0,max_down+1) cout<<s[0][i];
        it(i,max_down,n) cout<<s[1][i];
        cout<<endl; 
        cout<<max_down-min_down+1<<endl;
    }
    return 0;
}
