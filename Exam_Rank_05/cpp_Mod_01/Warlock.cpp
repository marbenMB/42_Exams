
#include "Warlock.hpp"

Warlock::Warlock (std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << _name << ": " << "This looks like another boring day." << std::endl;
}

Warlock::~Warlock (void)
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const&	Warlock::getName (void) const
{
	return _name;
}

std::string const&	Warlock::getTitle (void) const
{
	return _title;
}

void	Warlock::setTitle (std::string const &tl)
{
	_title = tl;
}

void	Warlock::introduce (void) const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell (ASpell *spell)
{
	if (spell != NULL)
		_war[spell->getName()] = spell;
}

void	Warlock::forgetSpell (std::string spellName)
{
	std::map<std::string, ASpell *>::iterator	it = _war.find(spellName);

	if (it != _war.end())
		_war.erase(it);
}

void	Warlock::launchSpell (std::string spellName, ATarget &target)
{
	std::map<std::string, ASpell *>::iterator	it = _war.find(spellName);

	if (it != _war.end())
		it->second->launch(target);
}