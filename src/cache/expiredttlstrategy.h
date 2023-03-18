#ifndef EXPIREDTTLSTRATEGY_H
#define EXPIREDTTLSTRATEGY_H

#include "icacheclearstrategy.h"
#include "../config.h"


class ExpiredTtlStrategy : public ICacheClearStrategy {
public:
    void Clear(std::map<boost::uuids::uuid, Entry> &cache) override {
        std::erase_if(cache, [&] (auto entry) {
            return (std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()
                                                              - entry.second.createdAt).count()) > Config::TIME_TO_LIVE_ENTRY;
        });
    }
};

#endif // EXPIREDTTLSTRATEGY_H
