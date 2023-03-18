#include "cachegarbagecollector.h"

void CacheGarbageCollector::SetStrategy(std::unique_ptr<ICacheClearStrategy> &&strategy) {
    strategy_ = std::move(strategy);
}

void CacheGarbageCollector::RemoveGarbage(std::map<boost::uuids::uuid, Entry> &cache) {
    strategy_->Clear(cache);
}
