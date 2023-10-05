#include <iostream>
using namespace std;

// Subsystem 1: CPU
class CPU {
public:
    void powerOn() {
        cout << "CPU is powered on." << endl;
    }

    void executeInstructions() {
        cout << "CPU is executing instructions." << endl;
    }
};

// Subsystem 2: Memory
class Memory {
public:
    void initialize() {
        cout << "Memory is initialized." << endl;
    }
};

// Subsystem 3: GPU
class GPU {
public:
    void enableGraphics() {
        cout << "GPU graphics are enabled." << endl;
    }
};

// Subsystem 4: Disk Drive
class DiskDrive {
public:
    void bootFromDisk() {
        cout << "Booting from the disk drive." << endl;
    }
};

// Subsystem 5: Network Interface
class NetworkInterface {
public:
    void connectToNetwork() {
        cout << "Connected to the network." << endl;
    }
};

// Facade: Computer System
class ComputerSystemFacade {
private:
    CPU cpu;
    Memory memory;
    GPU gpu;
    DiskDrive diskDrive;
    NetworkInterface networkInterface;

public:
    void startComputer() {
        cout << "Starting the computer..." << endl;
        cpu.powerOn();
        memory.initialize();
        gpu.enableGraphics();
        diskDrive.bootFromDisk();
        networkInterface.connectToNetwork();
        cpu.executeInstructions();
        cout << "Computer is ready to use." << endl;
    }
};

int main() {
    ComputerSystemFacade computer;

    // User initiates the computer startup process with a single call
    computer.startComputer();

    return 0;
}
