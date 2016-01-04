#include "Header.h"
#pragma once

/*
Instance Factory constructor.
Register the types of Instance here.
*/
InstanceFactory::InstanceFactory()
{
	Register("Node", &Node::Create);
}

void InstanceFactory::Register(const std::string &instanceName, CreateInstanceFn pfnCreate)
{
	m_FactoryMap[instanceName] = pfnCreate;
}

Instance *InstanceFactory::CreateInstance(const std::string &instanceName)
{
	FactoryMap::iterator it = m_FactoryMap.find(instanceName);
	if (it != m_FactoryMap.end())
		return it->second();
	return NULL;
}

