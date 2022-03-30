#include "Direction.hpp"
#include <iostream>
#include <string>
#include "Notebook.hpp"

namespace ariel{

    const int row_length = 100;
    const int minChar = 33;
    const int maxChar = 126;

    void common_checks(int page,  int row,  int col,Direction direc, int lenght){

        // check if the page value is negative
        if(page < 0){
            throw std::invalid_argument("Page value can't be negative");
        }
        // check if the row value is negative
        if(row < 0){
            throw std::invalid_argument("Row value can't be negative");
        }
        // check if the column value is negative
        if(col < 0){
            throw std::invalid_argument("Column value can't be negative");
        }
        // check the column is lower than 100
        if(col >= row_length){
            throw std::invalid_argument("Column value can't be after the end of the line");
        }
        // check the work is in the row
        if(direc==  Direction::Horizontal &&  col+lenght >= row_length){
            throw std::invalid_argument("Cant write/read/erase after the end of the line");
        } 
        //check if the legth value is negative
        if(length < 0){
            throw std::invalid_argument("Length value can't be negative");
        }
    }

    void string_input_test(const std::string &text){
        for (char const &c: text) {
            if(c=='~'){
                throw std::invalid_argument("invalid input, contains ~");
            }
            //doesn't work somehow
            if(c<minChar || c>maxChar){
                throw std::invalid_argument("invalid char, unprintable");
            }
        }
    }

    void Notebook::write( int page,  int row,  int col, Direction direc, const std::string& input){

        // check the input
        common_checks(page,row,col,direc,input.length());
        
        // check if the given text is ascii
        string_input_test(input);
        
        // check that we don't write on an erased line
        string_input_test(read(page,row,col,direc,input.length()));

        notes[page].write(row,col,direc,input);

    }

    std::string Notebook::read( int page,  int row,  int col,Direction direc,  int length){

        //check the input
        common_checks(page,row,col,direc,length);

        return notes[page].read(row,col,direc,length);
    }

    void Notebook::erase( int page,  int row,  int col,Direction direc,  int length){

        //check the input
        common_checks(page,row,col,direc,length);

        notes[page].erase(row,col,direc,length);

    }

    void Notebook::show( int page){
        
        //check the input, the only real test here is for page
        common_checks(page,0,0,Direction::Vertical,0);

        notes[page].show(row,col,direc,length);
    }

}