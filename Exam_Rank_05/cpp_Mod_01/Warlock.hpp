
#ifndef	_HPP_
#define _HPP_

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class	ASpell;
class	ATarget;

class	Warlock
{
	private :
		std::string	_name;
		std::string	_title;
		std::map<std::string, ASpell *>	_war;
	public :
		Warlock (std::string const &name, std::string const &title);
		~Warlock ();
		std::string	const&	getName		(void) const;
		std::string	const&	getTitle	(void) const;
		void				setTitle	(std::string const &tl);
		void				introduce	(void) const;
		void				learnSpell	(ASpell *spell);
		void				forgetSpell	(std::string spellName);
		void				launchSpell	(std::string spellName, ATarget &target);
};

#endif