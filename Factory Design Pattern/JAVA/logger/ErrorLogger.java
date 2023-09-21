package logger;

public class ErrorLogger implements Logger {
    public void log(String msg) {
        System.out.println("ERROR: " + msg);
    }
}
