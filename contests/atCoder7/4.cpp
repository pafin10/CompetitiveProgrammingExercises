#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#define int long long
#define it(i, start, n) for (int i = start; i < n; ++i)

int32_t main() {
    ifstream cin("4.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, char>> events;
    it(i,0,n) {
        int l, r;
        cin >> l >> r;
        events.emplace_back(l, 's'); 
        events.emplace_back(r, 'e'); 
    }

    sort(events.begin(), events.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    int ans = 0;
    int active_intervals = 0;

    // would have to modify, dont necessarily decrease intervals when an end is encountered
    for (const auto& event : events) {
        if (event.second == 's') {
            ans += active_intervals;
            ++active_intervals;
        } else {
            --active_intervals;
        }
    }

    cout << ans << endl;

    return 0;
}
