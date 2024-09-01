#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("1.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        set<int> uniques(a.begin(), a.end());
        int u = uniques.size();
        vector<vector<int>> pos(u);
        int clan;
        int ti;
        for (int i = 0; i < n; i++) {
            pos[a[i] - 1].push_back(i);
        }

        int mini = INT_MAX; // Using INT_MAX for initial comparison
        for (int i = 0; i < u; i++) {
            int maxi = 0;
            vector<int> cur = pos[i];

            // Iterate over positions for the current unique element
            for (int j = 0; j < cur.size() - 1; j++) {
                int distance = (cur[j + 1] - cur[j]) / 2;
                maxi = max(maxi, distance);
            }

            // Check the distance from the first and last positions
            maxi = max(maxi, cur[0]); // Distance to the first position
            maxi = max(maxi, n - 1 - cur.back()); // Distance to the last position

            if (maxi < mini) {
                mini = maxi;
                clan = i + 1;
            }
        }

        cout << clan << " " << mini << "\n";
    }
    return 0;
}