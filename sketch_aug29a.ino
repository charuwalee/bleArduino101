#include <CurieBLE.h>
#include <CurieIMU.h>

int rssiVal = 0;
BLEPeripheral   blePeripheral;

void setup() {
    Serial.begin(9600);

    // Initialise the IMU
    //CurieIMU.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  bool res;
  while(!Serial)
  Serial.println();
  String  myServiceID = "19B10000-E8F2-537E-4F6C-D104768A121";
  rssiVal = rssiVal+1;
  if (rssiVal == 10) 
    rssiVal = 0;
  Serial.println("======= start loop =======");
  myServiceID.concat(rssiVal);
  Serial.print("sketch: myServiceID: \"");
  Serial.print(myServiceID);
  Serial.println("\"");
 
  BLEService      rssiService(myServiceID.c_str());
  
  blePeripheral.setLocalName("Pang_05");
  blePeripheral.setAdvertisedServiceUuid(rssiService.uuid());
  Serial.println("sketch: calling blePeripheral.begin()");
  res = blePeripheral.begin();
  Serial.print("sketch: return from blePeripheral.begin() (1 if success) => ");
  Serial.println(res);
  delay(5000);
  if (res == 1) {
    Serial.println("sketch: calling blePeripheral.end().");
    blePeripheral.end();
    delay(10000);
  }
}
