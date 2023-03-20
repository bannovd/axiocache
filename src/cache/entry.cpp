#include "entry.h"


std::ostream& operator<<(std::ostream& out, const cache::Entry& entry) {
    out << "Id: <" << boost::uuids::to_string(entry.id) << ">\t"
        << "Data: <" << entry.data << ">\t"
        << "Created at: <" <<timePointAsString(entry.createdAt) << ">\t";
    return out;
}

static std::string timePointAsString(const std::chrono::system_clock::time_point& tp) {
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::string ts = std::ctime(&t);
    ts.resize(ts.size() - 1);
    return ts;
}
