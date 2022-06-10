#include <iostream>
#include <string>
#include <vector>
#include<fstream>
  


using namespace std;

class Time
{
public:
    Time();

    //about user
    void Login(string,string ,string , string);
    void Edit_User(string, string, string, string, string);
    void Delete_User(string, string, string, string);
    void Add_User(string , string , string , string);
    void Adjust_User(string, string, string, string);
    //about book
    void Delete_Book(string, string, string, string);
    void Add_Book(string, string, string, string);
    void Edit_Book(string, string, string, string, string);
    void See_Book(string , string);
    void Search_Book(string , string , string );


    ~Time();
private:
    string line;
    vector <string> Record;


};

Time::Time()
{
    ifstream mFile ("Time.txt");  

    if(mFile.is_open()) 
	  {
		while(mFile.peek()!=EOF)
		  {
			   getline(mFile, line);
               Record.push_back(line);
		  }
		  mFile.close();
	  } 
}
void Time::Login(string time,string username,string postion, string result)
{
    string test = "";
    test += "User with username : ";
    test += username;
    test += "  ";
    test += "Entered the system as user : ";
    test += postion;
    test += "  ";
    test += "Event time : ";
    test += time;
    test += "    ";
    test += "Result : ";

    test += result;

    Record.push_back(test);

  


}

void Time::Edit_User(string time,string username, string part, string username_edit, string result)
{
    string test = "";
    test += "User with username : ";
    test += username;
    test += "  ";
    test += "Edited the";
    test += part;
    test += " section";
    test += "  ";
    test += "User information, with username  : ";
    test += username_edit;
    test += "  ";
    test += "Event time : ";
    test += time;
    test += "  ";
    test += "Result : ";
    test += result;

    Record.push_back(test);
    

}
void Time::Delete_User(string time, string username, string username_del, string result)
{
    string test = "";
    test += "User with username : ";
    test += username;
    test += "  ";
    test += "Deleted the User, with username";
    test += username_del;
    test += "  ";
    test += "Event time : ";
    test += time;
    test += "  ";
    test += "Result : ";
    test += result;

    Record.push_back(test);


}
void Time::Add_User(string time, string username, string username_add,  string result)
{
    string test = "";
    test += "User with username : ";
    test += username;
    test += "  ";
    test += "add the User, with username";
    test += username_add;
    test += "  ";
    test += "Event time : ";
    test += time;
    test += "  ";
    test += "Result : ";
    test +=  result;

    Record.push_back(test);
}
void Time::Adjust_User(string time, string username, string username_adjust, string result)
{
    string test = "";
    test += "User with username : ";
    test += username;
    test += "  ";
    test += "Changed the user access level, with username";
    test += username_adjust;
    test += "  ";
    test += "Event time : ";
    test += time;
    test += "  ";
    test += "Result : ";
    test += result;

    Record.push_back(test);
}
void Time::Delete_Book(string time, string username, string code_del, string result)
{
    string test = "";
    test += "User with username : ";
    test += username;
    test += "  ";
    test += "Deleted the book, with code";
    test += code_del;
    test += "  ";
    test += "Event time : ";
    test += time;
    test += "  ";
    test += "Result : ";
    test += result;

    Record.push_back(test);
}
void Time::Add_Book(string time, string username, string code_add, string result)
{
    string test = "";
    test += "User with username : ";
    test += username;
    test += "  ";
    test += "Add the book, with code";
    test += code_add;
    test += "  ";
    test += "Event time : ";
    test += time;
    test += "  ";
    test += "Result : ";
    test += result;

    Record.push_back(test);
}
void Time::Edit_Book(string time, string username, string part, string code_edit, string result)
{
    string test = "";
    test += "User with username : ";
    test += username;
    test += "  ";
    test += "Edited the";
    test += part;
    test += " section";
    test += "  ";
    test += "Book information, with code  : ";
    test += code_edit;
    test += "  ";
    test += "Event time : ";
    test += time;
    test += "  ";
    test += "Result : ";
    test += result;

    Record.push_back(test);
}
void Time::See_Book(string time, string username)
{
    string test = "";
    test += "User with username : ";
    test += username;
    test += "  ";
    test += "Looked at the list of all books";
    test += "  ";
    test += "Event time : ";
    test += time;
    test += "  ";
    Record.push_back(test);

    


   
}
void Time::Search_Book(string time, string username, string part)
{
    string test = "";
    test += "User with username : ";
    test += username;
    test += "  ";
    test += "Search the books in ";
    test += part;

    test += "Event time : ";
    test += time;
    test += "  ";
    Record.push_back(test);

}
Time::~Time()
{
    ofstream myfile ("Time.txt");  
    if(myfile.is_open())
    {
       
       for(int i = 0; i < Record.size(); i++)
          myfile << Record[i] << endl;

        myfile.close();
    }
}