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
    // TODO: check optimized code from solutions 
    //ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, n; cin>>h>>w>>n;
    int matrix[h][w]; // 0 is white, 1 is black

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            matrix[i][j] = 0;  
        }
    }
    int cnt = 1; 
    matrix[0][0] = 1;
    int i = 0, j = 0;
    string dir = "right";
    bool moved = false;
    while (cnt<n) {
        moved = false; 
        if (dir == "right" && !moved) {
            (j + 1) == w ? j = -1 : j = j;
            if (matrix[i][j+1] == 0) {
                matrix[i][j+1] = 1;
                dir = "down";
                cnt++, j++;
            }
            else {
                matrix[i][j+1] = 0;
                dir = "up";
                cnt++, j++;
            }
            moved = true;
        }
        else if (dir == "down" && !moved) {
            (i + 1) == h ? i = -1 : i = i;
            if (matrix[i+1][j] == 0) {
                matrix[i+1][j] = 1;
                dir = "left";
                cnt++, i++;
            }
            else {
                matrix[i+1][j] = 0;
                dir = "right";
                cnt++, i++;
            }
            moved = true;
        }
        else if (dir == "left" && !moved) {
            (j - 1) == -1 ? j = w : j = j;
            if (matrix[i][j-1] == 0) {
                matrix[i][j-1] = 1;
                dir = "up";
                cnt++, j --;
            }
            else {
                matrix[i][j-1] = 0;
                dir = "down";
                cnt++, j--;
            }
            moved = true;
        }
        else if (dir == "up" && !moved) {
            (i - 1) == -1 ? i = h : i = i;
            if (matrix[i-1][j] == 0) {
                matrix[i-1][j] = 1;
                dir = "right";
                cnt++, i--;
            }
            else {
                matrix[i-1][j] = 0;
                dir = "left";
                cnt++, i--;
            }
            moved = true;
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            matrix[i][j] == 1 ? cout<<"#" : cout<<".";
        }
        cout<<endl;
    }
       


	return 0;
}