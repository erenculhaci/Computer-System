#include "Computer.h"

///////////////////----CUDA----////////////////////////
///////////////////////////////////////////////////////

CUDA::CUDA(int ncores = 0){ //constructor for CUDA class initializes numCores.
        numCores = ncores;
        std::cout << "CUDA is ready" << std::endl; // when CUDA's constructor works it prints "CUDA is ready"
}

int CUDA::get_numCores() const { //getter for numCores.
    return numCores; 
}
void CUDA::set_numCores(const int nCores){ //setter for numCores.
    numCores = nCores;
}
std::string CUDA::render() const{ // render method for CUDA. When it works it prints "Video is rendered"
    return "Video is rendered";
}
std::string CUDA::trainModel() const{ // trainModel method for CUDA. When it works it prints "AI Model is trained"
   return "AI Model is trained";
}

///////////////////----ALU----/////////////////////////
///////////////////////////////////////////////////////

    ALU::ALU(int n_p_Cores = 0){ //constructor for ALU class initializing numPerCores.
        numPerCores = n_p_Cores;
        std::cout << "ALU is ready" << std::endl; // when ALU's constructor works it prints "ALU is ready"
    }
    
    int ALU::add(const int a, const int b) const{ // add method for ALU. It calculates a+b and returns the result value.
        return a+b;
    }
    int ALU::subtract(const int a, const int b) const{ // subtract method for ALU. It calculates a-b and returns the result value.
        return a-b;
    }
    int ALU::multiply(const int a, const int b) const{ // multiply method for ALU. It calculates a*b and returns the result value.
        return a*b;
    }
    int ALU::get_numPerCores() const{ //getter for numPerCores
        return numPerCores;
    }
    void ALU::set_numPerCores(const int nPerCores){ //setter for numPerCores
        numPerCores = nPerCores;
    }

///////////////////----GPU----/////////////////////////
///////////////////////////////////////////////////////

    GPU::GPU(int cuda_cores){ //constructor for GPU class initializing numCores of the CUDA object.
        cuda.set_numCores(cuda_cores);
        std::cout << "GPU is ready" << std::endl; // when GPU's constructor works it prints "GPU is ready"
    }

    std::string GPU::execute(const std::string operation) const{ //execute method to execute GPU operations (render, trainModel). It gets string argument which decides the operation.
        if(operation == "render"){ //If the string operation is "render" this code block calls the render() method of cuda object and returns the string value.
            return cuda.render();
        }
        else if (operation == "trainModel"){ //Else if the string operation is "trainModel" this code block calls the trainModel() method of cuda object and returns the string value.
            return cuda.trainModel();
        }
        return ""; //default
    }

    CUDA GPU::get_cuda() const{ //getter method for cuda
        return cuda;
    }

    void GPU::set_cuda(CUDA cd){ //setter method for cuda
        cuda=cd;
    }

///////////////////----CPU----/////////////////////////
///////////////////////////////////////////////////////

    CPU::CPU(int alu_cores){ //constructor for CPU class initializing numPerCores of the ALU object.
    alu.set_numPerCores(alu_cores);
    std::cout << "CPU is ready" << std::endl; // when CPU's constructor works it prints "CPU is ready"
    }

    int CPU::execute(const std::string operation) const{ //execute method to execute CPU operations (add, subtract, multiply). It gets string argument which decides the operation.
        int a,b; // two integers for calculation.
        std::cout << "Enter two integers" << std::endl; //prints "Enter two integers" on screen.
        std::cin >> a >> b; // it gets two a and b integer value inputs from keyboard.

        if(operation == "add"){ //If the string operation is "add" this code block calls the add() method of alu object and returns the string value.
            return alu.add(a,b);
        }
        else if (operation == "subtract"){ //If the string operation is "subtract" this code block calls the subtract() method of alu object and returns the string value.
            return alu.subtract(a,b);
        }
        else if (operation == "multiply"){ //If the string operation is "multiply" this code block calls the multiply() method of alu object and returns the string value.
            return alu.multiply(a,b);
        }
        return 0; //default
    }

    ALU CPU::get_alu() const{ //getter for alu
        return alu;
    }

    void CPU::set_alu(ALU Alu){ //setter for alu
        alu=Alu;
    }

///////////////////----COMPUTER----////////////////////
///////////////////////////////////////////////////////

Computer::Computer(){
    std::cout << "Computer is ready" << std::endl; // when Computer's constructor works it prints "Computer is ready"
    attachedCPU = NULL; //initializing attachedCPU pointer as null.
    attachedGPU = NULL; //initializing attachedGPU pointer as null.
}

Computer Computer::operator+(const CPU &cpu){ //operator overloading for "+" operation to attach CPU to computer. It takes reference of the cpu object.
    if(attachedCPU == NULL){ //if there isn't any attached CPU, it attaches the cpu to computer.
        attachedCPU = &cpu; //attachedCPU now points the cpu.
        std::cout << "CPU is attached" << std::endl; // prints "CPU is attached" on display.
        return *this; //returns this computer object.
    }
    else{
        std::cout << "There is already a CPU" << std::endl; //If there is an attached CPU, it doesn't attach CPU anymore and prints There is already a CPU" on display.
        return *this; //returns this computer object.
    }
}

Computer Computer::operator+(const GPU &gpu){ //operator overloading for "+" operation to attach GPU to computer. It takes reference of the gpu object.
    if(attachedGPU == NULL){ //if there isn't any attached GPU, it attaches the gpu to computer.
        attachedGPU = &gpu; //attachedGPU now points the gpu.
        std::cout << "GPU is attached" << std::endl; // prints "GPU is attached" on display.
        return *this; //returns this computer object.
    }
    else{
        std::cout << "There is already a GPU" << std::endl; //If there is an attached GPU, it doesn't attach GPU anymore and prints There is already a GPU" on display.
        return *this; //returns this computer object.
    }
}

void Computer::execute(const std::string operation) const{ //execute method to execute all operations (render, trainModel, add, subtract, multiply). It gets string argument which decides the operation.
    if(operation == "render"){ //If the string operation is "render" this code block calls the execute() operation of the attachedGPU and prints the result string.
        std::cout << attachedGPU->execute(operation) << std::endl;
    }
    else if(operation == "trainModel"){ //If the string operation is "trainModel" this code block calls the execute() operation of the attachedGPU and prints the result string.
        std::cout << attachedGPU->execute(operation) << std::endl;
    }
    else if(operation == "add"){ //If the string operation is "add" this code block calls the execute() operation of the attachedCPU and prints the result integer value.
        std::cout << attachedCPU->execute(operation) << std::endl;
    }
    else if(operation == "subtract"){ //If the string operation is "subtract" this code block calls the execute() operation of the attachedCPU and prints the result integer value.
        std::cout << attachedCPU->execute(operation) << std::endl;
    }
    else if(operation == "multiply"){ //If the string operation is "multiply" this code block calls the execute() operation of the attachedCPU and prints the result integer value.
        std::cout << attachedCPU->execute(operation) << std::endl;
    }
}