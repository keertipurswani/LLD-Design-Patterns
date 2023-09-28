import java.util.Scanner;

interface IButton {
    void press();
}

interface ITextbox {
    void settext();
}

class MacButton implements IButton {
    @Override
    public void press() {
        System.out.println("Mac button pressed");
    }
}

class WinButton implements IButton {
    @Override
    public void press() {
        System.out.println("Win button pressed");
    }
}

class MacTextBox implements ITextbox {
    @Override
    public void settext() {
        System.out.println("Setting text in Mac Textbox");
    }
}

class WinTextBox implements ITextbox {
    @Override
    public void settext() {
        System.out.println("Setting text in Win Textbox");
    }
}

interface IFactory {
    IButton createButton();
    ITextbox createTextbox();
}

class WinFactory implements IFactory {
    @Override
    public IButton createButton() {
        return new WinButton();
    }

    @Override
    public ITextbox createTextbox() {
        return new WinTextBox();
    }
}

class MacFactory implements IFactory {
    @Override
    public IButton createButton() {
        return new MacButton();
    }

    @Override
    public ITextbox createTextbox() {
        return new MacTextBox();
    }
}

class GUIAbstractFactory {
    public static IFactory createFactory(String osType) {
        if (osType.equals("windows")) {
            return new WinFactory();
        } else if (osType.equals("mac")) {
            return new MacFactory();
        }
        
        return null;
    }
}

public class UI {
    public static void main(String[] args) {
        System.out.println("Enter machine OS");
        Scanner scanner = new Scanner(System.in);
        String osType = scanner.nextLine();
        scanner.close();

        IFactory factory = GUIAbstractFactory.createFactory(osType);

        if (factory != null) {
            IButton button = factory.createButton();
            button.press();

            ITextbox textBox = factory.createTextbox();
            textBox.settext();
        } else {
            System.out.println("Invalid OS type");
        }
    }
}
