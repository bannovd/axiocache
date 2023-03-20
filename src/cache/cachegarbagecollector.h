#ifndef CACHEGARBAGECOLLECTOR_H
#define CACHEGARBAGECOLLECTOR_H

#include <memory>
#include "icacheclearstrategy.h"

namespace cache {
    class CacheGarbageCollector {
    public:
        explicit CacheGarbageCollector(std::unique_ptr<ICacheClearStrategy>&& strategy = {})
            : strategy_(std::move(strategy)) {}
        void SetStrategy(std::unique_ptr<ICacheClearStrategy>&& strategy);
        void RemoveGarbage(std::map<boost::uuids::uuid, Entry>& cache);
    private:
        std::unique_ptr<ICacheClearStrategy> strategy_;
    };
}

#endif // CACHEGARBAGECOLLECTOR_H
