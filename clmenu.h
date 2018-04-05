#ifndef CLMENU_H
#define CLMENU_H
#include "cllist.h"
#include "string"

class ClMenu{
    public:
        ClMenu();
        void init();
        int splash();
        int subMenu();
        void search();
        void searchMenu();
        void usercfg();

    private:
        ClList *list;
        std::string xml_file;
        std::string txt_file;
};

#endif // CLMENU_H
