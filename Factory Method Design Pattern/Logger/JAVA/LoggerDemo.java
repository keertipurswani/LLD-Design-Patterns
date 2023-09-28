interface ILogger {
    void log(String msg);
}

class DebugLogger implements ILogger {
    @Override
    public void log(String msg) {
        System.out.println("DEBUG : " + msg);
    }
}

class ErrorLogger implements ILogger {
    @Override
    public void log(String msg) {
        System.out.println("ERROR : " + msg);
    }
}

class InfoLogger implements ILogger {
    @Override
    public void log(String msg) {
        System.out.println("INFO : " + msg);
    }
}

interface LoggerFactory {
    ILogger createLogger();
}

class DebugLoggerFactory implements LoggerFactory {
    @Override
    public ILogger createLogger() {
        return new DebugLogger();
    }
}

class ErrorLoggerFactory implements LoggerFactory {
    @Override
    public ILogger createLogger() {
        return new ErrorLogger();
    }
}

class InfoLoggerFactory implements LoggerFactory {
    @Override
    public ILogger createLogger() {
        return new InfoLogger();
    }
}

public class LoggerDemo {
    public static void main(String[] args) {
        LoggerFactory loggerFactory = new InfoLoggerFactory();
        ILogger logger = loggerFactory.createLogger();

        logger.log("This is an info log message");
    }
}
