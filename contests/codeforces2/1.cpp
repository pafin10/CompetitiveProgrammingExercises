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
    //ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
        vector<pair<int,int>> v;
        int n; cin>>n; 
        vector<int> a(n); 
        int arr[2];
        set<int> s;
        map<int,int> m;
        for (int i = 0; i < n; ++i) {
            cin>>a[i]; s.insert(a[i]);
        }
        for(int i: a) {
            m[i]++;
        }
        vector<int> b;
        for (auto& pair:m) {
            b.push_back(pair.second);
        }
        int diff;
        if (b.size() == 2) diff = abs(b[0] - b[1]);
        else diff = 0;

        if (s.size() > 2 || (diff > 1)) cout<<"No"<<endl; 
        else cout<<"Yes"<<endl;
    }
    return 0;
}