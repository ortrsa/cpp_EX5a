#include "doctest.h"
#include "OrgChart.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using std::string;
using std::vector;
using std::endl;
using std::cout;
using namespace ariel;





TEST_CASE("Basic Chacks") {
    //init
    OrgChart organization;

    // add CEO and CFO
    CHECK_NOTHROW(organization.add_root("CEO").add_sub("CEO","CFO"));
    // check begin and add for all iterators
    CHECK((*organization.begin_level_order()).get_name() == "CEO");
    CHECK((*organization.end_level_order()).get_name() == "CFO");
    
    CHECK((*organization.begin_reverse_order()).get_name() == "CFO");
    CHECK((*organization.reverse_order()).get_name() == "CEO");
    
    CHECK((*organization.begin_preorder()).get_name() == "CEO");
    CHECK((*organization.end_preorder()).get_name() == "CFO");
    
    CHECK((*organization.begin()).get_name() == "CEO");
    CHECK((*organization.end()).get_name() == "CFO");

    // change the CEO
    CHECK_NOTHROW(organization.add_root("CEO2"));
    CHECK((*organization.begin_level_order()).get_name() == "CEO2");

    // try to add_sub with name that dont defind
    CHECK_THROWS(organization.add_sub("CEO3", "CTO"));
    //print the OrgChart
    CHECK_NOTHROW(cout<<organization<<endl);
}

TEST_CASE("tree checks") {
    /*
    
          E1
        /  |  \
      E2   E3  E4
      /\       /
    E5 E6    E7  
    
     */
    
    OrgChart smallorg;
    CHECK_NOTHROW(smallorg.add_root("E1").add_sub("E1","E2").add_sub("E1","E3").add_sub("E1","E4" ));
    CHECK_NOTHROW(smallorg.add_sub("E2", "E5").add_sub("E2","E6").add_sub("E4","E7"));
    
    //Check level order
    std::vector<string> level_order_vec{"E1","E2","E3","E4","E5", "E6", "E7"};
    unsigned int i1 = 0;
    for (auto it = smallorg.begin_level_order(); it != smallorg.end_level_order(); ++it)
    {
        CHECK((*it).get_name() == level_order_vec.at(i1));
        i1++;
    } 

    //Check reverse order
    std::vector<string> reverse_order_vec{"E5","E6","E7","E2","E3", "E4", "E1"};
    unsigned int i2 = 0;
    for (auto it = smallorg.begin_reverse_order(); it != smallorg.reverse_order(); ++it)
    {
        CHECK((*it).get_name() == reverse_order_vec.at(i2));
        i2++;
    } 

    //Check preorder
    std::vector<string> preorder_vec{"E1","E2","E5","E6","E3", "E4", "E7"};
    unsigned int i3 = 0;
    for (auto it = smallorg.begin_preorder(); it != smallorg.end_preorder(); ++it)
    {
        CHECK((*it).get_name() == preorder_vec.at(i3));
        i3++;
    } 

    
    
}
TEST_CASE("Change the root") {
    OrgChart rootchange;
    CHECK_NOTHROW(rootchange.add_root("E1").add_sub("E1","E2").add_sub("E1","E3").add_sub("E1","E4" ));
    CHECK_NOTHROW(rootchange.add_sub("E2", "E5").add_sub("E2","E6").add_sub("E4","E7"));

    // check the current root
    CHECK((*rootchange.begin()).get_name() == "E1");
    // change the root
    CHECK_NOTHROW(rootchange.add_root("E8"));
    // check the new root
    CHECK((*rootchange.begin()).get_name() == "E8");
    // check if all the node connect to the new root
    std::vector<string> level_order_vec{"E8","E2","E3","E4","E5", "E6", "E7"};
    unsigned int i = 0;
    for (auto it = rootchange.begin_level_order(); it != rootchange.end_level_order(); ++it)
    {
        CHECK((*it).get_name() == level_order_vec.at(i));
        i++;
    } 

    // Add two node with the same name
    CHECK_NOTHROW(rootchange.add_sub("E7", "E7"));
    CHECK((*rootchange.begin_reverse_order()).get_name() == "E7");


}

