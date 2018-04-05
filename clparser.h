#ifndef CLPARSER_H
#define CLPARSER_H
#include <fstream>
#include <string>

class ClParser{
    public:
        void print();
        int read_xml(std::string xml);
        int read_txt(std::string line);
        int search(int arg, std::string query);

        char *return_id()           { return id; }
        void setNext(ClParser *neu) { next = neu; }
        ClParser *getNext()         { return next; }

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
        char pf_sign[2];
        double pfactor;

    private:
        //List
        ClParser *next;
};

#endif // CLPARSER_H
