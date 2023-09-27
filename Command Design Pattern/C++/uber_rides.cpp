#include <iostream>

using namespace std;

// Receiver: RideService
class RideService {
public:
    void requestRide(const string& passenger, const string& srcLoc, const string& destLoc) {
        cout << "Requesting a ride for passenger: " << passenger
             << " from " << srcLoc << " to " << destLoc << endl;
        // Additional ride request processing logic here
    }

    void cancelRide(const string& passenger) {
        cout << "Canceling the ride for passenger: " << passenger << endl;
        // Additional cancellation logic here
    }
};

// Abstract Command interface
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

// Concrete Command: RideRequestCommand
class RideRequestCommand : public Command {
private:
    RideService* receiver;
    string passenger;
    string srcLoc;
    string destLoc;

public:
    RideRequestCommand(RideService* receiver, const string& passenger, const string& srcLoc, const string& destLoc)
        : receiver(receiver), passenger(passenger), srcLoc(srcLoc), destLoc(destLoc) {}

    void execute() override {
        receiver->requestRide(passenger, srcLoc, destLoc);
    }
};

// Concrete Command: CancelRideCommand
class CancelRideCommand : public Command {
private:
    RideService* receiver;
    string passenger;

public:
    CancelRideCommand(RideService* receiver, const string& passenger)
        : receiver(receiver), passenger(passenger) {}

    void execute() override {
        receiver->cancelRide(passenger);
    }
};

// Invoker: RideRequestInvoker
class RideRequestInvoker {
public:
    void processRequest(Command* command) {
        command->execute();
    }
};

int main() {
    // Create a receiver
    RideService rideService;

    // Create an invoker
    RideRequestInvoker rideRequestInvoker;

    // Execute ride request and cancellation commands directly
    Command* request1 = new RideRequestCommand(&rideService, "Keerti", "Sarjapur", "Koramangala");
    Command* request2 = new RideRequestCommand(&rideService, "Amit", "Koramangala", "Indiranagar");
    Command* cancel1 = new CancelRideCommand(&rideService, "Keerti");

    // Process the ride requests and cancellations
    rideRequestInvoker.processRequest(request1);
    rideRequestInvoker.processRequest(request2);
    rideRequestInvoker.processRequest(cancel1);

    // Clean up
    delete request1;
    delete request2;
    delete cancel1;

    return 0;
}
