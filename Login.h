#include <iostream>
#include <string>
#include <vector>
#include<fstream>
  


using namespace std;



class Login
{
public:  

   Login();  
   void Login_To_Profile(string , string);
   string Get_Position(string);
   bool Check_Login(string, string);
private:   

   int place;
   string username_test;
   string password_test;
   string line;
   string temp;
   vector <string> List_Of_Users;


   bool Check_User(string);
   int Find_Place(string);
};

Login::Login()
{
    ifstream mFile ("user.txt");  

    if(mFile.is_open()) 
	  {
		while(mFile.peek()!=EOF)
		  {
			   getline(mFile, line);
               List_Of_Users.push_back(line);
		  }
		  mFile.close();
	  } 
}



void Login::Login_To_Profile(string password, string username)
{
    if(Check_User(username) == true)
    {
        place = Find_Place(username);
        temp = List_Of_Users[place];

        size_t found1 = temp.find("*U");
        size_t found01 = temp.find("U-");
        username_test = temp.substr(found1 + 3,found01- found1 - 4);


        size_t found2 = temp.find("*PW");
        size_t found02 = temp.find("PW-");
        password_test = temp.substr(found2 + 4,found02- found2 - 5);


        if((password_test == password) && (username_test == username))
            cout << "Welcome to your account :)" << endl;
        else
            cout << "You entered your password or username incorrectly:( " << endl;    
    }
    else
    {
        cout << "***User not found***" << endl;
        cout << "****Please try again****" << endl;
    }
         
}



int Login::Find_Place(string username)
{
    string test;
    string username_test;
    for(int i = 0; i < List_Of_Users.size(); i++)
    {
        test = List_Of_Users[i];
        
        size_t found1 = test.find("*U");
        size_t found01 = test.find("U-");
        username_test = test.substr(found1 + 3,found01- found1 - 4);


        if(username == username_test)
             return i;

    }
}


bool Login::Check_User(string username)
{
    string test;
     string username_test;

    for(int i = 0; i < List_Of_Users.size(); i++)
    {
        test = List_Of_Users[i];
        
        size_t found1 = test.find("*U");
        size_t found01 = test.find("U-");
        username_test = test.substr(found1 + 3,found01- found1 - 4);


        if(username == username_test)
             return true;

    }
    return false;
}

string Login::Get_Position(string username)
{
        place = Find_Place(username);
        string tset = List_Of_Users[place];

        size_t found1 = tset.find("*PO");
        size_t found01 = tset.find("PO-");
        return tset.substr(found1 + 4,found01- found1 - 5);
}
bool Login::Check_Login(string username, string password)
{
    place = Find_Place(username);
    string tset = List_Of_Users[place];
    size_t found1 = tset.find("*U");
    size_t found01 = tset.find("U-");
    string username_a = tset.substr(found1 + 3,found01- found1 - 4);


    size_t found2 = tset.find("*PW");
    size_t found02 = tset.find("PW-");
    string password_a = tset.substr(found2 + 4,found02- found2 - 5);

  
   
    if(password_a == password && username_a == username)
       return true;
    return false;   


}
