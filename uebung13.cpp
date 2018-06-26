#include <vector>
#include <algorithm>
#include <iostream>

struct hardware {
	std::string vendor, name;
	unsigned int quantity;
	float cost, tax;

	void print() { std::cout << vendor << " " << name << " " << quantity << " " << cost << " " << tax << std::endl; 
}
};

int main(){
	std::vector<hardware> teile;

	hardware h1;
	h1.vendor = "Intel";
	h1.name = "laptop";
	h1.quantity = 2;
	h1.cost = 5;
	h1.tax = 10;
	teile.push_back(h1);

	hardware h2;
	h2.vendor = "Intel";
	h2.name = "eumelgeraet";
	h2.quantity = 1;
	h2.cost = 1;
	h2.tax = 10;
	teile.push_back(h2);

	std::for_each(teile.begin(), teile.end(), [](hardware &teil){ teil.print(); }); //alles ausgeben
			
	hardware billigstes = teile[0];
	hardware teuerstes = teile[0];

	std::for_each(teile.begin(), teile.end(), [&billigstes, &teuerstes](hardware &teil){
		if(billigstes.cost > teil.cost){
			billigstes = teil;}

		if(teuerstes.cost < teil.cost){
			teuerstes = teil;}}); //min und max

	std::cout<< "Billigstes: " << billigstes.name << std::endl;
	std::cout<< "Teuerstes: " << teuerstes.name << std::endl;

	int zaehler; 
	std::for_each(teile.begin(), teile.end(), [&zaehler] (hardware &teil) {
			if(teil.vendor == "Intel"){ zaehler++; } }  ); //alle teile von intel
	std::cout << "Es gibt " << zaehler << " Produkte von Intel." << std::endl;

	int sumOfCosts = 0;
	std::for_each(teile.begin(), teile.end(), [&sumOfCosts](hardware &teil){ sumOfCosts += teil.cost;});

	std::cout << "Der gesamte Warenbestand ist " << sumOfCosts << "€ wert" << std::endl;


	return 0;
}
