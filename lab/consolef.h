//
// Created by Евгений Беляков on 17.11.2021.
//

#ifndef LAB_CONSOLEF_H
#define LAB_CONSOLEF_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

namespace Console_func{
    void Menu_out();
    void Clear_console();
    void return_to_menu();
    template <typename T1,typename T2>
    void Out_to_File(std::unordered_map<int, T1> &pipes, std::unordered_map<int, T2> &compressors, std::string& File_name){
        std::ofstream out;
        out.open("/Users/evgenijbelakov/desktop/github2/Belyakov_AS/lab/data_file/" + File_name);
        if (!out.is_open()) {
            std::cout << "File didn't find ";
            Console_func::return_to_menu();
            Console_func::Clear_console();
            Console_func::Menu_out();
        }
        if (!pipes.empty()){
            out << "Pipe" << std::endl;
            for (auto item : pipes){
                out << item.second;
            }
        }
        if (!compressors.empty()){
            out << "CS" << std::endl;
            for (auto item : compressors){
                out << item.second;
            }
        }
        std::cout << "Data is upload to file" << std::endl;
        out.close();
        Console_func::return_to_menu();
        Console_func::Clear_console();
        Console_func::Menu_out();
    }

}

#endif //LAB_CONSOLEF_H
