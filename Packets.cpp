//#include "packet.cpp"

#include <vector>

using namespace std;

struct pcapHeader
{
    int magic;
    int version_major;
    int version_minor;
    int thiszone;     /* gmt to local correction */
    int sigfigs;    /* accuracy of timestamps */
    int snaplen;    /* max length saved portion of each pkt */
    int linktype;   /* data link type (LINKTYPE_*) */
};

class Packets 
{
// хранение инфы каждого пакета + инфа самого файла 
// схема хранения такая:
// пакет из packet (хедер + данные + инфа(разобранная)) -> в Packets(всеПакеты) (хедерФайла+ данныеОфайле+ всеПакеты)  
   
public:
    Packets();
    pcapHeader f_header; 
    int size_file; // размер cap файла для анализа
    string f_name;
    int allpackets=0;
    vector <packet> p_mass; // вектор в котором хранятся все пакеты cap файла
};

Packets::Packets()
{
    
}
