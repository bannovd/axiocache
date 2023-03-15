#include <iostream>
#include <thread>
#include <boost/uuid/uuid_io.hpp>
#include "cache/cachemanager.h"


using namespace std::chrono_literals;


int main() {
    std::cout << "Test cacheApp started." << std::endl;

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
        std::cout << entry;
    }

    std::this_thread::sleep_for(2000ms);

    std::cout << "\nCache data after delete:" << std::endl;
    for (auto entry : cm.GetAllEntries()) {
        std::cout << entry;
    }

    auto failEntry = cm.GetEntry(entryId1);
    if (!failEntry.has_value()) {
        std::cout << "\nEntry [id: " << entryId1 << "] not exist" << std::endl;
    }

    std::cout << "\nTest cacheApp finished." << std::endl;
    return 0;
}
