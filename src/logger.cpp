#include "logger.h"


Logger & Logger::Instance(LogLevel globalLogLevel, std::ostream& out) {
    static Logger instance(globalLogLevel, out);
    return instance;
}

Logger::~Logger() {
}

StreamDelegate Logger::Log(LogLevel level) {
    TimeStamp();
    LogLevelStamp(level);
    return StreamDelegate(logStream_, EndlineStrategy(level));
}

LogLevel Logger::GetGlobalLogLevel() {
    return globalLogLevel_;
}

void Logger::LogLevelStamp(LogLevel level) {
    logStream_ << std::setw(7) << LogLevelString(level) + "\t";
}

void Logger::TimeStamp() {
    logStream_ << __TIME__ << " ";
}

std::string Logger::LogLevelString(LogLevel level) {
    switch (level) {
        case LogLevel::TRACE: return "[TRACE]";
        case LogLevel::DEBUG: return "[DEBUG]";
        case LogLevel::INFO:  return "[INFO]";
        case LogLevel::WARNING: return "[WARNINIG]";
        case LogLevel::ERROR: return "[ERROR]";
        case LogLevel::OFF: break;
        default: break;
    }
}

std::function<void(std::ostream&)> Logger::EndlineStrategy(LogLevel level) {
    std::function<void(std::ostream&)> endlineNoFlush = [](std::ostream& out) {out << "\n"; };
    std::function<void(std::ostream&)> endlineFlush = [](std::ostream& out) {out << std::endl; };
    switch (level) {
        case LogLevel::TRACE: return endlineNoFlush;
        case LogLevel::DEBUG: return endlineNoFlush;
        case LogLevel::INFO:   return endlineNoFlush;
        case LogLevel::WARNING: return endlineFlush;
        case LogLevel::ERROR: return endlineFlush;
        case LogLevel::OFF: break;
        default: break;
    }
}

Logger::Logger(LogLevel globalLogLevel, std::ostream& out)
    : globalLogLevel_(globalLogLevel), logStream_(out) {}

StreamDelegate::StreamDelegate(std::ostream& out, std::function<void(std::ostream&)> endline)
    : out_(out), endline_(endline) {}

StreamDelegate::~StreamDelegate() {
    endline_(out_);
}
