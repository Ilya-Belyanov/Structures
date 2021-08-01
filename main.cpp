#include <iostream>

#include "node.hpp"
#include "queue.hpp"

using namespace std;

int main()
{
    Queue<int> q;
    Node<int> n(12);
    cout << n.data();
    return 0;
}
