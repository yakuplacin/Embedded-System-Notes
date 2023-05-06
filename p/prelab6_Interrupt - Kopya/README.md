This project is about interrupt based 2 bit counter (that counts only 2 bits from the least significant bit 'LSB').

Interrupt programming is a programming technique in which an interrupt service routine is used to interrupt the normal flow of a processor and handle a specific event, such as a button press. 
This technique is commonly used in embedded systems, which need to interact with various devices and respond to events quickly and accurately.
Interrupt programming allows the processor to handle device events in real-time and improve the overall responsiveness of the system.

In this projects, basically, you have 2 button that are implemented to Port B, PIN 1 and 2 as EXTI (external Interrupt). 
When you press PORTBPIN1, this increases the number and call the function so that you can see the changes that are implemented to output as PORT A, PIN 1 and 2.
When you press PORTBPIN2, this decreases the number and call the function. You can see the effects via GPIO Ports A and B, from peripherals window.
