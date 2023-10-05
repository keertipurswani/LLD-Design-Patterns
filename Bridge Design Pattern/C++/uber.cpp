#include <iostream>

using namespace std;

// Implementation Layer
class NavigationImpl
{
public:
    virtual void navigateTo(string destination) = 0;
};

// Concrete Implementation: GoogleMaps
class GoogleMaps : public NavigationImpl
{
public:
    void navigateTo(string destination)
    {
        cout << "Google Maps." << endl;
        // Actual navigation logic using Google Maps API
    }
};

// Concrete Implementation: AppleMaps
class AppleMaps : public NavigationImpl
{
public:
    void navigateTo(string destination)
    {
        cout << "Apple Maps." << endl;
        // Actual navigation logic using Apple Maps API
    }
};

// Abstraction Layer
class NavigationSystem
{
protected:
    NavigationImpl *navigationImpl;

public:
    virtual void navigate(string destination) = 0;
};

// Concrete Abstraction: UberRide
class UberRide : public NavigationSystem
{

private:
    string driverName;

public:
    UberRide(string driverName) : driverName(driverName) {}

    void navigate(string destination)
    {
        cout << "Uber ride with " << driverName << " to " << destination << " using ";
        navigationImpl->navigateTo(destination);
    }

    void setNavigationImpl(NavigationImpl *impl)
    {
        navigationImpl = impl;
    }
};

// Concrete Abstraction: UberEats
class UberEats : public NavigationSystem
{
private:
    string restaurantName;

public:
    UberEats(string restaurantName) : restaurantName(restaurantName) {}

    void navigate(string destination)
    {
        cout << "Uber Eats delivery from " << restaurantName << " to " << destination << " using ";
        navigationImpl->navigateTo(destination);
    }

    void setNavigationImpl(NavigationImpl *impl)
    {
        navigationImpl = impl;
    }
};

int main()
{
    // Create an UberRide with a driver
    UberRide uber("Keerti");

    // Create an UberEats delivery
    UberEats uberEats("Pizza Palace");

    // Create different navigation implementations
    GoogleMaps googleMaps;
    AppleMaps appleMaps;

    // Set the navigation implementation for UberRide
    uber.setNavigationImpl(&googleMaps);

    // Request an Uber ride with Google Maps navigation
    uber.navigate("Central Park");

    // Switch to Apple Maps navigation for UberEats
    uberEats.setNavigationImpl(&appleMaps);

    // Request an Uber Eats delivery with Apple Maps navigation
    uberEats.navigate("123 HSR");

    return 0;
}
