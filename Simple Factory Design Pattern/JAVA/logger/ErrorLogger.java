package logger;

public class ErrorLogger implements ILogger {
    public void log(String msg) {
        System.out.println("ERROR: " + msg);
    }
}
