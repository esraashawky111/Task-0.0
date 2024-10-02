# C Task 0.0
 **Embedded Software Gems ,Mentor Eng: Ahmed Tolba**
 __This repository focuses on evaluating different tasks related to the performance, memory usage, and precision for embedded systems. Each task compares
   two or more methods for solving a specific problem.__
 **why we use Look up table to generate sine wave..?**
 1. __Efficiency__: Computing a sine function in real-time using mathematical operations like trigonometric functions can be computationally expensive, especially in systems with limited processing power (like microcontrollers). A lookup table allows the system to retrieve precomputed sine values almost instantly.
2. __Speed__: Since the sine values are precomputed and stored in a table, the system only needs to access the table (often just a memory read operation) to get the output, making the process much faster than real-time calculation.
3. __Accuracy__: A lookup table can provide high accuracy by using a dense set of precomputed sine values. By interpolating between these values, even higher precision can be achieved without increasing the computation time.
**Using a lookup table (LUT) to generate a sine wave has several disadvantages:**
1. __Memory Usage__: A lookup table requires memory to store precomputed sine values. If high precision is needed (e.g., for a high-resolution sine wave), the table can become quite large, especially in systems with limited memory capacity.
2. __Limited Resolution__: The accuracy of a sine wave generated from a lookup table is limited by the number of entries in the table. If the table doesn't have enough points, the resulting sine wave may suffer from aliasing or quantization errors.
   
   **The result for code with LUT**
 

The sine values correspond to a sine wave over 360 degrees, starting from 0 and progressing to 360 degrees. Since the code cycles every 360 samples (i % LUT_SIZE), samples 360 to 999 will repeat the sine wave values from the start.


*SIZE of assembly code is bigger than in the second case **

**Execation time is =97 micro second**

                                      **///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////**

__THE result of code without using LUTs:__

The funcation you've written will generate a sine wave using The C Standard Library (math.h) offers functions.
*SIZE of assembly without usging LUT IS less in the first case *

**Execution time = 160 micro second**
