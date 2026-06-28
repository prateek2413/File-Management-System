#include<iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std;
class File{
    public:
    int id;
    string name;
    int size;
    File(int id, string name, int size){
        this->id=id;
        this->name=name;
        this->size=size;
    }

};
class FileManager{
    private:
    vector<File> files;
    public:
    bool idExists(int id){
        for(int i = 0; i < files.size(); i++)
        {
            if(files[i].id == id){
                return true;
            }
        }
        return false;
    }
    void addFile(){
        int id;
        string name;
        int size;

        while(true){
            cout<<"\nEnter File ID: ";
            cin>>id;
            if(cin.fail()){
                cout<<"Invalid ID! Enter a number only.\n";
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }
            if(idExists(id)){
                cout << "File ID already exists!\n";
                continue;
            }
            break;
        }
        
        cin.ignore(1000, '\n');
        while(true){
            cout<<"Enter File name: ";
            getline(cin, name);
            if(!name.empty()){
                break;
            }
            cout<<"Name of File cannot be Empty\n";

        }

        while(true){
            cout<<"Enter File Size: ";
            cin>>size;
            if(cin.fail()){
                cout<<"Invalid Size! Enter a number only.\n";
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }
            if(size<0){
                cout<<"Size of file can't be negative\n";
                continue;

            }
            break;
        }

        File newFile(id, name, size);
        files.push_back(newFile);
        cout<<"\nFile Added Successfully!\n";
    }
    void displayFiles(){
        if(files.empty()){
            cout<<"\nNo Files Available.\n";
            return;
        }
        cout<<"\n==== FILE LIST ====\n";
        for(int i=0;i<files.size();i++){
            cout<<"ID: "<<files[i].id<<" | Name: "<<files[i].name<<" | Size: "<<files[i].size<<"KB"<<endl;
        }
    }
    void searchFile(){
        if(files.empty()){
            cout<<"\nNo Files Available to Search.\n";
            return;
        }
        int searchId;
        cout<<"\nEnter File ID to search: ";
        cin>>searchId;
        if(cin.fail()){
            cout<<"Invalid ID! Enter a Number only.\n";
            cin.clear();
            cin.ignore(1000,'\n');
            return;
        }
        for(int i=0;i<files.size();i++){
            if(files[i].id==searchId){
                cout<<"\nFile Found!\n"<<"ID: "<<files[i].id<<" | Name: "<<files[i].name<<" | Size: "<<files[i].size<<"KB"<<endl;
                return;
            }
        }
        cout<<"\nFile with ID "<<searchId<<" not found.\n";
    }

};
int main(){
    FileManager fm;
    int choice;

    do{
        cout<<"\n==== SMART FILE MANAGER ====\n";
        cout<< "1.Add File\n";
        cout<<"2.Display Files\n";
        cout<<"3.Search File\n";
        cout<<"4.Exit\n";

        while(true){
            cout<<"Enter Choice: ";
            cin>>choice;
            if(cin.fail()){
                cout<<"Invalid input! Please enter a number.\n";
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }
            break;
        }

        switch(choice){
            case 1:
            fm.addFile();
            break;
            case 2:
            fm.displayFiles();
            break;
            case 3:
            fm.searchFile();
            break;
            case 4:
            cout<<"\nExiting Program...";
            break;
            default:
            cout<<"Invalid Choice!\n";
        }
    }while(choice!=4);
    return 0;
}

