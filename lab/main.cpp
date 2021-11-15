#include <iostream>
#include <string>
#include <fstream>
#include "verification.h"
#include "Pipe.h"
#include "CS.h"

using namespace std;

void Menu_out(){
    cout << "1. Добавить трубу\n"
            "2. Добавить КС\n"
            "3. Просмотр всех объектов\n"
            "4. Редактировать трубу\n"
            "5. Редактировать КС\n"
            "6. Сохранить\n"
            "7. Загрузить\n"
            "0. Выход\n";
}

void Clear_console(){
    cout << string(20, '\n');
}

void out_pipe_info(const Pipe &pipe){
    cout << endl << "Pipe_and_cs id: " << pipe.get_id() << endl
    << "Pipe_and_cs diameter: " << pipe.diameter << endl
    << "Pipe_and_cs length: " << pipe.length <<endl;
    if(pipe.repair_or_not){
        cout << "not in repair" << endl;
    } else{
        cout << "in repair" << endl;
    }
}

void out_cs_info(const CS &cs){
    cout << endl << "CS id: " << cs.get_id() << endl << "CS name: " << cs.name << endl
    << "CS count workshops: " << cs.count_workshops
    << endl << "CS count ready workshops: " << cs.count_ready_workshops<< endl;
}

void return_to_menu(){
    cout << "for return to menu push '1' button ";
    while (true) {
        if (cin.get() == '1') {
            break;
        }else{
            Clear_console();
            cout << "for return to menu push '1' button, you push wrong button ";
        }
    }
}

void out_to_file(const Pipe &pipe, const CS &cs, ofstream &out){
    out << pipe.get_id() << endl << pipe.diameter << endl
        << pipe.length << endl
        << pipe.repair_or_not << endl;
    out << ' ' << endl;
    out << cs.get_id() << endl << cs.name << endl << cs.count_workshops
        << endl << cs.count_ready_workshops << endl
        << cs.efficiency;
    out.close();
    cout << "Data is upload to file" << endl;
    return_to_menu();
}

void in_from_file(Pipe &pipe, CS &cs, ifstream &in){
    while (in.peek() != ' ') {
        in >> pipe.length;
        in >> pipe.diameter;
        in >> pipe.repair_or_not;
        in.ignore(1000, '\n');
    }
    in.ignore(1000, '\n');
    while (in.peek() != -1) {
        getline(in, cs.name);
        in >> cs.count_workshops;
        in >> cs.count_ready_workshops;
        in >> cs.efficiency;
        in.ignore(1000, '\n');
    }
    in.close();
    cout << "You download data from file" << endl;
    return_to_menu();
}

int main() {
    CS new_cs;
    Pipe new_pipe;
    char menu_pointer;
    Menu_out();
    while (true){
        cin >> ws;
        menu_pointer = cin.get();
        cin.clear();
        cin.ignore(10000, '\n');
        switch (menu_pointer) {
            case '1': {
                Clear_console();
                Menu_out();
                break;
            }
            case '2': {
                Clear_console();
                Menu_out();
                break;
            }
            case '3': {
                Clear_console();
                if (new_pipe.length != 0) {
                    cout << "Pipe_and_cs info:";
                    out_pipe_info(new_pipe);
                }
                if (new_cs.count_workshops != 0) {
                    cout << "\nCS info:";
                    out_cs_info(new_cs);
                }
                if (new_cs.count_workshops == 0 && new_pipe.length == 0) {
                    Clear_console();
                    cout << "You push wrong point in menu because you don't have pipe or CS\n\n";
                    Menu_out();
                    break;
                }
                return_to_menu();
                Clear_console();
                Menu_out();
                break;
            }
            case '4': {
                Clear_console();
                if (new_pipe.length == 0){
                    cout <<  "You push wrong point in menu because you don't have pipe\n\n";
                    Menu_out();
                    break;
                }
                new_pipe.switch_repair();
                Clear_console();
                Menu_out();
                break;
            }
            case '5': {
                Clear_console();
                if (new_cs.count_workshops == 0){
                    cout << "You push wrong point in menu because you don't have CS\n\n";
                    Menu_out();
                    break;
                }
                new_cs.change_workshops();
                Clear_console();
                Menu_out();
                break;
            }
            case '6': {
                if (new_cs.count_workshops == 0 || new_pipe.length == 0) {
                    Clear_console();
                    cout << "You push wrong point in menu because you don't have pipe and CS\n\n";
                    Menu_out();
                    break;
                }
                ofstream out;
                out.open("/Users/evgenijbelakov/desktop/github/Belyakov_AS/lab/Data.txt");
                if (!out.is_open()) {
                    cout << "File didn't find";
                    return_to_menu();
                    break;
                }
                out_to_file(new_pipe, new_cs, out);
                Clear_console();
                Menu_out();
                break;
            }
            case '7': {
                Clear_console();
                ifstream in("/Users/evgenijbelakov/desktop/github/Belyakov_AS/lab/Data.txt");
                if (!in.is_open()) {
                    cout << "File didn't find" << endl;
                    return_to_menu();
                    break;
                } else if (in.eof() == 1) {
                    cout << "File is empty" << endl;
                    return_to_menu();
                    break;
                }
                in_from_file(new_pipe, new_cs, in);
                Clear_console();
                Menu_out();
                break;
            }
            case '0': {
                Clear_console();
                return 0;
            }
            default: {
                break;
            }
        }
    }
}