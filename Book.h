#include <iostream>
#include <string>
#include <vector>
#include <fstream>
  


using namespace std;

class AdminBook
{
public:
    AdminBook();
    void AddBook(string, string, string, string, string, string);
    void EditBook(string, string, string);
    void DeleteBook(string);
    ~AdminBook();


    bool Check_Book(string);
    int Find_Place(string);


private:
   vector <string> List_Of_Books;
   string temp;
   int place;
   string Name, Writer, Code, Genre, Description, Situation;
   string line;

   string Give_InformationB(string, string);
   void Lunch_InformationB(string &, string, string, string, string, string, string);
};

AdminBook::AdminBook()
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

int AdminBook::Find_Place(string code)
{

    string test;
    for(int i = 0; i < List_Of_Books.size(); i++)
    {
        test = List_Of_Books[i];
        size_t found = test.find(code);

        if(found != std::string::npos)
             return i;
    }

}

bool AdminBook::Check_Book(string code)
{
    string test;
    for(int i = 0; i < List_Of_Books.size(); i++)
    {
        test = List_Of_Books[i];
        size_t found = test.find(code);

        if(found != std::string::npos)
             return true;

    }
    return false;
}
void AdminBook::DeleteBook(string code)
{
    if(Check_Book(code) == true)
    {
        place = Find_Place(code);
        List_Of_Books.erase(List_Of_Books.begin() + place);
        cout << " your performance was excellent " << endl;
        cout << "--> successfully removed book :)" << endl;
    }
    else
    {
        cout << "Book not found :(" << endl;
    }
}

void AdminBook::EditBook(string code, string part, string info)
{
     if(Check_Book(code) == true)
    {
        place = Find_Place(code);
        temp = List_Of_Books[place];
        List_Of_Books.erase(List_Of_Books.begin() + place);


        Name = Give_InformationB(temp, "name");
        Writer = Give_InformationB(temp, "writer");
        Code = Give_InformationB(temp, "code");
        Genre = Give_InformationB(temp, "genre");
        Description = Give_InformationB(temp, "description");
        Situation = Give_InformationB(temp, "situation");

        
        
        if(part == "Name"){Name = info;}
        else if(part == "Writer"){Writer = info;}
        else if(part == "Code"){Code = info;}
        else if(part == "Genre"){Genre = info;}
        else if(part == "Description"){Description = info;}
        else if(part == "Situation"){Situation = info;}
        Lunch_InformationB(temp, Code, Name, Writer, Genre, Description, Situation);
        List_Of_Books.push_back(temp);

        
        cout << " your performance was excellent " << endl;
        cout << "--> successfully edited book information :)" << endl;
    }
    else
    {
        cout << "book not found :(" << endl;
    }
}

void AdminBook::AddBook(string name, string code, string writer, string genre, string situation, string description)
{
    if(Check_Book(code) == false)
    {
      Lunch_InformationB(temp , code, name, writer, genre, situation, description);
      List_Of_Books.push_back(temp);
      cout << "The book in question was registered :)" << endl;
    }
    else
    {
        cout << "This book has already been registered with this code :(" << endl;
    }
}

string AdminBook::Give_InformationB(string list, string part)
{
    if(part == "name")
    {
        size_t found1 = list.find("*N");
        size_t found01 = list.find(")N-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "writer")
    {
        size_t found1 = list.find("*W");
        size_t found01 = list.find(")W-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "code")
    {
        size_t found1 = list.find("*C");
        size_t found01 = list.find(")C-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "genre")
    {
        size_t found1 = list.find("*G");
        size_t found01 = list.find(")G-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }

    else if(part == "description")
    {
        size_t found1 = list.find("*D");
        size_t found01 = list.find(")D-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
    else if(part == "situation")
    {
        size_t found1 = list.find("*S");
        size_t found01 = list.find(")S-");
        return list.substr(found1 + 3,found01- found1 - 3);
    }
  
   
}
void AdminBook::Lunch_InformationB(string& temp, string code, string name, string writer, string genre, string situation, string description)
{
    temp = "";

    temp += "*C(";
    temp += code;
    temp += ")C-";

    temp += "*N(";
    temp += name;
    temp += ")N-";

    temp += "*W(";
    temp += writer;
    temp += ")W-";


    temp += "*G(";
    temp += genre;
    temp += ")G-";

    temp += "*S(";
    temp += situation;
    temp += ")S-";

    temp += "*D(";
    temp += description;
    temp += ")D-";

}

AdminBook::~AdminBook()
{
    string speace;
    int check;
    ofstream myfile ("Book.txt");  
    if(myfile.is_open())
    {
       
       for(int i = 0; i < List_Of_Books.size(); i++)
             {
                 speace = List_Of_Books[i];
                 for(int i = 0; speace.length() > 0; i++)
                      if(speace[i] != ' ')
                         {
                             check++;
                             break;
                         }
                 if(check != 0)
                         myfile << List_Of_Books[i] << endl;
                  check = 0;       

             }

        myfile.close();
    }
}