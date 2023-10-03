// PaymentStrategy interface
interface PaymentStrategy {
    void processPayment(double amount);
}

// Concrete PaymentStrategy classes
class CreditCardPayment implements PaymentStrategy {
    public void processPayment(double amount) {
        System.out.println("Processing credit card payment of $" + amount);
    }
}

class PayPalPayment implements PaymentStrategy {
    public void processPayment(double amount) {
        System.out.println("Processing PayPal payment of $" + amount);
    }
}

class CryptocurrencyPayment implements PaymentStrategy {
    public void processPayment(double amount) {
        System.out.println("Processing cryptocurrency payment of $" + amount);
    }
}

// PaymentStrategyFactory
class PaymentStrategyFactory {
    public static PaymentStrategy createPaymentStrategy(String paymentMethod) {
        if (paymentMethod.equals("CreditCard")) {
            return new CreditCardPayment();
        } else if (paymentMethod.equals("PayPal")) {
            return new PayPalPayment();
        } else if (paymentMethod.equals("Cryptocurrency")) {
            return new CryptocurrencyPayment();
        } else {
            // Default to CreditCardPayment
            return new CreditCardPayment();
        }
    }
}

// PaymentProcessor
class PaymentProcessor {
    private PaymentStrategy paymentStrategy;

    public PaymentProcessor() {
        paymentStrategy = null;
    }

    public void setPaymentStrategy(String paymentMethod) {
        if (paymentStrategy != null) {
            // Clean up the previous strategy
            paymentStrategy = null;
        }
        paymentStrategy = PaymentStrategyFactory.createPaymentStrategy(paymentMethod);
    }

    public void processPayment(double amount) {
        if (paymentStrategy != null) {
            paymentStrategy.processPayment(amount);
        } else {
            System.err.println("Payment strategy not set.");
        }
    }

    public void finalize() {
        if (paymentStrategy != null) {
            // Clean up the strategy instance
            paymentStrategy = null;
        }
    }
}

public class PaymentDemo {
    public static void main(String[] args) {
        PaymentProcessor processor = new PaymentProcessor();

        // Use the factory to create payment strategies
        processor.setPaymentStrategy("CreditCard");
        processor.processPayment(100.0);

        processor.setPaymentStrategy("PayPal");
        processor.processPayment(50.0);
    }
}
