#include <iostream>
using namespace std;

// Define the RideState interface.
class RideState {
public:
    virtual void handleRequest() = 0;
    virtual void handleCancel() = 0;
};

// Implement concrete states.

class RideRequestedState : public RideState {
public:
    void handleRequest() override {
        cout << "Ride has been requested." << endl;
    }

    void handleCancel() override {
        cout << "Ride request has been canceled." << endl;
    }
};

class DriverAssignedState : public RideState {
public:
    void handleRequest() override {
        cout << "Ride is already assigned to a driver." << endl;
    }

    void handleCancel() override {
        cout << "Ride request has been canceled. The driver is notified." << endl;
    }
};

class EnRouteState : public RideState {
public:
    void handleRequest() override {
        cout << "Ride is already en route." << endl;
    }

    void handleCancel() override {
        cout << "Ride request cannot be canceled while en route." << endl;
    }
};

// Context

class Ride {
private:
    RideState* state;

public:
    Ride() {
        // Initial state is RideRequestedState.
        state = new RideRequestedState();
    }

    void setState(RideState* newState) {
        delete state;
        state = newState;
    }

    void requestRide() {
        state->handleRequest();
    }

    void cancelRide() {
        state->handleCancel();
    }
};

int main() {
    Ride ride;
    
    ride.requestRide();  // Output: Ride has been requested.
    
    ride.cancelRide();   // Output: Ride request has been canceled.

    cout<<"--------------------------------------------------"<<endl;
    cout<<"Setting state to Driver Assigned."<<endl;

    ride.setState(new DriverAssignedState());
    
    ride.requestRide();  // Output: Ride is already assigned to a driver.
    
    ride.cancelRide();   // Output: Ride request has been canceled. The driver is notified.

    cout<<"--------------------------------------------------"<<endl;
    cout<<"Setting state to EnRoute."<<endl;
    ride.setState(new EnRouteState());
    
    ride.requestRide();  // Output: Ride is already en route.
    
    ride.cancelRide();   // Output: Ride request cannot be canceled while en route.

    return 0;
}
