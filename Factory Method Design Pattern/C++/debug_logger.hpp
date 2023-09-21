#pragma once
#include "ilogger.hpp"

class DebugLogger : public ILogger {
    public:
        void log(const string& msg);
};