#include <iostream>
#include <string>
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
    cout << "Enter the name of cs, which have length in range (1 - 10)";
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
    cout << endl << new_pipe.id << endl << new_pipe.diameter << endl << new_pipe.length <<endl;
    if(new_pipe.repair_or_not){
        cout << "not in repair";
    } else{
        cout << "in repair";
    }
}

void out_cs_info(CS &new_cs){
    cout << endl << new_cs.id << endl << new_cs.name << endl << new_cs.count_workshops << endl << new_cs.count_ready_workshops<< endl;
}

int main(){
    Pipe new_pipe{};
    CS new_cs{};
    new_pipe.id = 1;
    new_cs.id = 1;
    Menu_out();
    char menu_pointer = cin.get();
    switch (menu_pointer){
        case '1':
            Clear_console();
            add_pipe_diametr(new_pipe.diameter);
            Clear_console();
            add_pipe_length(new_pipe.length);
            Clear_console();
            cout << "in Repair or not in repair? ";
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
            Menu_out();
            break;
        case '3':
            cout << "Pipe info:" << endl;
            out_pipe_info(new_pipe);
            cout << "CS info:" << endl;
            out_cs_info(new_cs);
            break;
        case '4':
            cout << "Enter pipe repair or not: ";
            true_false(new_pipe.repair_or_not);
            break;
        case '5':
            add_count_ready_workshops(new_cs.count_ready_workshops, new_cs.count_workshops);
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            return 0;
            break;
        default:
            break;
    }
    return 0;
}





