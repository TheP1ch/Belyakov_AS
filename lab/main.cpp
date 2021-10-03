#include <iostream>

using namespace std;

struct Pipe{
    int id;
    double length;
    int  diametr;
    bool repair_or_not;
};

void checkint(Pipe &pipe){

}

void checkdouble(){}
// diametr 114 - 1420
// length
void add_atribute_pipe(Pipe new_pipe){
    cout << "Add Pipe diametr" << endl;
    cin >> new_pipe.diametr;
    cout <<"Add Pipe length" << endl;
    cin >> new_pipe.length;
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
    cout << endl << new_pipe.id << endl << new_pipe.diametr << endl << new_pipe.length << endl;
}

int main(){
    Pipe new_pipe{};
    new_pipe.id = 1;
    Menu_out();
    int menu_pointer = cin.get();
    switch (menu_pointer){
        case '1':
            cout << string(10, '\n');

            break;
        case '2':
            cout << string(4, '\n');
            break;
        default:
            break;
    }
    return 0;
}





