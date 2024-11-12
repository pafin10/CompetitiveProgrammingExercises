#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)
#define pb push_back


ll calcW(vector<ll> s, ll c) {
    // WORKS LIKE THIS BUT CODEFORCES DOESNT SUPPORT IT, OTHER OPTIONS?? BTW LL SHOULD 
    // WORK IN THEORY, FIND OUT WHY IT DOESNT. ACTUALLY IT MUST BE THE DT FOR THE CALC 
    // CAUSE THE INTERMEDIATE RESULT HAS ONE DIGIT LESS THAN IT SHOULD
    ll x1 = s.size();
    ll x2 = 0;
    ll x3 = 0;
    for (ll val: s) {
        x3 += val * val;
        x2 += (2 * val);
    }
    x3 -= c;
    __int128_t x1_128 = x1;
    __int128_t x2_128 = x2;
    __int128_t x3_128 = x3;
    __int128_t discriminant = x2_128 * x2_128 - (4LL * x1_128 * x3_128);
    __int128_t sqrt_discriminant = sqrtl(discriminant);
    __int128_t w = (-x2_128 + sqrt_discriminant) / (2 * x1_128);
    w /= 2;
    return static_cast<ll>(w);
}


int main(int argc, char const *argv[]) {
    ll tst = -635472106078802616;
    cout<<tst*40<<endl;

     ifstream cin("cardboardForPictures.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    

    int t; cin>>t; 
    while(t--) {
        ll n, c; cin>>n>>c; 
        vector<ll> sizes(n);
        it(i, n) cin>>sizes[i];
        ll ans = calcW(sizes, c);
        cout<<ans<<endl; 
    }

    return 0;
}
