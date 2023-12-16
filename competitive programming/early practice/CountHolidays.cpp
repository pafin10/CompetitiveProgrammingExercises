// Update the code below to solve the problem

#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main() 
{
	ifstream cin("CH.txt");
	int t;
    cin >> t;
	
	while(t--)
	{
	    int N;
	    cin >> N;
	    int A[N];
	    for(int i=0; i < N; i++)
	    {
	        cin >> A[i];
	    }

	    int holidays = 8;
	    int weekends[30/7*2]; int cnt = 0;
	    
	    for (int i = 0; i < 8; i+=2) weekends[i] = 6+7*i/2;
	    for (int i = 1; i < 8; i+=2) weekends[i] = 7*i/2+4; //whyever this works
	    
        
	    for (int i = 0; i < N; i++) {
	        bool weekday = true;
	        for (int j = 0; j < 8; j++) {
	             if (A[i] == weekends[j]) weekday = false;
	        }
	        if (weekday) holidays++;
	    }
	   cout << holidays << "\n";
	}
}