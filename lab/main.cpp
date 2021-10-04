#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct Pipe{
    int id;
    double length;
    int  diameter;
    bool repair_or_not;
};

struct CS{
    int id;
    string name;
    int count_workshops;
    int count_ready_workshops;
    double efficiency;
};

bool checK_int_double(){
    if (cin.peek() != '\n' || !cin){
        cout << "YOUR NUMBER IS WRONG" << endl;
        cin.clear();
        cin.ignore(15000, '\n');
        cout << "Enter a new number: ";
        return false;
    }else{
        return true;
    }
}

bool check_cs_name(string &name){
    if (size(name) != 0 && size(name) <= 10){
        for(int i = 0; i <= size(name); ++i){
            if (name[i] != ' '){
                return true;
            }
        }
    }
    return false;
}

void get_cs_name(string &name_cs){
    cout << "Enter the name of cs, which have length in range (1 - 10):  ";
    bool check;
    while(true){
        getline(cin,name_cs);
        check = check_cs_name(name_cs);
        if (check){
            break;
        }
    }
}

void add_pipe_diametr(int &diameter){
    cout << "Enter the diameter in millimeters in the range{114 - 1420}: ";
    bool check;
    while(true){
        cin >> diameter;
        check = checK_int_double();
        if (check && (diameter >= 1420 || diameter <= 110)){
            cout << "YOUR NUMBER IS OUT OF RANGE" << endl;
            cout << "Enter a new number: ";
        } else if(check) {
            break;
        }
    }
}





void add_count_workshops(int &count_workshops){
    cout << "Enter the count of workshops in range (1 - 20): ";
    bool check;
    while(true){
        cin >> count_workshops;
        check = checK_int_double();
        if (check && (count_workshops >= 20 || count_workshops <= 1)){
            cout << "YOUR NUMBER IS OUT OF RANGE" << endl;
            cout << "Enter a new number: ";
        } else if(check) {
            break;
        }
    }
}

void add_count_ready_workshops(int &count_ready_workshops, int count_workshops){
    cout << "Enter the count of ready's workshops in range (0 - n) (n - is how many workshops you have): ";
    bool check;
    while(true){
        cin >> count_ready_workshops;
        check = checK_int_double();
        if (check && (count_ready_workshops >= count_workshops || count_ready_workshops <= 0)){
            cout << "YOUR NUMBER IS OUT OF RANGE" << endl;
            cout << "Enter a new number: ";
        } else if(check) {
            break;
        }
    }
}

void add_efficiency(double &efficiency){
    cout << "Enter the efficiency in range (0 - 100%): ";
    bool check;
    while(true){
        cin >> efficiency;
        check = checK_int_double();
        if (check && (efficiency >= 100 || efficiency <= 0)){
            cout << "YOUR NUMBER IS OUT OF RANGE" << endl;
            cout << "Enter a new efficiency: ";
        } else if(check) {
            break;
        }
    }
}

void add_pipe_length(double &length){
    cout << "Enter the length in meters in the range{10 - 100}: ";
    bool check;
    while(true){
        cin >> length;
        check = checK_int_double();
        if (check && (length >= 100 || length <= 10)){
            cout << "YOUR NUMBER IS OUT OF RANGE" << endl;
            cout << "Enter a new number: ";
        } else if(check) {
            break;
        }
    }
}

void true_false(bool &repair){
    char tfpointer;
    while(true){
        tfpointer = cin.get();
        if (tfpointer == 'y'){
            repair = true;
            break;
        } else if (tfpointer == 'n'){
            repair = false;
            break;
        }
    }
}

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


void out_pipe_info(Pipe &new_pipe){
    cout << endl << "Pipe id: " << new_pipe.id << endl
    << "Pipe diameter: " << new_pipe.diameter << endl
    << "Pipe length: " << new_pipe.length <<endl;
    if(new_pipe.repair_or_not){
        cout << "not in repair";
    } else{
        cout << "in repair";
    }
}

void out_cs_info(CS &new_cs){
    cout << endl << "CS id: " << new_cs.id << endl << "CS name: " << new_cs.name << endl
    << "CS count workshops: " << new_cs.count_workshops
    << endl << "CS count ready workshops: " << new_cs.count_ready_workshops<< endl;
}

void return_to_menu(){
    cout << "for return to menu push '1' button ";
    while (true) {
        cin.ignore(1000, '\n');
        if (cin.get() == '1') {
            break;
        }else{
            Clear_console();
            cout << "for return to menu push '1' button, you push wrong button ";
        }
    }
}

int main() {
    Pipe new_pipe{};
    CS new_cs{};
    char out_to_menu;
    new_pipe.id = 1;
    new_pipe.length = 0;
    new_cs.id = 1;
    new_cs.count_workshops = 0;
    char menu_pointer;
    Menu_out();
    while (true){
        menu_pointer = cin.get();
        switch (menu_pointer) {
            case '1':
                Clear_console();
                add_pipe_diametr(new_pipe.diameter);
                Clear_console();
                add_pipe_length(new_pipe.length);
                Clear_console();
                cout << "in Repair or not in repair? (Push 'y' or 'n' button): ";
                true_false(new_pipe.repair_or_not);
                Clear_console();
                Menu_out();
                break;
            case '2':
                Clear_console();
                get_cs_name(new_cs.name);
                Clear_console();
                add_count_workshops(new_cs.count_workshops);
                Clear_console();
                add_count_ready_workshops(new_cs.count_ready_workshops, new_cs.count_workshops);
                Clear_console();
                add_efficiency(new_cs.efficiency);
                Clear_console();
                Menu_out();
                break;
            case '3':
                Clear_console();
                if (new_pipe.length != 0) {
                    cout << "Pipe info:" << endl;
                    out_pipe_info(new_pipe);
                }
                if (new_cs.count_workshops != 0) {
                    cout << "CS info:" << endl;
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
            case '4':
                Clear_console();
                if (new_pipe.length != 0) {
                    cout << "Your pipe in: ";
                    if (new_pipe.repair_or_not) {
                        cout << "not in repair" << endl;
                    } else {
                        cout << "in repair" << endl;
                    }
                    cout << "Enter pipe repair or not: ";
                    true_false(new_pipe.repair_or_not);
                } else {
                    cout << "You push wrong point in menu because you don't have pipe\n\n";
                    Menu_out();
                    break;
                }
                Clear_console();
                Menu_out();
                break;
            case '5':
                Clear_console();
                if (new_cs.count_workshops != 0) {
                    cout << "Your CS had " << new_cs.count_ready_workshops << "ready workshops" << endl;
                    add_count_ready_workshops(new_cs.count_ready_workshops, new_cs.count_workshops);
                } else {
                    cout << "You push wrong point in menu because you don't have CS\n\n";
                    Menu_out();
                    break;
                }
                Clear_console();
                Menu_out();
                break;
            case '6': {
                if (new_cs.count_workshops == 0 || new_pipe.length == 0) {
                    Clear_console();
                    cout << "You push wrong point in menu because you don't have pipe and CS\n\n";
                    Menu_out();
                    break;
                    Clear_console();
                }
                ofstream out;
                out.open("/Users/evgenijbelakov/desktop/github/Belyakov_AS/lab/Data.txt");
                if (!out.is_open()) {
                    cout << "File didn't find";
                    break;
                }
                out << new_pipe.diameter << endl
                    << new_pipe.length << endl
                    << new_pipe.repair_or_not << endl;
                out << ' ' << endl;
                out << new_cs.name << endl << new_cs.count_workshops
                    << endl << new_cs.count_ready_workshops << endl
                    << new_cs.efficiency;
                out.close();
                cout << "Data is upload to file" << endl;
                return_to_menu();
                Clear_console();
                Menu_out();
                break;
            }
            case '7': {
                Clear_console();
                ifstream in("/Users/evgenijbelakov/desktop/github/Belyakov_AS/lab/Data.txt");
                if (!in.is_open()) {
                    cout << "File didn't find" << endl;
                    break;
                } else if (in.peek() == -1) {
                    cout << "File is empty" << endl;
                    break;
                }
                while (in.peek() != ' ') {
                    in >> new_pipe.length;
                    in >> new_pipe.diameter;
                    in >> new_pipe.repair_or_not;
                    in.ignore(1000, '\n');
                }
                in.ignore(1000, '\n');
                while (in.peek() != -1) {
                    getline(in, new_cs.name);
                    in >> new_cs.count_workshops;
                    in >> new_cs.count_ready_workshops;
                    in >> new_cs.efficiency;
                    in.ignore(1000, '\n');
                }
                in.close();
                cout << "You download data from file" << endl;
                return_to_menu();
                Clear_console();
                Menu_out();
                break;
            }
            case '0':
                Clear_console();
                return 0;
                break;
            default:
                break;
        }
    }
}