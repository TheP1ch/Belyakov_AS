#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Pipe{
    int id;
    double length;
    double  diametr;
    bool repair_or_not;
};
/*
void add_atribute_pipe(Pipe new_pipe){
    cout << "Add Pipe diametr" << endl;
    cin >> new_pipe.diametr;
    cout << endl <<"Add Pipe length" << endl;
    cin >> new_pipe.length;
}
 */

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

Pipe result(){
    Pipe result{};
    result.id = 0;
    cout << endl <<"Add Pipe length" << endl;
    cin >> result.length;
    cout << "Add Pipe diametr" << endl;
    cin >> result.diametr;
    return result;
}

void out_pipe_info(Pipe &new_pipe){
    cout << endl << new_pipe.id << endl << new_pipe.diametr << endl << new_pipe.length << endl;
}

int main() {
    /*Pipe new_pipe{};
    new_pipe = result();
    out_pipe_info(new_pipe);*/
    Menu_out();
    int a = cin.get();//getchar();
    switch (a) {
        case '1':
            cout << string(5, '\n');
            break;
        case '2':
            cout << string(4, '\n');
            break;
        default:
            break;
    }
    system("clear");
    cout << "Number2 " << char(a) << endl;
}





