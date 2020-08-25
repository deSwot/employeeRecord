#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct employee{ //struct to hold employee record basic information
  string name; 
  int age;
  float salary;
};
void WriteToFile(employee &e) //function to write data into the file for add a employee
{
	ofstream obj; //file object 
	obj.open("employee.txt", ios::app); //open file and append data 
	obj << e.name << "," << e.age << "," << e.salary<< endl; //add data 
	obj.close(); //close file object 
}
void menu(){ // menu to print choices
  cout<<endl;
  cout<<"1. Add a record"<<endl;
  cout<<"2. List records"<<endl;
  cout<<"3. Modify records"<<endl;
  cout<<"4. Delete records"<<endl;
  cout<<"5. Exit"<<endl;
}
void addEmployee(){ //function to add empployee 
  cout<<"Add a new Record"<<endl;
  employee e; //employee object 
  cout<<"Enter  name: ";
  cin.ignore(); //cin.ignore helps us to input string after every other datatype input otherwise it will skip the string input 
  getline(cin,e.name);
  cout<<"Enter  age: ";
  cin>>e.age;
  cout<<"Enter basic salary: ";
  cin>>e.salary;
  WriteToFile(e); // send to function
}
void display(){ //function to print employee record
        cout << "---------Employee Record ------------" << endl;
					string line;
          ifstream obj; 
          obj.open("employee.txt"); // open file 
					while (!obj.eof()){ //iterate until the end of file 
						getline(obj, line); //store it into a string 
						cout << line << endl; //print the string 
					}
}
void deleteRecord(){ //function to delete record 
  				employee e;
					string search; 
          int offset; 
          string line;
					ifstream obj;
					ofstream temp;
					ofstream temp2;
					obj.open("employee.txt");
					cout << "Enter the name you want to search: ";
					cin.ignore();
					getline(cin, search);
					if (obj.is_open()){ //if file is open 
						temp.open("removedEmployee.txt", ios::app); //create a new file to store remove employee data 
						temp2.open("temp.txt", ios::app); //temp file to switch record 
						while (!obj.eof()){// until the end of file 
							getline(obj, line);
							if (((offset = line.find(search, 0))) != string::npos){
								for (int i = 0; i < 1 && line != "/0"; i++){ // if record is found 
									temp << line << endl; //store it into the removed employee file 
								}
							}
							else{ //otherwise append in temp file 
								temp2 << line << endl;
							}
						}
            //close all opened file      
            temp.close();
						temp2.close();
						obj.close();
            //removed the previous version of the file 
						remove("employee.txt");
            //rename temp file as employee updated file 
						rename("temp.txt", "employee.txt");

					}
}
void updateRecord(){ //function to update record 
	employee c; 
	string search;
  string line;
	ifstream obj;
	ofstream temp;
	ofstream temp2;
	obj.open("employee.txt");
	cout << "Enter the name you want to search: ";
	cin.ignore();
	getline(cin, search);
	if (obj.is_open()){ //follow same proceducre as for delete a record 
		temp.open("deleted.txt", ios::app);
		temp2.open("tempo.txt", ios::app);
		while (!obj.eof()){
			getline(obj, line);
			if (((line.find(search, 0))) != string::npos){
				temp << line << endl;
			}
			else{
				temp2 << line << endl;
			}
		}      temp.close();
		temp2.close();
		obj.close();
		remove("captain.txt");
	}
  //this time remove the previous record we dont have to store it some where
	remove("employee.txt");
	remove("deleted.txt");
	rename("tempo.txt", "employee.txt");
  // enter new information 
	cout << "Enter name:  ";
	getline(cin, c.name);
	cout << "Enter age:  ";
	cin>> c.age;
	cout << "Enter basic salary: ";
	cin >> c.salary;
  //append into the file
	ofstream myfile; ofstream obj1;
	myfile.open("employee.txt", ios::app | ios::out);
		myfile << c.name << "," << c.age << "," << c.salary << endl;
}
int main() {
  int choice;
  char subChoice='y';
  while(1){
    menu();
    cout<<"Enter your choice: ";
    cin>>choice;
    if(choice==1){
      subChoice='y';
      while(subChoice=='y'){ // if y then keep on input 
        addEmployee();
        cout<<"Add another record (y/n): ";
        cin>>subChoice;
        if(subChoice=='n'){ //otherwise break the loop 
          break;
        }
      }

    }
    else if(choice==2){
      display();
    }
    else if(choice==3){
      updateRecord();
    }
    else if(choice==4){
      deleteRecord();
    }
    else if(choice==5){
      return 0;//exit 
    }
    else{
      cout<<"Invalid choice"<<endl;
    }
  }
}