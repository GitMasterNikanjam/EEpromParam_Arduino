/*

Schematic:

        +---U---+
    A0  | 1   8 |  VCC = +5V
    A1  | 2   7 |   WP = write protect pin
    A2  | 3   6 |  SCL = I2C clock
   GND  | 4   5 |  SDA = I2C data
        +-------+

default address = 0x50 .. 0x57 depending on three address lines

Constructor:

I2C_eeprom(uint8_t deviceAddress, TwoWire *wire = &Wire) constructor, optional Wire interface.
I2C_eeprom(uint8_t deviceAddress, uint32_t deviceSize, TwoWire *wire = &Wire) constructor, with optional Wire interface.
bool begin(uint8_t writeProtectPin = -1) initializes the I2C bus with the default pins. Furthermore it checks if the deviceAddress is available on the I2C bus. Returns true if deviceAddress is found on the bus, false otherwise. Optionally one can set the WP writeProtect pin. (see section below). If the WP pin is defined the default will be to not allow writing.
bool isConnected() test to see if deviceAddress is found on the bus.
uint8_t getAddress() returns device address set in the constructor.

Write functions:

int writeByte(uint16_t memoryAddress, uint8_t value) write a single byte to the specified memory address. Returns I2C status, 0 = OK.
int writeBlock(uint16_t memoryAddress, uint8_t * buffer, uint16_t length) write a buffer starting at the specified memory address. Returns I2C status, 0 = OK.
int setBlock(uint16_t memoryAddress, uint8_t value, uint16_t length) writes the same byte to length places starting at the specified memory address. Returns I2C status, 0 = OK.

Update functions:

int updateByte(uint16_t memoryAddress, uint8_t value) write a single byte, but only if changed. Returns 0 if value was same or write succeeded.
uint16_t updateBlock(uint16_t memoryAddress, uint8_t * buffer, uint16_t length) write a buffer starting at the specified memory address, but only if changed. Returns bytes written.

Read functions:

uint8_t readByte(uint16_t memoryAddress) read a single byte from a given address.
uint16_t readBlock(uint16_t memoryAddress, uint8_t * buffer, uint16_t length) read length bytes into buffer starting at specified memory address. Returns the number of bytes read, which should be length.
*/