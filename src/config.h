#ifndef CONFIG_H
#define CONFIG_H


class Config {
public:
    Config() = delete;
    static const int TIME_TO_LIVE_ENTRY = 3000;
    static const int TIMER_INTERVAL = 1000;
};

#endif // CONFIG_H
