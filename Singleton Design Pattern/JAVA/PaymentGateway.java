import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class PaymentGatewayManager {

    private PaymentGatewayManager() {
        System.out.println("Payment Gateway Manager initialized.");
    }

    private static PaymentGatewayManager instance;

    private static Lock mtx = new ReentrantLock();

    public static PaymentGatewayManager getInstance() {
        if (instance == null) { // First check without locking
            mtx.lock(); // Acquire the lock before creating the instance
            try {
                if (instance == null) { // Double-checked locking
                    instance = new PaymentGatewayManager();
                }
            } finally {
                mtx.unlock(); // Always release the lock
            }
        }
        return instance;
    }

    public void processPayment(double amount) {
        System.out.println("Processing payment of $" + amount + " through the payment gateway.");
    }

}

public class PaymentGateway {
    public static void main(String[] args) {

        PaymentGatewayManager paymentGateway = PaymentGatewayManager.getInstance();

        paymentGateway.processPayment(100.0);

        // Attempt to create another instance (should return the existing instance)
        PaymentGatewayManager anotherPaymentGateway = PaymentGatewayManager.getInstance();

        // Check if both instances are the same.
        if (paymentGateway == anotherPaymentGateway) {
            System.out.println("Both instances are the same. Singleton pattern is working.");
        } else {
            System.out.println("Singleton pattern is not working correctly.");
        }
    }
}
