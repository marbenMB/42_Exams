#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator () {}
TargetGenerator::~TargetGenerator () {}

void	TargetGenerator::learnTargetType (ATarget *target)
{
	_book[target->getType()] = target;
}

void	TargetGenerator::forgetTargetType (std::string const &typeName)
{
	std::map<std::string, ATarget *>::iterator	it = _book.find(typeName);

	if (it != _book.end())
		_book.erase(it);
}

ATarget	*TargetGenerator::createTarget (std::string const &typeName)
{
	std::map<std::string, ATarget *>::iterator	it = _book.find(typeName);
	
	if (it != _book.end())
		return it->second->clone();
	return NULL;
}