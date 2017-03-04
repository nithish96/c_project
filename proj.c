#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <libplayerc/playerc.h>
float *destination(char dest[])
	{
     float *array;
     array=(float*)malloc(sizeof(float)*2);
	if(strcmp(dest,"india")==0)
		{
		array[0]=6.0;
		array[1]=1.0;
	return array;
		}
	if(strcmp(dest,"china")==0)
		{
		array[0]=-4;
		array[1]=-4;
    
	return array;
		}
	if(strcmp(dest,"russia")==0)
		{
		array[0]=3;
		array[1]=2;

	return array;
		}
	if(strcmp(dest,"egypt")==0)
		{
		array[0]=5;
		array[1]=2;

	return array;
		}
	if(strcmp(dest,"none")==0)
		{
		array[0]=0;
		array[1]=0;
        return array;
		}
	}
int right(playerc_client_t *client,playerc_position2d_t *position2d,float x,float X)
    {
    float i=0,j=0;
    playerc_position2d_set_cmd_vel(position2d,0,0,DTOR(180), 1 );
    sleep(1);
    while((x-(position2d->px))<x-X)
        {
        playerc_client_read(client);
        playerc_position2d_set_cmd_vel(position2d,0.5,0, 0, 1 );
        fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px,position2d->py,position2d->pa);
     //       (   position2d->px)--;
    //        if((position2d->px)==X)
      //          break;
        }

    playerc_position2d_set_cmd_vel(position2d,0,0, 0, 0 );
    sleep(1);
    }
int left(playerc_client_t *client,playerc_position2d_t *position2d,float x)
    {
    float i=0;
    while((position2d->px)<x)
        {
        playerc_client_read(client);
        playerc_position2d_set_cmd_vel(position2d,1,0, 0, 1 );
        fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px,position2d->py,position2d->pa);
        }
    playerc_position2d_set_cmd_vel(position2d,0,0, 0, 0 );
    sleep(1);
    }
int up(playerc_client_t *client,playerc_position2d_t *position2d,float y)
    {
    float i=0;
    playerc_position2d_set_cmd_vel(position2d,0,0, DTOR(90), 1 );
    sleep(1);
    while(position2d->py<y)
        {
        playerc_client_read(client);
        playerc_position2d_set_cmd_vel(position2d,0.5,0, 0, 1 );
        fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px,position2d->py,position2d->pa);
        }
    return 0;
    }
int down(playerc_client_t *client,playerc_position2d_t *position2d,float y,float Y)
    {
    float i=0;
    playerc_position2d_set_cmd_vel(position2d,0,0, DTOR(90), 1 );
    sleep(1);
    while((y-(position2d->py))<y-Y)
        {
        playerc_client_read(client);
        playerc_position2d_set_cmd_vel(position2d,1,0, 0, 1 );
        fprintf(stdout, "X: %3.2f, Y: %3.2f, Yaw: %3.2f \n",position2d->px,position2d->py,position2d->pa);
       }
    return 0;
    }
int main (int argc, char* argv[])
    {
    int history[500];
    int i,counts=0;
    float angle1,ang1,ang2;
    playerc_client_t *client;
    playerc_position2d_t *position2d;
    int cycle, index=0;
    double dist,fidAngle = 0,lineAngle=0, fidDist=0, prevYaw=0,posAngle=0;
    client = playerc_client_create(NULL, "localhost", 6665);
    if (0 != playerc_client_connect(client))
           {
           return -1;
           }
    position2d = playerc_position2d_create(client, 0);
    if (playerc_position2d_subscribe(position2d, PLAYER_OPEN_MODE))
           return -1;
    float*dest1,*dest2,x,y,X,Y;
        dest1=destination(argv[1]);
        dest2=destination(argv[2]);
        x=dest1[0];
        y=dest1[1];
        X=dest2[0];
        Y=dest2[1];

    if(strcmp(argv[1],"none")==0)
        {
        FILE *in;
        in=fopen("output.dat","w");
        fprintf(in,"%f %f\n",X,Y);
        fclose(in);
        }
    if(strcmp(argv[1],"none")!=0)
        {
        FILE *in;
        in=fopen("output.dat","r");
        while(!feof(in))
            {
            fscanf(in,"%f",&x);
            fscanf(in,"%f\n",&y);
            }
        fclose(in);
        }
    if(X>x )
        {
        left(client,position2d,X-x);
  //      up(client,position2d,Y-y);
        }
    if(X<x)
        {
        right(client,position2d,x,X);
        }

    if(Y>y)
        {
        up(client,position2d,Y-y);
        }

     if(Y<y)
        {
        down(client,position2d,y,Y);
        }
playerc_position2d_unsubscribe(position2d);
playerc_position2d_destroy(position2d);
playerc_client_disconnect(client);
playerc_client_destroy(client);
return 0;	
}	
