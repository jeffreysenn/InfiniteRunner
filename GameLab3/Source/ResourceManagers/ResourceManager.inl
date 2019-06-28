#include <stdexcept>
#include <cassert>
#include <iostream>

template<typename ResourceType, typename IdentityType>
ResourceManager<ResourceType, IdentityType>::ResourceManager()
{
}

template<typename ResourceType, typename IdentityType>
ResourceManager<ResourceType, IdentityType>::~ResourceManager()
{
}

template<typename ResourceType, typename IdentityType>
void ResourceManager<ResourceType, IdentityType>::load(IdentityType id, const std::string &fileName)
{
	std::shared_ptr<ResourceType> resource = std::make_shared<ResourceType>();
	if (!resource->loadFromFile(fileName))
		throw std::runtime_error("ResourceManager::load - Failed to load " + fileName);

	insertResource(id, std::move(resource));
}

template<typename ResourceType, typename IdentityType>
template<typename SecondType>
inline void ResourceManager<ResourceType, IdentityType>::load(IdentityType id, const std::string & fileName, const SecondType & secondParam)
{
	std::shared_ptr<ResourceType> resource = std::make_shared<ResourceType>();
	if (!resource->loadFromFile(fileName, secondParam))
		throw std::runtime_error("ResourceManager::load - Failed to load " + fileName);

	insertResource(id, std::move(resource));
}

template<typename ResourceType, typename IdentityType>
std::shared_ptr<ResourceType> ResourceManager<ResourceType, IdentityType>::get(IdentityType id)
{
	auto found = mResourceMap.find(id);
	if (found != mResourceMap.end())
	{
		return found->second;
	}
	std::cout << "ResourceManager::get - Failed to get!" << std::endl;
	return nullptr;
}

template<typename ResourceType, typename IdentityType>
void ResourceManager<ResourceType, IdentityType>::insertResource(IdentityType id, std::shared_ptr<ResourceType> resource)
{
	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}