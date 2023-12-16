#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream cin("snapchat.txt");
	int t; cin>>t;
	while(t--) {
	    int N; cin>>N;
	    vector<int> a(N);
        vector<int> b(N);
	    int maxStreak = 0; int streakCount = 0;
	    for (int i = 0; i < N; i++) cin>>a[i];
	    for (int i = 0; i < N; i++) cin>>b[i];
	    
	    for (int i = 0; i < N; i++) {
	        if(a[i] > 0 && b[i] > 0) {
	            if(streakCount==0)streakCount=1;
	            else if (streakCount>0) {
	                streakCount++;
	            }
                if (streakCount>maxStreak) maxStreak=streakCount;
	        }
	        else streakCount=0;
	    }
	    cout<<maxStreak<<endl;


	}
	return 0;
}
