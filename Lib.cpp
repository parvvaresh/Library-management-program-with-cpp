#include <iostream>
#include <string>
#include <vector>
#include <ctime>


#include "Login.h"
#include "Check.h"
#include "Admin.h"
#include "Bookinfo.h"
#include "Time.h"
#include "Guide.h"

using namespace std;

int main()
{
   Check ck;
   Time T;
   WriteToProgram WTP;
   WTP.animation_Of_Hello();
   WTP.Welcome();
   WTP.EmpyLine(3);
   WTP.line();

   Guide GDE;
   GDE.Guide_Of_Login_User();


   string username, password;

   WTP.GetUsername();
   cin >> username;    
   while(ck.Check_Username(username) != true)
   {
        WTP.WrongMassage();
        WTP.GuideMassage();
        string G;
        cin >> G;
        if(G == "Yes")
           GDE.Guide_Of_Username();   
        WTP.GetUsername();
        cin >> username;  
   }

   WTP.GetPassword();
   cin >> password;
   while(ck.Check_Password(password) != true)
   {
        WTP.WrongMassage();
        WTP.GuideMassage();
        string G;
        cin >> G;
        if(G == "Yes")
           GDE.Guide_Of_Password();   
        WTP.GetPassword();
        cin >> password;
   }



   Login Lg;
   Lg.Login_To_Profile(password, username);





   if(Lg.Get_Position(username) == "admin" && Lg.Check_Login(username, password) == true)
   {
      
       
       WTP.Welcome();
       GDE.Guide_Of_Admin();
       AdminUser ad;
       AdminBook adB;
       BookInfo bi;

       GDE.Guide_Of_SelectAdmin();
       WTP.Do();
       string user;
       cin >> user;
           time_t l = time(NULL);
           char* timee = ctime(&l);
           T.Login(timee, username, "Admin", "Sucsses");
       while(user != "Exit") 
       {
          if(user == "Add_User")
          {
            GDE.Guide_Of_Add_User();

            string username_test;
            GDE.Guide_Of_Username();  
            cout << "Username, enter new user : " ;
            cin >> username_test;
            while(ck.Check_Username(username_test) != true)
             {
                  WTP.WrongMassage();
                  WTP.GuideMassage();
                  string G;
                  cin >> G;
                  if(G == "Yes")
                      GDE.Guide_Of_Username();   
                 cout << "Username, enter new user : " ;
                 cin >> username_test;  
            }

            string password_test;
            GDE.Guide_Of_Password();   

            cout << "password, enter new user : " ;
            cin >> password_test;

            while(ck.Check_Password(password_test) != true)
             {
                  WTP.WrongMassage();
                  WTP.GuideMassage();
                  string G;
                  cin >> G;
                  if(G == "Yes")
                      GDE.Guide_Of_Password();   
                 cout << "password, enter new user : " ;
                 cin >> password_test;  
            }
            if(ad.Check_User(password_test) == true || ad.Check_User(username_test) == true)
            {
                 cout << "Previously registered password or username :(" << endl;
                 cout << "You can edit the user :))))" << endl;
                 WTP.TryAgain();
                 time_t now = time(0);
                 string time = ctime(&now);
                 T.Add_User(time, username, username_test, " Not Sucsses");
            }
            else
            {
                 string lastname_test;
                 GDE.Guide_Of_Name("L");
                 cout << "Lastname, enter new user : " ;
                 cin >> lastname_test;
                 while(ck.Check_Name(lastname_test) != true)
                    {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                              GDE.Guide_Of_Name("L");


                         cout << "Lastname, enter new user : " ;
                         cin >> lastname_test;
                    }


                 string firstname_test;
                 GDE.Guide_Of_Name("F");

                 cout << "Firstname, enter new user : " ;
                 cin >> firstname_test;
                 while(ck.Check_Name(firstname_test) != true)
                    {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                              GDE.Guide_Of_Name("F");

                         cout << "Firstname, enter new user : " ;
                         cin >> firstname_test;
                    } 


                  string mobile_test;
                  GDE.Guide_Of_Mobile();

                  cout << "Mobile, enter new user : " ;
                  cin >> mobile_test;  
                  while(ck.Check_Mobile(mobile_test) != true)
                    {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                              GDE.Guide_Of_Mobile();
                         cout << "Mobile, enter new user : " ;

                         cin >> mobile_test;
                    }

                    
                  string email_test;
                  GDE.Guide_Of_Email();

                  cout << "Email, enter new user : " ;
                  cin >> email_test;  
                  while(ck.Check_Email(email_test) != true)
                    {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                              GDE.Guide_Of_Email();
                         cout << "Email, enter new user : " ;
                        
                         cin >> email_test;
                    }



                  string postion_test;
                  GDE.Guide_Of_Adjust();

                  cout << "position, enter new user : " ;
                  cin >> postion_test;  
                  while(ck.Check_Adjust(postion_test) != true)
                    {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                              GDE.Guide_Of_Adjust();
                         cout << "position, enter new user : " ;

                         cin >> postion_test;
                    }
                   cout <<":)" << endl;
                  if(ad.Check_User(email_test) == true || ad.Check_User(mobile_test) == true)  
                  {
                       if(ad.Check_User(email_test) == true){cout << "This Email is already registered" << endl;}
                       else if( ad.Check_User(mobile_test) == true){cout << "This mobile number is already registered" << endl;}
                       time_t now = time(0);
                       char *time = ctime(&now);
                       T.Add_User(time, username, username_test, " Not Sucsses");
                  }
                  else
                  {
                       ad.AddUser(firstname_test,  lastname_test,  mobile_test,  email_test,  username_test,  password_test,  postion_test);
                       cout << "User registered in the list :)" << endl;

                       time_t now = time(0);
                       char *time = ctime(&now);
                       T.Add_User(time, username, username_test, "Sucsses");
                  }

            }
          }
           else if(user == "Delete_User")
          {
           string username_test;
           GDE.Guide_Of_Username();  

           cout <<  "inter The username of that user who you want delete : " ; ;
           cin >> username_test;
           while(ck.Check_Username(username_test) != true)
             {
                  WTP.WrongMassage();
                  WTP.GuideMassage();
                  string G;
                  cin >> G;
                  if(G == "Yes")
                      GDE.Guide_Of_Username();  
                  cout <<  "inter The username of that user who you want delete : " ;

                 cin >> username_test;  
            }
            if(ad.Check_User(username_test) == true)
            {
               ad.DeleteUser(username_test);
               time_t now = time(0);
               char *time = ctime(&now);
               T.Add_User(time, username, username_test, "Sucsses");
 
            }
            else
            {
                  time_t now = time(0);
                  char *time = ctime(&now);
                  T.Add_User(time, username, username_test, "Not Sucsses");
                  cout << "User not found :(" << endl;
            }

          }
           else if(user == "Edit_User")
          {
             string username_test;
             GDE.Guide_Of_Username();   

             WTP.Edit_UStart1();
             cin >> username_test;
            while(ck.Check_Username(username_test) != true)
             { 
                 WTP.WrongMassage();
                 WTP.GuideMassage();
                 string user;
                 cin >> user;
                  if(user == "Yes")
                      GDE.Guide_Of_Username();   
                 WTP.GetUsername();
                 cin >> username_test;  
            }

           if(ad.Check_User(username_test) == true) 
            {  
               string part_test;
               GDE.Guide_Of_Part();
               cin >> part_test;
              
               if(part_test == "Firstname")
               {
                    GDE.Guide_Of_Name("F");

                    string Firstname; 
                    WTP.Edit_UStart3(part_test);
                    cin >> Firstname;
                    while(ck.Check_Name(Firstname) != true)
                    {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                             GDE.Guide_Of_Name("F");
                         WTP.Edit_UStart3(part_test);


                         cin >> Firstname;
                    }
                    ad.EditUser(username_test,part_test, Firstname);
                    time_t now = time(0);
                    char *time = ctime(&now);
                    T.Edit_User(time, username,"Firstname" , username_test, "Sucsses");

               }
               else if(part_test == "Lastname")
               {
                    GDE.Guide_Of_Name("L");

                    string Lastname; 
                    WTP.Edit_UStart3(part_test);
                    cin >> Lastname;
                    while(ck.Check_Name(Lastname) != true)
                    {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                              GDE.Guide_Of_Name("L");


                         WTP.Edit_UStart3(part_test);
                         cin >> Lastname;
                    }
                    ad.EditUser(username_test,part_test, Lastname);
                    time_t now = time(0);
                    char *time = ctime(&now);
                    T.Edit_User(time, username,"Lastname" , username_test, "Sucsses");
               }
               else if(part_test == "Mobile")
               {
                    GDE.Guide_Of_Mobile();

                    string Mobile; 
                    WTP.Edit_UStart3(part_test);
                    cin >> Mobile;
                    while(ck.Check_Mobile(Mobile) != true)
                    {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                              GDE.Guide_Of_Mobile();
                          
                         WTP.Edit_UStart3(part_test);
                         cin >> Mobile;
                    }
                    if(ad.Check_User(Mobile) == false)
                    {
                         ad.EditUser(username_test,part_test, Mobile); 
                         time_t now = time(0);
                         char *time = ctime(&now);
                         T.Edit_User(time, username,"Mobile" , username_test, "Sucsses");
                    }
                       
                    else
                    {
                         cout << "This mobile number is already registered" << endl;
                         time_t now = time(0);
                         char *time = ctime(&now);
                         T.Edit_User(time, username,"Mobile" , username_test, "Not Sucsses");
                    }
                      
             
               }
               else if(part_test == "Email")
               {
                    GDE.Guide_Of_Email();

                    string Email; 
                    WTP.Edit_UStart3(part_test);
                    cin >> Email;
                    while(ck.Check_Email(Email) != true)
                    {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                             GDE.Guide_Of_Email();
 
                         WTP.Edit_UStart3(part_test);
                         cin >> Email;
                    }
                    if(ad.Check_User(Email) == false)
                    {
                         ad.EditUser(username_test,part_test, Email);
                         time_t now = time(0);
                         char *time = ctime(&now);
                         T.Edit_User(time, username,"Email" , username_test, "Sucsses"); 
                    }
                       
                    else
                    {
                       cout << "This Email is already registered" << endl; 
                       time_t now = time(0);
                       char *time = ctime(&now);
                       T.Edit_User(time, username,"Email" , username_test, "Not Sucsses"); 
                    }
                      
                   

                }
               else if(part_test == "Username")
                {
                    GDE.Guide_Of_Username();  

                    string Username; 
                    WTP.Edit_UStart3(part_test);
                    cin >> Username;
                    while(ck.Check_Username(Username) != true)
                    {
                         
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                           GDE.Guide_Of_Username();  
                         WTP.Edit_UStart3(part_test);   
                         cin >> Username;


                    }




                    if(ad.Check_User(Username) == false)
                    {
                         ad.EditUser(username_test,part_test, Username);
                         time_t now = time(0);
                         char *time = ctime(&now);
                         T.Edit_User(time, username,"Username" , username_test, "Not Sucsses"); 
                    }
                    else
                    {
                         cout << "This Username is already registered" << endl;
                         time_t now = time(0);
                         char *time = ctime(&now);
                         T.Edit_User(time, username,"Username" , username_test, "Not Sucsses"); 
                    }
                      
                 

                }
               else if(part_test == "Password")
               {

                    GDE.Guide_Of_Password();   

                    string Password; 
                    WTP.Edit_UStart3(part_test);
                    cin >> Password;
                    while(ck.Check_Password(Password) != true)
                    {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                             GDE.Guide_Of_Password();   
                         WTP.Edit_UStart3(part_test);
                  
                         cin >> Password;
                      
                    }


                    if(ad.Check_User(Password) == false)
                    {
                         ad.EditUser(username_test,part_test, Password);
                         time_t now = time(0);
                         char *time = ctime(&now);
                         T.Edit_User(time, username,"Password" , username_test, "Sucsses");
 
                    }
                    else
                    {
                         cout << "This Password is already registered" << endl;
                         time_t now = time(0);
                         char *time = ctime(&now);
                         T.Edit_User(time, username,"Password" , username_test, "Not Sucsses"); 
                    }
                     
                 

               }
            } 


           else
           {
               WTP.User_Notfound();
               WTP.TryAgain();
               time_t now = time(0);
               char *time = ctime(&now);
               T.Edit_User(time, username,"NULL" , username_test, "Not Sucsses");

          }  

       }



       else if(user == "Adjust_Level")
        {
            string level_test;
            string username_test;
            GDE.Guide_Of_Username();   

            cout << "inter user of username who you want to change his level : ";
            cin >> username_test;
            while(ck.Check_Username(username_test) != true)
            { 
                 WTP.WrongMassage();
                 WTP.GuideMassage();
                 string G;
                 cin >> G;
                  if(G == "Yes")
                      GDE.Guide_Of_Username();   
                 cout << "inter user of username who you want to change his level : ";
                 cin >> username_test;  
            }
            GDE.Guide_Of_Adjust(); 
            cout << "user or admin ? ";
          
            cin >> level_test;



            while(ck.Check_Adjust(level_test) != true)
            {
                 
                    WTP.WrongMassage();
                    WTP.GuideMassage();
                    string G;
                    cin >> G;
                    if(G == "Yes")
                          GDE.Guide_Of_Adjust();   
                    cout << "user or admin ? ";
                    cin >> level_test;
            }
            if(ad.Check_User(username_test) == true)
            {
               ad.Adjust_Level(username_test, level_test);
               cout << ":)" << endl;
               time_t now = time(0);
               string time = ctime(&now);
               T.Adjust_User(time,username,username_test,"Sucsses");

            }
            else
            {
               time_t now = time(0);
               string time = ctime(&now);
               cout << "User not found :(" << endl;
               T.Adjust_User(time, username, username_test,"Not Sucsses");


            }

        }
        else if(user == "Add_Book")
       {
              GDE.Guide_Of_Add_Book();
              string code_test;
              GDE.Guide_Of_Code();

              cout << "Enter the Code of the new book : " ;
              cin >> code_test;
              while(ck.Check_Code(code_test) != true)
              {
                  WTP.WrongMassage();
                  WTP.GuideMassage();
                  string G;
                  cin >> G;
                  if(G == "Yes")
                      GDE.Guide_Of_Code();
                  cout << "Enter the Code of the new book : " ;
                  cin >> code_test;    

              }
              if(adB.Check_Book(code_test) == true)
              {
                   cout << "This book has already been registered with this code :(" << endl;
                   time_t now = time(0);
                   string time = ctime(&now);
                   T.Add_Book(time, username, code_test,"Not Sucsses");

              }
              else
              {
                     string name_test;
                     GDE.Guide_Of_NameB();

                     cout << "Enter the Name of the new book : " ;

                     cin >> name_test;
                     while(ck.Check_NameBook(name_test) != true)
                      {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                            GDE.Guide_Of_NameB();
                         cout << "Enter the Name of the new book : " ;
                         cin >> name_test;    
                      }
                     string writer_test ;
                     GDE.Guide_Of_Writer();

                     cout << "Enter the Writer of the new book : " ;
                     cin >> writer_test;
                     while(ck.Check_Writer(writer_test) != true)
                      {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                            GDE.Guide_Of_Writer();
                         cout << "Enter the Writer of the new book : " ;
                         cin >> writer_test;    
                      }

                     string genre_test;
                     GDE.Guide_Of_Genre();

                     cout << "Enter the Genre of the new book : " ;
                     cin >> genre_test;
                     while(ck.Check_Genre(genre_test) != true)
                      {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                            GDE.Guide_Of_Genre();
                         cout << "Enter the Genre of the new book : " ;
                         cin >> genre_test;

                     }
                     string situation_test;
                     GDE.Guide_Of_Situation();

                     cout << "Enter the Situation of the new book : " ;
                     cin >> situation_test;
                     while(ck.Check_Situation(situation_test) != true)
                      {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                            GDE.Guide_Of_Situation();
                         cout << "Enter the Situation of the new book : " ;
                         cin >> situation_test;

                     }
                     
                     string description_test;
                     GDE.Guide_Of_Description();

                     cout << "Enter the Description of the new book : " ;
                     cin >> description_test;
                     while(ck.Check_Description(description_test) != true)
                      {
                         WTP.WrongMassage();
                         WTP.GuideMassage();
                         string G;
                         cin >> G;
                         if(G == "Yes")
                            GDE.Guide_Of_Description();
                         cout << "Enter the Description of the new book : " ;
                         cin >> description_test;

                     }
                    adB.AddBook(name_test, code_test, writer_test, genre_test, situation_test, description_test);
                    time_t now = time(0);
                    string time = ctime(&now);
                    T.Add_Book(time, username, code_test,"Sucsses");
            }
       }

       else if(user == "Delete_Book")
       {
           GDE.Guide_Of_Delete_Book();
           string code_test;
           GDE.Guide_Of_Code(); 

           cout <<  "Enter The code of that book who you want delete : " ; ;
           cin >> code_test;
           while(ck.Check_Code(code_test) != true)
             {
                  WTP.WrongMassage();
                  WTP.GuideMassage();
                  string G;
                  cin >> G;
                  if(G == "Yes")
                      GDE.Guide_Of_Code(); 
                  cout <<  "Enter The code of that book who you want delete : " ; ;
    
                  cin >> code_test;
 

            }
            if(adB.Check_Book(code_test) == true)
            {
               adB.DeleteBook(code_test);
               time_t now = time(0);
               string time = ctime(&now);
               T.Delete_Book(time, username, code_test,"Sucsses");
               
            }
            else
            {
               cout << "Book not found :(" << endl;
               time_t now = time(0);
               string time = ctime(&now);
               T.Delete_Book(time, username, code_test,"Not Sucsses");

            }

       }

       else if (user == "Edit_Book")
       {
             GDE.Guide_Of_Edit_Book();
             GDE.Guide_Of_Code();
             string code_test;
             cout << "Enter the code of the book whose information you want to edit : " ;
             cin >> code_test;
              while(ck.Check_Code(code_test) != true)
              {
                  WTP.WrongMassage();
                  WTP.GuideMassage();
                  string G;
                  cin >> G;
                  if(G == "Yes")
                      GDE.Guide_Of_Code();
                  cout << "Enter the code of the book whose information you want to edit : " ;

                  cin >> code_test;    

              }
              if(adB.Check_Book(code_test) == true)
              {
                     string part_test;
                     GDE.Guide_Of_PartB();
                     cin >> part_test;
                     if(part_test == "Name")
                     {
                           string name_test;
                          GDE.Guide_Of_NameB();

                           cout << "Enter the new Name of the book : " ;

                            cin >> name_test;
                            while(ck.Check_NameBook(name_test) != true)
                           {
                               WTP.WrongMassage();
                               WTP.GuideMassage();
                               string G;
                               cin >> G;
                               if(G == "Yes")
                                 GDE.Guide_Of_NameB();
                               cout << "Enter the new Name of the book : " ;
                               cin >> name_test;    
                           }
                            adB.EditBook(code_test, part_test, name_test);
                            time_t now = time(0);
                            string time = ctime(&now);
                            T.Edit_Book(time, username, "Name" ,code_test,"Sucsses");


                     }
                     else if(part_test == "Writer")
                     {
                            string writer_test ;
                            GDE.Guide_Of_Writer();


                            cout << "Enter the new Writer of the book : " ;
                            cin >> writer_test;
                            while(ck.Check_Writer(writer_test) != true)
                            {
                                 WTP.WrongMassage();
                                 WTP.GuideMassage();
                                 string G;
                                 cin >> G;
                                 if(G == "Yes")
                                    GDE.Guide_Of_Writer();
                                 cout << "Enter the new Writer of the book : " ;
                                 cin >> writer_test;    
                            }
                            adB.EditBook(code_test, part_test, writer_test);
                            time_t now = time(0);
                            string time = ctime(&now);
                            T.Edit_Book(time, username, "Writer" ,code_test,"Sucsses");



                     }
                     else if(part_test == "Genre")
                     {
                            string genre_test;
                            GDE.Guide_Of_Genre();

                            cout << "Enter the new Genre of the book : " ;
                            cin >> genre_test;
                            while(ck.Check_Genre(genre_test) != true)
                           {
                                   WTP.WrongMassage();
                                   WTP.GuideMassage();
                                   string G;
                                   cin >> G;
                                   if(G == "Yes")
                                      GDE.Guide_Of_Genre();
                                  cout << "Enter the new Genre of the book : " ;
                                  cin >> genre_test;

                            }
                            adB.EditBook(code_test, part_test, genre_test);
                            time_t now = time(0);
                            string time = ctime(&now);
                            T.Edit_Book(time, username, "Genre" ,code_test,"Sucsses");


                     }
                     else if(part_test == "Description")
                     {
                          string description_test;
                          GDE.Guide_Of_Description();

                          cout << "Enter the new Description of the book : " ;
                          cin >> description_test;
                          while(ck.Check_Description(description_test) != true)
                         {
                                WTP.WrongMassage();
                                WTP.GuideMassage();
                                string G;
                                cin >> G;
                                if(G == "Yes")
                                       GDE.Guide_Of_Description();
                                 cout << "Enter the new Description of the book : " ;
                                 cin >> description_test;
                         }
                          adB.EditBook(code_test, part_test, description_test);
                          time_t now = time(0);
                          string time = ctime(&now);
                          T.Edit_Book(time, username, "Description" ,code_test,"Sucsses");

                     }
                     else if(part_test == "Situation")
                     { 
                            string situation_test;
                            GDE.Guide_Of_Situation();

                            cout << "Enter the new Situation of the book : " ;
                            cin >> situation_test;
                            while(ck.Check_Situation(situation_test) != true)
                           {
                               WTP.WrongMassage();
                               WTP.GuideMassage();
                               string G;
                               cin >> G;
                               if(G == "Yes")
                                  GDE.Guide_Of_Situation();
                               cout << "Enter the new Situation of the book : " ;
                               cin >> situation_test;

                           }
                          adB.EditBook(code_test, part_test, situation_test);
                          time_t now = time(0);
                          string time = ctime(&now);
                          T.Edit_Book(time, username, "Situation" ,code_test,"Sucsses");
                          

                     }
                     else if(part_test == "Code")
                     {
                            string code_test;
                            GDE.Guide_Of_Code();
                            cout << "Enter the new Code of the book : " ;
                            cin >> code_test;
                            while(ck.Check_Code(code_test) != true)
                            {
                                   WTP.WrongMassage();
                                   WTP.GuideMassage();
                                   string G;
                                   cin >> G;
                                   if(G == "Yes")
                                      GDE.Guide_Of_Code();
                                   cout << "Enter the new Code of the book : " ;
                                   cin >> code_test;    

                            }
                            if(adB.Check_Book(code_test) == true)
                            {
                                   cout << "This code is used for other books :(" << endl;
                                   time_t now = time(0);
                                   string time = ctime(&now);
                                   T.Edit_Book(time, username, "Code" ,code_test,"Not Sucsses");
                            }
                            else
                            {
                                   adB.EditBook(code_test, part_test, code_test);
                                   time_t now = time(0);
                                   string time = ctime(&now);
                                   T.Edit_Book(time, username, "Code" ,code_test,"Sucsses");
  
                            }

                     }
              }
              else
              {
                     cout << "book not found :(" << endl;
                    time_t now = time(0);
                    string time = ctime(&now);
                    T.Edit_Book(time, username, "NULL" ,code_test,"Not Sucsses");


              }
              


       }


      else if(user == "Search_Book")
      {   
       GDE.Guide_Of_Search();
       string Search_type ;
       cout << "Please select : " ;
       cin >> Search_type;
       if(Search_type == "Writer")
        {
                  time_t now = time(0);
               string time = ctime(&now);
               T.Search_Book(time, username, "Writer");

              string writer_test ;
             GDE.Guide_Of_Writer();

              cout << "Please enter Writer : " ;

              cin >> writer_test;
              while(ck.Check_Writer(writer_test) != true)
              {
                     WTP.WrongMassage();
                     WTP.GuideMassage();
                     string G;
                     cin >> G;
                     if(G == "Yes")
                            GDE.Guide_Of_Writer();
                     cout << "Please enter Writer : " ;

                     cin >> writer_test;    
              }
              bi.Search("Writer",writer_test);
          
        }
       else if(Search_type == "Name")
        {
                time_t now = time(0);
               string time = ctime(&now);
               T.Search_Book(time, username, "Name");

              string name_test;
              GDE.Guide_Of_NameB();

              cout << "Please enter Name : " ;

              cin >> name_test;
              while(ck.Check_NameBook(name_test) != true)
              {
                     WTP.WrongMassage();
                     WTP.GuideMassage();
                     string G;
                     cin >> G;
                     if(G == "Yes")
                     GDE.Guide_Of_NameB();
                     cout << "Please enter Name : " ;

                     cin >> name_test;    
              }
              bi.Search("Name",name_test);
            


        }
       else if(Search_type == "Code")
        {
               time_t now = time(0);
               string time = ctime(&now);
               T.Search_Book(time, username, "Code");
              string code_test;
              GDE.Guide_Of_Code();
              cout << "Please enter Code : " ;

              cin >> code_test;
              while(ck.Check_Code(code_test) != true)
              {
                     WTP.WrongMassage();
                     WTP.GuideMassage();
                     string G;
                     cin >> G;
                     if(G == "Yes")
                            GDE.Guide_Of_Code();
                     cout << "Please enter Code : " ;
      
                     cin >> code_test;    

              }
              bi.Search("Code", code_test);
             


        }
       else if(Search_type == "Genre")
        {
                time_t now = time(0);
               string time = ctime(&now);
               T.Search_Book(time, username, "Genre");
              string genre_test;
              GDE.Guide_Of_Genre();

              cout << "Please enter Genre : " ;

              cin >> genre_test;
              while(ck.Check_Genre(genre_test) != true)
              {
                     WTP.WrongMassage();
                     WTP.GuideMassage();
                     string G;
                     cin >> G;
                     if(G == "Yes")
                            GDE.Guide_Of_Genre();
                     cout << "Please enter Genre : " ;

                     cin >> genre_test;

              }
              bi.Search("Genre", genre_test);
            

        }
       else if(Search_type == "Situation")
        {
              time_t now = time(0);
               string time = ctime(&now);
               T.Search_Book(time, username, "Situation");
              string situation_test;
              GDE.Guide_Of_Situation();
              cout << "Please enter Situation : " ;
              cin >> situation_test;
              while(ck.Check_Situation(situation_test) != true)
              {
                 WTP.WrongMassage();
                 WTP.GuideMassage();
                 string G;
                 cin >> G;
                 if(G == "Yes")
                      GDE.Guide_Of_Situation();
                 cout << "Please enter Situation : " ;

                 cin >> situation_test;

              }
              bi.Search("Situation", situation_test);
              
        }
       
      }
      else if(user == "SeeBooks")
       {
          GDE.Guide_Of_See();
          string G;
          cin >> G;
          if(G == "yes")
          {
                 
               time_t now = time(0);
               string time = ctime(&now);
               T.See_Book(time, username);   
                bi.See_List_Of_Book();
          }
       
       }
       GDE.Guide_Of_SelectAdmin();
       WTP.Do();
       cin >> user;









       }
       

   
   }
   else if(Lg.Get_Position(username) == "user" && Lg.Check_Login(username, password) == true)
   {
         time_t l = time(0);
         char *timee = ctime(&l);
         T.Login(timee, username, "Admin", "Sucsses");
           WTP.Welcome();
           GDE.Guide_Of_User();
           GDE.Select_User();
           BookInfo bi;


           WTP.Do();
           string user;
           cin >> user;
           while (user != "Exit")
           {
               if(user == "Search_Book")
               {   
                    GDE.Guide_Of_Search();
                    string Search_type ;
                    cout << "Please select : " ;
                    cin >> Search_type;
                    if(Search_type == "Writer")
                    {
                              time_t now = time(0);
                              string time = ctime(&now);
                              T.Search_Book(time, username, "Writer");

                         string writer_test ;
                         GDE.Guide_Of_Writer();

                         cout << "Please enter Writer : " ;

                         cin >> writer_test;
                         while(ck.Check_Writer(writer_test) != true)
                         {
                                   WTP.WrongMassage();
                                   WTP.GuideMassage();
                                   string G;
                                   cin >> G;
                                   if(G == "Yes")
                                        GDE.Guide_Of_Writer();
                                   cout << "Please enter Writer : " ;

                                   cin >> writer_test;    
                         }
                         bi.Search("Writer",writer_test);
                         
                    }
                    else if(Search_type == "Name")
                    {
                              time_t now = time(0);
                              string time = ctime(&now);
                              T.Search_Book(time, username, "Name");

                         string name_test;
                         GDE.Guide_Of_NameB();

                         cout << "Please enter Name : " ;

                         cin >> name_test;
                         while(ck.Check_NameBook(name_test) != true)
                         {
                                   WTP.WrongMassage();
                                   WTP.GuideMassage();
                                   string G;
                                   cin >> G;
                                   if(G == "Yes")
                                   GDE.Guide_Of_NameB();
                                   cout << "Please enter Name : " ;

                                   cin >> name_test;    
                         }
                         bi.Search("Name",name_test);
                         


                    }
                    else if(Search_type == "Code")
                    {
                              time_t now = time(0);
                              string time = ctime(&now);
                              T.Search_Book(time, username, "Code");
                         string code_test;
                         GDE.Guide_Of_Code();
                         cout << "Please enter Code : " ;

                         cin >> code_test;
                         while(ck.Check_Code(code_test) != true)
                         {
                                   WTP.WrongMassage();
                                   WTP.GuideMassage();
                                   string G;
                                   cin >> G;
                                   if(G == "Yes")
                                        GDE.Guide_Of_Code();
                                   cout << "Please enter Code : " ;
                    
                                   cin >> code_test;    

                         }
                         bi.Search("Code", code_test);
                         


                    }
                    else if(Search_type == "Genre")
                    {
                              time_t now = time(0);
                              string time = ctime(&now);
                              T.Search_Book(time, username, "Genre");
                         string genre_test;
                         GDE.Guide_Of_Genre();

                         cout << "Please enter Genre : " ;

                         cin >> genre_test;
                         while(ck.Check_Genre(genre_test) != true)
                         {
                                   WTP.WrongMassage();
                                   WTP.GuideMassage();
                                   string G;
                                   cin >> G;
                                   if(G == "Yes")
                                        GDE.Guide_Of_Genre();
                                   cout << "Please enter Genre : " ;

                                   cin >> genre_test;

                         }
                         bi.Search("Genre", genre_test);
                         

                    }
                    else if(Search_type == "Situation")
                    {
                         time_t now = time(0);
                              string time = ctime(&now);
                              T.Search_Book(time, username, "Situation");
                         string situation_test;
                         GDE.Guide_Of_Situation();
                         cout << "Please enter Situation : " ;
                         cin >> situation_test;
                         while(ck.Check_Situation(situation_test) != true)
                         {
                              WTP.WrongMassage();
                              WTP.GuideMassage();
                              string G;
                              cin >> G;
                              if(G == "Yes")
                                   GDE.Guide_Of_Situation();
                              cout << "Please enter Situation : " ;

                              cin >> situation_test;

                         }
                         bi.Search("Situation", situation_test);
                         
                    }
                    
                    }
                    else if(user == "SeeBooks")
                    {
                         GDE.Guide_Of_See();
                         string G;
                         cin >> G;
                         if(G == "yes")
                         {
                              
                              time_t now = time(0);
                              string time = ctime(&now);
                              T.See_Book(time, username);   
                              bi.See_List_Of_Book();
                         }
                    
                    }
                 GDE.Guide_Of_SelectUser();

           WTP.Do();
           cin >> user;       

           }

   }





}
