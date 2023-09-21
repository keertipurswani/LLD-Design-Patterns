#pragma once
#include "common.hpp"

class ILogger {
    public:
        virtual void log(const string& msg) = 0;
        virtual ~ILogger() {}
};