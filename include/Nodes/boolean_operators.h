#pragma once



template<typename LHS, typename RHS>
class And: public Node<Inputs<Input<LHS>, Input<RHS>>, Outputs<Output<bool>>>{


public:

    And(){}
    And(Inputs<Input<LHS>, Input<RHS>> inputs):  And::Node(inputs, std::make_tuple(Output<bool>())){}
    And(Inputs<Input<LHS>, Input<RHS>> inputs, Outputs<Output<bool>> outputs):  And::Node(inputs, outputs){

    }

    void step(){

        auto a = std::get<0>(And::in_).get();
        auto b = std::get<1>(And::in_).get();

        std::get<0>(And::out_).put(a & b);
    }

};


template<typename LHS, typename RHS>
class Or: public Node<Inputs<Input<LHS>, Input<RHS>>, Outputs<Output<bool>>>{


public:

    Or(){}
    Or(Inputs<Input<LHS>, Input<RHS>> inputs, Outputs<Output<bool>> outputs):  Or::Node(inputs, outputs){

    }

    void step(){

        auto a = std::get<0>(Or::in_).get();
        auto b = std::get<1>(Or::in_).get();

        std::get<0>(Or::out_).put(a & b);
    }

};

template<typename LHS, typename RHS>
class GreaterThan: public Node<Inputs<Input<LHS>, Input<RHS>>, Outputs<Output<bool>>>{


public:

    GreaterThan(){}
    GreaterThan(Inputs<Input<LHS>, Input<RHS>> inputs):  GreaterThan::Node(inputs, std::make_tuple(Output<bool>())){

    }
    GreaterThan(Inputs<Input<LHS>, Input<RHS>> inputs, Outputs<Output<bool>> outputs):  GreaterThan::Node(inputs, outputs){

    }

    void step(){

        auto a = std::get<0>(GreaterThan::in_).get();
        auto b = std::get<1>(GreaterThan::in_).get();

        std::get<0>(GreaterThan::out_).put(a > b);
    }

};


template<typename LHS, typename RHS>
class LessThan: public Node<Inputs<Input<LHS>, Input<RHS>>, Outputs<Output<bool>>>{


public:

    LessThan(){}
    LessThan(Inputs<Input<LHS>, Input<RHS>> inputs, Outputs<Output<bool>> outputs):  LessThan::Node(inputs, outputs){

    }

    void step(){

        auto a = std::get<0>(LessThan::in_).get();
        auto b = std::get<1>(LessThan::in_).get();

        std::get<0>(LessThan::out_).put(a < b);
    }

};


template<typename LHS, typename RHS>
class Equals: public Node<Inputs<Input<LHS>, Input<RHS>>, Outputs<Output<bool>>>{


public:

    Equals(){}
    Equals(Inputs<Input<LHS>, Input<RHS>> inputs, Outputs<Output<bool>> outputs):  Equals::Node(inputs, outputs){

    }

    void step(){

        auto a = std::get<0>(Equals::in_).get();
        auto b = std::get<1>(Equals::in_).get();

        std::get<0>(Equals::out_).put(a == b);
    }

};