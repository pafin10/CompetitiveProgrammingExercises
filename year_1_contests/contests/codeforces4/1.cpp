#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    ifstream cin("1.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, k; cin>>n>>k;
        vector<ll> a(n);
        ll prod = 1;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
            prod *= a[i];
        }
        if (2023%prod != 0) {
            cout<<"NO"<<endl;
            continue;
        }
        else {
            int missing = 2023/prod;
            if (k == 1) {
                cout<<"YES"<<endl;
                cout<<missing<<endl;
                continue;
            }
            else {
                cout<<"YES"<<endl;
                cout<<missing<<" ";
                for (int i = 0; i < k-1; i++) {
                    cout<<1<<" ";
                }
                cout<<endl;
            }
        }

    }

    return 0;
}

