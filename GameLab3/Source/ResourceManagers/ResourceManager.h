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

	bool load(IdentityType id, const std::string &fileName);

	template<typename SecondType>
	bool load(IdentityType id, const std::string &fileName, const SecondType &secondParam);

	std::shared_ptr<ResourceType> get(IdentityType id);

	std::shared_ptr<const ResourceType> get(IdentityType id) const;

	void unload(IdentityType id);

	void unloadAll();

private:
	bool insertResource(IdentityType id, std::shared_ptr<ResourceType> resource);

private:
	std::map<IdentityType, std::shared_ptr<ResourceType>> mResourceMap;
};

#include "ResourceManager.inl"