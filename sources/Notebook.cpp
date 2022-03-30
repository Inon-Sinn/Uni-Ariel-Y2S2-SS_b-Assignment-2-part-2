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
    }

    
    void Notebook::write( int page,  int row,  int col, Direction direc, const std::string& input){

        // check 1-4
        common_checks(page,row,col,direc,input.length());
        
        // check if the input is printable

        // check that we don't write on an erased line
    }

    std::string Notebook::read( int page,  int row,  int col,Direction direc,  int length){

        //check 1-4
        common_checks(page,row,col,direc,length);

        //check if the legth value is negative
        if(length < 0){
            throw std::invalid_argument("Length value can't be negative");
        }

        return "empty";
    }

    void Notebook::erase( int page,  int row,  int col,Direction direc,  int length){

        //check 1-4
        common_checks(page,row,col,direc,length);
        
        //check if the legth value is negative
        if(length < 0){
            throw std::invalid_argument("Length value can't be negative");
        }
    }

    void Notebook::show( int page){

        // check if the page value is negative
        if(page < 0){
            throw std::invalid_argument("Page value can't be negative");
        }
    }

}