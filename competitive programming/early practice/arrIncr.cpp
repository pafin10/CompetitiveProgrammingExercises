#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("arrincr.txt");
	int t; cin>>t;
	while (t--) {
	    int N; 
	    cin>>N;
        bool incr = true;
	    int arr[N];
	    for (int i = 0; i < N; i++) {
	        cin>>arr[i];
	        if (i==0) continue;
	        if (arr[i] < arr[i-1]) {
	            incr = false;  cout<<"Smaller: "<< arr[i]<< " Bigger: " << arr[i-1]<<endl;
	            break; 
	           
	        }
	    }
	    if (incr) cout<<"Yes"<<endl;
	    else cout <<"No"<<endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}
	return 0;
}
