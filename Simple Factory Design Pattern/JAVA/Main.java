import logger.*;


public class Main {
    public static void main(String[] args) {
        Logger debugLogger = LoggerFactory.createLogger(LogLevel.DEBUG);
        Logger infoLogger = LoggerFactory.createLogger(LogLevel.INFO);
        Logger errorLogger = LoggerFactory.createLogger(LogLevel.ERROR);

        debugLogger.log("This is a debug log msg");
        infoLogger.log("This is an info log msg");
        errorLogger.log("This is an error log msg");
    }
}
