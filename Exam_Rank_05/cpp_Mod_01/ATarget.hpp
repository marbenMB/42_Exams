#ifndef	_AT_HPP
#define	_AT_HPP

#include <iostream>
#include "ASpell.hpp"

class	ASpell;

class	ATarget
{
	protected :
		std::string	_type;
	
	public :
		ATarget (std::string type);
		virtual ~ATarget ();
		std::string const	&getType (void) const;
		virtual ATarget const	*clone (void) = 0;
		void	getHitBySpell (ASpell const &spell) const;
};

#endif