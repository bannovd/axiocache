#ifndef ENTRY_H
#define ENTRY_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <string>
#include <chrono>

namespace cache {
    struct Entry {
    public:
        Entry() = default;
        Entry(boost::uuids::uuid id_, std::string data_, std::chrono::time_point<std::chrono::system_clock> createdAt_)
            : id(id_), data(data_), createdAt(createdAt_) {}
        Entry(const Entry& other)
        : id(other.id), data(other.data), createdAt(other.createdAt) {}

        boost::uuids::uuid id;
        std::string data;
        std::chrono::time_point<std::chrono::system_clock> createdAt;
    };
}

std::ostream& operator<<(std::ostream& out, const cache::Entry& entry);
static std::string timePointAsString(const std::chrono::system_clock::time_point& tp);

#endif // ENTRY_H
