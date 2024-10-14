# C Task 0.0
 # Embedded Software Gems ,Mentor Eng: Ahmed Tolba
 ##This repository focuses on evaluating different tasks related to the performance, memory usage, and precision for embedded systems. Each task compares
   two or more methods for solving a specific problem.__
 **why we use Look up table to generate sine wave..?**
 1. __Efficiency__: Computing a sine function in real-time using mathematical operations like trigonometric functions can be computationally expensive, especially in systems with limited processing power (like microcontrollers). A lookup table allows the system to retrieve precomputed sine values almost instantly.
2. __Speed__: Since the sine values are precomputed and stored in a table, the system only needs to access the table (often just a memory read operation) to get the output, making the process much faster than real-time calculation.
3. __Accuracy__: A lookup table can provide high accuracy by using a dense set of precomputed sine values. By interpolating between these values, even higher precision can be achieved without increasing the computation time.
**Using a lookup table (LUT) to generate a sine wave has several disadvantages:**
1. __Memory Usage__: A lookup table requires memory to store precomputed sine values. If high precision is needed (e.g., for a high-resolution sine wave), the table can become quite large, especially in systems with limited memory capacity.
2. __Limited Resolution__: The accuracy of a sine wave generated from a lookup table is limited by the number of entries in the table. If the table doesn't have enough points, the resulting sine wave may suffer from aliasing or quantization errors.
   
   ## The result for code with LUT
   ![This is signal waveform](https://github.com/esraashawky111/Task-0.0/blob/main/Signal%20by%20using%20LUT.png)
    

The sine values correspond to a sine wave over 360 degrees, starting from 0 and progressing to 360 degrees. Since the code cycles every 360 samples (i % LUT_SIZE), samples 360 to 999 will repeat the sine wave values from the start.


 SIZE of assembly code is bigger than in the second case.

**Execution time is =97 micro second**


                                      **//////////////////////////////////////////**

__THE result of code without using LUTs:__

![This is signal waveform](https://github.com/esraashawky111/Task-0.0/blob/main/Signal_without%20_LUT.png)
The funcation you've written will generate a sine wave using The C Standard Library (math.h) offers functions.
*SIZE of assembly without usging LUT IS less in the first case *

**Execution time = 160 micro second**
# The result of Execuation time of using LUT VS without LUT
![This is execuation time](https://github.com/esraashawky111/Task-0.0/blob/main/EXE%20_time%20%20LUT%20VS%20Without%20LUT.png)
 ## The code implementation 
 1. ![LUT.h](https://github.com/esraashawky111/Task-0.0/blob/main/LUT.h)
 2. ![LUT.c](https://github.com/esraashawky111/Task-0.0/blob/main/LUT.c)

                        **///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////**
                                   *//////////////////////////////////////////////////////////////////////////////////////////////////////////////**
                                             **///////////////////////////////////////////////////////////////////////////////////**
                                                   # Task 0.0 /Part 2: Using Fixed-Point Math for Floating-Point Operations. 


Arithmetic operations using fixed-point math and floating-point math have distinct differences in terms of precision, performance, and use cases. Here’s a comparison:

1. __Representation__:

Fixed-point:

Numbers are represented with a fixed number of decimal or binary places. The range and precision are predetermined based on how many bits are allocated to the integer and fractional parts.

Example: 1000 (in base 10) represents 10.00 if two decimal places are assumed.


Floating-point:

Numbers are represented using a mantissa and an exponent, which allows for a much wider dynamic range. The decimal point can "float," providing more flexibility in representing very large or very small numbers.

Example: 1.23 × 10^3 in scientific notation would be 1230.



2. __Precision__:

Fixed-point:

Offers higher precision for a limited range of numbers. Suitable for applications where the range of values is known, but precision is critical (e.g., financial calculations).

Precision is determined by the number of bits used for the fractional part.


Floating-point:

Offers greater dynamic range at the cost of precision, especially when dealing with very large or very small numbers.

Precision can vary; it's higher for numbers closer to zero and decreases as the number grows.



3.__Range__:

Fixed-point:

Limited range, as it cannot handle very large or very small numbers. The range is fixed based on the bit size (e.g., 16-bit or 32-bit).


Floating-point:

Can handle a much larger range of values, including very small fractions and very large numbers, which makes it suitable for scientific and engineering calculations.



4. __Performance__:

Fixed-point:

Faster on processors without dedicated floating-point units (FPUs) because operations are simpler and involve just integer math.

Ideal for embedded systems and real-time applications where performance is crucial.


Floating-point:

Requires more complex operations and is generally slower, especially on processors without FPUs. However, most modern processors have FPUs that can perform floating-point operations quickly.



5. __Memory Usage__:

Fixed-point:

Uses less memory since it typically deals with integer operations and the format is simpler.

Fixed size for both integer and fractional parts.


Floating-point:

Uses more memory (e.g., 32-bit or 64-bit formats) to store the mantissa and exponent.

Requires additional bits to manage the sign, mantissa, and exponent.



6. __Applications__:

Fixed-point:

Often used in systems with limited resources, such as embedded systems, digital signal processing (DSP), or applications where fixed precision is needed, like financial transactions.

Provides deterministic results in repeated calculations, which is important for control systems.


Floating-point:

Used in applications that require a large dynamic range, such as scientific computing, simulations, graphics, and audio processing.

Good for handling numbers that vary widely in scale but where absolute precision is less critical.



7. __Accuracy__:

Fixed-point:

Provides more predictable precision, but only within its limited range.

Can lead to truncation or overflow if numbers exceed the range.


Floating-point:

Offers better accuracy for numbers of different magnitudes but can introduce rounding errors, especially when dealing with very small or very large numbers.

8. __Execuation time__:

   Fixed-point: 91 micro second

   Floating-point: 182 micro second
   ## Code implementation
   ![FXP.h](https://github.com/esraashawky111/Task-0.0/blob/main/FXP.h)
   ![FPX.c](https://github.com/esraashawky111/Task-0.0/blob/main/FXP.c)

   ### The operation result of using fixed operation
   ![FXP_Operation](https://github.com/esraashawky111/Task-0.0/blob/main/FXP%20Operation.png)
   
   ### The Execuation time by using FXP VS Floating operation
   ![EXE_TIME](https://github.com/esraashawky111/Task-0.0/blob/main/FXP%20VS%20Floating.png)

**Summary**:

Fixed-point: Better for systems requiring high precision, predictability, and performance in a limited range, such as embedded systems and real-time processing.

Floating-point: Better for applications requiring a wide range of values and flexible precision, such as scientific computations and graphics.


Choosing between the two depends on the application needs: performance, range, and precision requirements.

# Task 0.0 / Part 3: Event-Based Systems in Embedded Software
## Overview of Event-Based Systems
Event-based systems are architectures that respond to events or changes in state rather than following a predetermined sequence of operations. In embedded systems, this approach is particularly useful for managing asynchronous inputs and outputs, allowing the system to react promptly to external stimuli.

## Key Features :

1_Asynchronous Processing: Event-based systems can handle multiple events simultaneously without blocking the main execution flow. This is crucial for real-time applications where timely responses are essential.

2_Decoupling of Components: Components in an event-based system can operate independently, leading to better modularity and easier maintenance. This decoupling allows for more straightforward updates and testing.

3_Resource Efficiency: By only processing events when they occur, these systems can be more efficient in terms of CPU and memory usage, which is vital for resource-constrained embedded systems.

## Advantages of Event-Based Systems :

*Responsiveness: Faster reaction times to external events, improving user experience and system performance.

*Scalability: Easier to scale the system by adding new event handlers without significant changes to existing code.

*Flexibility: Supports dynamic behavior changes, allowing the system to adapt to varying conditions or requirements.

## Example Use Cases :

*Sensor Monitoring: Continuously monitoring sensors and triggering actions based on specific thresholds.

*User Interfaces: Responding to user inputs (e.g., button presses) without polling.

*Communication Protocols: Handling incoming data packets in networking applications.
Suggested Diagram.

 ### Here’s a simple description for flowchart and what to include and illustrating the architecture of an event-based system:
 
*Event Sources: Represent sensors, user inputs, or other triggers.

*Event Queue: A buffer that holds events until they are processed.

*Event Handlers: Functions or methods that respond to specific events
.
*Main Loop: The core of the system that checks for events and dispatches them to the appropriate handlers.

![Event_System_diagram](https://github.com/esraashawky111/Task-0.0/blob/main/Event%20_Based%20_diagram.png)


## The code implementation 
1_ ![Event_System.c](https://github.com/esraashawky111/Task-0.0/blob/main/EVENT_SYS.c)
2_ ![Event_System.h](https://github.com/esraashawky111/Task-0.0/blob/main/EVENT_SYS.h)
3_ ![Main.c](https://github.com/esraashawky111/Task-0.0/blob/main/main.c)


## Protus Design 
![Event_System_design](https://github.com/esraashawky111/Task-0.0/blob/main/Event_Based%20_system.png)

