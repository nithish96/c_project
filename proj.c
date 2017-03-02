#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float *destination(char dest[])
	{
	float *array=(float*)malloc(sizeof(float)*2);
	if(strcmp(dest,"india")==0)
		{
		array[0]=75;
		array[1]=30;
		}
	if(strcmp(dest,"china")==0)
		{
		array[0]=105;
		array[1]=30;
		}
	if(strcmp(dest,"russia")==0)
		{
		array[0]=75;
		array[1]=60;
		}
	if(strcmp(dest,"egypt")==0)
		{
		array[0]=30;
		array[1]=30;
		}
	if(strcmp(dest,"none")==0)
		{
		array[0]=0;
		array[1]=0;
		}
	return array;
	}
void points(char dest1[],char dest2[])
	{
	float *array1;
	array1=destination(dest1);
	float *array2;
	array2=destination(dest2);
	float angle,angle1,dist=0,Dist,tempx,tempy;
	float X,Y,x,y;
	x=array1[0];
	y=array1[1];
	X=array2[0];
	Y=array2[1];
 	angle=atan2(X-x,Y-y)*(180/3.14);
 	Dist=sqrt((X-x)*(X-x) + (Y-y)*(Y-y));
 	tempx=x;
 	tempy=y;
	if(x<X && y<Y)
	 {
	 while(x<X+1 && y<Y+1)
  	       {
  	       do
  		{
   		angle1=atan2(X-x,Y-y)*(180/3.14);
   		if(angle1==angle || (X-x==0 && Y-y==0))
    			{
    			printf("%.1f %.1f\n",x,y);
    			}	
   		dist=sqrt((X-x)*(X-x)+(Y-y)*(y-y));
   		x++;
   		}while(dist<=Dist);
  	  x=tempx;
 	  y++;
  		}
 	 }
	else if(x >X && y>Y)
 	 {
 	 while((x+1>X) && (y+1>Y))
  		{
  		do
   		 {
   		 angle1=atan2(X-x,Y-y)*(180/3.14);
   		 if(angle1==angle||(X-x==0 && Y-y==0))
 			{
    			printf("%.1f %.1f\n",x,y);
   			}
   		 dist=sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
   		 x--;
   		 }while(dist>Dist||dist==Dist);
  	 x=tempx;
  	 y--;
  	 	}
 	}
	else if(x>X && y<Y)
 	 {
 	 while((x+1>X) && (y<Y+1))
  		{
  		do
   		 {
   		 angle1=atan2(X-x,Y-y)*(180/3.14);
  		 if(angle1==angle||(x-X==0 && y-Y==0))
      			{
   			printf("%.1f %.1f\n",x,y);
      			}
   		 dist=sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
  		 y++;
  		 }while((dist<Dist|| dist==Dist)&& y<Y+1);
 	  	y=tempy;
 	  	x--;
 	 	}
	 }
	else if(x<X && y>Y)
		{
		 while((x<X+1) && (y+1>Y))
  		      {
  		      do
   			{
   			angle1=atan2(X-x,Y-y)*(180/3.14);
   			if(angle1==angle|| (x-X==0 && y-Y==0))
    				{
    				printf("%.1f %.1f\n",x,y);
    				}
   			dist=sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
   			y--;
   			}while(dist<=Dist && y+1>Y);
  			y = tempy;
  			x++;
  		      }	
 		}	
	else if(x==X && y+1>Y)
  		{
  		do
   		 {
   		 if(angle1==angle || (y==Y))
   		 printf("%.1f %.1f\n",x,y);
  		 dist=sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
		 y--;
  		 }while(dist>Dist ||dist==Dist);
 		}
	 else if(x==X && y <Y+1)
  		{
  		do
   		 {
   		 angle1=atan2(X-x,Y-y)*(180/3.14);
  		 if(angle1==angle || (Y==y))
   		 printf("%.1f %.1f\n",x,y);
  		 dist=sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
  		 y++;
 		 }while(Dist>dist ||dist==Dist);
 	        }
 	 else if(Y==y && x+1>X)
 		{
  		while(dist<Dist ||Dist==dist)
   			{
   			angle1=atan2(X-x,Y-y)*(180/3.14);
   			if(angle1==angle || (x==X))
    				printf("%.1f %.1f\n",x,y);
   			dist=sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
   			x--;
   			}
  		}

 	else if(Y==y && X+1>x)
  		{
  		while(Dist>dist || dist==Dist)
   			{
   			angle1=atan2(X-x,Y-y)*(180/3.14);
   			if(angle1==angle || (X==x))
    				printf("%.1f %.1f\n",x,y);
   			dist=sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
   			x++;
  			}
 		}
	}
void speaks(char desti[])
	{
	if(strcmp(desti,"india")==0)
		{
		speak("india.txt");
		}
	if(strcmp(desti,"china")==0)
		{
		speak("china.txt");
		}
	if(strcmp(desti,"russia")==0)
		{
		speak("russia.txt");
		}
	if(strcmp(desti,"egypt")==0)
		{
		speak("egypt.txt");
		}
	}

int main(int argc,char *argv[])
	{
	if(argc==1)
		{
		printf("Usage: ./proj <destination1> <destination2> ...\n");
		printf("minimum number of arguments is 2\n");
		}
	if(argc==2)
		{
	 	points("none",argv[1]);
		speaks(argv[1]);
		}
	else if(argc==3)
		{
		points(argv[1],argv[2]);
		speaks(argv[2]);
		}
	else if(argc>3)
		{
		int i=1;
		points("none",argv[1]);
		speaks(argv[1]);
		while(i<argc)
			{
			points(argv[i],argv[i+1]);
			speaks(argv[i+1]);
			i++;
			printf("i=%d\n",i);
			}
		printf("Hello\n");
		}
	return 0;
	}
