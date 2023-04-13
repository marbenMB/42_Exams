#include "Fwoosh.hpp"

Fwoosh::Fwoosh () : ASpell("Fwoosh", "fwooshed") {}
Fwoosh::~Fwoosh () {}

ASpell const	*Fwoosh::clone (void) { return (new Fwoosh()); }