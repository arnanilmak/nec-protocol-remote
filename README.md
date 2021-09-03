# nec-protocol-remote
Here is a c code for ir remote controllers that use NEC protocol.
The code is generated for PIC micro controller but its better you just understand the concept and use it for other mcus too.
The NEC protocol is just 4 byte of data which two of them are bit inverse of each other.
The first byte is the device address and the second is bit inverse of the device address and the third is the key address which is pressed and the last byte is bit inverse of that key address.
We measure the time between each two falling edge of PC1 GPIO to figure whats going on.
For more information about NEC protocol follow the link bellow:
