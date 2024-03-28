#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <fstream>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main()
{

    //ifstream cin("2.txt");

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x; cin>>x; 
    ll y = x / 10;
    ll rest = x % 10; 
    if (x >= 0) {
        rest == 0 ? cout << y << endl : cout << y+1 <<endl;
    }
    else {
        cout<<y<<endl;    
    }

	return 0;
}

