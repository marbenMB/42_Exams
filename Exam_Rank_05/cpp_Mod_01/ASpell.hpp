
#ifndef	_A_HPP_
#define	_A_HPP_

#include <iostream>

class	ASpell
{

	public :
		ASpell (std::string name, std::string effects);
		std::string	const	&getName	(void) const;
		std::string	const	&getEffects	(void) const;
		ASpell const*		clone	(void);

	protected :
		std::string	_name;
		std::string	_effects;
}

#endif