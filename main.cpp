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
    void addfile(){
        int id;
        string name;
        int size;

        cout<<"\nEnter File ID: ";
    }

};
int main(){
    
}


