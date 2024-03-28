#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

vector<int> precomputeCards(int maxi) {
    vector<int> out(maxi+10);
    it(i, maxi) {
        if (i < (maxi+1)/2) {
            out[i] = 2*i-1;
        }
        else {
            int ind = 0, fact = 2;
            int curr = fact*out[ind];
            while(out.size() < maxi-1) {
                while(curr <= maxi) {
                    out[i] = curr;
                    ind++;
                    curr = fact*out[ind];
                }
                fact++;
            }
        }
    }  
    return out;   
}

int main(int argc, char const *argv[]) {
    ifstream cin("5.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<"runs"<<endl;
    int t; 
    cin >> t; 
    vector<int> cards = precomputeCards(pow(10, 9));
    while (t--) {
        int n, k; 
        cin >> n >> k;
        cout<<cards.size()<<endl;
        cout<<cards[k]<<endl;
    }
    return 0;
}