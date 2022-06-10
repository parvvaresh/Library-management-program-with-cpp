#include <iostream>
#include <vector>
#include <string>
#include <regex>
using namespace std;
    

class Check

{
public:
    //about users
    bool Check_Password(string);
    bool Check_Username(string);
    bool Check_Part(string);
    bool Check_Name(string);
    bool Check_Email(string);
    bool Check_Mobile(string);
    bool Check_Adjust(string);

    //about
    bool Check_Code(string);
    bool Check_NameBook(string);
    bool Check_Writer(string);
    bool Check_Genre(string);
    bool Check_Description(string);
    bool Check_Situation(string);




};




bool Check::Check_Password(string password)
{
    if(password.length() < 5)
       return false;
    return true;   
}

bool Check::Check_Username(string username)
{
    for(int i = 0; i < username.length(); i++)
    {
        if((int(username[i]) <= 47) || (int(username[i]) >= 58))
           return false;
    }
    if(username.length() == 7 || username.length() == 8)
       return true;

   
    return true;

}
bool Check::Check_Name(string name)
{
    for(int i = 0; i < name.length(); i++)
      if(isalpha(name[i]) == 0)
        return false;
    return true;     
}

bool Check::Check_Mobile(string mobile)
{
    for(int i = 0; i < mobile.length(); i++)
         if(isdigit(mobile[i]) == 0)
           return false;
    if(mobile.length() != 11)
      return false;

    return true;  
}

bool Check::Check_Email(string email)
{
    const regex pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

bool Check::Check_Adjust(string adjust)
{
    if(adjust == "admin" || adjust == "user")
        return true;
    return false;    
}


bool Check::Check_Writer(string wirter)
{
    for(int i = 0; i < wirter.length(); i++)
       if(isalpha(wirter[i]) == 0)
           return false;
    return true;       

}

bool Check::Check_NameBook(string name)
{
    for(int i = 0; i < name.length(); i++)
        if(isalpha(name[i]) == 0)
           return false;
    return true;        
}

bool Check::Check_Genre(string genre)
{
    for(int i = 0; i < genre.length(); i++)
       if(isalpha(genre[i]) == 0)
          return false;
    return true;       
}
bool Check::Check_Situation(string condition)
{
    if(condition == "Available" || condition == "Unavailable")
        return true;
    return false;    
}
bool Check::Check_Description(string summary)
{
    if(summary.length() > 30)
       return false;
    return true;   
}

bool Check::Check_Code(string code)
{
    if(code.length() != 7)
       return false;
    for(int i = 0; i < code.length(); i++)
       if(isdigit(code[i]) == 0)
         return false;
    return true;        

}
