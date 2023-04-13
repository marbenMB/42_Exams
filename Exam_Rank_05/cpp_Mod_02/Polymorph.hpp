#ifndef	_PM_HPP
#define	_PM_HPP

#include "ASpell.hpp"

class	Polymorph : public ASpell
{
	public :
		Polymorph ();
		~Polymorph ();
		ASpell	*clone (void) const;
};

#endif