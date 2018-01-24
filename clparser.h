#ifndef CLPARSER_H
#define CLPARSER_H
#include <string>

class ClParser{
    public:
        int read_txt(std::string line);
        ClParser *getNext()         { return next; }
        void setNext(ClParser *neu) { next = neu; }
        void print();
        //write();

    private:
        // info from txt
        char id[4];
        char iso_used[5];
        char date[12];
        char format[4];
        // info from xml
        char brand[10];
        char type[10];
        char iso[5];
        char color[6];
        //list
        ClParser *next;
};

#endif // CLPARSER_H
