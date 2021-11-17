//
// Created by Евгений Беляков on 15.11.2021.
//

#include "Pipe.h"
#include "verification.h"
#include "consolef.h"

void Clear_console();

int Pipe::Max_ID = 0;

Pipe::Pipe(){
        id = ++Max_ID;
        std::cout << "Enter the diameter in millimeters in the range{114 - 1420}: ";
        verification::add_attributes(diameter, 110, 1420);
        Console_func::Clear_console();
        std::cout << "Enter the length in meters in the range{10 - 100}: ";
        verification::add_attributes(length, 10, 100);
        Console_func::Clear_console();
        std::cout << "in Repair or not in repair? (Push 'y'(not in repair) or 'n'(in repair) button): ";
        verification::true_false(repair_or_not);
        Console_func::Clear_console();
}

int Pipe::get_id() const{
    return id;
}

void Pipe::switch_repair() {
    std::cout << "Your pipe ";
    if (repair_or_not) {
        std::cout << "not in repair" << std::endl;
    } else {
        std::cout << "in repair" << std::endl;
    }
    std::cout << "Enter pipe repair or not (Push 'y'(not in repair) or 'n'(in repair) button): ";
    verification::true_false(repair_or_not);
}

std::ostream& operator << (std::ostream& out, const Pipe &pipe){
    out << std::endl << "Pipe id: " << pipe.get_id() << std::endl
         << "Pipe diameter: " << pipe.diameter << std::endl
         << "Pipe length: " << pipe.length <<std::endl;
    if(pipe.repair_or_not){
        out << "not in repair" << std::endl;
    } else{
        out << "in repair" << std::endl;
    }
    return out;
}

std::ofstream& operator << (std::ofstream& f_out, const Pipe &pipe){
    f_out << pipe.diameter << std::endl
        << pipe.length << std::endl;
    f_out << pipe.repair_or_not << std::endl;
    f_out << ' ' << std::endl;
    return f_out;
}

std::ifstream& operator >> (std::ifstream& f_in, Pipe &pipe){
    while (f_in.peek() != ' ') {
        f_in >> pipe.length;
        f_in >> pipe.diameter;
        f_in >> pipe.repair_or_not;
        f_in.ignore(1000, '\n');
    }
    f_in.ignore(1000, '\n');
    return f_in;
}
