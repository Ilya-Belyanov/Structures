#include <iostream>

#include "node.h"
#include "queue.h"

using namespace std;

int main()
{
    Queue<int> q;
    Node<int> n(12);
    cout << n.data();
    return 0;
}
