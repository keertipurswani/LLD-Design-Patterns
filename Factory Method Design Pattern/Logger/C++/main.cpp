#include "info_logger_factory.hpp"
#include "debug_logger_factory.hpp"
#include "error_logger_factory.hpp"

int main() {
    ILoggerFactory* loggerFactory1 = new InfoLoggerFactory;
    ILogger* infoLogger = loggerFactory1->createLogger();

    ILoggerFactory* loggerFactory2 = new ErrorLoggerFactory;
    ILogger* errorLogger = loggerFactory2->createLogger();

    ILoggerFactory* loggerFactory3 = new DebugLoggerFactory;
    ILogger* debugLogger = loggerFactory3->createLogger();

    debugLogger->log("This is a debug log msg");
    infoLogger->log("This is an info log msg");
    errorLogger->log("This is an error log msg");

    delete debugLogger;
    delete infoLogger;
    delete errorLogger;

    return 0;
}