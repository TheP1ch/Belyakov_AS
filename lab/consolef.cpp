//
// Created by Евгений Беляков on 17.11.2021.
//
#include "consolef.h"

void Console_func::Menu_out() {
    std::cout << "1. Добавить трубу\n"
            "2. Добавить КС\n"
            "3. Просмотр всех объектов\n"
            "4. Редактировать трубу\n"
            "5. Редактировать КС\n"
            "6. Сохранить\n"
            "7. Загрузить\n"
            "8. Удаление труб\n"
            "0. Выход\n";
}

void Console_func::Pipe_table() {
    std::cout << "Pipe info:" << std::endl;
    std::cout << "Pipe id:" << std::setw(20) << "Pipe's name:" << std::setw(20) << "Pipe diameter:" <<
         std::setw(20) << "Pipe length:" << std::setw(20) << "repair or not:" << std::endl;
}
void Console_func::CS_table(){
    std::cout << "CS info:" << std::endl;
    std::cout << "CS id:" << std::setw(17) << "Cs name:" << std::setw(27) << "CS count workshops:" <<
         std::setw(32) << "CS count ready workshops:" << std::setw(20) << "CS efficiency:" << std::endl;
}

void Console_func::Edit_menu() {
    std::cout << "1. " << "Edit all pipes in table" << std::endl
              << "2. " << "Edit certain pipes" << std::endl
              << "0. " << "Exit to menu press" << std::endl;
}

void Console_func::Delete_menu() {
    std::cout << "1. " << "Delete all pipes in table" << std::endl
              << "2. " << "Delete certain pipes" << std::endl
              << "0. " << "Exit to menu press" << std::endl;
}

void Console_func::Filter_Pipe_menu() {
    std::cout << "1. " << "Filter by repair" << std::endl
              << "2. " << "Filter by name" << std::endl
              << "0. " << "Exit to menu press" << std::endl;
}


void Console_func::Clear_console(){
    std::cout << std::string(20, '\n');
}

void Console_func::return_to_menu(){
    std::cout << "for return to menu push '1' button: ";
    std::cin >> std::ws;
    while (true) {
        if (std::cin.get() == '1') {
            Console_func::Clear_console();
            Console_func::Menu_out();
            break;
        }else{
            Clear_console();
            std::cout << "for return to menu push '1' button, you push wrong button: ";
        }
    }
}

void Console_func::Out_to_File(std::unordered_map<int, Pipe> &pipes, std::unordered_map<int, CS> &compressors,std::string &File_name){
    std::ofstream out;
    out.open("/Users/evgenijbelakov/desktop/github2/Belyakov_AS/lab/data_file/" + File_name);
    if (!out.is_open()) {
        std::cout << "File didn't find ";
        Console_func::return_to_menu();
    }
    if (!pipes.empty()){
        out << "Pipe" << std::endl << pipes.size() << std::endl;
        for (const auto& item : pipes){
            out << item.second;
        }
    }
    if (!compressors.empty()){
        out << "CS" << std::endl << compressors.size() << std::endl;
        for (const auto& item : compressors){
            out << item.second;
        }
    }
    std::cout << "Data is upload to file" << std::endl;
    out.close();
    Console_func::return_to_menu();
    Console_func::Clear_console();
    Console_func::Menu_out();
}

void Console_func::In_from_file(std::unordered_map<int, Pipe> &pipes, std::unordered_map<int, CS> &compressors,std::string &File_name){
    std::ifstream in("/Users/evgenijbelakov/desktop/github2/Belyakov_AS/lab/data_file/" + File_name);
    if (!in.is_open()) {
        std::cout << "File didn't find" << std::endl;
        Console_func::return_to_menu();
        return;
    } else if (in.eof()) {
        std::cout << "File is empty" << std::endl;
        Console_func::return_to_menu();
        return;
    }
    std::string check;
    in >> check;
    if (check == "Pipe"){
        Pipe::PIPE_Clear(pipes);
        int count_pipe;
        in >> count_pipe;
        for (int i = 0; i < count_pipe; ++i){
            Pipe new_pipe(in);
            in >> new_pipe;
            pipes.insert({new_pipe.get_id(), new_pipe});
        }
        if(!in.eof()){
            in >> check;
        }
    }
    if (check == "CS"){
        CS::CS_Clear(compressors);
        int count_cs;
        in >> count_cs;
        for (int i = 0; i < count_cs; ++i){
            CS new_cs(in);
            in >> new_cs;
            compressors.insert({new_cs.get_id(), new_cs});
        }
    }
    std::cout << "You download data from file" << std::endl;
    in.close();
    Console_func::return_to_menu();
}