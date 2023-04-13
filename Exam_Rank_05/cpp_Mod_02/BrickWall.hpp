#ifndef	_BW_HPP
#define	_BW_HPP

#include "ATarget.hpp"

class	BrickWall : public ATarget
{
	public :
		BrickWall ();
		~BrickWall ();
		ATarget *clone (void) const;
};

#endif