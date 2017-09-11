// Include the library inverse.h
#include <inverse.h>

void setup() {
  // Setup the lengths and rotation limits for each link
  Link base, upperarm, forearm, hand;
  
  base.init(0, b2a(0.0), b2a(180.0));
  upperarm.init(200, b2a(15.0), b2a(165.0));
  forearm.init(200, b2a(0.0), b2a(180.0));
  hand.init(270, b2a(0.0), b2a(180.0));

  // Attach the links to the inverse kinematic model
  Inverse.attach(base, upperarm, forearm, hand);

  Serial.begin(115200);

  float a0, a1, a2, a3;

  // Inverse.solve() return true if it could find a solution and false if not. 

  // Inverse.solve(x, y, z, a0, a1, a2, a3)
  if(Inverse.solve(200, 100, 100, a0, a1, a2, a3)) {
    Serial.print(a2b(a0)); Serial.print(',');
    Serial.print(a2b(a1)); Serial.print(',');
    Serial.print(a2b(a2)); Serial.print(',');
    Serial.println(a2b(a3));
  } else {
    Serial.print(a2b(0)); Serial.print(',');
    Serial.print(a2b(0)); Serial.print(',');
    Serial.print(a2b(0)); Serial.print(',');
    Serial.println(a2b(0));
  }

  // Inverse.solve(x, y, z, a0, a1, a2, a3, phi)
  if(Inverse.solve(200, 100, 100, a0, a1, a2, a3, 0.0)) {
    Serial.print(a2b(a0)); Serial.print(',');
    Serial.print(a2b(a1)); Serial.print(',');
    Serial.print(a2b(a2)); Serial.print(',');
    Serial.println(a2b(a3));
  } else {
    Serial.print(a2b(0)); Serial.print(',');
    Serial.print(a2b(0)); Serial.print(',');
    Serial.print(a2b(0)); Serial.print(',');
    Serial.println(a2b(0));
  }
}

void loop() {
  
}

// braccio to angle in radians 
float b2a(float b){ 
  return b / 180.0 * PI - HALF_PI;
}

// angle in radians to braccio
float a2b(float a) { 
  return (a + HALF_PI) * 180 / PI;
}
