# C Task 0.0
 **Embedded Software Gems ,Mentor eng: Ahmed Tolba*
 *why we use Look up table to generate sine wave..?*
 1. Efficiency: Computing a sine function in real-time using mathematical operations like trigonometric functions can be computationally expensive, especially in systems with limited processing power (like microcontrollers). A lookup table allows the system to retrieve precomputed sine values almost instantly.
2. Speed: Since the sine values are precomputed and stored in a table, the system only needs to access the table (often just a memory read operation) to get the output, making the process much faster than real-time calculation.
3. Accuracy: A lookup table can provide high accuracy by using a dense set of precomputed sine values. By interpolating between these values, even higher precision can be achieved without increasing the computation time.
 *Using a lookup table (LUT) to generate a sine wave has several disadvantages:*
1. Memory Usage: A lookup table requires memory to store precomputed sine values. If high precision is needed (e.g., for a high-resolution sine wave), the table can become quite large, especially in systems with limited memory capacity.
2. Limited Resolution: The accuracy of a sine wave generated from a lookup table is limited by the number of entries in the table. If the table doesn't have enough points, the resulting sine wave may suffer from aliasing or quantization errors.
   
   *The result for code with LUT*
   Here's what the output will look like for the first few samples:

Sample 0: Sine Value = 0.000000
Sample 1: Sine Value = 0.017452
Sample 2: Sine Value = 0.034899
Sample 3: Sine Value = 0.052336
Sample 4: Sine Value = 0.069757
Sample 5: Sine Value = 0.087156
Sample 6: Sine Value = 0.104528
Sample 7: Sine Value = 0.121869
Sample 8: Sine Value = 0.139173
Sample 9: Sine Value = 0.156434
...
Sample 359: Sine Value = -0.017452

The sine values correspond to a sine wave over 360 degrees, starting from 0 and progressing to 360 degrees. Since the code cycles every 360 samples (i % LUT_SIZE), samples 360 to 1079 will repeat the sine wave values from the start.

For example:

Sample 360: Sine Value = 0.000000  // Same as Sample 0
Sample 361: Sine Value = 0.017452  // Same as Sample 1
...
Sample 1079: Sine Value = -0.017452  // Same as Sample 359
*SIZE of assembly code is 110 line*

*Memory Size: The memory size will be 360 * 4 = 1440 bytes for the lookup table.*

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

_THE result of code without using LUTis:_

The code you've written will generate a sine wave using * characters on a 2D grid, with WIDTH = 100 (the number of points along the x-axis) and HEIGHT = 30 (the number of rows on the y-axis). The wave will be scaled to fit within these constraints, and the middle row (y = 15) will have ~ characters representing the x-axis.

*SIZE of assembly without usging LUT IS 80 LINE*

*Memory size :The memory used by the program is small, primarily 12 bytes for the local variables that are reused during the loop execution.*
