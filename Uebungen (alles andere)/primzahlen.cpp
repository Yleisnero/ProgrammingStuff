#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

std::vector<int> sieve(int n) {
	int sqrtN = (int)sqrt(n);
	std::vector<int> primes = std::vector<int>( );
	std::vector<bool> candidates(n + 1, true);

	if(n < 2) return primes;


	for (int i = 2; i <= sqrtN; ++i) {
		if(!candidates[i]) continue; //Precondition (wenn i schon falsch ist)
		for (int j = i * i; i * j <= n; j += i){ //um i weiter zählen
			candidates[j] = false;
		}
	}

	for (int i = 3; i <= n; i += 2){ //gerade Zahlen nicht beachten
		if (candidates[i]){
			primes.push_back(i);
		}
	}

	return primes;
}

std::vector<int> sieveOld(int n) {
	int sqrtN = (int)sqrt(n);
	std::vector<int> primes = std::vector<int>( );
	std::vector<bool> candidates(n + 1, true);

	for (int i = 2; i <= sqrtN; ++i) {
		for (int j = i; i * j <= n; ++j)
		candidates[i * j] = false;
	}

	for (int i = 2; i <= n; ++i)
		if (candidates[i]) primes.push_back(i);
	
	return primes;
}

int main(){

	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	
	for(int x : sieve(7919)){ //7919 ist Primzahl Nummer 1000
		std::cout << x << std::endl; 
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Printing took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << "us.\n";
	
	return 0;
}
