#include <iostream>
#include <assert.h>
#include <simtown/building.h>

int main(int arg, char** argv) {
	std::cout << "/ Initialisation... " << std::endl;
	DynArray<Building> street;
	std::cout << "*** Enter IDs (-99 to end) ***" << std::endl;
	int id = -1;
	std::cin >> id;
	while (id != -99) {
		street.push_back(Building(id, 5));
		std::cin >> id;
	}
	for (unsigned int i = 0; i < street.size(); ++i) {
		std::cout << street[i];
	}
	if (street.size() >= 2) {
		street[0].swap_rock(street[1], 2, 4);
	}
	std::cout << "/ End of program" << std::endl;

	return 0;
}