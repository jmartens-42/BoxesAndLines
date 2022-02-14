

#include <iostream>
#include <tuple>

#include "node.h"
#include "Nodes/test_node.h"
#include "Nodes/boolean_operators.h"
#include "connections.h"


int main(){



    Output<int> a;
    Output<int> b;
    Output<int> c;

    Output<bool> y;
    

    TestNode t(std::make_tuple(a.getConnection(), b.getConnection(), c.getConnection()), std::make_tuple(y));

    auto out = t.getOutput<0>();

    // auto can = NodeCanister(std::make_tuple(n, n2));

    // NodeHolder can(n2);

    a.put(7);
    b.put(6);
    c.put(5);

    t.step();


    auto res2 = out.get();



    std::cout << "hello, world! " << res2 << "\n";
    return 0;
}





