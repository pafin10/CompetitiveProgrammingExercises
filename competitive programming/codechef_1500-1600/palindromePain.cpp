#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>


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
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
const int MAX_N = 100'005;

int main(int argc, char const *argv[]) {
    //ifstream cin("palindromePain.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int x,y; cin>>x>>y; 
        int sm = x+y, firstOther = 0;
        vector<char> ans1(sm), ans2(sm);
        bool poss = 1;
        if (sm%2 == 0) {
            if (x%2 != 0 || y%2 != 0) poss = 0;
            else {
                int i = 0;
                for (; i < x/2; i++) {ans1[i] = ans1[sm-1-i] = 'a'; firstOther=i+1;}
                for (; i < sm-(x/2); i++) {ans1[i] = ans1[sm-1-i] = 'b';}
                ans2 = ans1; 
                swap(ans2[0], ans2[firstOther]);
                swap(ans2[sm-1], ans2[sm-1-firstOther]);
            }
        }
        else {
            if (x==1 || y == 1) poss = 0;
            else {
                char even = x%2==0 ? 'a' : 'b';
                char odd = even == 'a' ? 'b' : 'a';
                int i = 0, end = 'a' == even ? x/2 : y/2;
                for (; i < end; i++) {ans1[i] = ans1[sm-1-i] = even; firstOther=i+1;}
                for (; i < sm-end; i++) {ans1[i] = ans1[sm-1-i] = odd;}
                ans2 = ans1; 
                swap(ans2[0], ans2[firstOther]);
                swap(ans2[sm-1], ans2[sm-1-firstOther]);
            }
        }
        if (poss) {
            it(i,0,sm) cout<<ans1[i];
            cout<<endl; 
            it(i,0,sm) cout<<ans2[i];
            cout<<endl; 
        }
        else cout<<-1<<endl; 
    }
}