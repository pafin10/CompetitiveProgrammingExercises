#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>
#define endl "\n"
#define ll long long

using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    //ifstream cin("1.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, k; cin>>n>>k;
        string s = ""; 
        if (k == 1) {
            int i = 0; 
            while(i<n) {
                s += 'a';
                i++;
            }
            cout<<s<<endl;
            continue;
        }
        int totLen = n*k, j = 0; 
        while (j<totLen) {
            for (int i = 0; i < k; i++) {
                s += 'a' + i;
                j++;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}