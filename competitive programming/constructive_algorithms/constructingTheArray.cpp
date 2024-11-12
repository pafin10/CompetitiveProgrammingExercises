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
#include <queue>


using namespace std;
#define ll long long
#define endl "\n"
#define ff first
#define ss second
#define it(i, start, n) for (int i = start; i < n; ++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int arr[200010];

int main(int argc, char const *argv[]) {
    //ifstream cin("constructingTheArray.txt");
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        int cnt = 1; 

        priority_queue<pair<int, pair<int, int>>> q;
        q.push({n, {-1, -n}}); // - because top returns max el. (max heap)

        while(!q.empty()) {
            int L = -q.top().ss.ff; 
            int R = -q.top().ss.ss; 
            q.pop();

            int mid = (L+R) / 2; 
            arr[mid] = cnt++;

            if (L==R) continue;
            if (L < mid) 
                q.push({(mid-L), {-L, -(mid-1)}});
            
            if (R > mid)
                q.push({R-mid, {-(mid+1), -(R)}});
        }
        it(i,1,n+1) cout<<arr[i]<<" ";
        cout<<endl; 

    }
}