#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

#define it(i, start, n) for (int i = start; i < n; ++i)
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define vout(v) it(i,0,sz(v)) cout<<v[i]<<" "

const int MAX_N = 100'005;

int main() {
    //ifstream cin("2.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        vector<vi> matrix(n, vi(m));

        it(i, 0, n) {
            it(j, 0, m) cin >> matrix[i][j];
        }

        it(i, 0, n) {
            it(j, 0, m) {
                int current_value = matrix[i][j];
                int max_neighbor = 0;

                if (i > 0) max_neighbor = max(max_neighbor, matrix[i - 1][j]); 
                if (i < n - 1) max_neighbor = max(max_neighbor, matrix[i + 1][j]); 
                if (j > 0) max_neighbor = max(max_neighbor, matrix[i][j - 1]);
                if (j < m - 1) max_neighbor = max(max_neighbor, matrix[i][j + 1]); 

                matrix[i][j] = min(current_value, max_neighbor);
            }
        }

        for (auto& k : matrix) {vout(k); cout<<endl;}
    }
}
