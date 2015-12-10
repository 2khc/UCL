// Obsolete class. No longer required.

class DataSet
{
 ArrayList<Float> accel;
 float RC;
 float dt;
 float alpha;
 float[] filteredData;
 
 DataSet(ArrayList<Float> accelData)
 {
   accel = accelData;
 };
  
 public void addPoint(float x)
 {
   accel.add(x);
 }
  
 public void setParams(float dtVal, float alphaVal)
 {
   dt = dtVal;
   alpha = alphaVal;
   RC = calcRC(dt, alpha);
 }
  
 private float calcRC(float dt, float alpha)
 {
   return dt * (1 - alpha) / (alpha);
 }
  
 public void applyLowPass()
 {
   filteredData = new float[accel.size()];
   
   filteredData[0] = accel.get(0);
    
   for (int i = 1; i < accel.size(); i++)
   {
     filteredData[i] = filteredData[i - 1] + alpha * (accel.get(i) - filteredData[i - 1]);
   }
 }
 
 public float[] getFilteredData()
 {
   return filteredData;
 }
 
 public float[] getAccel()
 {
   float[] accelArray = new float[accel.size()];
   for (int i = 0; i < accel.size(); i++)
   {
     accelArray[i] = accel.get(i);
   }
  return accelArray;
 }
 
 public int getSteps()
 {
   int steps = 0;
   for (int i = 0; i < filteredData.length; i++)
   {
     if (filteredData[i] > 55)
     {
       steps++;
     }
   }
   return steps;
 }
 
 public int getDistance()
 {
   return 1;
 }
}