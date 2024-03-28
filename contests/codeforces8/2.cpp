#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
#define ll long long
#define endl "\n"
#define it(i, n) for (int i = 0; i < n; ++i)

int main(int argc, char const *argv[])
{
    //ifstream cin("2.txt");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t; 

    while (t--) {
        int n; 
        cin >> n;

        bool square = false;

        int ln1 = 0, ln2 = 0;
        bool first = true, second = false; 

        it(i, n) {
            it(j, n) {
                char el; 
                cin >> el;
                if (first && el == '1') ln1++;
                else if (el == '1' && second) ln2++;
            }
            if (ln1 != 0) {first = false; second = true;}
            if (ln2 != 0) { second = false; }
        }
        ln1 == ln2 ? cout << "SQUARE" << endl : cout << "TRIANGLE" << endl;
    }

    return 0;
}
