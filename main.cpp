#include <iostream>

#include "node.hpp"
#include "node_dl.hpp"
#include "queue.hpp"
#include "list.hpp"

using namespace std;

int main()
{
    Queue<int> q(0);
    q += q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.back()<< endl;
    q.flip();
    cout << q.back()<< endl;
    return 0;
}
