#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_SAT_UZ 100


int dugumSayisi=0;
int **dizi;


int CharSay(char* s,char c)
{
	int sy=0;
	int i=0;
	while(s[i]!='\0')
	{
		if(s[i]==c)sy++;
		i++;
	}
	return sy;
}

void DosyaOku()
{
	char satir[MAX_SAT_UZ];
	int satirSayisi=0;
	int maxSatirdakiVeriSayisi=0;
	int temp=0;
	FILE *fp;
	if ((fp=fopen("Veri.txt", "r")) == NULL) {
      printf("Dosya açýlamadý!\n");
      exit(1);
	}


  while (fgets(satir, 80, fp)!=NULL)
  {
 	
  	satirSayisi++;
  	temp=CharSay(satir,' ')+1;
    if(temp>maxSatirdakiVeriSayisi)maxSatirdakiVeriSayisi=temp;
  } 
  fclose (fp);
  
  
  if(satirSayisi>maxSatirdakiVeriSayisi)dugumSayisi=satirSayisi; else dugumSayisi=maxSatirdakiVeriSayisi;
  
  

 

  dizi =(int **)malloc (dugumSayisi * sizeof (int*));
  
  for(int i=0;i<dugumSayisi;i++)
  {
  	dizi[i]=(int *)malloc (dugumSayisi * sizeof (int));
  }
  
  
  for(int i=0;i<dugumSayisi;i++)
  {
  	for(int j=0;j<dugumSayisi;j++)
  	{
  		dizi[i][j]=0; 
	}
  }
  
  if ((fp=fopen("Veri.txt", "r")) == NULL) {
      printf("Dosya açýlamadý!\n");
      exit(1);
	}


  for(int i=0;i<satirSayisi;i++)
  {
  	fgets(satir, 80, fp);
  	maxSatirdakiVeriSayisi=CharSay(satir,' ')+1;
  	
  	for(int j=0;j<maxSatirdakiVeriSayisi;j++)
  	{
  		dizi[i][j]=satir[j*2]-'0';
  		
	}
  	
  }
 
  
}



int main(){

		
	DosyaOku();

	int toplam=0;
	int derece=0;
	int derecetut=0;
	
	int secim;

	while(1){
	
	printf("\n");
	printf("1-Matris icerigini listeleyiniz\n");
	printf("2-giris ve cikis dereceleri\n");
	printf("3-Kenar sayisi\n");
	printf("4-Grafin kenar maliyetleri toplamini yazdiriniz\n");
	printf("5-Kenar maliyet yazdirma\n");
	printf("6-Graf tam graf mi\n");
	printf("7-Graf yonlu mu?\n");
	printf("8-Cikis\n");
	
	printf("\nSecim yapiniz: ");
	scanf("%d",&secim);
	printf("\n");
	int tam=1;
		switch(secim)
		{

		case 1:
			
			for(int i=0;i<dugumSayisi;i++)
			{
				for(int k=0;k<dugumSayisi;k++)
				{
					printf("%d ",dizi[i][k]);
				}
				printf("\n");
			}
				
			break;
		case 2:
			
			derecetut=0;
			printf("Dugum numarasini gir (0-4) :");
			scanf("%d",&derece);
			
			for(int i=0;i<dugumSayisi;i++)
			{						
			
				if(dizi[i][derece]>0){
					derecetut++;
				}
				
			}
			
			printf("\ngiris sayisi :%d\n",derecetut);
			
			derecetut=0;
			
			for(int i=0;i<dugumSayisi;i++)
			{
				if(dizi[derece][i]>0){
					derecetut++;
				}
			}
			
			printf("\ncikis sayisi :%d\n",derecetut);
			
			
			
			
			break;
		case 3:
			
			derecetut=0;
				for(int i=0;i<dugumSayisi;i++)
				{
					for(int k=0;k<dugumSayisi;k++)
					{
						
						derece = dizi[i][k];
						if(derece>0){
							derecetut++;
						}
						
					}					
				}
	
			printf("\nkenar sayisi : %d\n",derecetut);
			

			break;
		case 4:
			
				for(int i=0;i<dugumSayisi;i++)
				{
					for(int k=0;k<dugumSayisi;k++)
					{
						toplam += dizi[i][k];						
					}
				}
				
				printf("Graf Toplam: %d ",toplam);
				
			break;
		case 5:
				
			derecetut=0;
			printf("Dugum numarasini gir (0-4) :");
			scanf("%d",&derece);
				
			printf("Dugumu No :%d \n",derece);	
			for(int i=0;i<dugumSayisi;i++)
			{
				if(dizi[derece][i]>0)	
					printf("%d -> %d  Maliyet = %d\n",derece, i,dizi[derece][i]);
			
			}
			

			break;
		case 6:
				derecetut=0;
				tam=1;
				for(int i=0;i<dugumSayisi;i++)
				{
					for(int k=0;k<dugumSayisi;k++)
					{
						if(i==k)
						{
						   if(dizi[i][k] !=0)tam=0;
						} 
						else
						{
							if(dizi[i][k] ==0)tam=0;
						}
						
					
						
					}
				}
				
				if(tam==0)
				{
					printf("Dizi tam graf degil");
				}
				else
				{
					printf("Dizi tam graf");
				}
				
			break;
		case 7:
				derecetut=0;
				for(int i=0;i<dugumSayisi;i++)
				{
					for(int k=0;k<dugumSayisi;k++)
					{
						if(dizi[i][k] != dizi[k][i])
						{
							derecetut++;
						}
					}
				}
				
				if(derecetut>0)
				{
					printf("Dizi simetrik degil (Yonlu)\n");
				}else
				{
					printf("Dizi simetrik  (Yonsuz)\n");
				}
			
			break;
			
			
		case 8:
			exit(0);
			break;
			

		}
	}

	
}
