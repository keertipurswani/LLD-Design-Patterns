package logger;

public class InfoLogger implements ILogger {
    public void log(String msg) {
        System.out.println("INFO: " + msg);
    }
}
