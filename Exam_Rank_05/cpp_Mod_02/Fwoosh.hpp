#ifndef	_FW_HPP
#define	_FW_HPP

#include "ASpell.hpp"

class	Fwoosh : public ASpell
{
	public :
		Fwoosh ();
		~Fwoosh ();
		ASpell	*clone (void) const;
};

#endif