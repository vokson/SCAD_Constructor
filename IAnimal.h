#include <iostream>
#pragma once

class IAnimal
{
public:
	virtual int GetNumberOfLegs() const = 0;
	virtual void Speak() = 0;
	virtual void Free() = 0;
};

typedef IAnimal* (__stdcall *CreateAnimalFn)(void);



// IAnimal implementations
class Cat : public IAnimal
{
public:
	int GetNumberOfLegs() const { return 4; }
	void Speak() { std::cout << "Meow" << std::endl; }
	void Free() { delete this; }

	static IAnimal * __stdcall Create() { return new Cat(); }
};

class Dog : public IAnimal
{
public:
	int GetNumberOfLegs() const { return 4; }
	void Speak() { std::cout << "Woof" << std::endl; }
	void Free() { delete this; }

	static IAnimal * __stdcall Create() { return new Dog(); }
};

class Spider : public IAnimal // Yeah it isn’t really an animal…
{
public:
	int GetNumberOfLegs() const { return 8; }
	void Speak() { std::cout << std::endl; }
	void Free() { delete this; }

	static IAnimal * __stdcall Create() { return new Spider(); }
};

class Horse : public IAnimal
{
public:
	int GetNumberOfLegs() const { return 4; }
	void Speak() { std::cout << "A horse is a horse, of course, of course." << std::endl; }
	void Free() { delete this; }

	static IAnimal * __stdcall Create() { return new Horse(); }
};