
#ifndef	_AT_HPP_
#define	_AT_HPP_

#include <iostream>
#include "ASpell.hpp"

class	ATarget
{
	public :
		ATarget ();
		std::string	const&	getType	(void) const;
		ATarget const virtual	*clone(void) = 0;

	private :
		std::string	_type;
};

#endif