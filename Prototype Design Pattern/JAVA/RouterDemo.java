abstract class NetworkDevice {
    public abstract NetworkDevice clone();

    public abstract void display();

    public abstract void update(String newName);
}

class Router extends NetworkDevice {
    private String name;
    private String ip;
    private String securityPolicy;

    public Router(String name, String ip, String securityPolicy) {
        this.name = name;
        this.ip = ip;
        this.securityPolicy = securityPolicy;
    }

    @Override
    public NetworkDevice clone() {
        return new Router(name, ip, securityPolicy);
    }

    @Override
    public void display() {
        System.out.println("Router - Name: " + name + ", IP: " + ip + ", Security Policy: " + securityPolicy);
    }

    @Override
    public void update(String newName) {
        name = newName;
    }
}

class Switch extends NetworkDevice {
    private String name;
    private String protocol;

    public Switch(String name, String protocol) {
        this.name = name;
        this.protocol = protocol;
    }

    @Override
    public NetworkDevice clone() {
        return new Switch(name, protocol);
    }

    @Override
    public void display() {
        System.out.println("Switch - Name: " + name + ", Protocol: " + protocol);
    }

    @Override
    public void update(String newName) {
        name = newName;
    }
}

public class RouterDemo {
    public static void main(String[] args) {
        // Create prototype instances of a router and a switch
        NetworkDevice routerPrototype = new Router("Router A", "192.168.1.1", "Firewall Enabled");
        NetworkDevice switchPrototype = new Switch("Switch X", "Ethernet");

        // Clone and display router and switch devices
        NetworkDevice routerClone = routerPrototype.clone();
        NetworkDevice switchClone = switchPrototype.clone();

        System.out.println("Router Clone:");
        routerClone.display();

        System.out.println("\nSwitch Clone:");
        switchClone.display();

        // Update the names of the clones
        routerClone.update("Router B");
        switchClone.update("Switch Y");

        System.out.println("\nUpdated Router Clone:");
        routerClone.display();

        System.out.println("\nUpdated Switch Clone:");
        switchClone.display();
    }
}