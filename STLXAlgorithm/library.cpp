#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<fstream>
using namespace std;
fstream dataBook;
class Book{
   private:
      string author;
      string title;
      string type;
      float price;
      int code;
      vector<int> numberUsage;
   public:
      Book(){
         author="None";
         title="None";
         type="None";
         price=0.0;
         code=0;
      }
      void input(){
         dataBook.open("book.csv", ios::out | ios::app);
         cout<<"Enter Title  : ";cin>>title;
         // cout<<"Enter Type   : ";cin>>type;
         cout<<"Enter Code   : ";cin>>code;
         // cout<<"Enter Author : ";cin>>author;
         // cout<<"Enter Price  : ";cin>>price;
         dataBook<<title<<","<<code<<","<<endl;
         dataBook.close();
      }
      void output(){
         cout<<"+-------------------------------+"<<endl;
         cout<<"Title  : "<<title<<endl;
         // cout<<"Type   : "<<type<<endl;
         cout<<"Code   : "<<code<<endl;
         // cout<<"Author : "<<author<<endl;
         // cout<<"Price  : "<<price<<endl;
      }
};
int main(){
   vector <Book> books;
   Book newBook;
   while(1){
      cout<<"1 . Input"<<endl;
      cout<<"2 . Output"<<endl;
      cout<<"3 . Search"<<endl;
      cout<<"4 . Delete"<<endl;
      cout<<"0 . Exit"<<endl;
      int choose;
      cin>>choose;
      switch(choose){
         case 1:
            newBook.input();
            books.push_back(newBook);
            break;
         case 2:
            for(Book i:books){
               i.output();
            }
            break;
         case 3:
            break;
         case 0:
            exit(2);
            break;
      }
   }
   return 0;
}