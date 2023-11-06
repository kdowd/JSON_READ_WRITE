
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
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
    theFile.open("data.txt", ios::in | ios::out | ios::app);

    json theDoc = json::parse(theFile);


    //std::cout << theDoc.dump(4);

    //auto temp = theDoc.at("users").get<vector<MyTest>>();

    auto temp = theDoc.at("users");
    temp[0]["age"] = 666;
    temp.push_back({ make_pair("id", 16),make_pair("firstName", "Jezabel"),make_pair("age", 66) });

  // theDoc.push_back({ make_pair("id", 16),make_pair("firstName", "Jezabel"),make_pair("age", 66) });


    MyTest xx;
    xx.t1 = make_pair("id", 16);
    xx.t2 = make_pair("firstName", "dfsdfsd");
    xx.t3 = make_pair("age", 66);
 

    for (auto i : temp) {
        cout << i << endl;
        cout << i["age"] << endl;
    }
   
    map<string, int> fff;
    fff.insert(make_pair("age", 66));

 
    theFile << theDoc.dump(4);;

    theFile.close();
    

   // cout << temp.type_name() << endl;

}
