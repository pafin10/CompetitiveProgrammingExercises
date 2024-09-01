#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>

using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n,k; cin>>n>>k; 
        string s; cin>>s;
        map<char,int> p; 

        for (char c : s) {
            if (isalpha(c)) 
                p[c]++;
        }

        int oddCount = 0;
        for (const auto& entry : p) {
            if (entry.second % 2 != 0) {
                oddCount++;
            }
        }

        if (p.size() == 1) {cout<<"YES"<<endl; continue;}
        else {
            if ((n-k)%2 ==1) {
                if (abs(k-oddCount) % 2 == 1 && oddCount <= k+1) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else {
                if (abs(k-oddCount) % 2 == 0 && oddCount<=k) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
