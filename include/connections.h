#pragma once

#include<mutex>
#include<memory>
#include <iostream>
#include <queue>
#include <condition_variable>





//***************************
// Connections:
// one-way mailbox shared data container
// Data has a mutex and private put() member
// Output is friends with Data and is allowed to put new data
// Input is not friends and only has access to get data
//***************************


class connection{

public:

    virtual void stop(){

    }

};





template<class T>
class Output;
 
// this is the mailbox
// provides thread-safety and read/write  security
template<class T>
class Data
{


public:

    Data(T initial)
    {
        item_ = initial;

    }

    Data(){}


    T get(){
        std::unique_lock<std::mutex> lg(m_);
        
        return item_;
    }


    // template<class U>
    // data(const data<U>& i){ 
    //     item_ = (T)(i.item_);
    // }


private:

    std::mutex m_;


    T item_;

    friend class Output<T>;
    
    void put(T item)
    {
        std::unique_lock<std::mutex> lg(m_);

        item_ = item;
    }


};


// the read end of the connection
template<class T>
class Input: public connection
{


public:

    Input(Data<T>* data)
    {
        data_ = data;
    }
    Input(std::shared_ptr<Data<T>> data){
        data_ = data.get();
    }
    Input(){};

    T get() const
    {
        return data_->get();
    }

    // template<class U>
    // Input(const Input<U>& i){ 

    //     data_ = reinterpret_cast<data<T>*>(i.getDataPtr());
    // }

    const Data<T>* getDataPtr() const {
        return data_;
    }

private:

    Data<T>* data_;

 
};


// the write end of the connection
template<class T>
class Output: public connection
{

public:

    Output(T initial_Output)
    {
        // data_ = std::make_shared<data<T>>(initial_Output);
        data_ = std::make_shared<Data<T>>(initial_Output);
    }

    Output()
    {
        //data_ = std::make_shared<data<T>>();
        data_ = std::make_shared<Data<T>>();
    }

    void put(T item)
    {
        if(data_)
        {
            
            data_->put(item);
        }
    }

    T get() const
    {
        return data_->get();
    }

    
    Input<T> getConnection()
    {
        return Input<T>(data_);
    }

private:

    std::shared_ptr<Data<T>> data_; 


};







