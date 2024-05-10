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

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back


int main(int argc, char const *argv[]) {

    //ifstream cin("ternaryString.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin>>t; 
    while(t--) {
        string s; cin>>s; 
        int ptr1 = -1, ptr2 = -1, ptr3 = -1;
        int n = s.length();
        vector<int> ans;
        it(i,0,n) {
            if (s[i] == '1') ptr1 = i;
            else if (s[i] == '2') ptr2 = i; 
            else ptr3= i;
            if (!(ptr1 == -1 || ptr2 == -1 || ptr3 == -1)) {
                ans.pb((max(max(ptr1, ptr2), ptr3)) - min(min(ptr1, ptr2), ptr3) + 1);
            }
        }
        if (ptr3 == -1 || ptr2 == -1 || ptr1 == -1) {cout<<0<<endl; continue;}
        sort(ans.begin(), ans.end());
        cout<<ans[0]<<endl; 
    }
    return 0;
}
