#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_map>
#include <cassert>
#include <array>
#include <deque>
#include <functional>


using namespace std;
#define NDEBUG
#define endl "\n"
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int)x.size()
//#define int long long
constexpr int MAX_N = 100'005;
constexpr int INF = 1E9;  

vector<vector<int>> getMainDiagonals(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> diagonals;

    // Start from first row
    for (int j = 0; j < cols; j++) {
        vector<int> diagonal;
        for (int x = 0, y = j; x < rows && y < cols; x++, y++) {
            diagonal.push_back(matrix[x][y]);
        }
        diagonals.push_back(diagonal);
    }

    // Start from first column (excluding first row)
    for (int i = 1; i < rows; i++) {
        vector<int> diagonal;
        for (int x = i, y = 0; x < rows && y < cols; x++, y++) {
            diagonal.push_back(matrix[x][y]);
        }
        diagonals.push_back(diagonal);
    }

    return diagonals;
}

// Function to get all anti-diagonals (↙)
vector<vector<int>> getAntiDiagonals(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> diagonals;

    // Start from first row
    for (int j = 0; j < cols; j++) {
        vector<int> diagonal;
        for (int x = 0, y = j; x < rows && y >= 0; x++, y--) {
            diagonal.push_back(matrix[x][y]);
        }
        diagonals.push_back(diagonal);
    }

    // Start from last column (excluding first row)
    for (int i = 1; i < rows; i++) {
        vector<int> diagonal;
        for (int x = i, y = cols - 1; x < rows && y >= 0; x++, y--) {
            diagonal.push_back(matrix[x][y]);
        }
        diagonals.push_back(diagonal);
    }

    return diagonals;
}

int32_t main() {
    ifstream cin("xSum.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 

    while(t--) {
        int n, m; cin>>n>>m;
        vector<vector<int>> ma(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>ma[i][j];
            }
        }
        vector<vector<int>> main_diagonals = getMainDiagonals(ma), anti_diagonals = getAntiDiagonals(ma);
        int ans = 0;
        for (auto& d1: main_diagonals) {
            for (auto& d2: anti_diagonals) {
                
            }
        }
    }
}