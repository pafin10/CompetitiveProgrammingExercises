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

int main(int argc, char const *argv[])
{
    //ifstream cin("1.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        string s; cin>>s; 
        int ln = s.length();
        int cntA = 0, cntB = 0; 
        it(i, ln) {
            s[i] == 'A' ? cntA++ : cntB++;
        }
        cntA > cntB ? cout<<"A"<<endl : cout<<"B"<<endl;
    }
	return 0;
}