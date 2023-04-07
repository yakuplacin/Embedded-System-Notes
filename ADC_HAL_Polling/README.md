This project is about using ADC-HAL libraries.

If you click the button that is associated with PB2 (Port B Pin 2) It checks the current value of the ADC.
When current value from ADC is higher than 1.5V, the led (that is associated with PA10, Port A Pin 10, as Output) blink just once with 1 sec.
Otherwise, it doesn't blink.

For the calculating 1.5 V that we assume as a minimum voltage, we should use the formula. Here:

(1.5V / 3.3 V) \* 2^12

That is nearly equal to 1861. If we change that one to hexadecimal, It will be equal to 0x745.
So, we just use this value when we compare the ADC value to blink the led.
