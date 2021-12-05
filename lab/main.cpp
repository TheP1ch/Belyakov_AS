#include "Pipe.h"
#include "CS.h"
#include "consolef.h"
#include "verification.h"
#include <vector>
#include "Filter.h"

using namespace std;

int main() {
    unordered_map<int, Pipe> pipes;
    unordered_map<int, CS> compressors;
    char menu_pointer;
    Console_func::Menu_out();
    while (true){
        cin >> ws;
        menu_pointer = cin.get();
        cin.clear();
        cin.ignore(10000, '\n');
        switch (menu_pointer) {
            case '1': {
                Pipe new_pipe;
                pipes.insert({new_pipe.get_id(), new_pipe});
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            case '2': {
                CS new_cs;
                compressors.insert({new_cs.get_id(), new_cs});
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            case '3': {
                Console_func::Clear_console();
                if (!pipes.empty()) {
                    Console_func::Pipe_table();
                    for (auto &item : pipes){
                        cout << item.second;
                    }
                    cout << endl;
                }
                if (!compressors.empty()) {
                    Console_func::CS_table();
                    for (auto &item : compressors){
                        cout << item.second;
                    }
                    cout << endl;
                }
                if (pipes.empty() && compressors.empty()) {
                    Console_func::Clear_console();
                    cout << "You push wrong point in menu because you don't have pipe or CS\n\n";
                    Console_func::Menu_out();
                    break;
                }
                Console_func::return_to_menu();
                break;
            }
            case '4': {
                Console_func::Clear_console();
                if (pipes.empty()){
                    cout <<  "You push wrong point in menu because you don't have pipe\n\n";
                    Console_func::Menu_out();
                    break;
                }
                vector<int> vec_id;
                Filter::Choose_Pipe_filter(pipes, vec_id);
                Filter::switch_Pipe_true_false(pipes, vec_id);
                break;
            }
            case '5': {
                Console_func::Clear_console();
                if (compressors.empty()){
                    cout << "You push wrong point in menu because you don't have CS\n\n";
                    Console_func::Menu_out();
                    break;
                }
                vector<int> vec_id;
                Filter::Choose_CS_filter(compressors, vec_id);
                Filter::switch_CS_workshops(compressors, vec_id);
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            case '6': {
                if (compressors.empty() && pipes.empty()) {
                    Console_func::Clear_console();
                    cout << "You push wrong point in menu because you don't have pipe or CS\n\n";
                    Console_func::Menu_out();
                    break;
                }
                string file_name;
                Console_func::Clear_console();
                cout << "Enter the file name: ";
                getline(cin, file_name);
                Console_func::Out_to_File(pipes, compressors, file_name);
                break;
            }
            case '7': {
                Console_func::Clear_console();
                string file_name;
                cout << "Enter the file name: ";
                getline(cin, file_name);
                Console_func::In_from_file(pipes, compressors, file_name);
                break;
            }
            case '8':{
                Console_func::Clear_console();
                if (pipes.empty()){
                    cout <<  "You push wrong point in menu because you don't have pipe\n\n";
                    Console_func::Menu_out();
                    break;
                }
                vector<int> vec_id;
                Filter::Choose_Pipe_filter(pipes, vec_id);
                if(!vec_id.empty()){
                    Console_func::Pipe_table();
                    Filter::Delete_CS_OR_PIPE(pipes, vec_id);
                }

                break;
            }
            case '9':{
                Console_func::Clear_console();
                if (compressors.empty()){
                    cout <<  "You push wrong point in menu because you don't have compressors\n\n";
                    Console_func::Menu_out();
                    break;
                }
                vector<int> vec_id;
                Filter::Choose_CS_filter(compressors, vec_id);
                if(!vec_id.empty()){
                    Console_func::CS_table();
                    Filter::Delete_CS_OR_PIPE(compressors, vec_id);
                }
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