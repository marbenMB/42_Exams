
#ifndef	_HPP_
#define _HPP_

#include <iostream>

class	Warlock
{
	public :
		Warlock (std::string name, std::string titel);
		~Warlock ();
		std::string	const&	getName	(void) const;
		std::string	const&	getTitle	(void) const;
		void				setTitle	(std::string const &tl);
		void				introduce	(void) const;
	private :
		std::string	_name;
		std::string	_title;
		Warlock ();
		Warlock (Warlock const& obj);
		Warlock	&operator=	(Warlock const&	obj);
};

#endif