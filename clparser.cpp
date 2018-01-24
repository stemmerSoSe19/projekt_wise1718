#include "clparser.h"
using namespace std;
#include <fstream>
#include <string.h>
#include <iostream>
#include <cmath>

//Opens file with filename xml
//Parses file until line with "film id" is found
//Checks if film id is equal to object.id
//If false, keeps parsing file
//If true starts to fill member variables according to state
//In ISO-State (state = 3), calculates push/pull-factor from iso and iso_used
int ClParser::read_xml(string xml){
    int state = 0;
    int n = 0;
    char buffer[100];
    string a, b;
    string line;
    ifstream input_xml;
    input_xml.open(xml);

    while(getline(input_xml, line)){
        if(line.find("film id") != string::npos && state == 0){
            line.erase(0, line.find('"') + 1);
            for(int i = 0; i < int(line.find('"')); i++){
                buffer[n] = line[i];
                n++;
            }
            buffer[n] = '\0';
            n = 0;
            a = buffer;
            b = id;
            if(a == b){
                state = 1;
            }
        }else{
            switch(state){
            case 1:
                line.erase(0, line.find('>') + 1);
                for(int i = 0; i < int(line.find('<')); i++){
                    buffer[n] = line[i];
                    n++;
                }
                buffer[n] = '\0';
                n = 0;
                strcpy(brand, buffer);
                state = 2;
                break;

            case 2:
                line.erase(0, line.find('>') + 1);
                for(int i = 0; i < int(line.find('<')); i++){
                    buffer[n] = line[i];
                    n++;
                }
                buffer[n] = '\0';
                n = 0;
                strcpy(type, buffer);
                state = 3;
                break;

            case 3:
                line.erase(0, line.find('>') + 1);
                for(int i = 0; i < int(line.find('<')); i++){
                    buffer[n] = line[i];
                    n++;
                }
                buffer[n] = '\0';
                n = 0;
                strcpy(iso, buffer);

                if(atoi(iso_used) / atoi(iso) == 1){
                    strcpy(pfactor,"0");

//TODO: figure out a way to write calculation result into string.
//                }else if(atoi(iso_used) / atoi(iso) > 1){
//                    strcpy(pfactor,"+N");
//                }else{
//                    strcpy(pfactor,"-N");
                }

                state = 4;
                break;

            case 4:
                line.erase(0, line.find('>') + 1);
                for(int i = 0; i < int(line.find('<')); i++){
                    buffer[n] = line[i];
                    n++;
                }
                buffer[n] = '\0';
                n = 0;
                strcpy(color, buffer);
                state = 0;
                break;
            }
        }
    }
    input_xml.close();
    return 1;
}

int ClParser::read_txt(string line){
    int n = 0;
    char buffer[20];

    //Checks if line is valid, skips if invalid
    for(int i = 0; i < int(line.size()); i++){
        if(line[i] == ';') n++;
    }
    if(n < 3){
        return 0;
    }
    n = 0;
    //Parses line from txt file
    //Reads to first semicolon and writes into corresponding (by state) member variable
    //Then erases everything up to and including that semicolon and starts over
    //Last entry for format not necessary, defaults to 135
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
    cout << "Brand:        " << brand << endl;
    cout << "Type:         " << type << endl;
    cout << "ISO/used:     " << iso << "/" << iso_used << endl;
    cout << "Color:        " << color << endl;
    cout << "Format:       " << format << endl;
    cout << "Date:         " << date << endl;
//    if(pfactor[0] == '+'){
//        cout << "Push/Pull:    Pushed by " << pfactor << " stops." << endl;
//    }else if(pfactor[0] == '-'){
//        cout << "Push/Pull:    Pulled by " << pfactor << " stops." << endl;
//    }else{
//        cout << "Push/Pull:    Shot at box speed." << endl;
//    }
    cout << "-----------------" << endl;
}
