package logger;

public class DebugLogger implements ILogger {
    public void log(String msg) {
        System.out.println("DEBUG: " + msg);
    }
}
