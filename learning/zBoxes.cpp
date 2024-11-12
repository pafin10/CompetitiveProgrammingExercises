#include <vector>
#include <string>
#include <iostream>
#define endl "\n"

using namespace std;


vector<int> zBox(string s) {
    int m = s.size();
    vector<int> Z(m, 0);

    int l = 0, r = 0, i = 1; 
    for (int k = 1; k < m; k++) {
        if (k > r) {
            i = k; 
            while (i < m && s[i] == s[i - k]) i++;
            Z[k] = i - k; 
            if (Z[k] > 0) {
                l = k, r = i - 1;
            }
        }
        else {
            if (Z[k - l] < r - k + 1) Z[k] = Z[k - l];
            else {
                i = r + 1;
                while (i < m && s[i] == s[i - k]) i++;
                Z[k] = i - k; 
                if (i - 1 > r) {
                    l = k , r = i - 1;
                }
            }
        }
    }
    Z.erase(Z.begin(), Z.begin() + 1);
    return Z;
}

int main(int argc, char const *argv[])
{   
    vector<string> tests = {"ananas" , "abaabaabab"};
    for (auto test : tests) {
        vector<int> Z = zBox(test);
        for (auto val : Z) cout<<val<<" ";
        cout<<endl; 
    }
    return 0;
}
