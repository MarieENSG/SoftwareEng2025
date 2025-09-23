# include <simtown/building.h>
# include <simtown/rock.h>

Building::Building() : id_(-1), rocks_(0) {
	std::cout << "Building::Building(), id_ = " <<
		id_ << " at " << this << std::endl; // this = addresse
} // Constructeur par déafut

Building::Building(unsigned int id, unsigned int nb_rocks) : id_(id), rocks_(nb_rocks) {
	std::cout << "Building::Building(" << id << ") at "
		<< this << std::endl;
	for (unsigned int ir = 0; ir < rocks_.size(); ++ir) {
		rocks_[ir] = new Rock;
	}
} // Constructeur

Building::~Building() {
	std::cout << "Building::~Building(" << id_ << ") at "
		<< this << std::endl;
	for (unsigned int ir = 0; ir < rocks_.size(); ++ir) {
		delete rocks_[ir];
	}
} // Déstructeur

Building::Building(const Building& rhs) : id_(rhs.id_), rocks_(rhs.rocks_) { // right hand side
	std::cout << "Building::Building(Building&), id_ = " <<
		id_ << " at " << this << "with " << rocks_.size() << " rocks" << std::endl;
	for (unsigned int i = 0; i < rocks_.size(); ++i) {
		rocks_[i] = new Rock(*rhs.rocks_[i]);
	}
} // Constructeur par copie

std::ostream& operator<<(std::ostream& out, const Building& rhs) {
	out << "|" << &rhs << " - " << rhs.id_ << " | " << rhs.rocks_.size() << " rocks" << std::endl;
	for (unsigned int i = 0; i < rhs.rocks_.size(); ++i) {
		out << "| " << rhs.rocks_[i] << " |" << std::endl;
	}
	return out;
} // Surchage de l'opérateur << pour l'affichage

Building& Building::operator=(const Building& rhs) {
	std::cout << "Building::Building(" << &rhs << "," <<
		rhs.id_ << "), id_ = " << id_ << " at " << this << std::endl;
	// fait ce que le déstructeur fait
	// fait ce que le constructeur par copie fait
	if (this != &rhs) {
		id_ = rhs.id_;
		for (unsigned int ir = 0; ir < rocks_.size(); ++ir) {
			rocks_[ir] = new Rock(*rhs.rocks_[ir]);
		}
	}
	return *this;
}

/*
const Building::Rock* get_rock(int index) const {
	return rocks_[index];
}*/

bool Building::swap_rock(Building partner, unsigned int this_index, unsigned int partner_index) {
	if (this_index < rocks_.size() && partner_index < partner.rocks_.size()) {
		Rock* tmp = rocks_[this_index];
		rocks_[this_index] = partner.rocks_[partner_index];
		partner.rocks_[partner_index] = tmp;
		return true;
	}
	return false;
}
