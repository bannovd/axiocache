#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

#include <map>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <optional>
#include <chrono>

#include "entry.h"
#include "../callbacktimer.h"


class CacheManager {
public:
    CacheManager();
    std::optional<Entry> GetEntry(const boost::uuids::uuid& id);
    boost::uuids::uuid NewEntry(const std::string& data);
    void DeleteEntry(const boost::uuids::uuid& id);    
    std::vector<Entry> GetAllEntries();
private:
    boost::uuids::uuid GenerateEntryId();
    void ClearOldEntries();

    std::map<boost::uuids::uuid, Entry> cache_;
    CallbackTimer timer;
};

#endif // CACHEMANAGER_H
