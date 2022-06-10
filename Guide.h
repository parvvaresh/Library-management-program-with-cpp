#include <iostream>
#include <string>
#include <vector>

#include "Write.h"

using namespace std;

class Guide
{
public:
   


   //abouy user:)
   void Guide_Of_Login_User();
   void Guide_Of_Edit_User();
   void Guide_Of_Delete_User();
   void Guide_Of_Add_User();
   void Guide_Of_User();
   void Guide_Of_Admin();
   void Guide_Of_Part();

   void Guide_Of_Email();
   void Guide_Of_Mobile();
   void Guide_Of_Password();
   void Guide_Of_Username();
   void Guide_Of_Name(string);
   void Guide_Of_Adjust();
   void Select_User();
   //about book
   void Guide_Of_Code();
   void Guide_Of_NameB();
   void Guide_Of_Writer();
   void Guide_Of_Genre();
   void Guide_Of_Situation();
   void Guide_Of_Description();
   void Guide_Of_Delete_Book();
   void Guide_Of_Edit_Book();
   void Guide_Of_Add_Book();
   void Guide_Of_PartB();
   void Guide_Of_Search();
   void Guide_Of_See();
   void Guide_Of_SelectAdmin();
   void Guide_Of_SelectUser();







   


   
private:
    vector <string> comment;
    WriteToProgram WTP;
    
    



};






void Guide::Guide_Of_Login_User()
{
    WTP.animation_Flash("Guide_Of_LogIn");
    cout << "Please enter your username and password for signing in:)" << endl;
    cout << " *Attention*>>> your username is your student number" << endl;
  
}







void Guide::Guide_Of_Add_User()
{
  cout << "In this section you can add new users For adding users  enter  : "<< endl ;

  cout << "-->User name" << endl;
  cout << "--->Consider an example : 99xxxxx or 400xxxxx" << endl;
  cout << "---->*Attention* : Only numbers are allowed" << endl;
  WTP.line();
 


  cout << "-->First name" <<endl;
  cout << "--->Consider an example : alireza" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  WTP.line();

 

  cout << "-->Last name" << endl;
  cout << "--->Consider an example : parvaresh" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  WTP.line();

  

  cout << "-->Phone number" << endl;
  cout << "--->Consider an example : 09xxxxxxxxx" << endl;
  cout << "---->*Attention* : Only numbers are allowed" << endl;
  WTP.line();

  

  cout << "-->Email address" << endl;
  cout << "--->Consider an example : xxxxxxx@gmail.com" << endl;
  WTP.line();



  cout << "-->Password" << endl;
  cout << "--->Consider an example : fhjsdhgjhs" << endl;
  cout << "---->*Attention* : The number of characters in the password should not be less than five" << endl;
  
  cout << "-->Postion" << endl;
  cout << "--->Consider an example : admin or user" << endl;
  WTP.line();

  
  

 

 
  WTP.star();
  cout << "***************************************************************************************************" << endl;
  cout << "~~~Attention" << endl;
  cout << "    --->your id is your student number!" << endl;
}

void Guide::Guide_Of_Edit_User()
{
  cout << "In this section you can edit user's information .First, enter id number then enter the parts that you want to edit.After selecting desired part, please enter new information and wait.." << endl;
  cout << "***************************************************************************************************" << endl;

  cout << "~~~Attention" << endl;
  cout << "    --->id is student number!" << endl;

}

void Guide::Guide_Of_Delete_User()
{
  
  cout << "In this section, you can delete user by entering :" << endl;
  cout << "-->Identification number" << endl;

  cout << "***************************************************************************************************" << endl;
  cout << "~~~Attention" << endl;
  cout << "    --->id is  student number!" << endl;
}


void Guide::Guide_Of_Password()
{
    cout << "-->Password" << endl;
    cout << "--->Consider an example : fhjsdhgjhs" << endl;
    cout << "---->*Attention* : The number of characters in the password should not be less than five" << endl;
  
}

void Guide::Guide_Of_Username()
{
  cout << "-->User name" << endl;
  cout << "--->Consider an example : 99xxxxx or 400xxxxx" << endl;
  cout << "---->*Attention* : Only numbers are allowed" << endl;
  WTP.line();
}

void Guide::Guide_Of_Admin()
{

    cout << "******************************welcome******************************" << endl;
    cout << "-->You are logged in as an admin" << endl;
    cout << "Your features as an admin are  : " << endl;
    cout << "  ->About Users" << endl;
    cout << "     ->Add user" << endl;
    cout << "     ->Delete user" << endl;
    cout << "     ->Edit user information" << endl;
    cout << "     ->Adjust user access level" << endl;
    cout << "  ->About Books" << endl;
    cout << "     ->Add book information about users" << endl;
    cout << "     ->Edit book information" << endl;
    cout << "     ->Delete book" << endl;
    cout << "     ->Search Books" << endl;
    cout << "     ->See List Of Books" << endl;



    WTP.line();
    WTP.line();
    WTP.line();
    WTP.line();
    cout << "                                       ;)                                   " << endl;

    

}
void Guide::Guide_Of_SelectAdmin()
{
      cout << "--------------------------->To Add user, write (Add_User)<--------------------------" << endl;
      cout << "--------------------------->To Delete user, write (Delete_User)<--------------------------" << endl;
      cout << "--------------------------->To Edit Books, write (Edit_User)<--------------------------" << endl;

      cout << "--------------------------->To Edit information user, write (Edit_User)<--------------------------" << endl;
      cout << "--------------------------->To Adjust Level, write (Adjust_Level)<--------------------------" << endl;
      cout << "--------------------------->To Add Book, write (Add_Book)<--------------------------" << endl;
      cout << "--------------------------->To Delete Book, write (Delete_Book)<--------------------------" << endl;
      cout << "--------------------------->To Search_Book, write (Search_Book)<--------------------------" << endl;
      cout << "--------------------------->To See Books, write (SeeBooks)<--------------------------" << endl;

      cout << "--------------------------->To exit, write (Exit)<--------------------------" << endl;

      cout <<"---------------->For your comfort, exactly copy these parts>----------------" << endl;

}
void Guide::Guide_Of_SelectUser()
{
      cout << "--------------------------->To Search_Book, write (Search_Book)<--------------------------" << endl;
      cout << "--------------------------->To See Books, write (SeeBooks)<--------------------------" << endl;
      cout << "--------------------------->To exit, write (Exit)<--------------------------" << endl;

      cout <<"---------------->For your comfort, exactly copy these parts>----------------" << endl;



}
void Guide::Guide_Of_Part()
{
  cout << "Choose one between (First name, Last name, Mobile, Email, Username, Password)" << endl;
  cout << "which one ? " ;
}

void Guide::Guide_Of_Email()
{
  cout << "-->Email address" << endl;
  cout << "--->Consider an example : xxxxxxx@gmail.com" << endl;
  WTP.line();

}

void Guide::Guide_Of_Mobile()
{
  cout << "-->Phone number" << endl;
  cout << "--->Consider an example : 09xxxxxxxxx" << endl;
  cout << "---->*Attention* : Only numbers are allowed" << endl;
  WTP.line();

}

void Guide::Guide_Of_Name(string name)
{
  if(name == "L")
  {

  cout << "-->Last name" << endl;
  cout << "--->Consider an example : parvaresh" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  WTP.line();

  }


  if(name == "F")
  {

  cout << "-->First name" <<endl;
  cout << "--->Consider an example : alireza" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  WTP.line();

  }
}

void Guide::Guide_Of_Adjust()
{
  cout << "-->Postion" << endl;
  cout << "--->Consider an example : admin or user" << endl;
}

void Guide::Guide_Of_Add_Book()
{
  cout << "In this section you can add new books For adding users  enter  : "<< endl ;

  cout << "-->Code" << endl;
  cout << "--->Consider an example : 9678201" << endl;
  cout << "---->*Attention* : Only numbers are allowed" << endl;
  WTP.line();
 


  cout << "-->Name Book" <<endl;
  cout << "--->Consider an example : Hafez" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  WTP.line();

 

  cout << "-->Genre" << endl;
  cout << "--->Consider an example : Action" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  WTP.line();

  

  cout << "-->Writer" << endl;
  cout << "--->Consider an example : Ferdowsi" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  
  WTP.line();

  

  cout << "-->Situation" << endl;
  cout << "--->Consider an example : xxxxxxx@gmail.com" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;

  WTP.line();



  cout << "-->Description" << endl;
  cout << "--->Consider an example : " << endl;
  cout << "---->*Attention* : The number of characters in the Description should not be more than thirty" << endl;
  
  WTP.line();

  
  

 

 
  WTP.star();

}
void Guide::Guide_Of_Code()
{
  cout << "-->Code" << endl;
  cout << "--->Consider an example : 9678201" << endl;
  cout << "---->*Attention* : Only numbers are allowed" << endl;
  WTP.line();
}
void Guide::Guide_Of_NameB()
{
  cout << "-->Name Book" <<endl;
  cout << "--->Consider an example : Hafez" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  WTP.line();

}
void Guide::Guide_Of_Writer()
{
  cout << "-->Writer" << endl;
  cout << "--->Consider an example : Ferdowsi" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  WTP.line();

}
void Guide::Guide_Of_Genre()
{
  cout << "-->Genre" << endl;
  cout << "--->Consider an example : Action" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  WTP.line();

}
void Guide::Guide_Of_Situation()
{
  cout << "-->Situation" << endl;
  cout << "--->Consider an example : Unavailable or Available" << endl;
  cout << "---->*Attention* : Only letters are allowed <-------> Do not use punctuation marks, etc..." << endl;
  WTP.line();

}
void Guide::Guide_Of_Description()
{
  cout << "-->Description" << endl;
  cout << "--->Consider an example : " << endl;
  cout << "---->*Attention* : The number of characters in the Description should not be more than thirty" << endl;
  WTP.line();

}
void Guide::Guide_Of_Delete_Book()
{
  cout << "-->You should enter the code of the book if you want delete that book ;)" << endl;
}
void Guide::Guide_Of_Edit_Book()
{
  cout << "-->For edit the information at first you should enter the code of book and then enter the part that you want delete and then enter the information of that part" << endl;
}
void Guide::Guide_Of_PartB()
{
  cout << "The editable sections are:" << endl;
  cout << "-->Name" << endl;
  cout << "-->Writer" << endl;
  cout << "-->Genre" << endl;
  cout << "-->Description" << endl;
  cout << "-->Situation" << endl;
  cout << "-->Code" << endl;
  cout << "---->*Attention* : The number of characters in the Description should not be more than thirty" << endl;
        cout <<"---------------->For your comfort, exactly copy these parts>----------------" << endl;


  


}
void Guide::Guide_Of_Search()
{
  cout << "You can search for books based on the following: " << endl;
  cout << "Name--Writer--Code--Genre--Situation" << endl;
  cout << "**For your comfort, exactly copy these parts." << endl;

}
void Guide::Guide_Of_See()
{
  cout << "-->Here you can see the list of books page by page and click on the word (Yes) to go to the next page" << endl;
  cout << "are you ready? " << " If you are ready, write yes :" ; 
}
void Guide::Guide_Of_User()
{
    cout << "******************************welcome******************************" << endl;
    cout << "-->You are logged in as an user" << endl;
    cout << "--->Your features as an user are  : " << endl;
    cout << "    ->About Books" << endl;
    cout << "       ->Search the books" << endl;
    cout << "       ->See the list of books in pagination" << endl;



    WTP.line();
    WTP.line();
    WTP.line();
    WTP.line();
  
    cout << "                                       ;)                                   " << endl;


}
void Guide::Select_User()
{

      cout << "--------------------------->To Search_Book, write (Search_Book)<--------------------------" << endl;
      cout << "--------------------------->To See Books, write (SeeBooks)<--------------------------" << endl;
      cout << "--------------------------->To exit, write (Exit)<--------------------------" << endl;

      cout <<"---------------->For your comfort, exactly copy these parts>----------------" << endl;

}