#include "Dummy.hpp"

Dummy::Dummy () : ATarget("Target Practice Dummy") {}
Dummy::~Dummy() {}

ATarget const	*Dummy::clone (void) { return (new Dummy()); }