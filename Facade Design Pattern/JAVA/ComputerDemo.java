// Subsystem 1: CPU
class CPU {
    public void powerOn() {
        System.out.println("CPU is powered on.");
    }

    public void executeInstructions() {
        System.out.println("CPU is executing instructions.");
    }
}

// Subsystem 2: Memory
class Memory {
    public void initialize() {
        System.out.println("Memory is initialized.");
    }
}

// Subsystem 3: GPU
class GPU {
    public void enableGraphics() {
        System.out.println("GPU graphics are enabled.");
    }
}

// Subsystem 4: Disk Drive
class DiskDrive {
    public void bootFromDisk() {
        System.out.println("Booting from the disk drive.");
    }
}

// Subsystem 5: Network Interface
class NetworkInterface {
    public void connectToNetwork() {
        System.out.println("Connected to the network.");
    }
}

// Facade: Computer System
class ComputerSystemFacade {
    private CPU cpu;
    private Memory memory;
    private GPU gpu;
    private DiskDrive diskDrive;
    private NetworkInterface networkInterface;

    public ComputerSystemFacade() {
        this.cpu = new CPU();
        this.memory = new Memory();
        this.gpu = new GPU();
        this.diskDrive = new DiskDrive();
        this.networkInterface = new NetworkInterface();
    }

    public void startComputer() {
        System.out.println("Starting the computer...");
        cpu.powerOn();
        memory.initialize();
        gpu.enableGraphics();
        diskDrive.bootFromDisk();
        networkInterface.connectToNetwork();
        cpu.executeInstructions();
        System.out.println("Computer is ready to use.");
    }
}

public class ComputerDemo {
    public static void main(String[] args) {
        ComputerSystemFacade computer = new ComputerSystemFacade();

        // User initiates the computer startup process with a single call
        computer.startComputer();
    }
}
