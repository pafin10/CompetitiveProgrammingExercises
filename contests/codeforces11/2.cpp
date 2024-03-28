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
    //ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        int n; cin>>n; 
        char start = '/';
        it (i, 2*n) {
            if (i % 4 == 0 || i % 4 == 1) start = '#';
            else start = '.';
            string el(2*n, 'a');
            if (start == '#') {
                it (j, 2*n) {
                    if (j % 4 == 0 || j % 4 == 1) el[j] = '#';
                    else el[j] = '.';
                }
            }
            else {
                it (j, 2*n) {
                    if (j % 4 == 0 || j % 4 == 1) el[j] = '.';
                    else el[j] = '#';
                }
            }
            cout<<el<<endl; 
        }
    }
	return 0;
}