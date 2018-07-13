#include <iostream>
#include <cmath>
using namespace std;

//functions have to edited by yourself
long double f (long double x) {
	return pow(x, 3)-4;
}

long double fab (long double x) {
	return 3 * pow(x, 2) ;
}

long double newton (long double &x, int limiter) {
	for (int i = 0; i < limiter; i++)
		x = x - (f(x) / fab(x));//, cout << x <<endl;
	return x;
}

int main() {
	long double x = 1;
	int l;
	cout << "Schrittweite: ", cin >> l;
	cout << "Angenäherte Nullstelle: " << newton(x, l) << endl;
	return 0;
}
