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
        int n, m; cin>>n>>m; 
        if (m == 1) {
            cout<<-(n/2)<<endl;
            continue;
        }
        cout<<m/2*n<<endl; 

    }
    return 0;
}