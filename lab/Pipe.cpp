//
// Created by Евгений Беляков on 15.11.2021.
//

#include "Pipe.h"
#include "verification.h"
#include "consolef.h"

int Pipe::Max_ID = 0;

Pipe::Pipe(){
        Console_func::Clear_console();
        id = ++Max_ID;
        std::cout << "Enter the name of pipe, which have length in range (1 - 10): ";
        verification::check_string(name, 10);
        Console_func::Clear_console();
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

void Pipe::setID(int ID) {
    this->id = ID;
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
        << "Pipe's name: " << pipe.name << std::endl
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
    f_out << pipe.get_id() << std::endl << pipe.name << std::endl << pipe.diameter << std::endl
        << pipe.length << std::endl;
    f_out << pipe.repair_or_not << std::endl;
    return f_out;
}

std::ifstream& operator >> (std::ifstream& f_in, Pipe &pipe){
    int x, buf = 0;
    f_in >> x >> std::ws;
    if(buf <= x){
        buf = x;
        Pipe::Max_ID = x;
    }
    pipe.setID(x);
    getline(f_in, pipe.name);
    f_in >> pipe.length;
    f_in >> pipe.diameter;
    f_in >> pipe.repair_or_not;
    f_in >> std::ws;
    return f_in;
}

Pipe::Pipe(std::ifstream& in){
    name = "";
    length = 0;
    diameter = 0;
    repair_or_not = false;
}
