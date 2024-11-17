#ifndef I2C_EEPROM_PARAM_H
#define I2C_EEPROM_PARAM_H

// ###################################################################################
// Include libraries:

#include <Arduino.h>
#include <I2C_eeprom.h>               // For External I2C EEPROM. https://github.com/RobTillaart/I2C_EEPROM

// ####################################################################################

class EEPROM_PARAM
{
  public:

    /// @brief Last error occurred for the object.
    String errorMessage;

    struct ParametersStructure
    {

    }parameters;

    bool init(void);

  private:

  bool _checkParameters(void);

}











#endif