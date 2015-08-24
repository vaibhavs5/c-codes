#include<stdio.h>
#include<stdbool.h>

int a[4][13];

int card1,card2;

bool sameSuite(int card1,int card2);
bool greater(int card1,int card2);

int main()
{
    bool suite,compare;
    int i,j;
    
	for(i=1;i<=4;i++)
    {
		for(j=1;j<=13;j++)
		{
		    a[i][j]=i*j;
		}
    }

	card1=a[2][3];
	card2=a[3][8];
    
	suite=sameSuite(card1,card2);
    compare=greater(card1,card2);
	
	if(suite^0)
	{
		printf("same suite\n");
	}
	else
	{
		printf("different suite\n");
	}
    return 0;
}


bool greater(int card1,int card2)
{
	return 0;
}


bool sameSuite(int card1,int card2)
{
	return !((card1 & 0x30)^(card2 & 0x30));
}
