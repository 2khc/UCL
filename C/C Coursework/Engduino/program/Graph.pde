// This is the Class that handles the graphing of the data.
// The more days you use the engduino and upload data, the more datapoints you will have.
// The graph will scale and add more and more datapoints into the graph as the days pass.

class Graph
{
  int x, y;
  int width, height;
  color backgroundColour;
  PFont font;
  String xLabel, yLabel, yMaxValue;
  int[] steps;
  int[] distance;
  String[] numOfPoints;
  int maxYValue;
  int xInterval;
  boolean active = false;
  String[] fileNames;
  int totalNumberOfDays;
  int totalNumberOfSteps = 0;
  
  Graph(int x, int y, int width, int height, color backgroundColour, PFont font)
  {
    this.x = x;
    this.y = y;
    this.width = width;
    this.height = height;
    this.backgroundColour = backgroundColour;
    this.font = font;
    
    fill(255);
    this.yLabel = " ";
    this.xLabel = " ";
    this.yMaxValue = " ";
  }
  
  public void update()
  {    
    text(this.yMaxValue, this.x - 5, this.y);
  }
  
  public void buildData()
  {
    this.steps = calculatePlots();
    this.numOfPoints = this.fileNames;
    
    for (int i = 0; i < this.steps.length; i++)
    {
      println(this.steps[i]);
      this.totalNumberOfSteps += this.steps[i];
    }
    this.totalNumberOfDays = this.steps.length;
    println("Data has been built");
  }
  
  public void drawAxis()
  {
    this.maxYValue = max(this.steps);
    float yMax = map(this.maxYValue, 0, this.maxYValue, this.y, this.y + this.height);
    int yInterval = (int) (yMax / 10);
    this.xInterval = this.width / this.numOfPoints.length;
    
    for (int i = 0; i <= this.width; i++)
    {
      line(this.x + this.xInterval * i, this.y + this.height, this.x + this.xInterval * i, this.y + this.height + 10);
    }
    for (int i = 0; i <= 10; i++)
    {
      line(this.x, this.y + yInterval * i, this.x - 10, this.y + yInterval * i);
    }
    setMaxYLabel(str(this.maxYValue));
    setYLabel("date");
    setXLabel("steps");
    
  }

  public void plot()
  {
    fill(#27F56F);
    float firstPointY = map(this.steps[0], 0, maxYValue, this.y + this.height, this.y);
    ellipse(this.x + xInterval, firstPointY, 10, 10);
     textSize(11);
    for (int i = 1; i < this.steps.length; i++)
    {
       ellipse(this.x + xInterval * i,  map(this.steps[i], 0, maxYValue, this.y + this.height, this.y), 10,10);
       text(this.fileNames[i], this.x + xInterval * i, this.y + this.height);
    }    
  }
  
  public void showStats()
  {
     text("You have walked " + this.totalNumberOfSteps + " steps over " + this.totalNumberOfDays + " days.", this.x+this.width- 100,this.y);
  }
  
  // PRIVATE functions
  // ====================================================================
  
  // Takes an input of an array integer and returns the highest numberOfSteps taken in that day.
  // It is used to scale the graph.
  private int max(int[] numOfSteps)
  {
    int max = numOfSteps[0];
    for (int i = 1; i < numOfSteps.length; i++)
    {
      if (numOfSteps[i] > max)
      {
        max = numOfSteps[i];
      }
    }
    return max;
  }
  
  private int[] calculatePlots()
  {
    getNumberOfPoints();
    
    float[] filteredData;
    int[] numOfSteps = new int[this.fileNames.length];
    for (int i = 0; i < this.fileNames.length; i++)
    {
      println("Filenames[i] is: " + this.fileNames[i]);
      ArrayList<Float> accel = new ArrayList<Float>();
      String lines[] = loadStrings(this.fileNames[i]);
      
      for (int j = 0 ; j < lines.length; j++) 
      {    
        accel.add(float(lines[j]));
        println("accel is: "+accel.get(j));
      }
      
      filteredData = applyLowPass(accel);
      
      numOfSteps[i] = getSteps(filteredData);
    }
    return numOfSteps;
  }
  
 private float[] applyLowPass(ArrayList<Float> accel)
 {
   float[] filteredData = new float[accel.size()];
   float alpha = 0.5;
   filteredData[0] = accel.get(0);
    
   for (int i = 1; i < accel.size(); i++)
   {
     filteredData[i] = filteredData[i - 1] + alpha * (accel.get(i) - filteredData[i - 1]);
   }
   return filteredData;
 }
 
 private int getSteps(float[] filteredData)
 {
   int steps = 0;
   for (int i = 0; i < filteredData.length; i++)
   {
     if (filteredData[i] > 1.3)
     {
       steps++;
     }
   }
   return steps;
 }

  // This function looks into the directory 'data' and determines how many files there are. Each
  // file represents a day of walking, and thus a single datapoint.
  private void getNumberOfPoints()
  {

    java.io.File folder = new java.io.File(sketchPath("/data"));
 
    this.fileNames = folder.list();
 
    println(this.fileNames.length + " files in specified directory");
 
    for (int i = 0; i < this.fileNames.length; i++) 
    {
      println(this.fileNames[i]);
    }    
  }
  
  // SETTERS
  // =======================
  
  public void setSteps()
  {
    //set to step here
    this.xLabel = "Date";
    this.yLabel = "Steps";
  }
  
  public void setDistance()
  {
    //set to distance here
    this.yLabel = "Distance";
  }
  
  private void setXLabel(String text)
  {
    this.xLabel = text;
  }
  
  private void setMaxYLabel(String text)
  {
    this.yMaxValue = text;
  }
  
  private void setYLabel(String text)
  {
    this.yLabel = text;
  }
  
  // GETTERS
  // =============================
  
  public String getYLabel()
  {
    return this.yLabel;
  }
  
  public String getXLabel()
  {
    return this.xLabel;
  }
  
  public int getY()
  {
    return this.y;
  }
  
  public int getHeight()
  {
    return this.height;
  }
  
  public int getX()
  {
    return this.x;
  }
  
  public int getWidth()
  {
    return this.width;
  }
}