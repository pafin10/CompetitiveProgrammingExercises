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
    //ifstream cin("1.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin>>s; 
    istringstream ss(s);
    string token = "", lastToken = ""; 

    while(getline(ss, token, '.')) {
        lastToken = token;
    }
    cout<<lastToken<<endl;
    
	return 0;
}