#include "Direction.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace ariel{

    class Page{
        
        private:

        std::unordered_map<int,std::string> Lines;
        
        // int maxLine = 0;
            
        public:

            //constuctor
            Page(){}

            //destructor
            ~Page(){}

            // given the row and col write the given string, horizontal or vertical
            void write(int row,  int col, Direction direc,const std::string& input){}

            // given the row and col read the given amount of characters, horizontal or vertical
            std::string read(int row,  int col,Direction direc,  int length){
                return "test";
            }

            // given the row and col earse the given given amount of characters, horizontal or vertical
            void erase(int row,  int col,Direction direc,  int length){}

            // prints the notebook
            void show(){}

    };
};