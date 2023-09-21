#pragma once

#include "logger_factory.hpp"

class InfoLoggerFactory : public ILoggerFactory{
    public:
        ILogger* createLogger() {
            return new InfoLogger();
        }
};