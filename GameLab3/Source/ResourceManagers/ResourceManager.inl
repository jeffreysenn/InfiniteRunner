#include <stdexcept>
#include <cassert>
#include <iostream>
#include "ResourceManager.h"

template<typename ResourceType, typename IdentityType>
ResourceManager<ResourceType, IdentityType>::ResourceManager()
{
}

template<typename ResourceType, typename IdentityType>
ResourceManager<ResourceType, IdentityType>::~ResourceManager()
{
}

template<typename ResourceType, typename IdentityType>
bool ResourceManager<ResourceType, IdentityType>::load(IdentityType id, const std::string &fileName)
{
	std::shared_ptr<ResourceType> resource = std::make_shared<ResourceType>();
	if (!resource->loadFromFile(fileName))
	{
		throw std::runtime_error("ResourceManager::load - Failed to load " + fileName);
		return false;
	}

	return insertResource(id, std::move(resource));
}

template<typename ResourceType, typename IdentityType>
template<typename SecondType>
bool ResourceManager<ResourceType, IdentityType>::load(IdentityType id, const std::string & fileName, const SecondType & secondParam)
{
	std::shared_ptr<ResourceType> resource = std::make_shared<ResourceType>();
	if (!resource->loadFromFile(fileName, secondParam))
	{
		throw std::runtime_error("ResourceManager::load - Failed to load " + fileName);
		return false;
	}

	return insertResource(id, std::move(resource));
}

template<typename ResourceType, typename IdentityType>
std::shared_ptr<ResourceType> ResourceManager<ResourceType, IdentityType>::get(IdentityType id)
{
	auto found = mResourceMap.find(id);
	if (found == mResourceMap.end())
	{
		std::cout << "ResourceManager::get - Failed to get!" << std::endl;
		return nullptr;
	}
	return found->second;
}

template<typename ResourceType, typename IdentityType>
std::shared_ptr<const ResourceType> ResourceManager<ResourceType, IdentityType>::get(IdentityType id) const
{
	auto found = mResourceMap.find(id);
	if (found == mResourceMap.end())
	{
		std::cout << "ResourceManager::get - Failed to get!" << std::endl;
		return nullptr;
	}
	return found->second;
}

template<typename ResourceType, typename IdentityType>
void ResourceManager<ResourceType, IdentityType>::unload(IdentityType id)
{
	auto found = mResourceMap.find(id);
	if (found == mResourceMap.end())
		return;

	// making sure nothing else is still referencing the resource
	assert(found->second.use_count() <= 1);

	mResourceMap.erase(found);
}

template<typename ResourceType, typename IdentityType>
void ResourceManager<ResourceType, IdentityType>::unloadAll()
{
	bool bResourceInUse = false;

	// making sure nothing else is still referencing the resource
	for (auto itor : mResourceMap)
	{
		if ((itor.second).use_count() > 1)
		{
			bResourceInUse = true;
			break;
		}
	}
	assert(!bResourceInUse);

	mResourceMap.clear();
}

template<typename ResourceType, typename IdentityType>
bool ResourceManager<ResourceType, IdentityType>::insertResource(IdentityType id, std::shared_ptr<ResourceType> resource)
{
	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
	return inserted.second;
}