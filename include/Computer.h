#include <iostream>
#include <string>

///////////////////----CUDA----////////////////////////
///////////////////////////////////////////////////////

class CUDA{
    public:
    CUDA(int); //constructor
    int get_numCores() const; //getter for numCores
    void set_numCores(const int); //setter for numCores
    std::string render() const; //render method
    std::string trainModel() const; //trainModel method

    private:
    int numCores;
};

///////////////////----ALU----/////////////////////////
///////////////////////////////////////////////////////

class ALU{
    public:
    ALU(int); //constructor
    int add(const int,const int) const; //add method with two integers
    int multiply(const int,const int) const; //multiply method with two integers
    int subtract(const int,const int) const; //subtract method with two integers
    int get_numPerCores() const; //getter method for numPerCores
    void set_numPerCores(const int); //setter method for numPerCores

    private:
    int numPerCores;
};

///////////////////----GPU----/////////////////////////
///////////////////////////////////////////////////////

class GPU{
    public:
    GPU(int); //constructor
    std::string execute(const std::string) const; //executing operation getting the operation string as argument.
    CUDA get_cuda() const; //getter for CUDA
    void set_cuda(CUDA); //setter for CUDA

    private:
    CUDA cuda; //CUDA object
};

///////////////////----CPU----/////////////////////////
///////////////////////////////////////////////////////

class CPU{
    public:
    CPU(int); //constructor
    int execute(const std::string) const; //execute method for cpu, getting operation string as argument.
    ALU get_alu() const; //getter for ALU
    void set_alu(ALU); //setter for ALU

    private:
    ALU alu; //ALU object
};

///////////////////----COMPUTER----////////////////////
///////////////////////////////////////////////////////

class Computer{
    public:
    Computer(); //constructor
    Computer operator+(const CPU&); // "+" operator overloading for attaching CPU to Computer. It takes CPU as reference.
    Computer operator+(const GPU&); // "+" operator overloading for attaching GPU to Computer. It takes GPU as reference.
    void execute(const std::string) const; //execute method getting operation string as argument.

    private:
    const CPU* attachedCPU; //pointer to CPU
    const GPU* attachedGPU; //pointer to GPU
};