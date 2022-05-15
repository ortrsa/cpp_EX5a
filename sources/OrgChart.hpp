#ifndef OrgChart_H
#define OrgChart_H

#include <iostream>
#include <vector>
#include "Node.hpp"

using std::string;
using std::vector;
using std::invalid_argument;
using std::ostream;
namespace ariel
{
    class Iter;
    class Node;
    class OrgChart
    {

        Node top;
    public:
        OrgChart(){
            
        };
        OrgChart add_root(string node);
        OrgChart add_sub(string node1, string node2 );
        Iter begin_level_order();
        Iter end_level_order();
        Iter begin_reverse_order();
        Iter reverse_order();
        Iter begin_preorder();
        Iter end_preorder();
        Iter begin();
        Iter end();

        friend ostream &operator << ( ostream &output, const OrgChart &n);


    };

    class Iter{

        public:
            Iter(){};
            
            // ptr to element in iterator
            Node operator*(){
                return Node();
            };
            // increase by 1
            Iter operator++(){
                return *this;
            };
            string* operator->() const{
                return nullptr;
            };
            bool operator == (const Iter &it)const{
                return false;
            };
            bool operator != (const Iter &it)const{
                return false;
            };

            
        


    };
}
#endif