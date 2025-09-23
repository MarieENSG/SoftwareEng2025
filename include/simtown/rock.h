# ifndef rock_h
# define rock_h

# include <iostream>

class Rock {
public:
	Rock();
	~Rock();

private:
	friend std::ostream& operator<<(std::ostream& out, const Rock& rhs);
	static int rock_counter_; // Created once for all Rock instances
	int rid_;
};

# endif