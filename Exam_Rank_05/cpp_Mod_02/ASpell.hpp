#ifndef	_AS_HPP
#define	_AS_HPP

#include <iostream>
#include "ATarget.hpp"

class	ATarget;

class	ASpell
{
	protected :
		std::string	_name;
		std::string	_effects;
	
	public :
		ASpell (std::string name, std::string effect);
		virtual ~ASpell ();
		std::string	const	&getName (void) const;
		std::string	const	&getEffects (void) const;
		virtual	ASpell	*clone (void) const = 0;
		void		launch (ATarget const &target) const;
};

#endif