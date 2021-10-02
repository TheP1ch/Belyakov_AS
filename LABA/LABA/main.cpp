#include <iostream>
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
Pipe result(){
    Pipe result;
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
    Pipe new_pipe;
    new_pipe = result();
    out_pipe_info(new_pipe);
    
    return 0;
}


