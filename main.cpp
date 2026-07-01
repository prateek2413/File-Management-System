#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<unordered_map>
#include<queue>
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
    unordered_map<int, int> idIndex;
    queue<File> recentFiles;
    const int RECENT_LIMIT=5;
    public:
    bool idExists(int id){
        return idIndex.find(id)!=idIndex.end();
    }
    void rebuildIndex(){
        idIndex.clear();
        for(int i=0;i<files.size();i++){
            idIndex[files[i].id]=i;
        }
    }
    void addToRecent(File f){
        recentFiles.push(f);
        if(recentFiles.size()>RECENT_LIMIT){
            recentFiles.pop();
        }
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
        idIndex[id]=files.size()-1;
        addToRecent(newFile);
        cout<<"\nFile Added Successfully!\n";
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
        auto it=idIndex.find(searchId);
        if(it!=idIndex.end()){
            int pos=it->second;
            cout<<"\nFile Found!\n"<<files[pos].id<<" | Name: "<<files[pos].name<<" | Size: "<<files[pos].size<<"KB"<<endl;
        }else{
            cout<<"\nFile with ID "<<searchId<<" not Fund.";
        }
    }
    void deleteFile(){
        if(files.empty()){
            cout<<"\nNo Files Available to Delete.\n";
            return;
        }
        int deleteId;
        cout<<"\nEnter File ID to Delete: ";
        cin>>deleteId;
        if(cin.fail()){
            cout<<"Invalid ID! Enter a number only.\n";
            cin.clear();
            cin.ignore(1000,'\n');
            return;
        }
        cin.ignore(1000,'\n');
        
        auto it = idIndex.find(deleteId);
        if(it==idIndex.end()){
            cout<<"\nFile with ID "<<deleteId<<" not Found.\n";
            return;
        }
        int pos=it->second;
        files.erase(files.begin()+pos);
        idIndex.erase(it);
        for(auto &pair : idIndex){
            if(pair.second>pos){
                pair.second--;
            }
        }
        cout<<"\nFile with ID "<<deleteId<<" deleted successfully!\n";

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
    void sortByName(){
        if(files.empty()){
            cout<<"\nNo Files Available for Sort. \n";
            return;
        }
        int n=files.size();
        for(int i=0;i<n-1;i++){
            bool swapped=false;
            for(int j=0;j<n-i-1;j++){
                if(files[j].name>files[j+1].name){
                    swap(files[j],files[j+1]);
                    swapped=true;
                }
            }
            if(!swapped){
                break;
            }
        }
        cout<<"\nFiles sorted by Name successfully!\n";
        rebuildIndex();
        displayFiles();
    }
    void sortBySize(){
        if(files.empty()){
            cout<<"\nNo Files Available to sort.\n";
            return;
        }
        int n=files.size();        
        for(int i=0;i<n-1;i++){
            bool swapped=false;
            for(int j=0;j<n-i-1;j++){
                if(files[j].size>files[j+1].size){
                    swap(files[j],files[j+1]);
                    swapped=true;
                }
            }
            if(!swapped){
                break;
            }
        }
        cout<<"\nFiles sorted by Size successfully.\n";
        rebuildIndex();
        displayFiles();
    }
    void showRecentFiles(){
        if(recentFiles.empty()){
            cout<<"\nNo Recent Files.\n";
            return;
        }
        queue<File> temp=recentFiles;
        cout<<"\n==== RECENT FILES (Oldest to Newest) ====\n";
        while(!temp.empty()){
            File f=temp.front();
            cout<<"ID: "<<f.id<<" | Name: "<<f.name<<" | Size: "<<f.size<<"KB"<<endl;
            temp.pop();
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
        cout<<"3.Search File\n";
        cout<<"4.Delete File\n";
        cout<<"5.Sort by Name\n";
        cout<<"6.Sort by Size\n";
        cout<<"7.View Recent Files\n";
        cout<<"8.Exit\n";

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
            fm.deleteFile();
            break;
            case 5:
            fm.sortByName();
            break;
            case 6:
            fm.sortBySize();
            break;
            case 7:
            fm.showRecentFiles();
            break;
            case 8:
            cout<<"\nExiting Program...";
            break;
            default:
            cout<<"Invalid Choice!\n";
        }
    }while(choice!=8);
    return 0;
}


