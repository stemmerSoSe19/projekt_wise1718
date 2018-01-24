#include "clparser.h"
using namespace std;
#include <fstream>
#include <string.h>
#include <iostream>

//int ClParser::read_txt(ifstream &input){
//    char buffer[100];
//    int counter = 0;
//    char zeichen;
//    enum readstate {r_id, r_iso, r_date, r_format};
//    enum readstate state;

//    for (input.get(zeichen), state = r_id; !input.eof(); input.get(zeichen)){
//        switch(zeichen){
//            case ';':
//                switch(state){
//                    case r_id:
//                        buffer[counter] = '\0';
//                        strcpy(id,buffer);
//                        state = r_iso;
//                        counter = 0;
//                        break;
//                    case r_iso:
//                        buffer[counter] = '\0';
//                        strcpy(iso_used,buffer);
//                        state = r_date;
//                        counter = 0;
//                        break;
//                    case r_date:
//                        buffer[counter] = '\0';
//                        strcpy(date,buffer);
//                        state = r_format;
//                        counter = 0;
//                        break;
//                    case r_format:
//                        buffer[counter] = '\0';
//                        strcpy(format,buffer);
//                        counter = 0;
//                        break;
//                }
//                break;
//            default:
//                buffer[counter] = zeichen;
//                counter++;
//                break;
//        }
//    }
//    return 1;
//}

int ClParser::read_txt(string line){
    int n = 0;
    char buffer[20];
    for(int state = 0; state < 4; state++){
        for(int i = 0; i < int(line.find(";")); i++){
            buffer[n] = line[i];
            n++;
        }
        buffer[n] = '\0';
        n = 0;
        if(state < 3){
            line.erase(0, line.find(";") + 1);
        }
        switch(state){
            case 0:
                strcpy(id, buffer);
                break;
            case 1:
                strcpy(iso_used, buffer);
                break;
            case 2:
                strcpy(date, buffer);
                break;
            case 3:
                if (buffer[0] != '\0'){
                    strcpy(format, buffer);
                }else{
                    strcpy(format, "135");
                }
                break;
        }
    }
    return 1;
}

void ClParser::print(){
    cout << "ID:       " << id << endl;
    cout << "ISO used: " << iso_used << endl;
    cout << "Date:     " << date << endl;
    cout << "Format:   " << format << endl;
}
