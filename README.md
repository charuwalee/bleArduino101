# bleArduino101
Bluetooth Peripheral on Arduino 101 board that can modify the contents of its advertising packets.

- sketch_aug29a.ino: 
This file is a project file where the main loop resides.

- BLEPeipheral.cpp: 
The change is made on the file BLEPeripheral.cpp version 1.0.6.
Replace the file BLEPeripheral.cpp in C:\Users\...\AppData\Local\Arduino15\packages\Intel\hardware\arc32\1.0.6\libraries\CurieBLE\src directory.
In BLEPeripheral::begin() function, a condition is added before calling  _init() function as followed.

  if (_state == BLE_PERIPH_STATE_NOT_READY) {
	  status = _init();
		  if (status != BLE_STATUS_SUCCESS) {
			  return false;
		  }
	}
