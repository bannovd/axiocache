#ifndef CALLBACKTIMER_H
#define CALLBACKTIMER_H

#include <atomic>
#include <thread>
#include <functional>


class CallbackTimer {
public:
    CallbackTimer()
        :execute_(false) {}

    ~CallbackTimer() {
        if(execute_.load(std::memory_order_acquire) ) {
            Stop();
        };
    }

    void Stop();
    void Start(int msInterval, std::function<void(void)> func);
    bool IsRunning() const noexcept;

private:
    std::atomic<bool> execute_;
    std::thread thd_;
};

#endif // CALLBACKTIMER_H
