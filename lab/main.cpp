#include "Pipe.h"
#include "CS.h"
#include <vector>
#include "consolef.h"
#include "verification.h"
#include <unordered_set>

using namespace std;

bool filter_true_false(const Pipe& pipe, bool repair){
    if(repair == pipe.repair_or_not){
        return true;
    }else {
        return false;
    }
}

template <typename T>
bool Filter_by_name(const T &cs_or_pipe, string name){
    if(name == cs_or_pipe.name){
        return true;
    }else {
        return false;
    }
}

bool Filter_by_percentworkshops(const CS &cs, double left_border_percent){
    return ((double)cs.count_ready_workshops/cs.count_workshops > left_border_percent
             && (double)cs.count_ready_workshops/cs.count_workshops < left_border_percent + 10);
}

template <typename T, typename T_param>
using filter_repair = bool(*)(const T& cs_or_pipe, T_param param);

template <typename T, typename T_param>
void Filter_id_true_false(const std::unordered_map<int, T> &MAP,filter_repair<T, T_param> filter, std::vector<int> &vec_id, T_param param){
    for (const auto &item : MAP){
        if (filter(item.second, param)){
            vec_id.push_back(item.second.get_id());
        }
    }
}

void switch_Pipe_true_false(unordered_map<int, Pipe> &pipes, const vector<int> &id_vec){
    if (!id_vec.empty()){
        Console_func::Pipe_table();
        for (const auto  &id : id_vec){
            std::cout << pipes.at(id);
        }
        char menu_pointer2;
        Console_func::Edit_menu();
        cin >> ws;
        menu_pointer2 = cin.get();
        cin.clear();
        cin.ignore(10000, '\n');
        switch(menu_pointer2){
            case '1': {
                bool repair;
                std::cout << "Choose which pipes you want in repair or not (if in repair push 'y', if not in repair push 'n': ";
                verification::true_false(repair);
                for(auto id : id_vec){
                    pipes[id].repair_or_not = repair;
                }
                Console_func::return_to_menu();
                break;
            }
            case '2': {
                bool repair;
                unordered_set<int> table_pos;
                std::cout << "Enter the serial number of the pipe in the table which you want to change "
                             "if you enter the wrong number, an error will occur and you will need to re-enter: ";
                while(true){
                    int x;
                    verification::add_attributes(x, 0, id_vec.size());
                    table_pos.insert(id_vec[x-1]);
                    cout << "if you want to continue press '1', otherwise press'0': ";
                    char menu_pointer3;
                    while(true){
                        cin >> ws;
                        menu_pointer3 = cin.get();
                        cin.clear();
                        cin.ignore(10000, '\n');
                        if (menu_pointer3 == '1'){
                            break;
                        }else if(menu_pointer3 == '0'){
                            break;
                        }
                    }
                    if(menu_pointer3 == '0'){
                        break;
                    }
                    std::cout << "Enter the serial number of the pipe in the table: ";
                }
                std::cout << std::endl <<"Choose which pipes you want in repair or not (if in repair push 'y', if not in repair push 'n': ";
                verification::true_false(repair);
                for(auto it_id = table_pos.begin(); it_id != table_pos.end(); ++it_id){
                    pipes[*it_id].repair_or_not = repair;
                }
                Console_func::return_to_menu();
                break;
            }
            case '0': {
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            default:{
                break;
            }
        }
    }
}
template <typename T>
void Delete_CS_OR_PIPE(unordered_map<int, T> &cs_or_pipe, const vector<int> &id_vec){
    if (!id_vec.empty()){
        for (const auto  &id : id_vec){
            std::cout << cs_or_pipe.at(id);
        }
        char menu_pointer2;
        Console_func::Delete_menu();
        cin >> ws;
        menu_pointer2 = cin.get();
        cin.clear();
        cin.ignore(10000, '\n');
        switch(menu_pointer2){
            case '1': {
                for(auto id : id_vec){
                    cs_or_pipe.erase(cs_or_pipe.find(id));
                }
                Console_func::return_to_menu();
                break;
            }
            case '2': {
                bool repair;
                unordered_set<int> table_pos;
                std::cout << "Enter the serial number in the table which you want to delete: ";
                while(true){
                    int x;
                    verification::add_attributes(x, 0, id_vec.size());
                    table_pos.insert(id_vec[x-1]);
                    cout << "if you want to continue press '1', otherwise press'0': ";
                    char menu_pointer3;
                    while(true){
                        cin >> ws;
                        menu_pointer3 = cin.get();
                        cin.clear();
                        cin.ignore(10000, '\n');
                        if (menu_pointer3 == '1'){
                            break;
                        }else if(menu_pointer3 == '0'){
                            break;
                        }
                    }
                    if(menu_pointer3 == '0'){
                        break;
                    }
                    std::cout << "Enter the serial number in the table: ";
                }
                for(auto it_id = table_pos.begin(); it_id != table_pos.end(); ++it_id){
                    cs_or_pipe.erase(cs_or_pipe.find(*it_id));
                }
                Console_func::return_to_menu();
                break;
            }
            case '0': {
                Console_func::Clear_console();
                Console_func::Menu_out();
                break;
            }
            default:{
                break;
            }
        }
    }
}



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
                char menu_pointer2;
                Console_func::Filter_Pipe_menu();
                cin >> ws;
                menu_pointer2 = cin.get();
                cin.clear();
                cin.ignore(10000, '\n');
                switch(menu_pointer2) {
                    case '1': {
                        Console_func::Clear_console();
                        vector<int> id_vec;
                        bool repair;
                        std::cout
                                << "Choose which pipes you want in repair or not (if in repair push 'y', if not in repair push 'n': ";
                        verification::true_false(repair);
                        Filter_id_true_false(pipes, filter_true_false, id_vec, repair);

                        if (id_vec.empty()) {
                            if (repair) {
                                std::cout << "You dont have Pipe in repair";
                            } else {
                                std::cout << "You dont have Pipe not in repair";
                            }
                            std::cout << std::endl;
                            Console_func::return_to_menu();
                            break;
                        }
                        switch_Pipe_true_false(pipes, id_vec);
                        break;
                    }
                    case '2': {
                        Console_func::Clear_console();
                        vector<int> id_vec;
                        string name;
                        std::cout << "Enter Pipe name: ";
                        verification::check_string(name, 10);
                        Filter_id_true_false(pipes, Filter_by_name,id_vec, name);
                        switch_Pipe_true_false(pipes, id_vec);
                        if (id_vec.empty()) {
                            std::cout << "You dont have Pipe with such name" <<std::endl;
                            Console_func::return_to_menu();
                        }
                        break;
                    }
                    case '0': {
                        Console_func::Clear_console();
                        Console_func::Menu_out();
                        break;
                    }
                }

                break;
            }
            case '5': {
                Console_func::Clear_console();
                if (compressors.empty()){
                    cout << "You push wrong point in menu because you don't have CS\n\n";
                    Console_func::Menu_out();
                    break;
                }
                //new_cs.change_workshops();
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
                char menu_pointer2;
                Console_func::Filter_Pipe_menu();
                cin >> ws;
                menu_pointer2 = cin.get();
                cin.clear();
                cin.ignore(10000, '\n');
                switch(menu_pointer2) {
                    case '1': {
                        Console_func::Clear_console();
                        vector<int> id_vec;
                        bool repair;
                        std::cout
                                << "Choose which pipes you want in repair or not (if in repair push 'y', if not in repair push 'n': ";
                        verification::true_false(repair);
                        Filter_id_true_false(pipes, filter_true_false, id_vec, repair);
                        if (id_vec.empty()) {
                            if (repair) {
                                std::cout << "You dont have Pipe in repair";
                            } else {
                                std::cout << "You dont have Pipe not in repair";
                            }
                            std::cout << std::endl;
                            Console_func::return_to_menu();
                            break;
                        }
                        Console_func::Pipe_table();
                        Delete_CS_OR_PIPE(pipes, id_vec);
                        break;
                    }
                    case '2': {
                        Console_func::Clear_console();
                        vector<int> id_vec;
                        string name;
                        std::cout << "Enter Pipe name: ";
                        verification::check_string(name, 10);
                        Filter_id_true_false(pipes, Filter_by_name,id_vec, name);
                        Delete_CS_OR_PIPE(pipes, id_vec);
                        if (id_vec.empty()) {
                            std::cout << "You dont have Pipe with such name" <<std::endl;
                            Console_func::return_to_menu();
                        }
                        break;
                    }
                    case '0': {
                        Console_func::Clear_console();
                        Console_func::Menu_out();
                        break;
                    }
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