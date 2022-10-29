//Daniel Elias Fonseca Rumin  102113149
//Ana Laura Angelosi Cruz     102113068

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio2.h>
#include <windows.h>
#include "TLabirinto.h"
char Mapa (FILE*Ptr,int &Prem,int &CordI,int &MatI,int &MatJ,int &CordJ,char Mat[100][100],TLab &Tl,Tpos &Tp)
{
	int i=0,j=0;
	char elem,NomeDoRobo[20];

	while(i<2)
	{
		if(i==0)
		{
			fscanf(Ptr,"%[^\n]",&NomeDoRobo);
		
		}	
		else if(i==1)
			fscanf(Ptr,"%d%d",&MatI,&MatJ);
		i++;
	}
	printf("%s\n[%d][%d]",NomeDoRobo,MatI,MatJ);
	
	for(i=0;i<MatI;i++)
		for(j=0;j<=MatJ;j++)
		{
			elem=toupper(fgetc(Ptr));
			if(elem=='P')	
				Prem++;
			else if(elem == 'O')
			{
				CordI=i;
				CordJ=j;
			}	
			Mat[i][j]=elem;
			printf("%c",Mat[i][j]);	
		}
}

void Andar(TpPilha &P,char Mat[100][100], char Robo, int &PremioC,int &i, int &j,TLab &Tl,Tpos &Tp)
{
	
	char elem, posA,posW,posS,posD;
	// para direita
	
	Tl.PosAtualLin = i;
	Tl.PosAtualCol = j;
    posA  = Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol-1].CampoVisitado;
 	posW = Tl.posicoes[Tl.PosAtualLin-1][Tl.PosAtualCol].CampoVisitado;
	posS  = Tl.posicoes[Tl.PosAtualLin+1][Tl.PosAtualCol].CampoVisitado;
	posD  = Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol+1].CampoVisitado;

	if(Mat[i][j+1]!='X'  && Mat[i][j+1]!='B' && posD!='V')
	{
		if(Mat[i][j+1]=='P')
			PremioC++;
		Mat[i][j+1]=Robo;
		Mat[i][j]=' ';
		
		Tp.TipoDeCampo=Mat[i][j];
		Tp.CampoVisitado='V';
		j+=1;
		Tl.PosAtualLin=i;
		Tl.PosAtualCol=j;
		Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
	
		insere(P,elem='D');
	}
	//para cima
	else if(Mat[i-1][j]!='X' && Mat[i-1][j]!='B' && posW!='V')
	{
		if(Mat[i-1][j]=='P')
			PremioC++;
	
		Mat[i-1][j]=Robo;
		Mat[i][j]=' ';
		Tp.TipoDeCampo=Mat[i][j];
		Tp.CampoVisitado='V';
		i-=1;
		Tl.PosAtualLin=i;
		Tl.PosAtualCol=j;
		Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
		
		insere(P,elem='W');	

	}
	//para a esquerda
	else if(Mat[i][j-1]!='X' && Mat[i][j-1]!='B' && posA!='V')
	{
		if(Mat[i][j-1]=='P')
			PremioC++;
			
		Mat[i][j-1]=Robo;
		Mat[i][j]=' ';
		Tp.TipoDeCampo=Mat[i][j];
		Tp.CampoVisitado='V';
		j-=1;
		Tl.PosAtualLin=i;
		Tl.PosAtualCol=j;
		Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
		insere(P,elem='A');
		
	
	}
	//para baixo
	else if(Mat[i+1][j]!='X' && Mat[i+1][j]!='B' && posS!='V')
	{
		if(Mat[i+1][j]=='P')
			PremioC++;

		Mat[i+1][j]=Robo;
		Mat[i][j]=' ';
		Tp.TipoDeCampo=Mat[i][j];
		Tp.CampoVisitado='V';
		i+=1;
		Tl.PosAtualLin=i;
		Tl.PosAtualCol=j;
		Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;	
		insere(P,elem='S');
		
	}
	else
	{
		//Volta Esquerda
		if(P.PILHA[P.TOPO] == 'D' && Mat[i][j-1]!='X' && Mat[i][j-1]!='B')
		{
			Mat[i][j-1]=Robo;
			Mat[i][j]=' ';	
			Tp.TipoDeCampo=Mat[i][j];
			
			j-=1;
			Tl.PosAtualLin=i;
			Tl.PosAtualCol=j;
			Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
		
		}
		//Volta Baixo
		else if(P.PILHA[P.TOPO] == 'W' && Mat[i+1][j]!='X' && Mat[i+1][j]!='B')
		{
			Mat[i+1][j]=Robo;
			Mat[i][j]=' ';	
			Tp.TipoDeCampo=Mat[i][j];
		
			i+=1;
			Tl.PosAtualLin=i;
			Tl.PosAtualCol=j;
			Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
			
		}
		//Volta Direita
		else if(P.PILHA[P.TOPO] == 'A' && Mat[i][j+1]!='X' && Mat[i][j+1]!='B')
		{
			Mat[i][j+1]=Robo;
			Mat[i][j]=' ';
			Tp.TipoDeCampo=Mat[i][j];
			
			j+=1;
			Tl.PosAtualLin=i;
			Tl.PosAtualCol=j;
			Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
				
		}
		//Volta Cima
		else if(P.PILHA[P.TOPO] == 'S' && Mat[i-1][j]!='X' && Mat[i-1][j]!='B')
		{
			Mat[i-1][j]=Robo;
			Mat[i][j]=' ';	
			Tp.TipoDeCampo=Mat[i][j];
		
			i-=1;
			Tl.PosAtualLin=i;
			Tl.PosAtualCol=j;
			Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;	
		}
		retira(P);	
	}	
 
}


void Finalizar(TpPilha &P,char Mat[100][100], char Robo, int PremioC,int Prem,int &i, int &j,int CordI,int CordJ,int MatI, int MatJ,TLab &Tl,Tpos &Tp)
{
	if(PremioC==Prem)
	{
		while(!vazia(P.TOPO) && Mat[CordI][CordJ]!=Robo)
		{
		
			if(P.PILHA[P.TOPO] == 'D')
			{
				Mat[i][j-1]=Robo;
				Mat[i][j]=' ';
				Tp.TipoDeCampo=Mat[i][j];
		
				j-=1;
				Tl.PosAtualLin=i;
				Tl.PosAtualCol=j;
				Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
			
			}
			//Volta Baixo
			else if(P.PILHA[P.TOPO] == 'W')
			{
				Mat[i+1][j]=Robo;
				Mat[i][j]=' ';	
				Tp.TipoDeCampo=Mat[i][j];
			;
				i+=1;
				Tl.PosAtualLin=i;
				Tl.PosAtualCol=j;
				Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
				
			}
			//Volta Direita
			else if(P.PILHA[P.TOPO] == 'A')
			{
				Mat[i][j+1]=Robo;
				Mat[i][j]=' ';	
				Tp.TipoDeCampo=Mat[i][j];
			
				j+=1;
				Tl.PosAtualLin=i;
				Tl.PosAtualCol=j;
				Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
					
			}
			//Volta Cima
			else if(P.PILHA[P.TOPO] == 'S')
			{
				Mat[i-1][j]=Robo;
				Mat[i][j]=' ';	
				Tp.TipoDeCampo=Mat[i][j];
			
				i-=1;
				Tl.PosAtualLin=i;
				Tl.PosAtualCol=j;
				Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;		
			}
			retira(P);		
			Exibir(Mat,MatI,MatJ,Tl,Tp,Robo);	
		}
	}
}

void Zerar(TLab &Tl, Tpos &Tp,int MatI,int MatJ,char Mat[100][100])
{
	int i=0,j=0;
	
	for(i=0;i<MatI;i++)
	{
		for(j=0;j<MatJ;j++)
		{
			Tp.TipoDeCampo=Mat[i][j];
			Tp.CampoVisitado=' ';
			Tl.PosAtualLin=i;
			Tl.PosAtualCol=j;
			Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
		}
	}
}

char menuLab (void)
{
	clrscr();
	printf("\n [1]- Fase 0");
	printf("\n [2]- Fase 1");	
	printf("\n [3]- Fase 2");
	printf("\n opcao: ");
	return getche();
}

void Iniciar()
{
	TpPilha P;
	TLab Tl;
	Tpos Tp;
	int  Linha=0,MatI=0,MatJ=0,elem=0,Prem=0,CordI=0,CordJ=0,i=0,j=0,l=0,m=0,PremioC=0,mov=0,MovTot=0;
	char NomeArq[20],op,Mat[100][100]={0},Robo=230,posA,posD,posW,posS;
									
	op=menuLab();
	switch(op)
	{
		case'1':
			strcpy(NomeArq,"Labirinto0.dat");
		break;
		
		case'2':
			strcpy(NomeArq,"Labirinto1.dat");
		break;
		
		case'3':
			strcpy(NomeArq,"Labirinto2.dat");
		break;
	}
	clrscr();
	
	FILE*PtrArq = fopen(NomeArq,"r");
	if(PtrArq==NULL)
	{
		printf("Problemas ao Ler O mapa!!");
	}
	else
	{
		inicializa(P);
		Mapa(PtrArq,Prem,CordI,MatI,MatJ,CordJ,Mat,Tl,Tp);
		printf("\n\nTotal de Premios no mapa:%d\nCoordenada Inicial: [%d][%d]\n",Prem,CordI,CordJ);
		printf("\nlabirinto possui Mat[%d][%d] tamanho\n",MatI,MatJ);
		printf("\nO Robo sera representado por um %c",Robo);
		printf("\nAperte qualquer tecla para continuar!!!");
		getch();
		for(i=0;i<MatI;i++)
			for(j=0;j<MatJ;j++)
				if(Mat[i][j]=='X')
				{
					Tp.CampoVisitado='V';
					Tl.PosAtualLin=i;
					Tl.PosAtualCol=j;
					Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol] = Tp;
				}
		
		i=CordI;
		j=CordJ;
		
		//Enquanto premios coletados diferente de premios do mapa e cordenada inicial diferente de Robo
		
		while(PremioC!=Prem || Mat[CordI][CordJ]!=Robo && posA != 'V' || Mat[CordI][CordJ]!=Robo &&  posD != 'V' || Mat[CordI][CordJ]!=Robo &&  posS != 'V' || Mat[CordI][CordJ]!=Robo &&  posW != 'V')
		{
			Andar(P, Mat, Robo, PremioC,i,j,Tl,Tp);
			Exibir(Mat,MatI,MatJ,Tl,Tp,Robo);
			mov++;
			posA  = Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol-1].CampoVisitado;
		 	posW = Tl.posicoes[Tl.PosAtualLin-1][Tl.PosAtualCol].CampoVisitado;
			posS  = Tl.posicoes[Tl.PosAtualLin+1][Tl.PosAtualCol].CampoVisitado;
			posD  = Tl.posicoes[Tl.PosAtualLin][Tl.PosAtualCol+1].CampoVisitado;
		}	
		//Se premios coletados igual a premios no mapa enta retirar tudo da pilha
		Finalizar(P ,Mat, Robo, PremioC,Prem,i,j,CordI,CordJ,MatI,MatJ,Tl,Tp);
		Exibir(Mat,MatI,MatJ,Tl,Tp,Robo);
		printf("\nPremios: Pegos/No mapa \n%d/%d",PremioC,Prem);
		printf("\nNumero de Movimentos executados %d",mov);
		fclose(PtrArq);	
	}
	Zerar(Tl,Tp,MatI,MatJ,Mat);
	getch();
}

char menu()
{
	clrscr();
	printf("[1]-Iniciar\n");
	printf("opcao: ");
	return getche();
}

int main (void)
{
	
	char opcao;
	do
	{
		opcao=menu();
		switch(opcao)
		{
			case '1':Iniciar();
		}
	}while(opcao!=27);	
	return 1;
}
