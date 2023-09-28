#include <iostream>

using namespace std;

// Define the abstract base class for order handlers.
class OrderHandler {
    protected:
        OrderHandler* nextHandler;
    public:
        OrderHandler(OrderHandler* nextHandler) : nextHandler(nextHandler) {}

        virtual void processOrder(const string& order) = 0;
};

// Concrete handler for order validation.
class OrderValidationHandler : public OrderHandler {
    public:
        OrderValidationHandler(OrderHandler* nextHandler) : OrderHandler(nextHandler) {}

        void processOrder(const string& order) {
            cout<<"Validating order: "<<order<<endl;

            if(nextHandler)
                nextHandler->processOrder(order);
        }

        ~OrderValidationHandler() {
            cout<<"validation handler dtor called"<<endl;
        }
};

// Concrete handler for payment processing.
class PaymentProcessingHanlder : public OrderHandler {
    public:
        PaymentProcessingHanlder(OrderHandler* nextHandler) : OrderHandler(nextHandler) {}

        void processOrder(const string& order) {
            cout<<"Processing payment for order: "<<order<<endl;

            if(nextHandler)
                nextHandler->processOrder(order);
        }

        ~PaymentProcessingHanlder() {
            cout<<"PaymentProcessingHanlder dtor called"<<endl;
        }
};

// Concrete handler for order preparation.
class OrderPreparationHandler : public OrderHandler {
    public:
        OrderPreparationHandler(OrderHandler* nexxtHandler) : OrderHandler(nextHandler) {}

        void processOrder(const string& order) {
            cout<<"Preparing order: "<<order<<endl;

            if(nextHandler)
                nextHandler->processOrder(order);
        }
        ~OrderPreparationHandler() {
            cout<<"OrderPreparationHandler dtor called"<<endl;
        }
};

// Concrete handler for delivery assignment.
class DeliveryAssignmentHandler : public OrderHandler {
    public:
        DeliveryAssignmentHandler(OrderHandler* nexxtHandler) : OrderHandler(nextHandler) {}

        void processOrder(const string& order) {
            cout<<"Assigning delivery for order: "<<order<<endl;

            if(nextHandler)
                nextHandler->processOrder(order);
        }

        ~DeliveryAssignmentHandler() {
            cout<<"DeliveryAssignmentHandler dtor called"<<endl;
        }
};

// Concrete handler for order tracking.
class OrderTrackingHandler : public OrderHandler {
    public:
        OrderTrackingHandler(OrderHandler* nexxtHandler) : OrderHandler(nextHandler) {}

        void processOrder(const string& order) {
            cout<<"Tracking order: "<<order<<endl;

            if(nextHandler)
                nextHandler->processOrder(order);
        }

        ~OrderTrackingHandler() {
            cout<<"OrderTrackingHandler dtor called"<<endl;
        }
};

int main() {
    
    // Create a chain of responsibility for order processing
    OrderHandler* orderProcessingChain = 
        new OrderValidationHandler(
            new PaymentProcessingHanlder(
                new OrderPreparationHandler(
                    new DeliveryAssignmentHandler(  
                        new OrderTrackingHandler(nullptr)))));

    // Simulate an order being placed
    string order = "Pizza";
    orderProcessingChain->processOrder(order);

    /*
        OrderHandler* orderTrackingHandler = new OrderTrackingHandler(nullptr);
        OrderHandler* deliveryAssignmentHandler = new DeliveryAssignmentHandler(orderTrackingHandler);
        OrderHandler* orderPreparationHandler = new OrderPreparationHandler(deliveryAssignmentHandler);
        OrderHandler* paymentProcessingHandler = new PaymentProcessingHandler(orderPreparationHandler);
        OrderHandler* orderValidationHandler = new OrderValidationHandler(paymentProcessingHandler);

        // Simulate an order being placed
        std::string order = "Burger and Fries";
        orderValidationHandler->processOrder(order);

        // Clean up by deleting all handler objects
        delete orderValidationHandler;
        delete paymentProcessingHandler;
        delete orderPreparationHandler;
        delete deliveryAssignmentHandler;
        delete orderTrackingHandler;
    
        //Or use shared pointers so that we don't have to handle cleanup
    */

   /*
   //Add setters to choose successor or next handler on run-time
   //Hanlder will have setSuccessor func
    orderValidation.setSuccessor(paymentProcessing);
    paymentProcessing.setSuccessor(shipping);
   */

    return 0;
}