#include <iostream>

#include "node.hpp"
#include "node_dl.hpp"
#include "queue.hpp"

using namespace std;

int main()
{
    Queue<int> q(0, 1, 2, 3, 4, 5, 6);
    q += q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.back();
    q.flip();
    cout << q.back();
    return 0;
}
