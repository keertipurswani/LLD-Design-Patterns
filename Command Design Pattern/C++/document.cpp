#include <iostream>

using namespace std;

// Command Interface
class ActionListenerCommand {
public:
    virtual void execute() = 0;
    virtual ~ActionListenerCommand() {}
};

// Receiver - performing the operation
class Document {
public:
    void open() {
        cout << "Document Opened" << endl;
    }

    void save() {
        cout << "Document Saved" << endl;
    }
};

// Concrete Command
class ActionOpen : public ActionListenerCommand {
private:
    Document* doc;

public:
    ActionOpen(Document* document) : doc(document) {}

    void execute() {
        doc->open();
    }
};

// Concrete Command
class ActionSave : public ActionListenerCommand {
private:
    Document* doc;

public:
    ActionSave(Document* document) : doc(document) {}

    void execute() {
        doc->save();
    }
};

// Invoker
class MenuOptions {
private:
    vector<ActionListenerCommand*> commands;

public:
    void addCommand(ActionListenerCommand* command) {
        commands.push_back(command);
    }

    void executeCommands() {
        for (ActionListenerCommand* command : commands) {
            command->execute();
        }
    }
};

int main() {
    Document doc;
    MenuOptions menu;

    ActionListenerCommand* clickOpen = new ActionOpen(&doc);
    ActionListenerCommand* clickSave = new ActionSave(&doc);

    menu.addCommand(clickOpen);
    menu.addCommand(clickSave);
    
    // Client code only adds commands to the menu
    // The invoker (menu) doesn't need to change when new commands are added
    menu.executeCommands();

    delete clickOpen;
    delete clickSave;

    return 0;
}
