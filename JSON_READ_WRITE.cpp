
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <tuple>
#include "json.hpp"
#include "json_fwd.hpp"

using namespace std;
using json = nlohmann::json;

struct MyTest {
    pair<string,int> t1;
    pair<string, string> t2;
    pair<string, int> t3;
};



int main()
{
    std::cout << "Hello World!\n";

    fstream theFile;
    theFile.open("data.txt", ios::in);

    json theDoc = json::parse(theFile); 


    //std::cout << theDoc.dump(4);

   // auto temp = theDoc.at("users").get<vector<MyTest>>();

    auto temp = theDoc.at("users");
    temp.push_back( { make_pair("id", 16),make_pair("firstName", "Jezabel"),make_pair("age", 66) });
    //cout << temp[0]["firstName"].get<string>() << endl;

    for (auto i : temp) {
        cout << i << endl;
        cout << i["age"] << endl;
    }
    MyTest xx;
    xx.t1 = make_pair("id", 16);
    xx.t2 = make_pair("dd", "dfsdfsd");
    xx.t3 = make_pair("xx", 66);

   
    

   // cout << temp.type_name() << endl;

}
