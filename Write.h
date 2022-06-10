#include <iostream>
#include <string>
#include <vector>


using namespace std;

class WriteToProgram
{
public:
   void Welcome();

   void animation_Flash(string);
   void animation_Of_Hello();
   void space();
   void line();
   void star();
   void EmpyLine(int);
   void GetUsername();
   void GetPassword();
   void TryAgain();
   void WrongMassage();
   void GuideMassage();
   void Do();
   void User_Notfound();

   void Edit_UStart1();
   void Edit_UStart2();

   void Edit_UStart3(string = "NULL");

};

void WriteToProgram::Welcome()
{
    space();
    cout << "***********************************************************************" << endl;
    space();
    cout << "*******" << "                                                         "    << "*******" << endl;
    space();
    cout << "*******Hello and welcome to Amir Kabir University Library System*******" << endl;
    space();
    cout << "*******" << "                                                         "    << "*******" << endl;
    space();
    cout << "***********************************************************************" << endl;
}


void WriteToProgram:: animation_Flash(string str) 
{
  for(int i = 0; i < 3; i++)
    cout <<"            *****************************            " << endl;
    
    cout << "            " << "            "<< str << "          " << "            " << endl; 

    int star = 10;
    for(int i = 0; i < 10; i++)
    {
        cout << "                 ";
        for(int j = 0 ; j < i ; j++)
          cout << " ";
        for(int j = 0; j < 2*star; j++)
          cout << "*";  
        for(int j = 0 ; j < i ; j++)
          cout << " ";

        cout << "                 ";
        cout << endl;
        star--;
    }
}



void WriteToProgram::animation_Of_Hello()
{
    cout << "      HHHHH" << "             " << "HHHHH" << "        " << "EEEEEEEEEEEE" << "    LLL           " << "      " << "LLL           "  <<  "     "  << "                O                " << endl;
    cout << "      HHHHH" << "             " << "HHHHH" << "        " << "EEEEEEEEEEEE" << "    LLL           " << "      " << "LLL           "  <<  "     "  << "               OOO               " << endl;
    cout << "      HHHHH" << "             " << "HHHHH" << "        " << "EEE         " << "    LLL           " << "      " << "LLL           "  <<  "     "  << "            OOO   OOO            " << endl;
    cout << "      HHHHH" << "             " << "HHHHH" << "        " << "EEE         " << "    LLL           " << "      " << "LLL           "  <<  "     "  << "         OOO         OOO         " << endl;
    cout << "      HHHHH" << "             " << "HHHHH" << "        " << "EEE         " << "    LLL           " << "      " << "LLL           "  <<  "     "  << "      OOO               OOO      " << endl;
    cout << "      HHHHH" << "HHHHHHHHHHHHH" << "HHHHH" << "        " << "EEEEEEEEEEEE" << "    LLL           " << "      " << "LLL           "  <<  "     "  << "   OOO                     OOO   " << endl;
    cout << "      HHHHH" << "HHHHHHHHHHHHH" << "HHHHH" << "        " << "EEEEEEEEEEEE" << "    LLL           " << "      " << "LLL           "  <<  "     "  << "OOO                           OOO" << endl;
    cout << "      HHHHH" << "HHHHHHHHHHHHH" << "HHHHH" << "        " << "EEEEEEEEEEEE" << "    LLL           " << "      " << "LLL           "  <<  "     "  << "   OOO                     OOO   " << endl;
    cout << "      HHHHH" << "             " << "HHHHH" << "        " << "EEE         " << "    LLL           " << "      " << "LLL           "  <<  "     "  << "      OOO               OOO      " << endl;
    cout << "      HHHHH" << "             " << "HHHHH" << "        " << "EEE         " << "    LLL           " << "      " << "LLL           "  <<  "     "  << "         OOO         OOO         " << endl;
    cout << "      HHHHH" << "             " << "HHHHH" << "        " << "EEE         " << "    LLL           " << "      " << "LLL           "  <<  "     "  << "            OOO   OOO            " << endl;
    cout << "      HHHHH" << "             " << "HHHHH" << "        " << "EEEEEEEEEEEE" << "    LLLLLLLLLLLLLL" << "      " << "LLLLLLLLLLLLLL"  <<  "     "  << "               OOO               " << endl;
    cout << "      HHHHH" << "             " << "HHHHH" << "        " << "EEEEEEEEEEEE" << "    LLLLLLLLLLLLLL" << "      " << "LLLLLLLLLLLLLL"  <<  "     "  << "                O                " << endl;
}



void WriteToProgram::space()
{
   for(int i = 0; i < 10; i++)
      cout << " ";
}


void WriteToProgram::line()
{
    cout <<"--------------------------------------------------------------------------------------------------->" << endl;
}


void WriteToProgram::star()
{
    cout << "***************************************************************************************************" << endl;
}


void WriteToProgram::EmpyLine(int counter)
{
  for(int i = 0; i < counter; i++)
     cout << "                                                                                           " << endl;
}
void WriteToProgram::GetUsername()
{
  cout << "Please enter your username : " ;
}
void WriteToProgram::GetPassword()
{
  cout << "Please enter your password : " ;
}

void WriteToProgram::TryAgain()
{
  cout << "------->Please try again" << endl;
}
void WriteToProgram::WrongMassage()
{
  cout << "****************************************Wrong****************************************" << endl;
}
void WriteToProgram::GuideMassage()
{
    cout << "---->Do you want to see the help in this section?" << endl;
    cout << "Yes or NO?" << endl << "              Type Yes or No      :     " ;
  
}

void WriteToProgram::Do()
{
    cout << "what do you want to do????" ;
}


void WriteToProgram::Edit_UStart1()
{
   cout << "Enter the username, the user whose information you want to change : " ; 
}

void WriteToProgram::User_Notfound()
{
  cout << "User not found :(" << endl;
}

void WriteToProgram::Edit_UStart3(string part)
{
  cout << "Enter the new " << part << " : " ;
}







