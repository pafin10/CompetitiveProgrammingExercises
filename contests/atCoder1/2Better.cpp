#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[])
{
    //ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, n; cin>>h>>w>>n;
    string field[101]; 
    // x row and y column, like in coordinate system
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int x = 0, y = 0, d = 0;

    it(i, h) field[i] = string(w, '.');
    
    while (n--) {
        if (field[y][x] == '.') {
            field[y][x] = '#';
            d = (d+1)%4;
            x = (x + w + w + dx[d]) % w;
            y = (y + h + h + dy[d]) % h; 
        }
        else {
            field[y][x] = '.';
            d = (d+3)%4;
            x = (x + w + w + dx[d]) % w;
            y = (y + h + h + dy[d]) % h; 
        }
    }
    it (i, h) cout<<field[i]<<endl;
	return 0;
}