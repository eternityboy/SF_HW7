#include <iostream>
#include "IntArray.h"

int main()
{
    int arrayLength = 10;
//    int arrayLength = -10;
    try
    {
        IntArray arr(arrayLength);
        arr.showArray();
        arr.CreateArray();
        arr.showArray();
        arr.showLength();

        arr.erase();
        arr.showLength();

        arr.resize(arrayLength);
        arr.resize(arrayLength - 1);
        arr.CreateArray();
        arr.showArray();
        arr.showLength();
//        arr.insert(5, 77);
        arr.insert(77, 5);
        arr.showArray();
        arr.remove(0);
        arr.showArray();
        arr.insertAtTheBeginning(11);
        arr.insertAtTheEnd(11);
        arr.showArray();
        arr.showLength();
    }
    catch (BadLength& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (BadRange& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}