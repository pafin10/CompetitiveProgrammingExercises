#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>

#define ll long long
using namespace std;

vector<bool> sieveOfErastothenes(int limit) {
    vector<bool> isPrime(limit+1, true);
    isPrime[0] = false; isPrime[1] = false;
    
    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p*p; i<=limit; i+=p) {
                isPrime[i] = false;
            }
        }
    }
    return isPrime;
}

vector<bool> dpTable;  // Dynamic programming table

bool canWin(int height, const vector<int>& primePowers) {
    if (height == 0) return false;
    if (dpTable[height]) return false;
    
    for (int power: primePowers) {
        if (power <= height) {
            if (!canWin(height - power, primePowers)) {
                dpTable[height] = false; 
                return false;
            }
        }
        else {
            break;
        }
    }
    dpTable[height] = true; 
    return true; 
}

int main() {
    ifstream cin("chef&coinsGame.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t; 
    while(t--) {
        int n; cin>>n; 
        if (n == 1) {cout<<"Chef"<<endl; continue;}
        bool isPP = false;
        vector<bool> isPrime = sieveOfErastothenes(n);
        vector<int> primePowers;
        for (int p = 1; p <= n; p++) {
            if (isPP) break;
            if (isPrime[p]) {
                int x = 1;
                while (pow(p,x) <= n) {
                    if (pow(p,x) == n) {
                        isPP = true; 
                        break;
                    }
                    primePowers.push_back(pow(p,x)); 
                    x++;  
                }
            }
        }
        if (isPP) {cout<<"Chef"<<endl; continue;}
        else {
            dpTable.assign(n+1, false);
            bool chefWins = canWin(n, primePowers);
            
            if (chefWins) {cout<<"Chef"<<endl; }
            else cout<<"Misha"<<endl;
        }
       
    
    }
    
	return 0;
}
