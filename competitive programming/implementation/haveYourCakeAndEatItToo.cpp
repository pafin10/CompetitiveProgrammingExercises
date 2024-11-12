#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>


using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define itb(i, start, n) for (int i = start; i >= n; --i)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "
//#define int long long
const int MAX_N = 100'005;

int32_t main() {
    ifstream cin("haveYourCakeAndEatItToo.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n; cin>>n; 
        vi a(n), b(n), c(n);
        vi prefA(n), prefB(n), prefC(n);
        int tot = 0;

        for (int i = 0; i < n; i++) {
            cin>>a[i];
            tot += a[i];
            if (i) prefA[i] = prefA[i-1] + a[i];
            else prefA[i] = a[i];
        }
        for (int i = 0; i < n; i++) {
            cin>>b[i];
            if (i) prefB[i] = prefB[i-1] + b[i];
            else prefB[i] = b[i];
        }
        for (int i = 0; i < n; i++) {
            cin>>c[i];
            if (i) prefC[i] = prefC[i-1] + c[i];
            else prefC[i] = c[i];
        }

        // for each permutation of arrays: 
        // use prefix sums to determine when threshold is reached, then go to next array

        string perm = "abc"; 
        bool pos = false; 
        int l1 = -1, r1 = -1, l2 = -1, r2 = -1, l3 = -1, r3 = -1;
        do {
            l1 = -1, r1 = -1, l2 = -1, r2 = -1, l3 = -1, r3 = -1;
            vi *first, *second, *third;

            // Assign vectors based on the current permutation
            if (perm[0] == 'a') first = &prefA;
            else if (perm[0] == 'b') first = &prefB;
            else first = &prefC;

            if (perm[1] == 'a') second = &prefA;
            else if (perm[1] == 'b') second = &prefB;
            else second = &prefC;

            if (perm[2] == 'a') third = &prefA;
            else if (perm[2] == 'b') third = &prefB;
            else third = &prefC;

            int currSum = 0;
            for (int i = 0; i < n; i++) {
                if (l1 == -1 && (*first)[i] >= (tot / 3)) {
                    l1 = 0; 
                    r1 = i;
                }
                else if (l1 != - 1 && (*second)[i] - (*second)[r1] >= (tot / 3)) {
                    l2 = r1 + 1;
                    r2 = i;  
                }
                else if (l2 != -1 && (*third)[i] - (*third)[r2] >= (tot / 3)) {
                    l3 = r2 + 1;
                    r3 = i;
                }
            }
            if (r3 != -1) {
                pos = true;
                break; 
            }
        }
        while (next_permutation(perm.begin(), perm.end()));

        if (pos) {
            cout<<l1<<r1<<l2<<r2<<l3<<n-1<<endl;
        }
        else {
            cout<<-1<<endl; 
        }


    }
}