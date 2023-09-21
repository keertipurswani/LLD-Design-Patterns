#pragma once

#include "logger_factory.hpp"

class ErrorLoggerFactory : public ILoggerFactory{
    public:
        ILogger* createLogger() {
            return new ErrorLogger();
        }
};