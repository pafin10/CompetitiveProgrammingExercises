#include <iostream>
#include <cmath>
#include <fstream>

#define ll long long
#define same(a, b) (abs(a - b) < 1E-5)
using namespace std;

// WHY IS THE ORDERING IMPORTANT?? - SUCH THAT C IS THE LARGEST SIDE!
ll square(ll x) {
    return x*x;
}

void order(long long &a, long long &b, long long &c) {
  if (a > c) {
    swap(a, c);
  }
  if (b > c) {
    swap(b, c);
  }
  if (a > b) {
    swap(a, b);
  }
}

string getAngleClassification(ll a, ll b, ll c)
 {
    order(a, b, c);
    if (a + b == c) return "right";
    else if (a + b > c) return "acute";
    else return "obtuse";
 }
int main() {
    ifstream cin("TriangleClassification.txt");
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int subt; cin>>subt; 
    int t; cin>>t; 
    while(t--) {
        ll x1, y1, x2, y2, x3, y3; 
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        ll a = square(x1-x2) + square(y1-y2);
        ll b = square(x1-x3) + square(y1-y3);
        ll c = square(x2-x3) + square(y2-y3);
        bool scal = false, iso = false;
        if (!same(a, b) && !same(b, c) && !same(a, c)) scal = true;
        else if (same(a,b) ^ same(b,c) ^ same(a,c)) iso = true;
            
        if (subt == 1) {
            if (scal) {
                cout<<"Scalene triangle"<<endl; 
                continue;
            }
            else if (iso) {
                cout<<"Isosceles triangle"<<endl;
                continue;
            }
        }
        else {
            cout << (scal ? "Scalene " : "Isosceles ") << getAngleClassification(a, b, c) << " "<<"triangle"<< endl;
        }
    }
	return 0;
}