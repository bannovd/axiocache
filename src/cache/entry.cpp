#include "entry.h"

std::ostream& operator<<(std::ostream& out, const Entry& entry) {
    out << "id: " << boost::uuids::to_string(entry.id) << "\t"
        << "data: " << entry.data << "\t"
        << "created at: " << timePointAsString(entry.createdAt) << "\t"
        << std::endl;
    return out;
}

static std::string timePointAsString(const std::chrono::system_clock::time_point& tp) {
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::string ts = std::ctime(&t);
    ts.resize(ts.size()-1);
    return ts;
}
