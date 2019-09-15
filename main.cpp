#include <notification.h>
#include <iostream>
#include <thread>


using namespace std;

void funkcja(void)
{
  cout << "modyfikacja pliku" << endl;

}

notify loger("./plik.log");

void func_load()
{

loger.epolling();

}

int main()
{

//notify loger("./plik.log");
loger.RegisterCallback(funkcja);
//thread t1(func_load);
while(1)
{
 // loger.epolling();


func_load();

}

}
