import processing.serial.*;

Serial myPort;
// Holds the entire string value that is sent by the Engduino
String number = new String();

// Initialise instance of the Button class, which is used to display the data.
Button stepsButton;
// Initialise an instance of graph, which is injected into the Button Class.
Graph graph;
PFont f;


// File creation purposes. Each day we create a new file to store pedometer values.
PrintWriter output;
boolean fileCreated = false;
int d = day();
int m = month();
int y = year();

void setup()
{
  size(1400,800);
  background(0);
  noStroke();
  
  f = createFont("Calibri",25,true);
  graph = new Graph(50, 50, width*7/8,height*3/4,#AFD0DB, f);
  stepsButton = new Button(width/4, height - 100, 180,80, color(255), color(50), color(100), false,f, graph, "steps");
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
} //<>//
 //<>//
void draw()
{
  textFont(f,50);
  fill(255);
  text("PEDOMETER!!", width/2 - 200, 50); //<>//
  update();
}

void update()
{
  stepsButton.update("Steps");
  graph.update();
}

void mouseClicked()
{
  stepsButton.click();
} //<>//

// This triggers when Serial data is sent to 
void serialEvent(Serial myPort)
{
  char inByte = char(myPort.read());
  
  if (fileCreated == false)
  {
    output = createWriter("/data/" + d + "-" + m + "-" + y + ".txt");
    fileCreated = true;
  }
  // If Engduino sends an 'A', it means that it has finished with transfer
  // and we can proceed to separate the received String and save it to our own local file.
  if (inByte == 'A') 
  {
    float[] accelValues = float(split(number,'\n'));
    
    for (int i = 0; i < accelValues.length - 1; i++)
    {
      output.println(accelValues[i]);
    }
    output.flush();
    output.close();
    println("Data upload complete");
  }
  else
  { 
    println("Uploading.... " + inByte);
    number += inByte;
  }
}