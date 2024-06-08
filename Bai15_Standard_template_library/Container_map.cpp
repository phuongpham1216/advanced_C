#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map <string, int> myMap;
    map <string, int> :: iterator it;

    //Thêm phần tử vào map
    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;

    myMap.insert(make_pair("four",4));

    cout << "----------------------" << endl;
    for(auto const var:myMap)
        {
            cout << "Key: " << var.first << ", " << "Value: " << var.second << endl;
        }

    myMap.erase("one");
    cout << "----------------------" << endl;

    for(it=myMap.begin(); it!=myMap.end(); ++it)
        {
            cout << "Key: " << (*it).first << ", " << "Value: " << (*it).second << endl;
        }

    return 0;

}