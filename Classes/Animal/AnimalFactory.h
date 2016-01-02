#include <string>
#include <map>
#include <iterator>
#include <string>
#pragma once

// Factory for creating instances of IAnimal
class AnimalFactory
{
private:
	AnimalFactory();
	AnimalFactory(const AnimalFactory &) { }
	AnimalFactory &operator=(const AnimalFactory &) { return *this; }

	typedef std::map<std::string, CreateAnimalFn> FactoryMap;
	FactoryMap m_FactoryMap;
public:
	~AnimalFactory() { m_FactoryMap.clear(); }

	static AnimalFactory *Get()
	{
		static AnimalFactory instance;
		return &instance;
	}

	void Register(const std::string &animalName, CreateAnimalFn pfnCreate);
	IAnimal *CreateAnimal(const std::string &animalName);
};

/*
Animal factory constructor.
Register the types of animals here.
*/
AnimalFactory::AnimalFactory()
{
	Register("Horse", &Horse::Create);
	Register("Cat", &Cat::Create);
	Register("Dog", &Dog::Create);
	Register("Spider", &Spider::Create);
}

void AnimalFactory::Register(const std::string &animalName, CreateAnimalFn pfnCreate)
{
	m_FactoryMap[animalName] = pfnCreate;
}

IAnimal *AnimalFactory::CreateAnimal(const std::string &animalName)
{
	FactoryMap::iterator it = m_FactoryMap.find(animalName);
	if (it != m_FactoryMap.end())
		return it->second();
	return NULL;
}