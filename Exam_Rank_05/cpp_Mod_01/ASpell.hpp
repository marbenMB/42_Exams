
#ifndef	_AS_HPP_
#define	_AS_HPP_

#include <iostream>

class	ASpell
{

	public :
		ASpell (std::string name, std::string effects);
		std::string	const	&getName	(void) const;
		std::string	const	&getEffects	(void) const;
		ASpell const virtual	*clone(void) = 0;

	protected :
		std::string	_name;
		std::string	_effects;
	
	private :
		ASpell	();
		ASpell	(ASpell const &obj);
		ASpell	&operator= (ASpell const &obj);
};

#endif