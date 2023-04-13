
#ifndef	_HPP_
#define _HPP_

#include <iostream>

class	Warlock
{
	private :
		std::string	_name;
		std::string	_title;
	public :
		Warlock (std::string name, std::string title);
		~Warlock ();
		std::string	const&	getName		(void) const;
		std::string	const&	getTitle	(void) const;
		void				setTitle	(std::string const &tl);
		void				introduce	(void) const;
};

#endif