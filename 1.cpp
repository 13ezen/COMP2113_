  #include<iostream> 
#include<string> 
#include<algorithm> 
#include<map> 
#include<vector> 
// You can add more libraries here (if needed) 
using namespace std; 
// Define structure, classes and member functions
struct Student {
 // Code given above
};
class Table {
 // Code given above
};
bool operator<(const Student&a, const Student&b) {
 // This function may be required by your implementation.
}
//insert one record in to the map
void Table::InsertStudent(Student x, int y) {
 // To be implemented
}
//return the name and grade of the student with id x
void Table::SearchbyID(int x) {
 // To be implemented
}
//return the id and name of the student with grade y
void Table::SearchbyGrade(int y) {
 // To be implemented
}
void Table::Statistics() {
 // To be implemented
}
//Print all records in the accending order of id
void Table::PrintAll() {
 // To be implemented
}
int main() { 
 Table t;
 string command;
 int id;
