class Desktop {
    String motherboard;
    String processor;
    String memory;
    String storage;
    String graphicsCard;

    void display() {
        System.out.println("Desktop Specs:");
        System.out.println("Motherboard: " + motherboard);
        System.out.println("Processor: " + processor);
        System.out.println("Memory: " + memory);
        System.out.println("Storage: " + storage);
        System.out.println("Graphics Card: " + graphicsCard);
    }
}

abstract class DesktopBuilder {
    protected Desktop desktop;

    abstract DesktopBuilder buildMotherboard();

    abstract DesktopBuilder buildProcessor();

    abstract DesktopBuilder buildMemory();

    abstract DesktopBuilder buildStorage();

    abstract DesktopBuilder buildGraphicsCard();

    Desktop build() {
        return desktop;
    }
}

class DellDesktopBuilder extends DesktopBuilder {
    DellDesktopBuilder() {
        desktop = new Desktop();
    }

    @Override
    DesktopBuilder buildMotherboard() {
        desktop.motherboard = "Dell Motherboard";
        return this;
    }

    @Override
    DesktopBuilder buildProcessor() {
        desktop.processor = "Dell Processor";
        return this;
    }

    @Override
    DesktopBuilder buildMemory() {
        desktop.memory = "32GB DDR4 RAM";
        return this;
    }

    @Override
    DesktopBuilder buildStorage() {
        desktop.storage = "1TB SSD + 2TB HDD";
        return this;
    }

    @Override
    DesktopBuilder buildGraphicsCard() {
        desktop.graphicsCard = "NVIDIA RTX 3080";
        return this;
    }
}

class HpDesktopBuilder extends DesktopBuilder {
    HpDesktopBuilder() {
        desktop = new Desktop();
    }

    @Override
    DesktopBuilder buildMotherboard() {
        desktop.motherboard = "Hp Motherboard";
        return this;
    }

    @Override
    DesktopBuilder buildProcessor() {
        desktop.processor = "Intel Core i5";
        return this;
    }

    @Override
    DesktopBuilder buildMemory() {
        desktop.memory = "16GB DDR4 RAM";
        return this;
    }

    @Override
    DesktopBuilder buildStorage() {
        desktop.storage = "512GB SSD";
        return this;
    }

    @Override
    DesktopBuilder buildGraphicsCard() {
        desktop.graphicsCard = "Integrated Graphics";
        return this;
    }
}

class DesktopDirector {
    Desktop buildDesktop(DesktopBuilder builder) {
        return builder.buildMotherboard().buildProcessor().buildMemory().buildStorage().buildGraphicsCard().build();
    }
}

public class DesktopBuilderDemo {
    public static void main(String[] args) {
        // Director
        DesktopDirector director = new DesktopDirector();

        // Build a high-end Desktop
        DellDesktopBuilder DellBuilder = new DellDesktopBuilder();
        Desktop DellDesktop = director.buildDesktop(DellBuilder);

        // Build an Hp Desktop
        HpDesktopBuilder HpBuilder = new HpDesktopBuilder();
        Desktop HpDesktop = director.buildDesktop(HpBuilder);

        // Display Desktop specifications
        DellDesktop.display();
        HpDesktop.display();
    }
}