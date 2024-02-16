#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[])
{
    //ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        int n, m, k; cin>>n>>m>>k;
        vector<int> a(n);    
        vector<int> b(m); 
        set<int> aUsed, bUsed;
        it(i, n) {
            cin>>a[i];
            if (a[i] <= k) aUsed.insert(a[i]);
        }

        it(i, m) {
            cin>>b[i];
            if (b[i] <= k) bUsed.insert(b[i]);
        }
        
        set<int> fin;
        if (aUsed.size() >= (k/2) && bUsed.size() >= (k/2)) {
            auto itA = aUsed.begin();
            auto itB = bUsed.begin();
            int longer = max(aUsed.size(), bUsed.size());


            for (; itA != aUsed.end() && itB != bUsed.end(); ++itA, ++itB) {
                if (*itA <= k) fin.insert(*itA);
                if (*itB <= k) fin.insert(*itB);
            }

            auto& longerSet = (longer == aUsed.size()) ? aUsed : bUsed;
            auto& longerIt = (longer == aUsed.size()) ? itA : itB;

            while (longerIt != longerSet.end()) {
                if (*longerIt <= k) fin.insert(*longerIt);
                ++longerIt;
            }
        }

        else {
            cout<<"NO"<<endl;
            continue;   
        }
        
        fin.size() == k ? cout<<"YES"<<endl : cout<<"NO"<<endl;
        
    }
	return 0;
}