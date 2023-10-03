#include <iostream>
using namespace std;

class PaymentStrategy {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

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

class PaymentProcessor {
private:
    PaymentStrategy* paymentStrategy;

public:
    PaymentProcessor() : paymentStrategy(nullptr) {}

    void setPaymentStrategy(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
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

    // Select and set the payment strategy at runtime
    PaymentStrategy* strategy = new CreditCardPayment();
    processor.setPaymentStrategy(strategy);

    // Process the payment
    processor.processPayment(100.0);

    // Change the payment strategy
    delete strategy; // Clean up the previous strategy
    strategy = new PayPalPayment();
    processor.setPaymentStrategy(strategy);

    // Process another payment using the new strategy
    processor.processPayment(50.0);

    // Clean up
    delete strategy;

    return 0;
}
