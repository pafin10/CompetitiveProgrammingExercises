#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    //ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        ll a, b; cin>>a>>b;
        ll ans = 0;
        ll mini = min(a, b);
        ll maxi = max(a, b);
        
        if (a==1 || b==1) {
            ans = max(a, b);
            ans = ans * ans;
        }
        else {
            ans = (a * b) / __gcd(a, b);
            if (ans == maxi) ans = maxi * (maxi/mini);
        }

        cout<<ans<<"\n";
    }

    return 0;
}

