#include <iostream>
#include <string>
#include <fstream>

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

bool check_int_double(){
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

bool check_string(string &string, int max_symbols){
    if (size(string) != 0 && size(string) <= max_symbols){
        for(int i = 0; i <= size(string); ++i){
            if (string[i] != ' '){
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
        check = check_string(name_cs, 10);
        if (check){
            break;
        }
    }
}
template <typename T>
void add_attributes(T &attribute, int left_border,int right_border){
    bool check;
    while(true){
        cin >> attribute;
        check = check_int_double();
        if (check && (attribute > right_border || attribute < left_border)){
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
        cin >> ws;
        tfpointer = cin.get();
        cin.ignore(10000, '\n');
        if (tfpointer == 'y'){
            repair = true;
            break;
        } else if (tfpointer == 'n'){
            repair = false;
            break;
        }else
            cout << "You push the wrong button, please try again: ";
    }
}

void Menu_out(){
    cout << "1. Добавить трубу\n "
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
    cout << endl << "Pipe id: " << pipe.id << endl
    << "Pipe diameter: " << pipe.diameter << endl
    << "Pipe length: " << pipe.length <<endl;
    if(pipe.repair_or_not){
        cout << "not in repair" << endl;
    } else{
        cout << "in repair" << endl;
    }
}

void out_cs_info(const CS &cs){
    cout << endl << "CS id: " << cs.id << endl << "CS name: " << cs.name << endl
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

void add_pipe(Pipe &pipe){
    pipe.id = 1;
    cout << "Enter the diameter in millimeters in the range{114 - 1420}: ";
    add_attributes(pipe.diameter, 110, 1420);
    Clear_console();
    cout << "Enter the length in meters in the range{10 - 100}: ";
    add_attributes(pipe.length, 10, 100);
    Clear_console();
    cout << "in Repair or not in repair? (Push 'y'(not in repair) or 'n'(in repair) button): ";
    true_false(pipe.repair_or_not);
    Clear_console();
}

void add_cs(CS &cs){
    cs.id = 1;
    get_cs_name(cs.name);
    Clear_console();
    cout << "Enter the count of workshops in range (1 - 20): ";
    add_attributes(cs.count_workshops, 1, 20);
    Clear_console();
    cout << "Enter the count of ready's workshops in range (0 - n) (n - is how many workshops you have): ";
    add_attributes(cs.count_ready_workshops, 0, cs.count_workshops);
    Clear_console();
    cout << "Enter the efficiency in range (0 - 100%): ";
    add_attributes(cs.efficiency, 0, 100);
    Clear_console();
}

void switch_repair(Pipe &pipe){
        cout << "Your pipe ";
        if (pipe.repair_or_not) {
            cout << "not in repair" << endl;
        } else {
            cout << "in repair" << endl;
        }
        cout << "Enter pipe repair or not (Push 'y'(not in repair) or 'n'(in repair) button): ";
        true_false(pipe.repair_or_not);
}

void change_workshops(CS &cs){
        cout << "Your CS had " << cs.count_ready_workshops << " ready workshops" << endl;
        cout << "Enter the count of ready's workshops in range (0 - n) (n - is how many workshops you have):";
        add_attributes(cs.count_ready_workshops, 0, cs.count_workshops);
}

void out_to_file(const Pipe &pipe, const CS &cs, ofstream &out){
    out << pipe.id << endl << pipe.diameter << endl
        << pipe.length << endl
        << pipe.repair_or_not << endl;
    out << ' ' << endl;
    out << cs.id << endl << cs.name << endl << cs.count_workshops
        << endl << cs.count_ready_workshops << endl
        << cs.efficiency;
    out.close();
    cout << "Data is upload to file" << endl;
    return_to_menu();
}

void in_from_file(Pipe &pipe, CS &cs, ifstream &in){
    while (in.peek() != ' ') {
        in >> pipe.id;
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
    Pipe new_pipe{};
    CS new_cs{};
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
                add_pipe(new_pipe);
                Menu_out();
                break;
            }
            case '2': {
                Clear_console();
                add_cs(new_cs);
                Menu_out();
                break;
            }
            case '3': {
                Clear_console();
                if (new_pipe.length != 0) {
                    cout << "Pipe info:";
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
                switch_repair(new_pipe);
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
                change_workshops(new_cs);
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
                break;
            }
            default: {
                break;
            }
        }
    }
}