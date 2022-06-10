#include <iostream>
#include <string>
#include <vector>
#include <fstream>
  


using namespace std;
class BookInfo 
{
public:

    BookInfo();
    void Search(string, string);
    string Give_InformationB(string, string);
    void See_List_Of_Book();
    void Show_Information(string, string, string, string, string, string);
    bool Check_Book(string);
    int Find_Place(string);
    

private:
    string line;
    vector <string> List_Of_Books;
    string temp;
    string test;

};
BookInfo::BookInfo()
{
      
    ifstream mFile ("Book.txt");  

    if(mFile.is_open()) 
	  {
		while(mFile.peek()!=EOF)
		  {
			   getline(mFile, line);
               List_Of_Books.push_back(line);
		  }
		  mFile.close();
	  } 

}
void BookInfo::Search(string part, string info)
{
   
    if(part == "Name")
    {
        int check = 0;
        string c,w,g,d,s;
        for(int i = 0; i < List_Of_Books.size(); i++)
        {
            test = List_Of_Books[i];
            string Find = Give_InformationB(test, "name");
            size_t found = Find.find(info);
            if(found != std::string::npos)
               {
                         cout << "Books with this name : " << endl;

               
                  c = Give_InformationB(test, "code");
                  w = Give_InformationB(test, "writer");
                  g = Give_InformationB(test, "genre");
                  d = Give_InformationB(test, "description");
                  s = Give_InformationB(test, "situation");
                  cout << "Code : " << c <<  " || "  << "Writer : "  <<  w << " || " << "Genre : " << g << " || " << "description : " << d << " || " << " Situation : " << s << endl;
                  check++;
                   

               }
          
        }
        if(check == 0)
                cout << "No book with this name found :(" << endl;  
    }
    else if(part == "Writer")
    {
        int check = 0;
        string c,n,g,d,s;

        for(int i = 0; i < List_Of_Books.size(); i++)
        {
            
            test = List_Of_Books[i];
            string Find = Give_InformationB(test, "writer");
            size_t found = Find.find(info);
            if(found != std::string::npos)
               {
                      cout << "Books with this author" << endl;

                 
                  c = Give_InformationB(test, "code");
                  n = Give_InformationB(test, "name");
                  g = Give_InformationB(test, "genre");
                  d = Give_InformationB(test, "description");
                  s = Give_InformationB(test, "situation");
                  cout << "Code : " << c <<  " || "  << "Name : "  <<  n << " || " << "Genre : " << g << " || " << "description : " << d << " || " << " Situation : " << s << endl;
                check++;

               }
             
        }
        if(check == 0)
                cout << "No books were found with this author :(" << endl; 
    }
    else if(part == "Code")
    {
        int check = 0;
        string w,n,g,d,s;

        for(int i = 0; i < List_Of_Books.size(); i++)
        {
            test = List_Of_Books[i];
            string Find = Give_InformationB(test, "code");
            size_t found = Find.find(info);
            if(found != std::string::npos)
               {
                         cout << "Books with this code" << endl;

                    w = Give_InformationB(test, "writer");
                    n = Give_InformationB(test, "name");
                    g = Give_InformationB(test, "genre");
                    d = Give_InformationB(test, "description");
                    s = Give_InformationB(test, "situation");
                   cout << "Writer : " << w <<  " || "  << "Name : "  <<  n << " || " << "Genre : " << g << " || " << "description : " << d << " || " << " Situation : " << s << endl;
                   check++;

               }
          
        }
        if(check == 0)
             cout << "No books were found with this code :(" << endl; 
    }
    else if(part == "Genre")
    {
        int check = 0;
        string w,n,c,d,s;
        for(int i = 0; i < List_Of_Books.size(); i++)
        {
            test = List_Of_Books[i];
            string Find = Give_InformationB(test, "genre");
            size_t found = Find.find(info);
            if(found != std::string::npos)
               {
                            cout << "Books in this genre" << endl;

                    w = Give_InformationB(test, "writer");
                    n = Give_InformationB(test, "name");
                    c = Give_InformationB(test, "code");
                    d = Give_InformationB(test, "description");
                    s = Give_InformationB(test, "situation");
                    cout << "Code : " << c <<  " || "  << "Name : "  <<  n << " || " << "Writer : " << w << " || " << "description : " << d << " || " << " Situation : " << s << endl;
                  
                   check++;

               }
           
        }
         if(check == 0)
                cout << "No books were found in this genre :(" << endl;   

    }
    else if(part == "Situation")
    {
        string w,n,c,d,g;
        int check = 0;
        for(int i = 0; i < List_Of_Books.size(); i++)
        {
            test = List_Of_Books[i];
            string Find = Give_InformationB(test, "situation");

            if(Find == info)
               {
                      cout << "Books in this Situation" << endl;
                    w = Give_InformationB(test, "writer");
                    n = Give_InformationB(test, "name");
                    c = Give_InformationB(test, "code");
                    d = Give_InformationB(test, "description");
                    g = Give_InformationB(test, "genre");
                    cout << "Code : " << c <<  " || "  << "Name : "  <<  n << " || " << "Writer : " << w << " || " << "Genre : " <<  g << " || " << "description : " << d  << endl;
                   check++;

               }
            
       }
       if(check == 0)
                cout << "No books were found in this Situation :(" << endl;   

    }
}
void BookInfo::See_List_Of_Book()
{
    if(List_Of_Books.size()  < 10)
    {
        string w,n,c,d,g,s;


       for(int i = 0; i < List_Of_Books.size(); i++)
       {
            w = Give_InformationB(test, "writer");
            n = Give_InformationB(test, "name");
            c = Give_InformationB(test, "code");
            d = Give_InformationB(test, "description");
            g = Give_InformationB(test, "genre");
            s = Give_InformationB(test, "situation");
            cout << i + 1 << "-" << "Code : " << c <<  " || "  << "Name : "  <<  n << " || " << "Writer : " << w << " || " << "Genre : " <<  g << " || " << "description : " << d << " || " << " Situation : " << s << endl;


           

       }
    }
    else
    {
        string w,n,c,d,g,s;
      for(int i = 0; i < 10; i++)
       {
           test = List_Of_Books[i];
            w = Give_InformationB(test, "writer");
            n = Give_InformationB(test, "name");
            c = Give_InformationB(test, "code");
            d = Give_InformationB(test, "description");
            g = Give_InformationB(test, "genre");
            s = Give_InformationB(test, "situation");
            cout << i + 1 << "-" << "Code : " << c <<  " || "  << "Name : "  <<  n << " || " << "Writer : " << w << " || " << "Genre : " <<  g << " || " << "description : " << d << " || " << " Situation : " << s << endl;


        }


    int count = 2;
    while((count * 10) <= List_Of_Books.size())
    {
        string w,n,c,d,g,s;
        cout << "Do you want to see the next page?"  << endl;
        cout << "Type <<Yes>> Or <<No>>" ;
        string Answer;

        cin >> Answer;
        if(Answer == "Yes")
        for(int i = (count - 1) * 10; i < count* 10; i++)
        {
            test = List_Of_Books[i];
            w = Give_InformationB(test, "writer");
            n = Give_InformationB(test, "name");
            c = Give_InformationB(test, "code");
            d = Give_InformationB(test, "description");
            g = Give_InformationB(test, "genre");
            s = Give_InformationB(test, "situation");
            cout << i + 1 << "-" << "Code : " << c <<  " || "  << "Name : "  <<  n << " || " << "Writer : " << w << " || " << "Genre : " <<  g << " || " << "description : " << d << " || " << " Situation : " << s << endl;
        }
        count++;
        
    }
    count  = count - 1;
    if(List_Of_Books.size() - (count * 10) != 0)
    {
        cout << "Do you want to see the next page?"  << endl;
        cout << "Type <<Yes>> Or <<No>>" ;
        string Answer;
        cin >> Answer;
        if(Answer == "Yes")
        {
            for(int i = count * 10; i < List_Of_Books.size(); i++)
            {
                  string w,n,c,d,g,s;
                  test = List_Of_Books[i];
                  w = Give_InformationB(test, "writer");
                  n = Give_InformationB(test, "name");
                  c = Give_InformationB(test, "code");
                  d = Give_InformationB(test, "description");
                  g = Give_InformationB(test, "genre");
                  s = Give_InformationB(test, "situation");
                  cout << i + 1 << "-" << "Code : " << c ;
                  cout <<  " || "  << "Name : "  <<  n ;
                  cout << " || " << "Writer : " << w ;
                  cout << " || " << "Genre : " <<  g ;
                  cout << " || " << "description : " << d;
                  cout  << " || " << " Situation : " << s << endl;
            }

              
        }

    } 

    }   
          

}


string BookInfo::Give_InformationB(string list, string part)
{
    if(part == "name")
    {
        size_t found1 = list.find("*N(");
        size_t found01 = list.find(")N-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "writer")
    {
        size_t found1 = list.find("*W(");
        size_t found01 = list.find(")W-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "code")
    {
        size_t found1 = list.find("*C(");
        size_t found01 = list.find(")C-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "genre")
    {
        size_t found1 = list.find("*G(");
        size_t found01 = list.find(")G-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }

    else if(part == "description")
    {
        size_t found1 = list.find("*D(");
        size_t found01 = list.find(")D-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "situation")
    {
        size_t found1 = list.find("*S(");
        size_t found01 = list.find(")S-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
  
   
}
