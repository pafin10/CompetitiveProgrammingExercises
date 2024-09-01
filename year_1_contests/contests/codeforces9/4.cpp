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

// DEBUGGING AND PROBABLY CHECK SOLUTION (tourist)

ll computeMin(vector<ll> a, ll i) {
    vector<ll> left(i-1), right(a.size() - i); 
    ll leftSum = 0, rightSum = 0;
    ll cnt1 = 1000000, ptr = i;
    bool found = false;

    while(ptr > 1) {
        if (ptr > 2) {
            if (a[ptr-1] + a[ptr-2] != a[ptr-3] && a[ptr-1] != a[ptr-2]) {
                // add a[i-2] + a[i-1]
                a.insert(a.begin()+ptr, a[ptr-1]+a[ptr-2]);
                // delete a[i-2] + a[i-1]
                a.erase(a.begin()+ptr-2, a.begin()+ptr);
                cnt1++, ptr--;
            }
            else {
                // add a[i-3] + a[i-2]
                a.insert(a.begin()+ptr-1, a[ptr-2]+a[ptr-3]);
                // delete a[i-2] + a[i-1]
                a.erase(a.begin()+ptr-3, a.begin()+ptr-1);
                cnt1++, ptr--;
            }
            if (a[ptr-1]+a[ptr-2] > a[ptr]) {
                found = true;
                break;
            }
        }
        else {
            a.insert(a.begin()+ptr, a[ptr-1]+a[ptr-2]);
            a.erase(a.begin()+ptr-2, a.begin()+ptr);
            cnt1++;
        }   
    }
    if (a[ptr-1] + a[ptr-2] > a[ptr]) found = true;

    ll cnt2 = 1000000;
    for (ptr = i; ptr < a.size() - 1; ++ptr) {
        if (ptr < a.size() - 2) {
            if (a[ptr+1] + a[ptr+2] != a[ptr+3] && a[ptr+1] != a[ptr+2]) {
                // add a[i+1] + a[i+2]
                a.insert(a.begin()+ptr+2, a[ptr+1]+a[ptr+2]);
                // delete a[i+1] + a[i+2]
                a.erase(a.begin()+ptr+1, a.begin()+ptr+3);
                cnt2++;
            }
            else {
                // add a[i+2] + a[i+3]
                a.insert(a.begin()+ptr+2, a[ptr+2]+a[ptr+3]);
                // delete a[i+1] + a[i+2]
                a.erase(a.begin()+ptr+1, a.begin()+ptr+3);
                cnt2++;
            }
            if (a[ptr+1]+a[ptr+2] > a[ptr]) {
                break;
            }
        }
        else {
            a.insert(a.begin()+ptr+2, a[ptr+1]+a[ptr+2]);
            a.erase(a.begin()+ptr+1, a.begin()+ptr+3);
            cnt2++;
        }
    }

    if (a[ptr+1] + a[ptr+2] > a[ptr]) {
        ll result = cnt1 < cnt2 ? cnt1 : cnt2;
        return result;
    }
    return -1; 
}

int main(int argc, char const *argv[])
{
     ifstream cin("4.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        ll n; cin>>n; 
        vector<ll> a;
        it (i, n) {
            ll j; cin>>j; 
            a.push_back(j);
        }

        vector<ll> mins(n);
        it (i, n) {
            mins[i] = computeMin(a, i);
            cout<<mins[i]<<" ";
        }
        cout<<endl; 
    }
	return 0;
}