#include <math.h>
#include <string.h>

using namespace std;

int pins[4] = { 13, 12, 8,7};

double dmod(double x, double y) {
    return x - (int)(x / y) * y;
}

String decimalToBinary(double n) {
    double k = n;
    String r = "";

    while (k != 0) {
        double division = k / 2;

        Serial.println("k = " + String(k));
        Serial.println("division = " + String(division));
        Serial.println("MOD => " + String(dmod(division, 1)));
    if (dmod(division, 1)!=0) {
            k = int(division);
            r = r + "1";
        }
        else {
            k = division;
            r = r + "0";
        }
    }

    while (r.length() < 4) {
        r = "0" + r;
        }

    return r;
}

void setup() {
    Serial.begin(9600);
    for (int i=0; i<=3; i++){
        pinMode(pins[i], OUTPUT);
    }
}


void loop() {
    delay(1000);

    for (double i = 1; i <= 15.0; i++) {
        Serial.println(i);

        String binary = decimalToBinary(i);
        Serial.println("BINARY => "+ binary);

        for (int k = 0; k <= binary.length(); k++) {
            if (binary[k] == '1') {
                digitalWrite(pins[k], HIGH);
            }
        }

        delay(500);
        for (int i = 0; i <= 3; i++) {
            digitalWrite(pins[i], LOW);
        }
    }
}