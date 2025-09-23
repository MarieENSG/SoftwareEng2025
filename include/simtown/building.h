#ifndef building_h
#define building_h


# include <iostream>
# include <simtown/rock.h>
# include <simtown/building.h>
# include <simtown/dynarray.h>

class Rock; // Forward declaration (rock is a type, defined somewhere)

class Building{
	public:
		Building();
		Building(unsigned int id, unsigned int nb_rocks); // Constructeur
		~Building();
		Building(const Building& rhs);
		Building& operator=(const Building& rhs);
		
		// const Rock* get_rock(unsigned int index) const;
		bool swap_rock(Building partner, unsigned int this_index, unsigned int partner_index);

	private:
		friend std::ostream& operator<<(std::ostream& out, const Building& rhs);  
		// friend permet à une fonction d'accéder à id_ même s'il est privé
		int id_;
		DynArray<Rock*> rocks_;
};

#endif