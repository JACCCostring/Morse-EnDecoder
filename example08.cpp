#include <iostream>

#include "MorseTable.hpp"

int main(int argc, char **argv){

    Encode::MorseEncoder mEncoder;
    std::string word("hola 4m1302");

    for(int i = 0; i < word.size(); i++){
        if(mEncoder.validate(word[i]))
                std::cout << "exist " << word[i]<< " " 
                << mEncoder.getEncoded(word[i]) << std::endl;

        else    std::cout << "no exist " << word[i]<< std::endl;
    }
    //.... --- .-.. .- / ....- -- .---- ...-- ----- ..---
    return 0;
}