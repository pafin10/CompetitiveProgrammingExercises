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

int main() {
    ifstream cin("2.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        vector<int> a;
        if (n & (n-1) == 0) {
            cout<<"Bob"<<endl;
            continue;
        }
        for (int i = 1; i <= n/3; i+=2) {
            if (n%i == 0) a.push_back(i);  
        }
        int cnt = 0; bool found = false;
        for (int p: a) {
            int m = n;
            int cnt = 0;
            while (m-p >= 0 && !(m-p & (m-p-1))) {
                m-=p;
                cnt++;
            }
            if (cnt%2 == 1) {cout<<"Alice"<<endl; found = true; break;}
        }
        if (found) continue;
        cout<<"Bob"<<endl;
    }
	return 0;
}
