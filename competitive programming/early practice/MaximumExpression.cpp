#include <iostream>
#include <algorithm>
using namespace std;

// WORKS, BUT TOO SLOW: ALTERNATIVE SORTING WITHOUT USING LIBRARIES
// UPDATE: JUST STICK TO BLACKBOXING, CODECHEF ACCEPTS IT AND IT MAKES LIFE EASIER

void solve();

int main() {
	int t; 
	cin>>t; 
	while (t--) {
	    solve();
	}
	
	return 0;
}

void solve() {
    int N; string S;
	    cin >> N;
	    cin.ignore();
	    getline(cin, S);
	    int opCount = 0;int numCount = 0; int plusCount = 0; int minusCount = 0;
	    
	    for (int i = 0; i < N; i++) {
	        if (S[i] == '+' || S[i] == '-') {
                opCount++;
                if (S[i] == '+') plusCount++;
                else minusCount++;
            }  
	        else numCount++; 
	    }

	    int sortedArr[numCount];
        numCount = 0; 
        for (int i = 0; i < N; i++) {
            if (!(S[i] == '+' || S[i] == '-')) {
                sortedArr[numCount] = S[i] - '0'; numCount++; // converts char to int
            }
        }
        
	    sort(sortedArr, sortedArr + numCount); // sorts array
        reverse(sortedArr, sortedArr + numCount); // reverses array
        
        int lengthNum = numCount;
        int untilHereApp = lengthNum - opCount;
        numCount = 0;

        for (int i = 0; i < lengthNum; i++) {
            if (i < untilHereApp) {
                cout << sortedArr[numCount++];
                continue;
            }

            if (i < lengthNum) {
                if (plusCount > 0) {
                    cout << "+";
                    plusCount--;
                } else {
                    cout << "-";
                    minusCount--;
                }
            }
            cout << sortedArr[numCount++];
        }

    cout << endl;
}