#include <iostream>
using namespace std;

// Data analytics tool that expects JSON data
// Adaptee
class JSONAnalyticsTool
{
    string pJsonData;

public:
    void setJsonData(string jsonData) {
        pJsonData = jsonData;
    }
    void AnalyzeData()
    {
        if (pJsonData.find("json") != string::npos) {
            cout << "Analysing JSON Data - " << pJsonData << endl;
        } else {
            cout << "Not correct format. Can't analyse! " << endl;
        }
    }
};

// Interface Class
// Target
class AnalyticsTool {
    public:
        virtual void AnalyzeData() = 0;
        virtual ~AnalyticsTool() {}
};

// Adapter
class XMLToJSONAdapter : public AnalyticsTool
{
private:
    JSONAnalyticsTool jsonAnalyticsTool;

public:
    XMLToJSONAdapter(string xmlData) {
         cout<<"Converting the XML Data '" << xmlData <<"' to JSON Data!"<<endl;
         string newData = xmlData + " in json";
         jsonAnalyticsTool.setJsonData(newData);
    }

    void AnalyzeData()
    {    
        //Could convert here instead of the constructor
        jsonAnalyticsTool.AnalyzeData();
    }
};

int main()
{
    string xmlData = "Sample Data";
    JSONAnalyticsTool tool1;
    tool1.setJsonData(xmlData);
    tool1.AnalyzeData();

    cout<<"----------------------------------------------"<<endl;

    AnalyticsTool *tool2 = new XMLToJSONAdapter(xmlData);
    tool2->AnalyzeData();
    delete tool2;
    return 0;
}
