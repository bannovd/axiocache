#include "cachemanager.h"


CacheManager::CacheManager() {
    gc_.SetStrategy(std::make_unique<ExpiredTtlStrategy>());
    timer_.Start(Config::TIMER_INTERVAL, [&] () {gc_.RemoveGarbage(cache_);});
}

std::optional<Entry> CacheManager::GetEntry(const boost::uuids::uuid &id) {
    if (cache_.contains(id)) {
        return std::make_optional(cache_[id]);
    }
    return std::nullopt;
}

boost::uuids::uuid CacheManager::NewEntry(const std::string &data) {
    boost::uuids::uuid id = GenerateEntryId();
    Entry newEntry(id, data, std::chrono::high_resolution_clock::now());
    cache_[id] = newEntry;
    return id;
}

void CacheManager::DeleteEntry(const boost::uuids::uuid &id) {
    if (cache_.contains(id)) {
        cache_.erase(id);
    }
}

boost::uuids::uuid CacheManager::GenerateEntryId() {
    boost::uuids::random_generator generator;
    return generator();
}

std::vector<Entry> CacheManager::GetAllEntries() {
    std::vector<Entry> entries;
    for (auto entryPair : cache_) {
        entries.push_back(entryPair.second);
    }
    return entries;
}
