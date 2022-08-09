import controlP5.*; //import ControlP5 library
import processing.serial.*;

Serial port;

ControlP5 cp5; //create ControlP5 object
String val;

void setup(){ //Same as setup in arduino
  size(1080, 920);                          //Window size, (width, height)
  //port = new Serial(this, "COM3", 9600);   //Change this to your port
  //port.bufferUntil('\n');

  
}

void draw(){  //Same as loop in arduino

  //float value1 = port.read(); //this is the serial read comm variable from the arduino board

  float var1, var2, var3;
  background(50, 50 , 50); //Background colour of window (r, g, b) or (0 to 255)
  
  fill(#FFFFFF);
  rect(445, 0, 180, 920);
  
  fill(#FFFFFF);
  rect(0, 360, 1080, 140);
  
  var1 = 12.102;
  var2 = 5.990;
  var3 = 73.400;
  
  
  Sensor(20, 10, 350, 190, 170, 210, "Sensors 1 (Online)" , var1,  var2,var3);
  Sensor(680, 10, 350, 190, 610, 15, "Sensors 2 (Offline)" ,  0.000, 0.000,  0.000);
  Sensor(680, 310, 350, 190, 830, 250, "Sensors 3 (Offline)" , 0.000, 0.000,  0.000);
  Sensor(680, 550, 350, 190, 610, 570,  "Sensors 4 (Offline)" , 0.000, 0.000, 0.000);
  
}

void blueRec(int x, int y)
{
  fill(#00FFFF);
  rect(x, y, 50, 50);
  
}

void Sensor(int a, int b, int c, int d, int e, int f, String senName, float var1, float var2, float var3)
{
  fill(#FFFFFF);
  rect(a, b, c, d);
  line(a, b + 30, c + a, b + 30);
  line(a, b + 85, c + a, b + 85);
  line(a, b + 140, c + a, b + 140);
  line(a + 210, b + 30, a + 210, b + 190);
  
  textSize(20);
  fill(#000000);
  text(senName, a + 20, b + 20);
  
  textSize(20);
  fill(#000000);
  text("Temperature:                      " + var1, a + 20, b + 65);
  
  textSize(20);
  fill(#000000);
  text("Gas & Smoke Density:      " + var2, a + 20, b + 120);
  
  textSize(20);
  fill(#000000);
  text("Traffic Density:                    " + var3, a + 20, b + 175);
  
  blueRec(e, f);
 
}





void serialEvent(Serial port)
{
  val =  port.readStringUntil('\n');
}
