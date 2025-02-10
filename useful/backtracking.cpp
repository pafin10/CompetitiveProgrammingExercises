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
#define ll long long
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define sz(x) (int)x.size()
#define int long long
const int MAX_N = 100'005;
const int INF = 1E9;
using namespace std;

typedef long long ll;

int main() {
    // Input: number of bags
    int N; 
    cin >> N;

    // Input: number of stones in each bag
    vector<ll> A(N);
    for (auto &x : A) cin >> x;

    // To store all unique XOR results
    vector<ll> results;

    // To keep track of subsets (modified bags)
    vector<ll> subsets;

    // Backtracking function to explore all possible distributions of stones
    function<void(int)> backtrack = [&](int idx) -> void {
        // Base case: all bags have been processed
        if (idx == N) {
            ll xor_sum = 0;

            // Compute XOR of all subsets
            for (auto s : subsets) xor_sum ^= s;

            // Store the result for this configuration
            results.push_back(xor_sum);
            return;
        }

        // Option 1: Add current bag's stones to an existing subset
        for (int i = 0; i < subsets.size(); i++) {
            ll original = subsets[i]; // Save original state
            subsets[i] += A[idx];     // Add current bag's stones
            backtrack(idx + 1);       // Recurse to process the next bag
            subsets[i] = original;    // Undo the change (backtrack)
        }

        // Option 2: Create a new subset starting with the current bag's stones
        subsets.push_back(A[idx]);
        backtrack(idx + 1);           // Recurse to process the next bag
        subsets.pop_back();           // Remove the new subset (backtrack)
    };

    // Start backtracking from the first bag
    backtrack(0);

    // Remove duplicates and count unique XOR results
    sort(results.begin(), results.end()); // Sort results
    results.erase(unique(results.begin(), results.end()), results.end()); // Remove duplicates

    // Output the number of unique XOR values
    cout << results.size();
}
