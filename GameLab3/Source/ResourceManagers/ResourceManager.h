#pragma once

#include <map>
#include <memory>
#include <string>

template<typename ResourceType, typename IdentityType>
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void load(IdentityType id, const std::string &fileName);

	std::shared_ptr<ResourceType> get(IdentityType id);

	template<typename SecondType>
	void load(IdentityType id, const std::string &fileName, const SecondType &secondParam);

private:
	void insertResource(IdentityType id, std::shared_ptr<ResourceType> resource);

private:
	std::map<IdentityType, std::shared_ptr<ResourceType>> mResourceMap;
};

#include "ResourceManager.inl"