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
        bool first = true;
        int start = 60, cnt = 0, last = 0;
        it(i, n) {
            int j; cin>>j; 
            if (j == 1 && first) {
                start = i;
                first = false;
            }
            if (i>start && j == 0) cnt++;
            else if (j == 1) last = i;
        }         
        cnt -= (n-last-1);
        cout<<cnt<<endl;
    }
	return 0;
}