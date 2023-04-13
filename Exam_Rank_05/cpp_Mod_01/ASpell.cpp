#include "ASpell.hpp"

ASpell::ASpell (std::string name, std::string effect) : _name(name), _effects(effect) {}
ASpell::~ASpell () {}

std::string const	&ASpell::getName (void) const { return _name; }
std::string const	&ASpell::getEffects (void) const { return _effects; }

void	ASpell::launch (ATarget const &target) const
{
	target.getHitBySpell(*this);
}