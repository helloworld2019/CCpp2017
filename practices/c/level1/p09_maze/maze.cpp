/*

	这是一个很简单的迷宫（5×5），与复杂迷宫相比，差得是地图的复杂。


*/
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int main(void)
{
	
	char a[5][5];
	a[0][0]='*';
	a[0][1]=' ';
	a[0][2]='*';
	a[0][3]='*';
	a[0][4]='*';
	a[1][0]='*';
	a[1][1]=' ';
	a[1][2]='*';
	a[1][3]='*';
	a[1][4]='*';
	a[2][0]='*';
	a[2][1]=' ';
	a[2][2]='*';
	a[2][3]='*';
	a[2][4]='*';
	a[3][0]='*';
	a[3][1]=' ';
	a[3][2]=' ';
	a[3][3]=' ';
	a[3][4]='*';
	a[4][0]='*';
	a[4][1]='*';
	a[4][2]='*';
	a[4][3]='P';
	a[4][4]='*';

//	char registe_r1,registe_r2,registe_r3;
	int ws=4, ad=3;
	int steps=0;
	while(1){
		char direction;
		
		
		
		for(int i=0;i<5;i++){
			for(int j=0; j<5;j++){
				if(i!=0&&j==0)printf("\n");
				printf("%c",a[i][j]);
			}
		}
		if(a[0][1]=='P')break;
		fflush(stdin);
		direction=getchar();
		if(direction=='w'&&ws!=0&&a[ws-1][ad]!='*'){
			a[ws][ad]=' ';
			steps++;
			ws--;
		}
		if(direction=='s'&&ws!=4&&a[ws+1][ad]!='*'){
			a[ws][ad]=' ';
			steps++;
			ws++;
		}
		if(direction=='a'&&ad!=0&&a[ws][ad-1]!='*'){
			a[ws][ad]=' ';
			steps++;
			ad--;
		}
		if(direction=='d'&&ad!=4&&a[ws][ad+1]!='*'){
			a[ws][ad]=' ';
			steps++;
			ad++;
		}
		a[ws][ad]='P';
		system("cls");
		
	}
	printf("\nCongruatulaton you come out this maze with %d steps\n",steps);
	return 0;
}


	

	

	
	
