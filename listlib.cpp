#include "cllist.h"
using namespace std;
#include <string.h>
#include <iostream>
#include "clparser.h"

int ClList::createItem(std::string line, std::string xml){
    ClParser *temp = new ClParser;
    //Fill item
    //Stops creation for this node if read_txt() returns error state 0
    if (temp->read_txt(line) == 0) return 0;
    temp->read_xml(xml);
    //Create list
    temp->setNext(NULL);
    if(head == NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }else{
        tail->setNext(temp);
        tail=temp;
    }
    return 1;
}

//Prints all entries in list
void ClList::printAll(){
    ClParser *temp= new ClParser;
    temp=head;
    while(temp!=NULL){
      temp->print();
      temp=temp->getNext();
    }
}

void ClList::printAllToFile(std::string filename){
    ClParser *temp= new ClParser;
    temp=head;
    ofstream output (filename);
    output << "<?xml version='1.0'?>\n";
    output << "<!DOCTYPE listFilms SYSTEM 'films.dtd'>\n";
    output << "<listFilms>\n";
    while(temp!=NULL){
        output << "<film id=" << "'" << temp->id << "'>\n";
        output << "<brand>" << temp->brand << "</brand>\n";
        output << "<type>" << temp->type << "</type>\n";
        output << "<iso>" << temp->iso << "</iso>\n";
        output << "<iso_used>" << temp->iso_used << "</iso_used>\n";
        output << "<color>" << temp->color << "</color>\n";
        output << "<format>" << temp->format << "</format>\n";
        output << "<date>" << temp->date << "</date>\n";
        output << "<pfactor>" << temp->pfactor << "</pfactor>\n";
        output << "</film>\n";
        temp=temp->getNext();
    }
    output << "</listFilms>\n";
    output.close();
}

//Searches through list and prints entries that match search parameters
//log_op 0 = AND, log_op 1 = OR, log_op 2 = single search query
//arg1 / arg2
// 0 = brand, 1 = type, 2 = iso, 3 = iso_used, 4 = color, 5 = format, 6 = date
void ClList::printSearchToFile(std::string filename, int log_op, int arg1, int arg2, std::string query1, std::string query2){
    ClParser *temp= new ClParser;
    temp=head;
    ofstream output (filename);
    output << "<?xml version='1.0'?>\n";
    output << "<!DOCTYPE listFilms SYSTEM 'films.dtd'>\n";
    output << "<listFilms>\n";
    while(temp!=NULL){
        switch(log_op){
            case 0:
                if(temp->search(arg1, query1) == 1 && temp->search(arg2, query2)){
                    output << "<film id=" << "'" << temp->id << "'>\n";
                    output << "<brand>" << temp->brand << "</brand>\n";
                    output << "<type>" << temp->type << "</type>\n";
                    output << "<iso>" << temp->iso << "</iso>\n";
                    output << "<iso_used>" << temp->iso_used << "</iso_used>\n";
                    output << "<color>" << temp->color << "</color>\n";
                    output << "<format>" << temp->format << "</format>\n";
                    output << "<date>" << temp->date << "</date>\n";
                    output << "<pfactor>" << temp->pfactor << "</pfactor>\n";
                    output << "</film>\n";
                }
                break;
            case 1:
                if(temp->search(arg1, query1) == 1 || temp->search(arg2, query2)){
                    output << "<film id=" << "'" << temp->id << "'>\n";
                    output << "<brand>" << temp->brand << "</brand>\n";
                    output << "<type>" << temp->type << "</type>\n";
                    output << "<iso>" << temp->iso << "</iso>\n";
                    output << "<iso_used>" << temp->iso_used << "</iso_used>\n";
                    output << "<color>" << temp->color << "</color>\n";
                    output << "<format>" << temp->format << "</format>\n";
                    output << "<date>" << temp->date << "</date>\n";
                    output << "<pfactor>" << temp->pfactor << "</pfactor>\n";
                    output << "</film>\n";
                }
                break;
            case 2:
                if(temp->search(arg1, query1) == 1){
                    output << "<film id=" << "'" << temp->id << "'>\n";
                    output << "<brand>" << temp->brand << "</brand>\n";
                    output << "<type>" << temp->type << "</type>\n";
                    output << "<iso>" << temp->iso << "</iso>\n";
                    output << "<iso_used>" << temp->iso_used << "</iso_used>\n";
                    output << "<color>" << temp->color << "</color>\n";
                    output << "<format>" << temp->format << "</format>\n";
                    output << "<date>" << temp->date << "</date>\n";
                    output << "<pfactor>" << temp->pfactor << "</pfactor>\n";
                    output << "</film>\n";
                }
                break;
        }
        temp=temp->getNext();
    }
    output << "</listFilms>\n";
    output.close();
}

void ClList::printSearch(int log_op, int arg1, int arg2, std::string query1, std::string query2){
    ClParser *temp= new ClParser;
    temp=head;
    while(temp!=NULL){
        switch(log_op){
            case 0:
                if(temp->search(arg1, query1) == 1 && temp->search(arg2, query2)){
                    temp->print();
                }
                break;
            case 1:
                if(temp->search(arg1, query1) == 1 || temp->search(arg2, query2)){
                    temp->print();
                }
                break;
            case 2:
                if(temp->search(arg1, query1) == 1){
                    temp->print();
                }
                break;
        }
        temp=temp->getNext();
    }
}
