#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[])
{
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        int n, m, k; cin>>n>>m>>k;
        vector<int> a(k+1, 0);
        for (int t = 0; t < 2; ++t) {
            for (int i = 0; i < (t == 0 ? n : m); i++) {
                int j;
                cin>>j;
                if (j <= k) {
                    a[j] |= 1 << t; 
                }
            }
        }

        int c[3]{};
        if (find(a.begin() + 1, a.end(), 0) != a.end()) {
            cout<<"NO"<<endl;
            continue;
        }

        for (int i = 1; i <= k; ++i) {
                c[a[i]]++; 
        }
        (c[1] > k/2 || c[2] > k/2) ? cout<<"NO"<<endl : cout<<"YES"<<endl;
    }
	return 0;
}