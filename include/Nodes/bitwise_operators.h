#pragma once


template<typename LHS, typename RHS>
class BitwiseAnd: public Node<Inputs<Input<LHS>, Input<RHS>>, Outputs<Output<bool>>>{


public:

    BitwiseAnd(){}
    BitwiseAnd(Inputs<Input<LHS>, Input<RHS>> inputs, Outputs<Output<bool>> outputs):  BitwiseAnd::Node(inputs, outputs){

    }

    void step(){

        auto a = std::get<0>(BitwiseAnd::in_).get();
        auto b = std::get<1>(BitwiseAnd::in_).get();

        std::get<0>(BitwiseAnd::out_).put(a & b);
    }

};


template<typename LHS, typename RHS>
class BitwiseOr: public Node<Inputs<Input<LHS>, Input<RHS>>, Outputs<Output<bool>>>{


public:

    BitwiseOr(){}
    BitwiseOr(Inputs<Input<LHS>, Input<RHS>> inputs, Outputs<Output<bool>> outputs):  BitwiseOr::Node(inputs, outputs){

    }

    void step(){

        auto a = std::get<0>(BitwiseOr::in_).get();
        auto b = std::get<1>(BitwiseOr::in_).get();

        std::get<0>(BitwiseOr::out_).put(a | b);
    }

};

template<typename LHS, typename RHS>
class BitwiseNand: public Node<Inputs<Input<LHS>, Input<RHS>>, Outputs<Output<bool>>>{


public:

    BitwiseNand(){}
    BitwiseNand(Inputs<Input<LHS>, Input<RHS>> inputs, Outputs<Output<bool>> outputs):  BitwiseNand::Node(inputs, outputs){

    }

    void step(){

        auto a = std::get<0>(BitwiseNand::in_).get();
        auto b = std::get<1>(BitwiseNand::in_).get();

        std::get<0>(BitwiseNand::out_).put(~(a & b));
    }

};


template<typename LHS, typename RHS>
class BitwiseNor: public Node<Inputs<Input<LHS>, Input<RHS>>, Outputs<Output<bool>>>{


public:

    BitwiseNor(){}
    BitwiseNor(Inputs<Input<LHS>, Input<RHS>> inputs, Outputs<Output<bool>> outputs):  BitwiseNor::Node(inputs, outputs){

    }

    void step(){

        auto a = std::get<0>(BitwiseNor::in_).get();
        auto b = std::get<1>(BitwiseNor::in_).get();

        std::get<0>(BitwiseNor::out_).put(~(a | b));
    }

};