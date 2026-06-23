#include<iostream>
#include<vector>
#include<string>
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
class Folder{
    private:
    string foldername;
};
class FileManager{
    private:
    vector<File> files;
    public:
    void addFile(){
        int id;
        string name;
        int size;

        cout<<"\nEnter File ID: ";
        cin>>id;
        
        cout<<"Enter File Name: ";
        cin>>name;

        cout<<"Enter File Size (KB): ";
        cin>>size;

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

};
int main(){
    FileManager fm;
    int choice;

    do{
        cout<<"\n==== SMART FILE MANAGER ====\n";
        cout<< "1.Add File\n";
        cout<<"2.Display Files\n";
        cout<<"3.Exit\n";

        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            fm.addFile();
            break;
            case 2:
            fm.displayFiles();
            break;
            case 3:
            cout<<"\nExiting Program...";
            break;
            default:
            cout<<"Invalid Choice!\n";
        }
    }while(choice!=3);
    return 0;
}


