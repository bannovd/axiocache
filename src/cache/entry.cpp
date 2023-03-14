#include "entry.h"

const boost::uuids::uuid Entry::id() noexcept {
    return id_;
}

const std::string Entry::data() noexcept {
    return data_;
}

const std::chrono::time_point<std::chrono::system_clock> Entry::createdAt() noexcept {
    return createdAt_;
}
