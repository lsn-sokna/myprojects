#include<stdio.h>
#include<process.h>
#include<conio.h>
void main()
{	int i,j,n,n1=0,num=0,id;
	float x;
	struct { int aut;
				int id;
				char name[20];
				int unit;
				float price;
			} p[10],dp[10];
	printf("input n: "); 	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	p[i].aut=num++;
		printf("id: ");	scanf("%d",&p[i].id);
		printf("name: ");	fflush(stdin);gets(p[i].name);
		printf("unit: ");	scanf("%d",&p[i].unit);
		printf("price: ");scanf("%f",&x); p[i].price=x;
	}
	while(1)
	{  clrscr();
		puts("1: show all products");
		puts("2: delete product");
		puts("3: undelete product");
		puts("4: show trash");
		puts("E: Exit");
		switch(getch())
		{	case '1':	puts("Id\tName\tUnit\tPrice");
							for(i=0;i<n;i++)
							{	printf("%d\t",p[i].id);
								printf("%s\t",p[i].name);
								printf("%d\t",p[i].unit);
								printf("%.2f\n",p[i].price);
							}
							break;
			case '2':   printf("Delete id: ");
							scanf("%d",&id);
							for(i=0;i<n;i++)
							{	if(p[i].id==id)
								{	n=n-1;
									n1=n1+1;
									dp[n1-1]=p[i];
									for(j=i;j<n;j++)
										p[j]=p[j+1];
									i--;
								}
							}
							break;
			case '3':	puts("Restore product");
							printf("Id: ");
							scanf("%d",&id);
							for(i=0;i<n1;i++)
								if(dp[i].id==id)
								{	for(j=n-1;j>=dp[i].aut;j--)
										p[j+1]=p[j];
									p[dp[i].aut]=dp[i];
									n=n+1;
									n1=n1-1;
									for(j=i;j<n1;j++)
										dp[j]=dp[j+1];
									i--;
								}
							break;
			case '4':   puts("all products in trash");
							puts("Id\tName\tUnit\tPrice");
							for(i=0;i<n1;i++)
							{	printf("%d\t",dp[i].id);
								printf("%s\t",dp[i].name);
								printf("%d\t",dp[i].unit);
								printf("%.2f\n",dp[i].price);
							}
							break;
			case	'E':	exit(0);
		}
		getch();
	}
}

