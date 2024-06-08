#include <iostream>
#include <list>

using namespace std;

int main()
{
    list <int> arr1 = {2, 5, 7, 4, 9};
    list <int> :: iterator  it;
    int i = 0;
    for (it = arr1.begin(); it != arr1.end(); ++it)
        {
            if(i==2)
                {
                    arr1.insert(it, 10);
                    break;
                }
            i++;
        }

    i = 0;
    for (it = arr1.begin(); it != arr1.end(); ++it)
        {
            if(i==4)
                {
                    arr1.erase(it);
                    break;
                }
            i++;
        }
    for(auto const var : arr1)
        {
            cout << "Value: " << var << endl;
        }
    
    return 0;
}