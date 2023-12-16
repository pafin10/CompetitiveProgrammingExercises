#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;
// execution works on Codechef, probably something with the .txt format input is messy here or random stuff that i dont get

char tmp[105];
string readString() {
	string s; cin>>s;
	cin.ignore();
	return s;
}

int main(int argc, char const *argv[])
{
	ifstream cin("SocialNetwork.txt");
	set<int> specials;
	int n,m; cin>>n>>m;
	while (n--) {
		int a; 
		cin>>a;
		assert(!specials.count(a));
		// assertion returns false if a is already in the set and terminates the program
		specials.insert(a);
		assert(1<=a<=10E5);
	}
	vector<pair<pair<int, int>, string>> posts;
	for (int i = 0; i < m; i++) {
		int who, pop; 
		cin>>who>>pop;
		posts.push_back(make_pair(make_pair(specials.count(who), pop), readString()));
	}
	sort(posts.rbegin(), posts.rend()); // reverse sorting, first by specialness, then by popularity (as order in the vector goes)
	for (auto p : posts) {
		cout<<p.second<<endl;
	}
	return 0;
}
