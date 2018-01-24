#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "clparser.h"
#include "cllist.h"

int main(){
    int errors = 0;
    ClList *list;
    list = new ClList;
    ifstream input_txt;
    string line;
    string xml = "films.xml";
    string txt = "myList.txt";
    input_txt.open(txt);

    while (getline(input_txt, line)){
        if(list->createItem(line, xml) == 0) errors ++;
    }

    //Tells user that either files were ok or that there were errors in the files.
    if(errors == 0){
        cout << "Files OK." << endl;
    }else{
        cout << "Found " << errors << " errors, please check your input files!" << endl;
    }

    list->displayAll();
    input_txt.close();
}
