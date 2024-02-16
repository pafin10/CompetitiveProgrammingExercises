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
    //ifstream cin("1.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        int n; cin>>n; 
        string s; cin>>s; 
        if (n == 1) {
            cout<<1<<endl; 
            continue;
        }
        
        bool first = true;
        int beg = 0, end = 0; 
        it(i, n) {
            if (s[i] == 'B' && first) {
                beg = i; 
                first = false; 
            }
            if (s[i] == 'B') end = i;
        }
        cout<<end-beg+1<<endl; 
    }
	return 0;
}