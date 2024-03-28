#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

#define endl "\n"
#define ll long long 
#define it(i, n) for (int i = 0; i <n; i++)
using namespace std;



int checkCell(const string field[51], int i, int j) {
    bool l = true, r = true, t = true, b = true;
    if (!(field[i][j-1] == '^' && field[i][j-2] == '^')) l = false; 
    if (!(field[i][j+1] == '^' && field[i][j+2] == '^')) r = false; 
    if (!(field[i-1][j] == '^' && field[i-2][j] == '^')) t = false; 
    if (!(field[i+1][j] == '^' && field[i+2][j] == '^')) b = false; 
    if (l && r && t && b) return 1;
    else return 0; 
}


int main() {
    ifstream cin("CAO_stage1.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string field[51];
    int t; cin>>t; 
    while(t--) {
        int r, c; cin>>r>>c; 
        it(i, r) {
            string s; cin>>s;
            field[i] = s;
        }
        int cnt = 0; 
        it(i, r) {
            it (j, c) {
                if (field[i][j] == '^' && (i > 1 && i < r-2 && j > 1 && j < c - 2)) {
                    cnt += checkCell(field, i, j);
                    cout<<"i: "<<i<<"j: "<<j<<" "<<"cnt: "<<cnt<<endl;
                    cout<<field[i][j+2]<<endl;
                }
            }
        }
        cout<<cnt<<endl;
    
    }
	return 0;
}