// TASK : Building Google Docs

// Features : 
// 1. Multiple Texts
// 2. Support Images
// 3. Scalable 
// 4. Extendible(We can add anything in future)

// Two types of Approaches :
// 1. Top-Down Approach --> Bade(Top) objects phle create honge then unki dependencies.
// 2. Bottom-Up Approach --> Phle chote objects & unki dependencies create hongi after that we will create bade wale objects.

// #Now Let's Start

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class docElement{
public:  
    virtual string render() = 0;
};

class textElements : public docElement{
private:
    string text;
public:
    textElements(string text){
        this->text = text;
    }
    string render() override {
        return text;
    }
};

class ImgElements : public docElement{
private:
    string imgPath;
public:
    
    ImgElements(string imgPath){
        this->imgPath = imgPath;
    }

    string render() override {
        return "[ Image : " + imgPath + " ]";
    }
};

class TabElements : public docElement{
public:
    string render() override {
        return "\t";
    }
};

class newLineElements : public docElement{
public:
   string render() override {
        return "\n";
    }
};

class persistenceDB{
public:
    virtual void save(string data) = 0;
};

class fileStorage : public persistenceDB{
public:
    void save(string text) override{
        ofstream fout("file.doc");
        if (fout){
        fout<<text;
        cout<<"Data Saved to file.doc file successfully !"<<endl;
        fout.close();
        }
    }
};

class dbStorage : public persistenceDB{
private:
    string text;
public:
    void save(string text) override{
        cout<<"Data saved to DataBase storage successfully"<<endl;
    }
};

class Document{
private:
    vector<docElement*>elements;

public:

    void addItem(docElement *doc){
        elements.push_back(doc);
    }

    string renderItems(){
        string result;
        for(auto item : elements){
            result += item->render();
        }
        return result;
    }
};

class documentEditor{
private:
    Document *doc;
    persistenceDB *storage;
    string renderedDoc;

public:
    documentEditor(Document *doc,persistenceDB *storage){
        this->doc = doc;
        this->storage = storage;
    }

    void addText(string text){
        doc->addItem(new textElements(text));
    }
    
    void addImg(string imgPath){
        doc->addItem(new ImgElements(imgPath));
    }
    
    void addNewLine(){
        doc->addItem(new newLineElements());
    }
    
    void addTab(){
        doc->addItem(new TabElements());
    }

    string renderDoc(){
        if (renderedDoc.empty()){
            return renderedDoc = doc->renderItems();
        }
        return renderedDoc;
    }

    void save2file(){
        storage->save(renderDoc());
    }

    ~documentEditor() {
        delete doc;
        delete storage;
    }
};

int main(){
    Document *document = new Document();
    persistenceDB *file = new fileStorage();

    documentEditor *docEdit = new documentEditor(document,file);

    docEdit->addText("Hello World ,I am Aditya Kumar Chaudhary ");
    docEdit->addNewLine();
    docEdit->addTab();
    docEdit->addImg("Beautiful.jpg");
    docEdit->save2file();

    cout<<docEdit->renderDoc();

    delete docEdit;

}