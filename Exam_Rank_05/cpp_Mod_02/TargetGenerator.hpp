#ifndef	_TG_HPP
#define	_TG_HPP

#include "ATarget.hpp"
#include <map>

class	TargetGenerator
{
	private :
		std::map<std::string, ATarget *>	_book;

	public :
		TargetGenerator ();
		~TargetGenerator ();
		void	learnTargetType (ATarget *target);
		void	forgetTargetType(std::string const &typeName);
		ATarget*	createTarget(std::string const &typeName);
};

#endif