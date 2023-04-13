#ifndef	_DU_HPP
#define	_DU_HPP

#include "ATarget.hpp"

class	Dummy : public ATarget
{
	public :
		Dummy ();
		~Dummy ();
		ATarget const *clone (void);
};

#endif
