#include "SpellBook.hpp"

SpellBook::SpellBook () {}
SpellBook::~SpellBook () {}

void	SpellBook::learnSpell (ASpell *spell)
{
	if (spell != NULL)
		_book[spell->getName()] = spell;
}

void	SpellBook::forgetSpell (std::string	const &spellName)
{
	std::map<std::string , ASpell *>::iterator	it = _book.find(spellName);
	if (it != _book.end())
		_book.erase(it);
}

ASpell	*SpellBook::createSpell (std::string const &spellName)
{
	std::map<std::string , ASpell *>::iterator	it = _book.find(spellName);
	if (it != _book.end())
		return it->second->clone();
	return (NULL);
}