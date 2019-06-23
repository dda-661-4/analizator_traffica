#include <iostream>
#include "packet.cpp"
#include "Packets.cpp"
#include <mutex>
#include <chrono>
#include <thread>
//#include "pcap.cpp"

class rulevoy
{
public:
    rulevoy();
};

using namespace std;

 void start();
 void shell(); 

int main()
{ 
    start();
    return 0;
}

rulevoy::rulevoy()
{
    
}

void start()
{
    // f_name=FileDialog::getOpenFileName(0,"open the     file","","(*.cap)");
    Packets ps;
    
    ps.f_name="/home/dribl/my_start/PINGGGGG"; // (временно) изменить!!! выбор в ручную ,выше
    ifstream file;
    int a=0;
    file.open(ps.f_name);
    
    file.seekg(0,file.end);
    ps.size_file=file.tellg();
    file.seekg(0,file.beg);
    
    file.read((char*)&ps.f_header,24); //считывается структура cap файла 
    
    packet pac;
    
   // unsigned char *arr; // указатель для записи данных каждого пакете (без заголовка)
    while(a<ps.size_file)
    {
    file.read((char*)&pac.pHeader,16); // считывается структура каждого пакета в файле cap
    //pac.pac_mass.reserve(pac.pHeader.len); // резервируется место в векторе pac 
    pac.packet_mass= new unsigned char[pac.pHeader.len];
   // arr= new unsigned char[pac.pHeader.len];
    
    file.read((char*)pac.packet_mass,pac.pHeader.len);
    //pac.pac_mass.reserve(pac.pHeader.len);
    
   // pac.pac_mass.push_back(*arr); // запись в вектор данных пакета 
    ps.p_mass.push_back(pac);  // запись в вектор пакетов всей структуры пакета
    ps.p_mass.reserve(ps.allpackets); // добавление места в векторе 
    
    ps.allpackets++;
    a=file.tellg(); // получение местонахождения каретки
    pac.razbor();
    pac.work_pack();
    //delete arr;
    }
    
   cout<<ps.p_mass[45].mac<<"-Mac- пакета(от -> кому)"<<endl<<ps.p_mass[45].DATA_16<<"-data в 16ном формате"<<endl<<ps.p_mass[45].packet_mass<<"-data в сыром виде"<<endl;
   //cout<<ps.p_mass[17].pHeader.len<<endl<<ps.p_mass[17].pac_mass[3000];
}

void shell() // нужна будет для работы в онлайн режиме (пришло, разобрал, положил , проанализировал)
{
  /* m_t.lock();
    pcap p;
    p.lookupdev();
    p.lookupnet();
    p.on_live();
    p.cap_next();
    m_t.unlock();*/
}

  //system("chmod 777 /home/dribl/my_start/shell");
  //  this_thread::sleep_for(std::chrono::seconds(1));
  
    //this_thread::sleep_for(std::chrono::seconds(3));




