#pragma once
#include "ilogger.hpp"

class InfoLogger : public ILogger {
    public:
        void log(const string& msg);
};