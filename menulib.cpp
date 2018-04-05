#include "clmenu.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

ClMenu::ClMenu(){
    init();
    while(splash());
    return;
}

//Initializes the inventory and checks for errors
void ClMenu::init(){
    int errors = 0;
    list = new ClList;
    ifstream input_txt;
    string line;
    string xml = "films.xml";
    string txt = "myList.txt";

    input_txt.open(txt);
    while (getline(input_txt, line)){
        if(list->createItem(line, xml) == 0) errors++;
    }

    //Tells user that either files were ok or that there were errors in the files.
    if(errors == 0){
        cout << "Files OK." << endl;
    }else{
        cout << "Found " << errors << " errors, please check your input files!" << endl;
    }
    input_txt.close();
}

//Menu splash "screen"
//Contains all menu functions
int ClMenu::splash(){
    int input;
    string choice;
    cout << "Menu:" << endl;
    cout << "(1) Search" << endl;
    cout << "(2) Print inventory to screen" << endl;
    cout << "(3) Print inventory to file" << endl;
    cout << "(4) Quit" << endl;
    cout << "Pick your option: ";
    cin >> input;

    switch(input){
        case 1:
            search();
            break;
        case 2:
            list->printAll();
            cout << "Print to (f)ile or return to (m)enu?: ";
            cin >> choice;
            if(choice == "f"){
                list->printAll();
            }else{
                break;
            }
            break;
        case 3:
            break;
        default:
            return 0;
    }
}

//Menu search function, asks for user input and gives it to ClList::printSearch
void ClMenu::search(){
    int log_op, arg1, arg2;
    string choice, query1, query2;
    searchMenu();
    cin >> arg1;
    cout << "Please enter your search term: ";
    cin >> query1;
    cout << "Search for a second parameter (y/n)?: ";
    cin >> choice;
    if(choice == "y"){
        searchMenu();
        cin >> arg2;
        cout << "Please enter your search term: ";
        cin >> query2;
        cout << "Search for both (0) or either (1)?: ";
        cin >> log_op;
    }else{
        log_op = 2;
    }
    if(list->printSearch(log_op, arg1, arg2, query1, query2)){
        cout << "Print to (f)ile or return to (m)enu?: ";
        cin >> choice;
        if(choice == "f"){
            list->printSearch(log_op, arg1, arg2, query1, query2);
        }else{
            return;
        }
    }else{
        cout << "No matches found." << endl;
        return;
    }
}

void ClMenu::searchMenu(){
    cout << "(0) Brand" << endl;
    cout << "(1) Type" << endl;
    cout << "(2) ISO" << endl;
    cout << "(3) ISO used" << endl;
    cout << "(4) Color (bw/color/slide)" << endl;
    cout << "(5) Format" << endl;
    cout << "(6) Date (YYYY-MM-DD)" << endl;
    cout << "Please pick your parameter: ";
}
