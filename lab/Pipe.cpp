//
// Created by Евгений Беляков on 15.11.2021.
//

#include "Pipe.h"
#include "verification.h"

void Clear_console();

int Pipe::Max_ID = 0;

Pipe::Pipe(){
        id = ++Max_ID;
        std::cout << "Enter the diameter in millimeters in the range{114 - 1420}: ";
        verification::add_attributes(diameter, 110, 1420);
        Clear_console();
        std::cout << "Enter the length in meters in the range{10 - 100}: ";
        verification::add_attributes(length, 10, 100);
        Clear_console();
        std::cout << "in Repair or not in repair? (Push 'y'(not in repair) or 'n'(in repair) button): ";
        verification::true_false(repair_or_not);
        Clear_console();
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
    out << std::endl << "Pipe_and_cs id: " << pipe.get_id() << std::endl
         << "Pipe_and_cs diameter: " << pipe.diameter << std::endl
         << "Pipe_and_cs length: " << pipe.length <<std::endl;
    if(pipe.repair_or_not){
        out << "not in repair" << std::endl;
    } else{
        out << "in repair" << std::endl;
    }
    return out;
}

std::ofstream& operator << (std::ofstream& f_out, const Pipe &pipe){
    f_out << pipe.get_id() << std::endl << pipe.diameter << std::endl
        << pipe.length << std::endl
        << pipe.repair_or_not << std::endl;
    f_out << ' ' << std::endl;
    return f_out;
}
