#ifndef ICACHECLEARSTRATEGY_H
#define ICACHECLEARSTRATEGY_H

#include <boost/uuid/uuid.hpp>
#include <map>
#include "entry.h"

namespace cache {
    class ICacheClearStrategy {
    public:
        virtual ~ICacheClearStrategy() = default;
        virtual void Clear(std::map<boost::uuids::uuid, Entry>& cache) = 0;
    };
}

#endif // ICACHECLEARSTRATEGY_H
