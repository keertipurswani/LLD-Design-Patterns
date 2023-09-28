#include <iostream>

using namespace std;

// Command Interface
class ActionListenerCommand {
public:
    virtual void execute() = 0;
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

    void execute() override {
        doc->open();
    }
};

// Concrete Command
class ActionSave : public ActionListenerCommand {
private:
    Document* doc;

public:
    ActionSave(Document* document) : doc(document) {}

    void execute() override {
        doc->save();
    }
};

// Invoker
class MenuOptions {
private:
    ActionListenerCommand* openCommand;
    ActionListenerCommand* saveCommand;

public:
    MenuOptions(ActionListenerCommand* openCmd, ActionListenerCommand* saveCmd)
        : openCommand(openCmd), saveCommand(saveCmd) {}

    void clickOpen() {
        openCommand->execute();
    }

    void clickSave() {
        saveCommand->execute();
    }
};

int main() {
    Document doc;

    ActionListenerCommand* clickOpen = new ActionOpen(&doc);
    ActionListenerCommand* clickSave = new ActionSave(&doc);

    MenuOptions menu(clickOpen, clickSave);

    menu.clickOpen();
    menu.clickSave();

    delete clickOpen;
    delete clickSave;

    return 0;
}
