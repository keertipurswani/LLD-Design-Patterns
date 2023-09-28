
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

//Invoker
class MenuOptions {
    private ActionListenerCommand openCommand;
    private ActionListenerCommand saveCommand;

    public MenuOptions(ActionListenerCommand openCommand, ActionListenerCommand saveCommand) {
        this.openCommand = openCommand;
        this.saveCommand = saveCommand;
    }

    public void clickOpen() {
        openCommand.execute();
    }

    public void clickSave() {
        saveCommand.execute();
    }
}

public class DocumentDemo
 {
    public static void main(String[] args) {
        Document doc = new Document();

        ActionListenerCommand clickOpen = new ActionOpen(doc);
        ActionListenerCommand clickSave = new ActionSave(doc);

        MenuOptions menu = new MenuOptions(clickOpen, clickSave);

        menu.clickOpen();
        menu.clickSave();
    }
}

