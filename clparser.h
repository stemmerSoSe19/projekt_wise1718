#ifndef CLPARSER_H
#define CLPARSER_H
#include <fstream>
#include <string>

class ClParser{
    public:
        int read_xml(std::string xml);
        int read_txt(std::string line);
        void print();
        char *return_id()           { return id; }
        ClParser *getNext()         { return next; }
        void setNext(ClParser *neu) { next = neu; }
        //write();

    private:
        //Info from txt
        char id[4];
        char iso_used[5];
        char date[12];
        char format[4];
        //Info from xml
        char brand[10];
        char type[10];
        char iso[5];
        char color[6];
        //Calculation
        char pfactor[5];
        //List
        ClParser *next;
};

#endif // CLPARSER_H
