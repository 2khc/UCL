class Button
{
  int x, y;
  int size, width, height;
  color buttonColour, baseColour;
  color highlight;
  color currentColour;
  boolean hoverOver;
  PFont font;
  Graph graph;
  String mode;
  boolean isBuilt = false;
  
  Button(int x, int y, int width, int height, color buttonColour, color highlight, color baseColour, boolean hoverOver,PFont f,Graph graph, String mode)
  {
   //constructor 
    this.x = x;
    this.y = y;
    this.width = width;
    this.height = height;
    this.buttonColour = buttonColour;
    this.baseColour = baseColour;
    this.highlight = highlight;
    this.currentColour = this.baseColour;
    this.hoverOver = hoverOver;
    this.font = f;
    this.graph = graph;
    this.mode = mode;
  }
  
  public void update(String text)
  {
    if (overButton())
    {
      fill(this.highlight);
    }
    else
    {
      fill(this.buttonColour);
    }
    
    stroke(255);
    rect(this.x, this.y, this.width, this.height);
    textFont(this.font,25); 
    fill(0);
    text(text, this.x, this.y+30);
    fill(255);
    text(this.graph.getYLabel(), this.graph.getX() + this.graph.getWidth() / 2, this.graph.getY() + this.graph.getHeight() + 45);
    //rotate(PI/2);
    text(this.graph.getXLabel(), this.graph.getX() - 40, this.graph.getY() + this.graph.getHeight() / 2);
    //rotate(-PI/2);
    //this.graph.update();
  }
  
  public void click()
  {
    if (overButton())
    {
      if (this.isBuilt == false)
      {
        this.graph.buildData();
        this.isBuilt = true;
      }
      this.graph.drawAxis();
      this.graph.plot();
      this.graph.showStats();
    }
  }
  
  private boolean overButton()
  {
    if (mouseX >= this.x && mouseX <= this.x + this.width && mouseY >= this.y && mouseY <= this.y + this.height)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}