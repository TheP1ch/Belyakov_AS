#include <iostream>
#include <string>
#include "verification.h"
#include "Pipe.h"
#include "CS.h"
#include "consolef.h"
#include <unordered_map>

using namespace std;

int main() {
    CS new_cs;
    Pipe new_pipe;
    char menu_pointer;
    Console_func::Menu_out();
    while (true){
        cin >> ws;
        menu_pointer = cin.get();
        cin.clear();
        cin.ignore(10000, '\n');
        switch (menu_pointer) {
            case '1': {
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            case '2': {
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            case '3': {
                Console_func::Clear_console();
                if (new_pipe.length != 0) {
                    cout << "Pipe_and_cs info:";
                    cout << new_pipe;
                }
                if (new_cs.count_workshops != 0) {
                    cout << "\nCS info:";
                    cout << new_cs;
                }
                if (new_cs.count_workshops == 0 && new_pipe.length == 0) {
                    Console_func::Clear_console();
                    cout << "You push wrong point in menu because you don't have pipe or CS\n\n";
                    Console_func::Menu_out();
                    break;
                }
                Console_func::return_to_menu();
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            case '4': {
                Console_func::Clear_console();
                if (new_pipe.length == 0){
                    cout <<  "You push wrong point in menu because you don't have pipe\n\n";
                    Console_func::Menu_out();
                    break;
                }
                new_pipe.switch_repair();
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            case '5': {
                Console_func::Clear_console();
                if (new_cs.count_workshops == 0){
                    cout << "You push wrong point in menu because you don't have CS\n\n";
                    Console_func::Menu_out();
                    break;
                }
                new_cs.change_workshops();
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            case '6': {
                if (new_cs.count_workshops == 0 || new_pipe.length == 0) {
                    Console_func::Clear_console();
                    cout << "You push wrong point in menu because you don't have pipe and CS\n\n";
                    Console_func::Menu_out();
                    break;
                }
                ofstream out;
                out.open("/Users/evgenijbelakov/desktop/github2/Belyakov_AS/lab/Data.txt");
                if (!out.is_open()) {
                    cout << "File didn't find ";
                    Console_func::return_to_menu();
                    Console_func::Clear_console();
                    Console_func::Menu_out();
                    break;
                }
                out << new_pipe;
                out << new_cs;
                cout << "Data is upload to file" << endl;
                Console_func::return_to_menu();
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            case '7': {
                Console_func::Clear_console();
                ifstream in("/Users/evgenijbelakov/desktop/github2/Belyakov_AS/lab/Data.txt");
                if (!in.is_open()) {
                    cout << "File didn't find" << endl;
                    Console_func::return_to_menu();
                    break;
                } else if (in.eof()) {
                    cout << "File is empty" << endl;
                    Console_func::return_to_menu();
                    break;
                }
                in >> new_pipe;
                in >> new_cs;
                cout << "You download data from file" << endl;
                Console_func::return_to_menu();
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            case '0': {
                Console_func::Clear_console();
                return 0;
            }
            default: {
                break;
            }
        }
    }
}