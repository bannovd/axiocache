#include <iostream>
#include <thread>
#include <boost/uuid/uuid_io.hpp>
#include <boost/log/expressions.hpp>
#include "cache/cachemanager.h"
#include "logger.h"


using namespace std::chrono_literals;


int main() {
    std::cout << "Test cacheApp started." << std::endl;
    LOGGER_INIT(LogLevel::DEBUG, std::cout);

    cache::CacheManager cm;

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
        LOG(LogLevel::DEBUG) << entry;
    }

    auto entry1 = cm.GetEntry(entryId1);
    std::cout << "\nGet entry:" << std::endl;
    if (!entry1.has_value()) {
        LOG(LogLevel::WARNING) << "Entry Id: <" << entryId1 << "> not exist";
    } else {
        LOG(LogLevel::DEBUG) << entry1.value();
    }

    std::this_thread::sleep_for(1000ms);
    std::cout << "\nCache data after delete 1s:" << std::endl;
    for (auto entry : cm.GetAllEntries()) {
        LOG(LogLevel::DEBUG) << entry;
    }

    std::this_thread::sleep_for(2000ms);
    std::cout << "\nCache data after delete 2s:" << std::endl;
    for (auto entry : cm.GetAllEntries()) {
        LOG(LogLevel::DEBUG) << entry;
    }

    std::cout << "\nTest cacheApp finished." << std::endl;
    return 0;
}
