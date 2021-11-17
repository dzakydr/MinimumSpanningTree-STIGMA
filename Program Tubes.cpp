#include <iostream>
#include <fstream>
#define inf 99999
using namespace std;

int main() {
	int ukuran;
 	int x,y,u,v;
 	int min;
	int lewati[100]={0};
	int bobot_minimum=0;
	int sisi=1;
	int i=1;
	int j=1;
	
	ifstream file;
 	
 	file.open("graf.txt");
 	
 	file>>ukuran;
 	int matriks[ukuran][ukuran];
 	
	while (!file.eof()) 
	{
		for (i=1;i<=ukuran;i++)
		{
			for (j=1;j<=ukuran;j++)
			{
				file>>matriks[i][j];
				
				if (matriks[i][j]==-1)
				{
                    matriks[i][j]=inf;
				}
			} 
		}
 	
 	}
 	file.close();
	
	lewati[1]=1;
 
	while(sisi < ukuran)
	{
 
		for(i=1,min=inf;i<=ukuran;i++)
 
		for(j=1;j<=ukuran;j++)
 
		if(matriks[i][j]< min)
 
		if(lewati[i]!=0)
 
		{
 
			min=matriks[i][j];
 
			x=u=i;
 
			y=v=j;
 
		}
 
		if(lewati[u]==0 || lewati[v]==0)
 
		{
 			sisi++;
 			cout<<"("<<x<<","<<y<<") = "<<min<<endl; 				
			bobot_minimum+=min;
			lewati[y]=1;
 
		}
 
		matriks[x][y]=matriks[y][x]=inf;
 
	}
 
	cout<<"\nTotal bobot minimum spanning tree = "<<bobot_minimum;
 
	return 0;
 
}
