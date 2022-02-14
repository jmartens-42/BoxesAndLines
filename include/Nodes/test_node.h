#pragma once


#include "node.h"

#include <tuple>
#include <thread>
#include "connections.h"
#include "Nodes/boolean_operators.h"

class TestNode: public Node<std::tuple<Input<int>, Input<int>, Input<int>>, std::tuple<Output<bool>>>{

public:


    TestNode(std::tuple<Input<int>, Input<int>, Input<int>> a, std::tuple<Output<bool>> b): Node(a, b),

                                                                // connections happen here
                                                                gt_1(std::make_tuple(std::get<0>(in_), std::get<1>(in_))),
                                                                gt_2(std::make_tuple(std::get<1>(in_), std::get<2>(in_))),
                                                                // and_1 is wired into the output of the whole node, no need to transfer anything in our step function
                                                                // this should be done for all outputs for the block
                                                                and_1(std::make_tuple(gt_1.getOutput<0>(), gt_2.getOutput<0>()), b)
                                                                {}

    void step(){


        // this block computes input<0> > input<1> && input<1> > input<2>

        gt_1.step();
        gt_2.step();
        and_1.step();

    }



private:

    // std::mutex step_mutex_;


    GreaterThan<int, int> gt_1;
    GreaterThan<int, int> gt_2;
    And<bool, bool> and_1;
    

};

