package logger;

public class DebugLogger implements Logger {
    public void log(String msg) {
        System.out.println("DEBUG: " + msg);
    }
}
