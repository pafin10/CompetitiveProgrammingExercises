// Update the code below to solve the problem

#include <iostream>
#include <algorithm>
#include <set>
#include <fstream>
using namespace std;

int main() 
{
	ifstream cin("HS.txt");
	int t;
    cin >> t;
	
	while(t--)
	{
	    string S;
	    cin >> S;
	    set<char> vowels;
	    vowels.insert('a'); vowels.insert('e'); vowels.insert('i'); 
	    vowels.insert('o'); vowels.insert('u'); 
	    int vowCount = 0; bool happy = false; int last =0;
	    
	    for (int i= 0; i < S.length(); i++) {
	        if (vowels.find(S[i]) != vowels.end()) {
	            if (vowCount == 0) {
	                vowCount++;
	                last = i;
	            }
	            else if (vowCount > 0 && last == i-1) {
	                vowCount++;
	                last = i;
	                if (vowCount > 2) {
	                    happy = true;
	                    break;
	                }
	            }
	        }
	        if (last != i) vowCount = 0;
	    }
	    if (happy) cout << "Happy" << endl;
	    else cout << "Sad" << endl;
	    
	}
}