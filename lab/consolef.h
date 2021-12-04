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
#include "Pipe.h"
#include "CS.h"

namespace Console_func{
    void Menu_out();
    void Clear_console();
    void return_to_menu();
    void Out_to_File(std::unordered_map<int, Pipe> &pipes, std::unordered_map<int, CS> &compressors, std::string& File_name);
    void In_from_file(std::unordered_map<int, Pipe> &pipes, std::unordered_map<int, CS> &compressors, std::string& File_name);
    void Pipe_table();
    void CS_table();
    void Edit_menu();
    void Delete_menu();
    void Filter_Pipe_menu();
}

#endif //LAB_CONSOLEF_H

