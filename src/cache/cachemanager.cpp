#include "cachemanager.h"


CacheManager::CacheManager() {
    timer.Start(Config::TIMER_INTERVAL, std::bind(&CacheManager::ClearOldEntries, this));
}

std::optional<Entry> CacheManager::GetEntry(const boost::uuids::uuid& id) {
    if (cache_.contains(id)) {
        return std::make_optional(cache_[id]);
    }
    return std::nullopt;
}

boost::uuids::uuid CacheManager::NewEntry(const std::string& data) {
    boost::uuids::uuid id = GenerateEntryId();
    Entry newEntry(id, data, std::chrono::high_resolution_clock::now());
    cache_[id] = newEntry;
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

std::vector<Entry> CacheManager::GetAllEntries() {
    std::vector<Entry> entries;
    for (auto entryPair : cache_) {
        entries.push_back(entryPair.second);
    }
    return entries;
}

void CacheManager::ClearOldEntries() {
    std::erase_if(cache_, [&] (auto entry) {
        return (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()
                                                          - entry.second.createdAt).count()) > Config::TIME_TO_LIVE_ENTRY;
    });
}
