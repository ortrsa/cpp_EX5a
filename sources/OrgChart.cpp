#include "OrgChart.hpp"
using namespace std;
using namespace ariel;
namespace ariel{

    OrgChart OrgChart::add_root(string node){
        return *this;
    };
    OrgChart OrgChart::add_sub(string node1, string node2 ){
        return *this;
    };
    Iter OrgChart::begin_level_order(){
        Iter it;
        return it;
    };
    Iter OrgChart::end_level_order(){
        Iter it;
        ++it;
        return it;
    };
    Iter OrgChart::begin_reverse_order(){
        Iter it;
        return it;
    };
    Iter OrgChart::reverse_order(){
        Iter it;
        ++it;
        return it;
    };
    Iter OrgChart::begin_preorder(){
        Iter it;
        return it;
    };
    Iter OrgChart::end_preorder(){
        Iter it;
        ++it;
        return it;
    };
    Iter OrgChart::begin(){
        Iter it;
        return it;
    };
    Iter OrgChart::end(){
        Iter it;
        ++it;
        return it;
    };

    std::ostream &operator << ( ostream &output, const OrgChart &n){
            output << "a";
            return(output);
    };




}