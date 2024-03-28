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
    // ifstream cin("3.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) {
        string s; cin>>s; 
        if (s == "00:00") {cout<<"12:00 AM"<<endl; continue;}
        bool am = true;
        int hour = stoi(s.substr(0, 2));
        if (hour >= 12) am = false; 
        if (am) {
            if (hour != 0)
                cout<<s<<" AM"<<endl;
            else 
                cout<<"12:"<<s.substr(3,5)<<" AM"<<endl;
        }
        else {
            if (hour != 12) 
                hour-=12;
            string hourStr = (hour < 10) ? "0" + to_string(hour) : to_string(hour);
            cout<<hourStr<<":"<<s.substr(3,5)<<" PM"<<endl;
        }
    }
	return 0;
}