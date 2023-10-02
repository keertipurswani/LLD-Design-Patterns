import java.util.*;

//Command Interface
interface ActionListenerCommand {
    void execute();
}

//Receiver - performing the operation
class Document {
    public void open() {
        System.out.println("Document Opened");
    }

    public void save() {
        System.out.println("Document Saved");
    }
}

//Concrete Command
class ActionOpen implements ActionListenerCommand {
    private Document doc;

    public ActionOpen(Document doc) {
        this.doc = doc;
    }

    @Override
    public void execute() {
        doc.open();
    }
}

//Concrete Command
class ActionSave implements ActionListenerCommand {
    private Document doc;

    public ActionSave(Document doc) {
        this.doc = doc;
    }

    @Override
    public void execute() {
        doc.save();
    }
}

// Invoker
class MenuOptions {
    private List<ActionListenerCommand> commands = new ArrayList<>();

    public void addCommand(ActionListenerCommand command) {
        commands.add(command);
    }

    public void executeCommands() {
        for (ActionListenerCommand command : commands) {
            command.execute();
        }
    }
}

public class DocumentDemo {
    public static void main(String[] args) {
        Document doc = new Document(); // Receiver - performing action

        // Create concrete commands
        // Receiver with command
        ActionListenerCommand clickOpen = new ActionOpen(doc);
        ActionListenerCommand clickSave = new ActionSave(doc);

        // Invoker
        MenuOptions menu = new MenuOptions();

        // Client code only adds commands to the menu
        menu.addCommand(clickOpen);
        menu.addCommand(clickSave);

        menu.executeCommands();
    }
}


