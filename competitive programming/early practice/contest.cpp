#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
// CHECK CODECHEF SOLUTION

    ifstream cin("contest.txt");
	int t; cin>>t;
	while(t--) {
	    long long length; string n; long long modified_n = 0;
	    cin>>length>>n;
	    long long found = -1;
	    
	    //MAX VAL
	    if (length>=18) {
	        string firstHalfStr = n.substr(0, n.size() / 2);
	        string secondHalfStr = n.substr(n.size()/2);
	        long long sec = stoll(secondHalfStr);


	        long long above=10-(sec%10);
	        long long below =sec%10;
	        //cout<<"above: " << above << " below: " <<below<<endl;


	        
	        for (long long i = 1; i<below; i++) {
	            modified_n = sec-i;
	            if (modified_n%8==0) {
	                found = modified_n;
	                break;
	            }
	        }
	        if (found!=-1) {cout<<firstHalfStr+to_string(modified_n)<<endl; continue;}
	        
	        for (long long i = 1; i<above; i++) {
	            long long modified_n = sec+i;
	            if (modified_n%8==0) {
	                found = modified_n;
	                break;
	            }
	        }
	        cout<<firstHalfStr+to_string(modified_n)<<endl;
	    }

	    else if (stoi(n)%8==0) {cout<<n<<endl;}
	    else {
	        long long above=10-(stoi(n)%10);
	        long long below =stoi(n)%10;
	        cout<<"above: " << above << " below: " <<below<<endl;
	        
	        for (long long i = 1; i<below; i++) {
	            modified_n = stoi(n)-i;
	            if (modified_n%8==0) {
	                found = modified_n;
	                break;
	            }
	        }
	        if (found!=-1) {cout<<found<<endl; continue;}
	        
	        for (long long i = 1; i<above; i++) {
	            modified_n = stoi(n)+i;
	            if (modified_n%8==0) {
	                found = modified_n;
	                break;
	            }
	        }
	        cout<<found<<endl;
	    }
	}
	return 0;
}