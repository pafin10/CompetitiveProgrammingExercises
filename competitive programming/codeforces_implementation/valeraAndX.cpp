#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)
#define pb push_back


int main(int argc, char const *argv[]) {

    //ifstream cin("valeraAndX.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin>>n; 
    char diag = '-', rest = '.';
    string ans = "YES";
    it (i, n) {
        string line; cin>>line; 
        if (line[i] != line[n-1-i]) {ans = "NO"; break;}
        else {
            if (i == 0) {
                diag = line[0];
                rest = line[1];
                if (diag == rest) {ans = "NO"; break;}
            }
            if (i > 0 && (line[i] != diag || line[i-1] != rest)) {ans = "NO"; break;}
            it (j, n) {
                if (i != j && j != (n-i-1) && line[j] != rest) {
                    ans = "NO"; 
                    break; 
                }
            }
        }
    }
    
    cout<<ans<<endl; 


    return 0;
}
