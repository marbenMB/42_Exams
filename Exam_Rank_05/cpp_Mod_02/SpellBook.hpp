#ifndef	_SB_HPP
#define	_SB_HPP

#include "ASpell.hpp"
#include "map"

class	SpellBook
{
	private :
		std::map<std::string, ASpell *>	_book;
	public :
		SpellBook ();
		~SpellBook ();
		void	learnSpell(ASpell *spell);
		void 	forgetSpell(std::string const &spellName);
		ASpell*	createSpell(std::string const &spellName);
};

#endif