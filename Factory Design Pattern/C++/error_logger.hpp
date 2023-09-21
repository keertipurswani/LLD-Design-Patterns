#pragma once
#include "ilogger.hpp"

class ErrorLogger : public ILogger{
    public:
        void log(const string& msg);
};