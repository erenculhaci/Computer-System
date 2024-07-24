# Computer System

This project implements a simulation of a computer system with components including a CPU, GPU, ALU, and CUDA cores. Each component has specific responsibilities and interacts with others to perform various operations. This README provides an overview of the classes and their functionality.

## Classes Overview

### 1. Computer
The `Computer` class serves as the central hub for performing operations using attached components. It has the following attributes:

- **attachedCPU**: A reference to an attached `CPU` object.
- **attachedGPU**: A reference to an attached `GPU` object.

#### Key Features:
1. **Attach CPU/GPU**: CPUs and GPUs can be attached to a computer using the "+" operator. A `Computer` object and a reference to a `CPU` or `GPU` object are required. A computer can only have one CPU and one GPU attached at a time.

2. **Execute Operations**: The `execute` method is used to perform operations based on an operation name provided as an argument. The method delegates the operation to the appropriate component (CPU or GPU) as per the operation type and prints the result. The supported operations and their responsible components are outlined in Table 1.

## Operations Table (Table 1)

| Operation         | Responsible Component |
|-------------------|-----------------------|
| add          | CPU (via ALU)         |
| subtract       | CPU (via ALU)         |
| multiply    | CPU (via ALU)         |
| render   | GPU (via CUDA)        |
| trainModel | GPU (via CUDA)        |

### 2. CPU
The `CPU` class represents the Central Processing Unit of the computer and includes:

- **ALU**: An instance of the `ALU` class, which handles arithmetic operations.
- **numPerCores**: An attribute initialized by the CPU, representing the number of ALUs per core.

#### Key Features:
- **Execute Method**: The `CPU`'s `execute` method reads two integers from the user, delegates the operation to the `ALU`, and returns the result.

### 3. GPU
The `GPU` class represents the Graphics Processing Unit and includes:

- **CUDA**: An instance of the `CUDA` class, which handles specialized operations like rendering and AI model training.
- **numCores**: An attribute initialized by the GPU, representing the number of CUDA cores.

#### Key Features:
- **Execute Method**: The `GPU`'s `execute` method uses its `CUDA` object to perform specific operations and returns the result.

### 4. ALU
The `ALU` (Arithmetic Logic Unit) class performs basic arithmetic operations and includes:

- **numPerCores**: An integer representing the number of ALUs per CPU core.

#### Key Methods:
- **add(int a, int b)**: Returns the sum of `a` and `b`.
- **subtract(int a, int b)**: Returns the difference between `a` and `b`.
- **multiply(int a, int b)**: Returns the product of `a` and `b`.

### 5. CUDA
The `CUDA` class represents CUDA cores within the GPU and includes:

- **numCores**: An integer representing the number of CUDA cores.

#### Key Methods:
- **render()**: Renders a video and returns the result as: "Video is rendered".
- **trainModel()**: Trains an AI model and returns the result as: "AI Model is trained".

## Usage

To use the simulation:

1. Create instances of `Computer`, `CPU`, and `GPU`.
2. Attach the `CPU` and `GPU` to the `Computer` using the "+" operator.
3. Call the `execute` method on the `Computer` object with the desired operation name.

Example:
```cpp
Computer computer;
CPU cpu;
GPU gpu;

computer + cpu;
computer + gpu;

computer.execute("Addition");
```

## How to compile, run and test

To build:
```cpp
$ g++ -Wall -Werror src/Computer.cpp src/main.cpp -I include -o computersystem
$ ./computersystem
```

To test:
```cpp
$ calico test.yaml --debug |& tee calico_log.txt
```

## UML Diagram of the Classes
![CLASS RELATIONSHIP DIAGRAM](https://github.com/user-attachments/assets/ee27ad94-4271-43ab-94b4-fe269e16afb6)


