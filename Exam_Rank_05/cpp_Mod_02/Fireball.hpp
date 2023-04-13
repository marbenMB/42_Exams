#ifndef	_FR_HPP
#define	_FR_HPP

#include "ASpell.hpp"

class	Fireball : public ASpell
{
	public :
		Fireball ();
		~Fireball ();
		ASpell	*clone (void) const;
};

#endif