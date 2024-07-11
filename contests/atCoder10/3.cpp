#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

#define it(i, start, n) for (int i = start; i < n; ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

static vector<string> generateSierpinskiCarpet(int n) {
    if (n == 0) return vector<string>({"#"});
    
    vector<string> smallerCarpet = generateSierpinskiCarpet(n - 1);
    int size = sz(smallerCarpet);
    vector<string> carpet(size * 3, string(size * 3, '.'));
    
    it(i, 0, size) {
        it(j, 0, size) {
            carpet[i][j] = smallerCarpet[i][j];
            carpet[i][j + size] = smallerCarpet[i][j];
            carpet[i][j + 2 * size] = smallerCarpet[i][j];
            carpet[i + size][j] = smallerCarpet[i][j];
            carpet[i + size][j + size] = '.';
            carpet[i + size][j + 2 * size] = smallerCarpet[i][j];
            carpet[i + 2 * size][j] = smallerCarpet[i][j];
            carpet[i + 2 * size][j + size] = smallerCarpet[i][j];
            carpet[i + 2 * size][j + 2 * size] = smallerCarpet[i][j];
        }
    }
    
    return carpet;
}

int main() {
    //ifstream cin("3.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    vector<string> carpet = generateSierpinskiCarpet(n);
    
    for (const auto& line : carpet) {
        cout << line << endl;
    }
    
    return 0;
}
