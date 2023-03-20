#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <functional>
#include <iomanip>


enum class LogLevel {
    TRACE = 0,
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    OFF
};

class StreamDelegate {
public:
    StreamDelegate(std::ostream& out, std::function<void(std::ostream&)> endlineStrategy);
    ~StreamDelegate();
    StreamDelegate(const StreamDelegate&) = delete;
    StreamDelegate& operator=(const StreamDelegate&) = delete;
    StreamDelegate(StreamDelegate&&) = default;
    StreamDelegate& operator=(StreamDelegate&&) = default;
    template<class T>
    inline StreamDelegate& operator<<(T&& out) {
        out_ << std::forward<T>(out);
        return *this;
    }
private:
    std::function<void(std::ostream&)> endline_;
    std::ostream& out_;
};

class Logger {
public:
    static Logger& Instance(LogLevel globalLogLevel = LogLevel::OFF, std::ostream& out = std::cout);
    ~Logger();
    Logger(Logger const&) = delete;
    void operator = (Logger const&) = delete;
    StreamDelegate Log(LogLevel level);
    LogLevel GetGlobalLogLevel();
protected:
    void TimeStamp();
    void LogLevelStamp(LogLevel level);
    std::function<void(std::ostream&)> EndlineStrategy(LogLevel level);
    std::string LogLevelString(LogLevel level);
private:
    Logger();
    Logger(LogLevel globalLogLevel, std::ostream& out);
    std::ostream& logStream_;
    const LogLevel globalLogLevel_;
};

#define LOGGER_INIT(globalLogLevel, out) Logger::Instance(globalLogLevel, out);
#define LOG(level) if(Logger::Instance().GetGlobalLogLevel() <= (level) && (level) < LogLevel::OFF) Logger::Instance().Log(level)


#endif // LOGGER_H
