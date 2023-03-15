#include <iostream>
#include <thread>
#include <boost/uuid/uuid_io.hpp>
#include "cache/cachemanager.h"


using namespace std::chrono_literals;

static std::string timePointAsString(const std::chrono::system_clock::time_point& tp) {
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::string ts = std::ctime(&t);
    ts.resize(ts.size()-1);
    return ts;
}

int main() {
    std::cout << "Test cache app started." << std::endl;

    CacheManager cm;

    std::string str1 = "Цветок";
    std::string str2 = "Река";
    std::string str3 = "Солнце";


    auto entryId1 = cm.NewEntry(str1);
    std::this_thread::sleep_for(1456ms);
    auto entryId2 = cm.NewEntry(str2);
    std::this_thread::sleep_for(1231ms);
    auto entryId3 = cm.NewEntry(str3);

    std::cout << "\nCache data:" << std::endl;
    for (auto entry : cm.GetAllEntries()) {
        std::cout << "id: " << boost::uuids::to_string(entry.id()) << "\t"
                  << "data: " << entry.data() << "\t"
                  << "created at: " << timePointAsString(entry.createdAt()) << "\t"
                  << std::endl;
    }

    std::this_thread::sleep_for(2000ms);

    std::cout << "\nCache data after delete:" << std::endl;
    for (auto entry : cm.GetAllEntries()) {
        std::cout << "id: " << boost::uuids::to_string(entry.id()) << "\t"
                  << "data: " << entry.data() << "\t"
                  << "created at: " << timePointAsString(entry.createdAt()) << "\t"
                  << std::endl;
    }

    //std::cout << "Press Enter to stop..." << std::endl;
    //std::cin.get();

    std::cout << "\nTest cache app finished." << std::endl;
    return 0;
}
