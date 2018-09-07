
# Revision History

## v3A

- Added reverse polarity protection diode to power input (7V-35V input range?)


## Future Changes
* Change MCU to ATSAMD51J19A
  * Make it pin compatible with Metro M4 or Feather M4 boards, so Arduino IDE can be used easily
* Select better motor driver
  * TI DRV8848 - PWM interface, smaller, higher current output
  * Allegro A4970 - Same functionality as MTS62C19A, different pinout
  * Microchip MTS2916A - Same functionality as MTS62C19A, different pinout (same as A4970)
  * Toshiba TB6552 - Similar functionality as MTS62C19A
* Replace RFM12 module with RFM69 (RFM12 is obsolete now)
* Replace linear power regulators with buck converters
  * Is 5V supply actually needed?
  * Consider AOZ128x ICs
* Replace Mini-USB with Micro-USB connector
* Use SMT jack for DC plug (PJ-002AH-SMT)
* Use SMT headers for all external pin connectors
  * JST-PH connectors?
* Add support for battery charging circuit
  * NiMH on RC car side
  * LiPo on controller side


## Wiring Notes 

- all white lines connected to ground
- S-F (fire): orange, white
- S-R (right): purple, white
- S-L (left): green, white
- S-D (down): blue, white
- S-U (up): brown, white

- M3-F (fire): orange, red (red connected to +5V)
- M2-L/R (left/right): yellow, red
- M3-U/D (up/down): brown, red



