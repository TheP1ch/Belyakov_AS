#include <iostream>

using namespace std;

struct Pipe{
    int id;
    double length;
    int  diameter;
    bool repair_or_not;
};

void add_int_and_check(int &value){
    while(true){
        cin >> value;
        if ((cin.peek() != '\n') || (!cin)){
            cout << "YOUR NUMBER IS WRONG" << endl;
            cin.clear();
            cin.ignore(15000, '\n');
            cout << "Enter a new number: ";
        }else
            break;
    }
}

void add_pipe_diametr(int &diameter){
    cout << "Enter the diameter in millimeters in the range{114 - 1420}: ";
    add_int_and_check(diameter);
    if ((diameter >= 1420) || (diameter <= 110)){
        cout << "YOUR NUMBER IS OUT OF RANGE" << endl;
        cout << "Enter a new number: ";
        add_int_and_check(diameter);
    }
}

void add_and_check_double(double &value){
    while(true){
        cin >> value;
        if ((cin.peek() != '\n') || (!cin)){
            cout << "YOUR NUMBER IS WRONG" << endl;
            cin.clear();
            cin.ignore(15000, '\n');
            cout << "Enter a new number: ";
        }else
            break;
    }
}

void add_pipe_length(double &length){
    cout << "Enter the length in meters in the range{10 - 100}: ";
    add_and_check_double(length);
    if ((length >= 100) || (length <= 10)){
        cout << "YOUR NUMBER IS OUT OF RANGE" << endl;
        cout << "Enter a new number: ";
        add_and_check_double(length);
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
    cout << endl << new_pipe.id << endl << new_pipe.diameter << endl << new_pipe.length << endl;
}

int main(){
    Pipe new_pipe{};
    new_pipe.id = 1;
    Menu_out();
    int menu_pointer = cin.get();
    switch (menu_pointer){
        case '1':
            cout << string(10, '\n');
            add_pipe_diametr(new_pipe.diameter);
            Clear_console();
            add_pipe_length(new_pipe.length);
            Clear_console();
            out_pipe_info(new_pipe);
            break;
        case '2':
            cout << string(4, '\n');
            break;
        default:
            break;
    }
    return 0;
}





