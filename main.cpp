#include <iostream>

#include "queue.hpp"
#include "vector.hpp"

using namespace std;

int main()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.flip();
    cout << v.front() << endl;
    cout << v.back() << endl;
    return 0;
}
