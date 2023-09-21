package logger;

public class InfoLogger implements Logger {
    public void log(String msg) {
        System.out.println("INFO: " + msg);
    }
}
