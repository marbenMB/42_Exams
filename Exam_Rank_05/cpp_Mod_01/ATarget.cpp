#include "ATarget.hpp"

ATarget::ATarget (std::string type) : _type(type) {}
ATarget::~ATarget () {}

std::string const	&ATarget::getType (void) const { return _type; }

void	ATarget::getHitBySpell (ASpell const &spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}