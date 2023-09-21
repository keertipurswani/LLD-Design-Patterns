#include <string>
#include <iostream>
using namespace std;

class Ibutton{
    public :
    virtual void press() = 0;
   
};
class ITextbox{
    public :
    virtual void settext() = 0;
   
};

class MacButton : public Ibutton{
    public :
    void press(){
        cout<<"Mac button pressed"<<endl;
    }
   
};

class WinButton : public Ibutton{
    public :
    void press(){
        cout<<"Win button pressed"<<endl;
    }
   
};

class MacTextBox : public ITextbox{
    public :
    void settext(){
        cout<<"Setting text in Mac Textbox"<<endl;
    }
   
};

class WinTextBox : public ITextbox{
    public :
    void settext(){
        cout<<"Setting text in Win Textbox"<<endl;
    }
   
};

class IFactory{
    public :
        virtual Ibutton* createbutton() = 0;
        virtual ITextbox* createtextbox() = 0;
};


class WinFactory : public IFactory{
    public :
        Ibutton* createbutton(){
            return new WinButton();
        }
        ITextbox* createtextbox(){
            return new WinTextBox();
        }
   
};

class MacFactory : public IFactory{
    public :
    Ibutton* createbutton(){
        return new MacButton();
    }
    ITextbox* createtextbox(){
        return new MacTextBox();
    }
   
};

class GUIAbstractfactory{
  public:
    static IFactory* createfactory(string ostype){
        if(ostype == "windows"){
            return new WinFactory();
        }
        else if(ostype == "mac"){
            return new MacFactory;
        }
        return nullptr;
    }
};


int main(){
   
    cout<<"Enter machine OS\n";
    string ostype;
    cin>>ostype;
   
    IFactory* fact = GUIAbstractfactory::createfactory(ostype);
   
    Ibutton* button = fact->createbutton();
    button->press();
   
    ITextbox* textBox = fact->createtextbox();
    textBox->settext();
   
    return 0;
}
