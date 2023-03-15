#ifndef ENTRY_H
#define ENTRY_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <string>
#include <chrono>

class Entry {
public:
    Entry() = default;
    Entry(boost::uuids::uuid id, std::string data, std::chrono::time_point<std::chrono::system_clock> createdAt)
        : id_(id), data_(data), createdAt_(createdAt) {}
    Entry(const Entry& other)
    : id_(other.id_), data_(other.data_), createdAt_(other.createdAt_) {}
   /* Entry(Entry&& other)
        : id_(std::move(other.id_)), data_(std::move(other.data_)), createdAt_(std::move(other.createdAt_)) {
        other.id_ = boost::uuids::nil_uuid();
        other.data_.clear();
    }
*/
    const boost::uuids::uuid id() noexcept;
    const std::string data() noexcept;
    const std::chrono::time_point<std::chrono::system_clock> createdAt() noexcept;
private:
    boost::uuids::uuid id_;
    std::string data_;
    std::chrono::time_point<std::chrono::system_clock> createdAt_;
};

#endif // ENTRY_H
