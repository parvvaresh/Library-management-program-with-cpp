#include <iostream>
#include <string>
#include <vector>
#include<fstream>
  
#include "Book.h"
class AdminUser
{
public:
    AdminUser();
    void DeleteUser(string = "NULL");
    void EditUser(string = "NULL", string = "NULL", string = "NULL");
    void AddUser(string = "NULL", string = "NULL", string = "NULL", string = "NULL", string = "NULL", string = "NULL", string = "NULL");
    void Adjust_Level(string, string);
    ~AdminUser();



    bool Check_User(string);
    int Find_Place(string);


private: 
    string line;
    string temp;
    int place;
    vector <string> List_Of_Users;
    string Fname, Lname, Mobile, Email, Username, Password, Position;
    
    string Give_Information(string, string);
    void Lunch_Information(string &, string, string, string, string, string, string, string);
    

};

AdminUser::AdminUser()
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
int AdminUser::Find_Place(string username)
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



bool AdminUser::Check_User(string username)
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

void AdminUser::DeleteUser(string username)
{
    if(Check_User(username) == true)
    {
        place = Find_Place(username);
        List_Of_Users.erase(List_Of_Users.begin() + place);
        cout << " your performance was excellent " << endl;
        cout << "--> successfully removed user :)" << endl;
    }
    else
    {
        cout << "User not found :(" << endl;
    }
}
void AdminUser::EditUser(string username, string part, string info)
{
    if(Check_User(username) == true)
    {
        place = Find_Place(username);
        temp = List_Of_Users[place];
        List_Of_Users.erase(List_Of_Users.begin() + place);


        Fname = Give_Information(temp, "first name");
        Lname = Give_Information(temp, "last name");
        Mobile = Give_Information(temp, "mobile");
        Email = Give_Information(temp, "email");
        Username = Give_Information(temp, "username");
        Password = Give_Information(temp, "password");
        Position = Give_Information(temp, "postion");


        
        
        if(part == "Firstname"){Fname = info;}
        else if(part == "Lastname"){Lname = info;}
        else if(part == "Mobile"){Mobile = info;}
        else if(part == "Email"){Email = info;}
        else if(part == "Username"){Username = info;}
        else if(part == "Password"){Password = info;}
        Lunch_Information(temp,Fname, Lname, Mobile, Email, Username, Password, Position);
        List_Of_Users.push_back(temp);

        
        cout << " your performance was excellent " << endl;
        cout << "--> successfully edited user :)" << endl;
    }
    else
    {
        cout << "User not found :(" << endl;
    }

}

void AdminUser::AddUser(string fname, string lname, string mobile, string email, string username, string password, string position)
{
    if(Check_User(username) == false)
    {
      Lunch_Information(temp, fname, lname, mobile, email, username, password, position);
      List_Of_Users.push_back(temp);
    }
    else
    {
        cout << "This user is a member of the library" << endl;
        cout << "Use other software features :)" << endl;
    }
  
}

void AdminUser::Adjust_Level(string username , string level)
{
    if(Check_User(username) == true)
    {
        place = Find_Place(username);
        List_Of_Users.erase(List_Of_Users.begin() + place);

        temp = List_Of_Users[place];
        string f,l,m,e,u,p,P;

        f = Give_Information(temp, "first name");
        l = Give_Information(temp, "last name");
        m = Give_Information(temp, "mobile");
        e = Give_Information(temp, "email");
        u = Give_Information(temp, "username");
        p = Give_Information(temp, "password");
        P = Give_Information(temp, "postion");
        
        P = level;

        Lunch_Information(temp,f,l,m,e,u,p,P);

        List_Of_Users.push_back(temp);
        



    }
    else{cout << "User not found :(" << endl;}



}
string AdminUser::Give_Information(string list, string part)
{
    if(part == "first name")
    {
        size_t found1 = list.find("*F");
        size_t found01 = list.find(")F-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "last name")
    {
        size_t found1 = list.find("*L");
        size_t found01 = list.find(")L-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "mobile")
    {
        size_t found1 = list.find("*M");
        size_t found01 = list.find(")M-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "email")
    {
        size_t found1 = list.find("*E");
        size_t found01 = list.find(")E-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }

    else if(part == "username")
    {
        size_t found1 = list.find("*U");
        size_t found01 = list.find(")U-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "password")
    {
        size_t found1 = list.find("*PW");
        size_t found01 = list.find(")PW-");
        return list.substr(found1 + 4,found01- found1 - 4);
    }
    else if(part == "postion")
    {
        size_t found1 = list.find("*PO");
        size_t found01 = list.find(")PO-");
        return list.substr(found1 + 4,found01- found1 - 4);
    }

}

void AdminUser::Lunch_Information(string& list,string fname, string lname, string mobile, string email, string username, string password, string position) 
{
    list = "";
    list += "*F(";
    list += fname;
    list += ")F-";

    list += "*L(";
    list += lname;
    list += ")L-";


    list += "*M(";
    list += mobile;
    list += ")M-";
   

    list += "*E(";
    list += email;
    list += ")E-";

    list += "*U(";
    list += username;
    list += ")U-";


    list += "*PW(";
    list += password;
    list += ")PW-";


    list += "*PO(";
    list += position;
    list += ")PO-";
}

AdminUser:: ~AdminUser()
{
    ofstream myfile ("user.txt");  
    if(myfile.is_open())
    {
       
       for(int i = 0; i < List_Of_Users.size(); i++)
          myfile << List_Of_Users[i] << endl;

        myfile.close();
    }
}