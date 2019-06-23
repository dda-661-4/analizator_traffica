#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct pkt
{
        int t1;
        int t2;
        int caplen;
        int len;
};

class packet // описание каждого пакета
{
public:
    packet();
    void razbor();
    void work_pack();
    
    unsigned char *packet_mass; // для хранения всего пакета , для последующего его разбора в ascii
    //vector <unsigned char> pac_mass; // вектор для хранения данных пакета
    pkt pHeader; // заголовок пакета
    string mac; // 2 мака пакета в х16
    string DATA_16; // в х16
};

packet::packet()
{
    
}

void packet::razbor()
{
 string str=""; 
 unsigned char y;
 stringstream stream;
 int z;
   
  for(int i=0;i<12;i++)
   {
     //y=(unsigned char)pac_mass[i];
     z=(int)packet_mass[i];
     stream<<hex<<z;
   }

    str=stream.str();
    mac=str;
    //cout<<mac<<endl<<pHeader.caplen<<endl;
}

void packet::work_pack()
{
   string str=""; 
   unsigned char y;
   stringstream stream;
   int z;
   
  for(int i=12;i<pHeader.caplen;i++)
   {
     //y=(unsigned char)pac_mass[i];
     z=(int)packet_mass[i];
     stream<<hex<<z;
   }

    str=stream.str();
    DATA_16=str;
    //cout<<DATA_16<<endl;
}
// g++ start.cpp -o out.tuo -pthread -lpcap
