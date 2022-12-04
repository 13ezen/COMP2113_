#include<iostream> 
#include<string> 
#include<algorithm> 
#include<map> 
#include<vector> 
using namespace std; 

// Define structure, classes and member functions
//int id stores student ID, int grade stores student grade
//string name stores student name
struct Student {
    int id,grade;
    string name;
    Student() {
        id = 0;
        name = "invalid";
    };
    Student(int inputid, string inputname, int g) {
        id = inputid;
        name = inputname;
        grade = g;
    };
};

//vector<Student> records used to store student information
class Table {
public: 
    void InsertStudent(Student x); 
    void SearchbyID(int x); 
    void SearchbyGrade(int y); 
    void Statistics(); 
    void PrintAll(); 
 // You can add more member functions to help your
 // implementation.
private: 
    vector<Student> records;
};

//sort in ascending order of id 
bool operator<(const Student&a, const Student&b) {
    return a.id < b.id;
}

//sort in ascending order of grade 
bool Compare(const Student&a, const Student&b) {
    return a.grade < b.grade;
}
//insert one record in to the vector
void Table::InsertStudent(Student x) {
    if(records.size()!=0){
        for(int i = 0; i<records.size() ; i++){
            if (records[i].id == x.id){
                cout << "Student exists." << endl;
                break;
            }
        }
        records.insert(records.begin(),x);   
    }
    else{
        records.insert(records.begin(),x);
    }
    
}
//return the name and grade of the student with id x
void Table::SearchbyID(int x) {
    int count = 0;
    sort(records.begin(),records.end());
    for (auto itr = records.begin(); itr<records.end(); itr++){
        if((*itr).id == x){
            cout << (*itr).name << endl;
            cout << (*itr).grade << endl;
            break;
        }
        count+=1;
    }
    if(count==records.size()){cout << "No such student." << endl;}
}
//return the id and name of the student with grade y
void Table::SearchbyGrade(int y) {
    int count = 0;
    sort(records.begin(),records.end());
    for (auto itr = records.begin(); itr<records.end(); itr++){
        if((*itr).grade == y){
            cout << (*itr).id << " " << (*itr).name << endl;
            break;
        }
        count+=1;
    }
    if(count==records.size()){cout << "No such student." << endl;}
}

//Print maximum, median, minimum of grades
void Table::Statistics() {
    int max, min, size = records.size();
    double average;
    sort(records.begin(),records.end(),Compare);
    min=(*records.begin()).grade;
    max=(*(records.end()-1)).grade;
    cout << "Maximum " << max << endl;
    if(size%2==0){
        average = (records[(size/2)-1].grade + records[size/2].grade)/2.0;
    }
    else{
        average = records[size/2].grade;
    }
    cout << "Median " << average << endl;
    cout << "Minimum " << min << endl;
}
//Print all records in the accending order of id
void Table::PrintAll() {
    sort(records.begin(),records.end());
    for (auto itr = records.begin(); itr<records.end(); itr++){
        cout << (*itr).id << ' ' << (*itr).name << ' ' << (*itr).grade<< endl;
    }
    } 
int main() { 
    Table t;
    string command;
    int id;
    string name;
    int grade; 
    while (cin >> command) {
        if (command == "InsertStudent") {
            cin >> id >> name >> grade;
            Student s = {id, name, grade};
            t.InsertStudent(s);
    }
        else if (command == "SearchbyID") {
            cin >> id;
            t.SearchbyID(id);
    }
        else if (command == "SearchbyGrade") {
            cin >> grade;
            t.SearchbyGrade(grade);
        }
        else if (command == "PrintAll") {
            t.PrintAll();
        }
        else if (command == "Statistics") {
            t.Statistics();
        }
        else if (command == "exit") {
            break;
        }
}

return 0; 
}
