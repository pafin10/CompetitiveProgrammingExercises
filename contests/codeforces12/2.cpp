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
#include <bitset>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int main(int argc, char const *argv[]) {
    //ifstream cin ("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bitset<200005> bs; 
    int t; cin>>t; 
    while(t--) {
        bs.reset();
        int n; cin>>n; 
        int score = 0;
        it(i, 0, n) {
            int j; cin >> j;
            if (bs.test(j)) 
                score++;
            bs.set(j); 
        }
        cout << score << endl;
    }
}