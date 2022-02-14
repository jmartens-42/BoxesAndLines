#pragma once


#include <thread>

#include <concepts>



//***************************
// Node:
// This is the cornerstone
// Node is inherited by classes which impliment a step() function
// this step() function is where all of the functionality is
// Node provides tuples of data, one for inputs and the other for outputs
// currently using std::get<int> to access specific inputs/outputs
// commonly the InputTypes will be Inputs, and OutputTypes will be Outputs
//***************************





template<typename... T>
using Inputs = std::tuple<T...>;

template<typename... T>
using Outputs = std::tuple<T...>;


// non-templated base class so we can hold polymorphic 
// collections of Nodes as well as for the NodeItem concept
class NodeBase{};


// initial declaration of Node
// we will be using the specialized one where 
// the templates are split into input/output types
template<typename... T>
class Node: public NodeBase{};

// class specializations allow for mulitple variadic templates
template<typename... InputTypes, typename... OutputTypes>
class Node<Inputs<InputTypes...>, Outputs<OutputTypes...>>: public NodeBase{

public:

    Node(){}
    Node(Inputs<InputTypes...> inputs, Outputs<OutputTypes...> outputs): in_(inputs), out_(outputs){
    }
    Node(Inputs<InputTypes...> inputs, Outputs<OutputTypes...> outputs, auto trigger_inputs): in_(inputs), out_(outputs){

    }


    template<int I>
    auto getOutput(){
        return std::get<I>(out_).getConnection();
    }

protected:

    Inputs<InputTypes...> in_;
    Outputs<OutputTypes...> out_;

};


template<typename... InputTypes, typename... OutputTypes>
auto createNode(Inputs<InputTypes...> inputs, Outputs<OutputTypes...> outputs){
    return Node<Inputs<InputTypes...>, Outputs<OutputTypes...>>(inputs, outputs);
}


template<typename T>
concept NodeItem = requires(T a){

    { a.step() };
    requires std::derived_from<T, NodeBase>;
    
};




class NodeCanisterHandle{

};



template<NodeItem item>
class NodeHolder{
public:
    NodeHolder(item i): i_(i){
    }

    item i_;
};

template<NodeItem... items>
class NodeCanister: public NodeCanisterHandle{


public:

    NodeCanister(std::tuple<items...> nodes): nodes_(std::move(nodes)){

    }

private:


    std::tuple<items...> nodes_;

};






