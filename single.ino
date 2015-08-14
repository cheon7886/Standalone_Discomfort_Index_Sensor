#include <dht.h>
#define dhtA0 A0
dht DHT;
float humidity = DHT.humidity;
float temp = DHT.temperature;

void setup(){
  Serial.begin(9600);
  delay(300);//Let system settle
  Serial.println("How are you today?");
  delay(700);//Wait rest of 1000ms recommended delay before
  //accessing sensor

}//end "setup()"

void loop(){
  //This is the "heart" of the program.
    DHT.read11(dhtA0);
    float Awfulness = temp * atan(0.151977 * sqrt(humidity + 8.313659)) + atan(humidity + temp) - atan(humidity - 1.676331) + 0.00391838 * sqrt(humidity * humidity * humidity) * atan(0.023101 * humidity) - 4.686035;
    float result = 0.72 * (temp + Awfulness)+40.6 ;

    Serial.print("Current humidity = ");
    Serial.print(humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(temp); 
    Serial.println("C  ");
    Serial.print("Current discomfort index = ");
    Serial.println(result);
  delay(800);//Don't try to access too frequently... in theory
  //should be once per two seconds, fastest,
  //but seems to work after 0.8 second.
}// end loop()

