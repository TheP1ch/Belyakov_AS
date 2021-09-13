#include <iostream>
using namespace std;

struct Pipe{
    int id;
    double length;
    double  diametr;
    bool repair_or_not;
};
void add_atribute_pipe(Pipe new_pipe){
    cout << "Add Pipe diametr" << endl;
    cin >> new_pipe.diametr;
    cout << endl <<"Add Pipe length" << endl;
    cin >> new_pipe.length;
}

void out_pipe_info(Pipe new_pipe){
    cout << new_pipe.diametr << endl << new_pipe.length << endl;
}

int main() {
    Pipe new_pipe;
    new_pipe.id = 0;
    out_pipe_info(new_pipe);
    return 0;
}
