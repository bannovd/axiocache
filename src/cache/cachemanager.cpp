#include "cachemanager.h"


CacheManager::CacheManager() {

}

std::optional<Entry> CacheManager::GetEntry(const boost::uuids::uuid& id) {
    if (cache_.contains(id)) {
        return std::make_optional<Entry>(cache_[id]);
    }
    return std::nullopt;
}

boost::uuids::uuid CacheManager::NewEntry(const std::string& data) {
    auto id = GenerateEntryId();
    const auto [it_entry, success] =
        cache_.insert(std::make_pair(id, Entry{id, data, std::chrono::system_clock::now()}));
    return id;
}

void CacheManager::DeleteEntry(const boost::uuids::uuid& id) {
    if (cache_.contains(id)) {
        cache_.erase(id);
    }
}

boost::uuids::uuid CacheManager::GenerateEntryId() {
    boost::uuids::random_generator generator;
    return generator();
}
