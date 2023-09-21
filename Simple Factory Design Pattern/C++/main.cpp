#include "logger_factory.hpp"

int main() {
    ILogger* debugLogger = LoggerFactory::createLogger(LogLevel::DEBUG);
    ILogger* infoLogger = LoggerFactory::createLogger(LogLevel::INFO);
    ILogger* errorLogger = LoggerFactory::createLogger(LogLevel::ERROR);

    debugLogger->log("This is a debug log msg");
    infoLogger->log("This is an info log msg");
    errorLogger->log("This is an error log msg");

    delete debugLogger;
    delete infoLogger;
    delete errorLogger;

    return 0;
}