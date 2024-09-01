#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[])
{
    // TOO INEFFICIENT ALTHOUGH LOGIC SEEMS TO WORK OUT
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        int n, q; cin>>n>>q; 
        vector<ll> c(n);
        it(i, n) cin>>c[i];
        it(i, q) {
            ll l, r; cin>>l>>r; 
            l--, r--;
            vector<ll> sub(r-l+1);
            ll smC = 0, smSub = 0;
            for (int i = l; i < r; i++) {
                smC += c[i];
                if (c[i] != 1) {
                    sub[i-l] = 1;
                    smSub += 1;
                }
                else {
                    sub[i-l] = 2;
                    smSub += 2;
                }
            }
            smC += c[r];
            sub[r-l] = smC - smSub;

            if (sub[r-l] != c[r]) cout<<"YES"<<endl; 

            else {
                bool found = false, possible = true; 
                ll j = 0;
                // still possible, need to update previous elements of smSub
                if (r-l+1 == smC-1) possible = false;
                while(!found && possible) {
                    if (sub[r-l] > 1) sub[r-l]--;
                    else {
                        if (r==l) {
                            it (i, (r-l+1)) {
                                if (c[l+i] == sub[i]) {
                                    possible = false;
                                    break;
                                }
                            }
                        }
                        sub[r-l]++;
                        if (c[l+j] == 2) sub[r-l]++;
                        r--;
                        if (sub[j] > 1) sub[j]--;
                        else j++;
                        continue;
                    }
                    sub[j]++;
                    if (sub[j] != c[l+j]) {
                        cout<<"YES"<<endl; 
                        found = true; 
                    }
                    if (sub[r-l] == (smC - (r-l))) j++;
                    if (sub[r-l] == 1) r--;
                    if (r==l && j > (r-l)) possible = false;
                }
                if (!possible) cout<<"NO"<<endl; 
            }
        }
    }
	return 0;
}