#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "TEResource.h"
#include "TEResourceHandle.h"

#include <cassert>
#include <map>

namespace TE::IO {
  class DatFile;
}

namespace TE::Resources {
  template <typename ResourceT> class ResourceManager {
  public:
    enum {
      UNREGISTER_EXPLICIT,
      UNREGISTER_REFCOUNTZERO_UNLOAD,
      UNREGISTER_REFCOUNTZERO_UNREGISTER
    };

    ResourceManager(IO::FileIO &fileIO);
    ~ResourceManager();

    ResourceHandle<ResourceT> AddResource(ResourceT &resource, bool lazyLoad = false);
    ResourceHandle<ResourceT> GetResourceHandle(const std::string &filePath);
    void RemoveResource(const std::string &filePath);
    bool IsRegistered(const std::string &filePath);
    void Clear();
    void CleanupNoneReferenced();

  private:
    using ResourceTMap = std::map<std::string, ResourceT>;

    ResourceTMap m_resources;
    IO::FileIO &m_fileIO;
  };

  template <typename ResourceT> ResourceManager<ResourceT>::ResourceManager(IO::FileIO &fileIO)
      : m_fileIO(fileIO) {}

  template <typename ResourceT> ResourceManager<ResourceT>::~ResourceManager() {}

  template <typename ResourceT> ResourceHandle<ResourceT>
  ResourceManager<ResourceT>::AddResource(ResourceT &resource, bool lazyLoad) {
    assert(m_resources.find(resource.GetFilePath()) == m_resources.end());

    auto itr =
        m_resources.insert(std::make_pair(resource.GetFilePath(), std::move(resource))).first;

    if (!lazyLoad) {
      itr->second.Load(m_fileIO);
    }

    return ResourceHandle<ResourceT>(itr->second);
  }

  template <typename ResourceT> ResourceHandle<ResourceT>
  ResourceManager<ResourceT>::GetResourceHandle(const std::string &filePath) {
    assert(m_resources.find(filePath) != m_resources.end());

    auto itr = m_resources.find(filePath);

    if (!itr->second.IsLoaded()) {
      itr->second.Load(m_fileIO);
    }

    return ResourceHandle<ResourceT>(itr->second);
  }

  template <typename ResourceT>
  void ResourceManager<ResourceT>::RemoveResource(const std::string &filePath) {
    auto itr = m_resources.find(filePath);

    if (itr->second.IsLoaded()) {
      itr->second.Unload();
    }

    m_resources.erase(itr);
  }

  template <typename ResourceT>
  bool ResourceManager<ResourceT>::IsRegistered(const std::string &filePath) {
    return m_resources.find(filePath) != m_resources.end();
  }

  template <typename ResourceT> void ResourceManager<ResourceT>::Clear() {
    for (auto &itr : m_resources) {
      itr.second.Unload();
    }

    m_resources.clear();
  }

  template <typename ResourceT> void ResourceManager<ResourceT>::CleanupNoneReferenced() {
    // TODO: loop through all and unload those with zero reference count
  }
}

#endif
