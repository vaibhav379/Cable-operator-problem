#include<graphics.h>
#include<stdio.h>
#include<conio.h>
int main() {
   int gdriver = DETECT, gmode;
   int n,inf=999,nw=1,e,f,mincost=0;;
   scanf("%d",&n);
   int i,j,x[n],y[n],u,v,k[n];
   int a[n][n],visited[20]={0},b[n][n];
    char num[5];
    char node[5];


  initgraph(&gdriver, &gmode, "");
   getch();
   for(i=1;i<=n;i++){                            // loop for input of nodes
   getmouseclick(WM_LBUTTONDOWN, x[i], y[i]);   //function to get mouse click location
   /* circle(x[i], y[i],5); //to create dots on nodes
    circle(x[i], y[i],4);
    circle(x[i], y[i],3);
    circle(x[i], y[i],2);
    circle(x[i], y[i],1);*/
    rectangle(x[i]+40,y[i],x[i],y[i]+40);
     line((x[i]+x[i]+40)/2,y[i]-(y[i]+40-y[i])/2,x[i],y[i]);    //to create homes on node
     line((x[i]+x[i]+40)/2,y[i]-(y[i]+40-y[i])/2,x[i]+40,y[i]);

            sprintf(node, "%d", i);
            setcolor(RED);
            settextstyle(4, HORIZ_DIR, 1);

            outtextxy(x[i]-2,y[i]-2,node);


        printf("clicked at %d,%d\n",x[i],y[i]);
        k[i]=y[i];

    getch();
    setcolor(WHITE);


}





for(i=1;i<=n;i++){                      //to input adajacency matrix
    for(j=1;j<=n;j++){
            if(j>i){
        printf("Enter value of a[%d][%d]",i,j);
        scanf("%d",&a[i][j]);
        a[j][i]=a[i][j];

    }
    else{
        a[i][j]=999;
    }
    //a[i][j]=a[j][i];


    }

}

for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){

        if(a[i][j]==0){
            a[i][j]=999;
        }
    }
}

/*for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){

    printf("%d\n",a[i][j]);
    }
}
*/
/*for(i=1;i<=n;i++){
        printf("%d,%d",x[i],y[i]);

        //to put lines beteen nodes
}*/




for(i=1;i<=n;i++){   //to put lines beteen nodes
    for(j=1;j<=n;j++){

        if(a[i][j]!=999&&a[i][j]!=0)
            {

                line(x[i],y[i],x[j],y[j]);
        }
            }
    }


for(i=1;i<=n;i++){      //to put number on lines between nodes
    for(j=1;j<=n;j++){
        if(a[i][j]!=999&&a[i][j]!=0)
            {
                sprintf(num, "%d", a[i][j]);
                settextstyle(1, HORIZ_DIR, 1);
     outtextxy((x[i]+x[j])/2,(y[i]+y[j])/2,num);


        }
    }
}



getch();

for(i=1;i<=n;i++){                      //make b=0
    for(j=1;j<=n;j++){

        b[i][j]=0;

    }
}

visited[1]=1;


	while(nw< n)

	{

		for(i=1,inf=999;i<=n;i++)

		for(j=1;j<=n;j++)

		if(a[i][j]< inf)

		if(visited[i]!=0)

		{

			inf=a[i][j];

			e=u=i;

			f=v=j;

		}

		if(visited[u]==0 || visited[v]==0)

		{

			printf("\n Edge(%d %d) cost:%d",e,f,inf);
			nw++;
            b[e][f]=1;
            b[f][e]=1;
			mincost+=inf;
			visited[f]=1;


		}

		a[e][f]=a[f][e]=999;

	}

	printf("\n Minimun Length Required=%d",mincost);

for(i=1;i<=n;i++){   //to put green lines beteen nodes
    for(j=1;j<=n;j++){

        if(b[i][j]==1)
            {
                 setcolor(GREEN);
                line(x[i],y[i],x[j],y[j]);
        }


    //printf("%d\n",b[i][j]);
    }
}


getch();

}

