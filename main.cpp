#include <iostream>
#include "intentRecognition.h"
using namespace std;
int main(int argc, char** argv)
{
  std::cout<<"##### This is a command line tool for intent recognition #####"<<std::endl;
  std::cout<<"(Enter Close/Exit to stop the program)"<<std::endl;
  IntentRecognition intentRecObj;
  bool proceed = false;
  do{
	  proceed = intentRecObj.start();
  	}while(proceed);
  cout<<"Program exited!!"<<endl;
}

