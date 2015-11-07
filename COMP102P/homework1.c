#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define BUF_SIZE 24

int insertionSort(int n,int m, int o);
int calcNumberOfBags(int n, int m, int o, int p, int q);
int calcNumberOfBagsVariable(int num, ...);
int calcMin(int num, ...);

int main(void)
{
  /* int n[BUF_SIZE], m[BUF_SIZE], o[BUF_SIZE]; */
  int n, m, o, p, q, bags,a, min,sweetsPerBag;


  printf("Enter the first number: ");
  scanf("%d",&n);
  printf("Enter the second number: ");
  scanf("%d", &m);
  printf("Enter the third number: ");
  scanf("%d", &o);
  printf("Enter the fourth number: ");
  scanf("%d", &p);
  printf("Enter the fifth number: ");
  scanf("%d", &q);

  if (o == 0)
    {
      printf("n is %d.\n",n);
      printf("m is%d.\n",m);
      a = calcNumberOfBagsVariable(2,n, m);
      min = calcMin(2,n,m);
      printf("min is %d.\n",min);
      printf("a is %d.\n",a);
    
      sweetsPerBag = (n + m)/a;
      bags = (n + m) / sweetsPerBag;
      /* printf("%d.\n",(n + m) / a); */
      /* bags = min / a; */
      /* if (bags <  a) */
      /* 	{ */
      /* 	  bags = a; */
      /* 	} */

      printf("The number of bags is: %d.\n",bags);
      printf("The total number of candies per bag is %d.\n",sweetsPerBag);
    }
  else if( p == 0)
    {
      printf("n is %d.\n",n);
      printf("m is%d.\n",m);
      a = calcNumberOfBagsVariable(3,n, m, o);
      min = calcMin(3,n,m,o);
      printf("min is %d.\n",min);
      printf("a is %d.\n",a);
    

      bags = min / a;
      if (bags <  a)
	{
	  bags = a;
	}

      printf("The number of bags is: %d.\n",bags);
      printf("The total number of candies per bag is %d.\n",(n + m +o)/a);
    }
  else if (q == 0)
    {
       printf("n is %d.\n",n);
      printf("m is%d.\n",m);
      a = calcNumberOfBagsVariable(4,n, m,o,p);
      min = calcMin(4,n,m,o,p);
      printf("min is %d.\n",min);
      printf("a is %d.\n",a);
    

      bags = min / a;
      if (bags <  a)
	{
	  bags = a;
	}

      printf("The number of bags is: %d.\n",bags);
      printf("The total number of candies per bag is %d.\n",(n + m +o+p)/a);
    }
  else
    {
       printf("n is %d.\n",n);
      printf("m is%d.\n",m);
      a = calcNumberOfBagsVariable(5,n, m,o,p,q);
      min = calcMin(5,n,m,o,p,q);
      printf("min is %d.\n",min);
      printf("a is %d.\n",a);
    

      bags = min / a;
      if (bags <  a)
	{
	  bags = a;
	}

      printf("The number of bags is: %d.\n",bags);
      printf("The total number of candies per bag is %d.\n",(n + m+o+p+q)/a);
    }




  /*  printf("The number of bags is %d.\n",bags); */
  /*   printf("The number of hard candies per bag is %d.\n",n/bags); */
  /*   printf("The number of chocolates per bag is %d.\n",m/bags); */
  /*   printf("The number of lollipops per bag is %d.\n",o/bags); */
  /* printf("The number of lollipops per bag is %d.\n",p/bags); */
  /* printf("The number of lollipops per bag is %d.\n",q/bags); */


  return 0;
}


int calcNumberOfBagsVariable(int num, ...)
{
  va_list  arguments;

  int a = 2, i, counter, n_args, temp;

  do 
    {
      va_start(arguments, num);
      counter = 0;
      /* n_args = va_arg(arguments,int); */
      /* printf("n_args is %d.\n",num); */
      for (i = 0; i < num; i++)
	{
	  if ((temp = va_arg(arguments,int)) % a != 0)
	    {
	      a++;
	      va_end(arguments);
	      break;
	    } else {
	    counter++;
	    /* printf("%d.\n",counter); */
	  }
	  if (temp / a == 1)
	    {
	      return 1;
	    }
	
	  if (counter == num){
	    return a;
	  }	
	 
	}
      va_end(arguments);
    }
  while (a > 0);

}

int calcMin(int num, ...)
{
  int i, min, a;

  va_list arguments;
  va_start(arguments,num);
  /* printf("num is %d.\n",num); */
  min = va_arg(arguments, int);
  for (i = 2; i <= num; i++)
    {
      if ((a = va_arg(arguments,int)) < min) 
	{
	  min = a;
	}
    }

  va_end(arguments);
  return min;

}


