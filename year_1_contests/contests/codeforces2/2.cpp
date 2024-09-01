#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <fstream>
#include <map>

#define ll long long
using namespace std;

int main(int argc, char const *argv[])
{
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
        int n,m; cin>>n>>m;
        string s,d; cin>>s; bool pos = true;
        cin>>d; bool fine = true; set<char> rel;
        for (int i = 0; i < n -1; i++) {
            if (s[i] == s[i+1]) {
                fine = false;
                rel.insert(s[i]);
            }
        }
        for (int i = 0; i < m -1; i++) {
            if (d[i] == d[i+1]) {
                pos = false;
            }
        }
        if (fine) {cout<<"Yes"<<endl; continue;}
        if (!pos) {cout<<"No"<<endl; continue;}
        if (rel.size() == 2) {
            cout<<"No"<<endl;
            continue;
        }

        char first = d[0];
        char last = d[m-1];
        if (first == *rel.begin() || last == *rel.begin()) {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;

    }
    return 0;
}