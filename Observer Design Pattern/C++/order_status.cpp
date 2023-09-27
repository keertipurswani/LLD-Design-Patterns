#include <iostream>
using namespace std;

class Order;

// Observer interface
class Observer
{
public:
    virtual void update(Order *order) = 0;
};

// Concrete Observer: Customer
class Customer : public Observer
{
private:
    string name;

public:
    Customer(string name) : name(name) {}

    void update(Order *order);
};

// Concrete Observer: Restaurant
class Restaurant : public Observer
{
private:
    string restaurantName;

public:
    Restaurant(string name) : restaurantName(name) {}

    void update(Order *order);
};

// Concrete Observer: DeliveryDriver
class DeliveryDriver : public Observer
{
private:
    string driverName;

public:
    DeliveryDriver(string name) : driverName(name) {}

    void update(Order *order);
};

// Concrete Observer: CallCenter
class CallCenter : public Observer
{
public:
    void update(Order *order);
};

// Subject: Order
class Order
{
private:
    int id;
    string status;
    vector<Observer *> observers;

public:
    Order(int id) : id(id), status("Order Placed") {}

    int getId()
    {
        return id;
    }

    string getStatus()
    {
        return status;
    }

    void setStatus(string newStatus)
    {
        status = newStatus;
        notifyObservers();
    }

    void attach(Observer *observer)
    {
        observers.push_back(observer);
    }

    void detach(Observer *observer)
    {
        for (auto it = observers.begin(); it != observers.end(); ++it)
        {
            if (*it == observer)
            {
                observers.erase(it);
                break; // Assuming each observer can be attached only once
            }
        }
    }

    void notifyObservers()
    {
        for (Observer *observer : observers)
        {
            observer->update(this);
        }
    }
};

void Customer::update(Order *order)
{
    cout << "Hello, " << name << "! Order #" << order->getId() << " is now " << order->getStatus() << endl;
}

void Restaurant::update(Order *order)
{
    cout << "Restaurant " << restaurantName << ": Order #" << order->getId() << " is now " << order->getStatus() << endl;
}

void DeliveryDriver::update(Order *order)
{
    cout << "Driver " << driverName << ": Order #" << order->getId() << " is now " << order->getStatus() << endl;
}
void CallCenter::update(Order *order)
{
    cout << "Call center: Order #" << order->getId() << " is now " << order->getStatus() << endl;
}

int main()
{
    // Create an order
    Order order1(123);

    // Create customers, restaurants, drivers, and a call center to track the order
    Customer customer1("Customer 1");
    Restaurant restaurant1("Rest 1");
    DeliveryDriver driver1("Driver 1");
    CallCenter callCenter;

    // Attach observers to the order
    order1.attach(&customer1);
    order1.attach(&restaurant1);
    order1.attach(&driver1);
    order1.attach(&callCenter);

    // Simulate order status updates
    order1.setStatus("Out for Delivery");

    // Detach an observer (if needed)
    order1.detach(&callCenter);

    // Simulate more order status updates
    order1.setStatus("Delivered");

    return 0;
}
