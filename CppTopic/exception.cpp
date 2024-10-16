#include<iostream>
#include<exception>
using namespace std;
float division(float a,float b){
   if(b==0){
      throw false;
   }
   return a/b;
}
int main(){
   float num1=10.4;
   float num2=0;
   try{
      cout<<division(num1,num2)<<endl;
   }catch(...){
      cerr<<"Error Code";
   }
   cout<<"Hello World";
   return 0;
}