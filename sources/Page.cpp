#include "Direction.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Page.hpp"

namespace ariel{

    const int row_length = 100;

    std::string newLine(int length){
        std::string new_Line;
        for (int i = 0; i < length; i++)
        {
            new_Line.append("_");
        }
        return new_Line;
    }

    void Page::write(int row,  int col, Direction direc,const std::string& input){
        
        if(direc == Direction::Horizontal){
            //check if the line exists
            if(Lines.find(row) == Lines.end()){
                Lines.at(row) = newLine(row_length);
            }
            for (int i = col; i < col + (int)input.length(); i++){
                Lines.at(row).at((unsigned int)i) = input[(unsigned long)(i-col)];
            }
            // update maxLine for show
            if(row > maxLine){
                maxLine = row;
            }
        }

        if(direc == Direction::Vertical){
            for (int i = row; i < row + (int)input.length(); i++)
            {
                if(Lines.find(i) == Lines.end()){
                    Lines.at(i) = newLine(row_length);
                }
                Lines.at(i).at((unsigned int)col) = input[(unsigned long)(i-row)];
            }

            // update maxLine for show
            if(row + (int)input.length() > maxLine){
                maxLine = row;
            }
        }
        
    }

    std::string Page::read(int row,  int col,Direction direc,  int length){
        std::string answer;
        if(direc == Direction::Horizontal){
            //check if the line exists
            if(Lines.find(row) == Lines.end()){
                return newLine(length);
            }
            // Read the line
            for (int i = col; i < col + length; i++){
                char cur = (char)Lines.at(row).at((unsigned int)i);
                answer.push_back(cur);
            }
        }

        if(direc == Direction::Vertical){
            for (int i = row; i < row + length; i++)
            {
                if(Lines.find(i) == Lines.end()){
                    answer.push_back('_');
                }
                else{
                    char cur = (char)Lines.at(i).at((unsigned int)col);
                    answer.push_back(cur);
                }
            }
        }
        return answer;
    }

    void Page::erase(int row,  int col,Direction direc,  int length){

        if(direc == Direction::Horizontal){
            //check if the line exists
            if(Lines.find(row) == Lines.end()){
                Lines.at(row) = newLine(row_length);
            }
            for (int i = col; i < col + length; i++){
                Lines.at(row).at((unsigned int)i) = '~';
            }
        }

        if(direc == Direction::Vertical){
            for (int i = row; i < row + length; i++)
            {
                if(Lines.find(i) == Lines.end()){
                    Lines.at(i) = newLine(row_length);
                }
                Lines.at(i).at((unsigned int)col) = '~';
            }
        }
    }

    void Page::show(){
        for (int i = 0; i <= maxLine; i++)
        {
            if(Lines.find(i) == Lines.end()){
                std::cout<<newLine(row_length)<<std::endl;
            }
            else{
                std::cout<<read(i,0,Direction::Horizontal,row_length)<<std::endl;
            }
        }
        
    }
}