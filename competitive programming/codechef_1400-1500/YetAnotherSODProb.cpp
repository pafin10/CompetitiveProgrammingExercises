#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define ll long long 
using namespace std;

int main() {
    //ifstream cin("YetAnotherSODProb.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--) {
        ll l,r; cin>>l>>r; 
        ll diff = r-l;
        ll add = 0;
        if (diff<3) {
            for (ll i = l; i<=r; i++) {
                string str = to_string(i);
                ll sumDig = 0;
                for (int i = 0; i<str.length(); i++) {
                    sumDig += str[i] - '0';
                }
                if (sumDig%3==0) {
                    add =1; 
                    break;
                }
            }
           
        }
        if (diff%3 == 0) {
            string str_l = to_string(l);
            ll sumDig1 = 0;
            for (int i = 0; i<str_l.length(); i++) {
                sumDig1 += str_l[i] - '0';
            }
            if (sumDig1%3==0) {
                add =1; 
            }
        }

        else if (diff%3==1) {
            string str1 = to_string(l+1);
            string str2 = to_string(l);
            ll sumDig1 = 0; ll sumDig2 = 0;
            for (int i = 0; i<str1.length(); i++) {
                sumDig1 += str1[i] - '0';
                sumDig2 += str2[i] - '0';
            }
            if (sumDig1%3==0 || sumDig2%3 == 0) {
                add =1; 
            }
        }

        else add = 1;
        cout<<diff /3 + add<<endl;
    }
	return 0;
}