#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
#define ll long long
#define endl "\n"

int main(int argc, char const *argv[])
{
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n; 
    ll diff = 0;
    vector<ll> a(n); ll runSum = 0;

    // first element, if negative ignore
    cin>>a[0];
    if (a[0] >= 0) runSum += a[0];

    for (int i = 1; i < n; ++i) {
        cin>>a[i];
        (runSum + a[i]) < diff ? diff = (runSum + a[i]) : diff;
        runSum += a[i];
    }
    cout<<runSum+abs(diff)<<endl;
	return 0;
}