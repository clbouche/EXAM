#include <iostream>
#include <string>

class Warlock
{
private:
	std::string		_name;
	std::string		_title;

	Warlock( void );
	Warlock(const Warlock &src);
	Warlock		&operator=(const Warlock &other);
public:
	Warlock(std::string n, std::string t);

	const std::string& getName( void ) const ;
	const std::string& getTitle( void ) const ;

	void			setTitle(std::string t);

	void introduce() const;

	~Warlock();
};



