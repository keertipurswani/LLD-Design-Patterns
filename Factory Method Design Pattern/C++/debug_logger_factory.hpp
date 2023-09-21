#pragma once

#include "logger_factory.hpp"

class DebugLoggerFactory : public ILoggerFactory{
    public:
        ILogger* createLogger() {
            return new DebugLogger();
        }
};