#include <iostream>
using namespace std;

// PaymentStrategy interface
class PaymentStrategy {
public:
    virtual ~PaymentStrategy() {}
    virtual void processPayment(double amount) = 0;
};

// Concrete PaymentStrategy classes
class CreditCardPayment : public PaymentStrategy {
public:
    void processPayment(double amount) override {
        cout << "Processing credit card payment of $" << amount << endl;
    }
};

class PayPalPayment : public PaymentStrategy {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal payment of $" << amount << endl;
    }
};

class CryptocurrencyPayment : public PaymentStrategy {
public:
    void processPayment(double amount) override {
        cout << "Processing cryptocurrency payment of $" << amount << endl;
    }
};

// PaymentStrategyFactory
class PaymentStrategyFactory {
public:
    static PaymentStrategy* createPaymentStrategy(const string& paymentMethod) {
        if (paymentMethod == "CreditCard") {
            return new CreditCardPayment();
        } else if (paymentMethod == "PayPal") {
            return new PayPalPayment();
        } else if (paymentMethod == "Cryptocurrency") {
            return new CryptocurrencyPayment();
        } else {
            //default
            return new CreditCardPayment();
        }
    }
};

// PaymentProcessor
class PaymentProcessor {
private:
    PaymentStrategy* paymentStrategy;

public:
    PaymentProcessor() : paymentStrategy(nullptr) {}

    void setPaymentStrategy(const string& paymentMethod) {
        if (paymentStrategy) {
            delete paymentStrategy; // Clean up the previous strategy
        }
        paymentStrategy = PaymentStrategyFactory::createPaymentStrategy(paymentMethod);
    }

    void processPayment(double amount) {
        if (paymentStrategy) {
            paymentStrategy->processPayment(amount);
        } else {
            cerr << "Payment strategy not set." << endl;
        }
    }

    ~PaymentProcessor() {
        if (paymentStrategy) {
            delete paymentStrategy; // Clean up the strategy instance
        }
    }
};

int main() {
    PaymentProcessor processor;

    // Use the factory to create payment strategies
    processor.setPaymentStrategy("CreditCard");
    processor.processPayment(100.0);

    processor.setPaymentStrategy("PayPal");
    processor.processPayment(50.0);

    return 0;
}
