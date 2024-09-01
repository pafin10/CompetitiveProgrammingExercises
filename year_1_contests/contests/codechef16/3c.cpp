#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("3.txt");
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n), p(n);
        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) cin >> p[i];

        vector<bool> activated(n, false); // Initialize one activated vector for both moves
        vector<char> direction(n, '\0'); // Initialize one direction vector for both moves
        bool possible = false;
        for (int move = 0; move < 2; ++move) { // Perform up to two moves

            // Simulate the movement of balls
            for (int i = 0; i < n; ++i) {
                if (!activated[i]) {
                    char dir = (move == 0) ? 'l' : 'r'; // Direction for the current move
                    if ((i == 0 || (dir == 'r' && x[i] - p[i] > x[i - 1])) &&
                        (i == n - 1 || (dir == 'l' && x[i] + p[i] < x[i + 1]))) {
                        // Activate the ball and move it in the current direction
                        activated[i] = true;
                        direction[i] = dir;
                        x[i] += (dir == 'r') ? p[i] : -p[i];
                    } else {
                        // Ball strikes another ball, activate it in the same direction
                        activated[i] = true;
                        direction[i] = direction[i - 1];
                    }
                }
            }

            // Check if all balls are activated for the current move
            bool all_activated = true;
            for (int i = 0; i < n; ++i) {
                if (!activated[i]) {
                    all_activated = false;
                    break;
                }
            }
            if (all_activated) {
                possible = true;
                break; // If all balls are activated, no need to continue to the next move
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}
