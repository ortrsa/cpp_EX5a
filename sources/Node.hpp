#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::invalid_argument;
using std::ostream;
namespace ariel
{
    class Node{
    private:
        string name;

    
    public:
        
        Node(){};
        string get_name(){
            return name;
        };
        friend ostream &operator << ( ostream &output, const Node &n){
            output << "x";
            return(output);
        };

    };
}
#endif