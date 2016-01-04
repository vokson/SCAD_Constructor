#pragma once

/* Factory for creation of Instance objects */
class InstanceFactory
{
private:
	InstanceFactory();
	InstanceFactory(const InstanceFactory &) { }
	InstanceFactory &operator=(const InstanceFactory &) { return *this; }

	typedef std::map<std::string, CreateInstanceFn> FactoryMap;
	FactoryMap m_FactoryMap;
public:
	~InstanceFactory() { m_FactoryMap.clear(); }

	static InstanceFactory *Get()
	{
		static InstanceFactory instance;
		return &instance;
	}

	void Register(const std::string &InstanceName, CreateInstanceFn pfnCreate);
	Instance *CreateInstance(const std::string &InstanceName);
};