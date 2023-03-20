#include "callbacktimer.h"


void CallbackTimer::Stop() {
    execute_.store(false, std::memory_order_release);
    if (thd_.joinable()) {
        thd_.join();
    }
}

void CallbackTimer::Start(int intervalMs, std::function<void(void)> func) {
    if (execute_.load(std::memory_order_acquire)) {
        Stop();
    }
    execute_.store(true, std::memory_order_release);
    thd_ = std::thread([this, intervalMs, func]() {
        while (execute_.load(std::memory_order_acquire)) {
            func();
            std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));
        }
    });
}

bool CallbackTimer::IsRunning() const noexcept {
    return (execute_.load(std::memory_order_acquire) && thd_.joinable());
}
