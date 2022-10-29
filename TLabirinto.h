#define MAXPILA 300
struct Tpos
{
	char CampoVisitado, TipoDeCampo;
};
struct TLab
{
	int PosAtualLin, PosAtualCol;
	Tpos posicoes[100][100];	
};

struct TpPilha
{
    int TOPO;
    char PILHA[MAXPILA];
};
void inicializa(TpPilha &p);
void insere(TpPilha &p, char Elemento);
char retira(TpPilha &p);
char elementoTopo(TpPilha p);
int cheia(int topo);
int vazia(int topo);
int exibe(TpPilha p);

void inicializa(TpPilha &p)
{
    p.TOPO = -1;
}

void insere(TpPilha &p, char Elemento)
{
    p.PILHA[++p.TOPO] = Elemento;
}

char retira(TpPilha &p)
{
    return p.PILHA[p.TOPO--];
}

char elementoTopo(TpPilha p)
{
    return p.PILHA[p.TOPO];
}

int cheia(int topo)
{
    return topo == MAXPILA-1;
}

int vazia(int topo)
{
    return topo == -1;
}

int exibe(TpPilha p)
{
   while( !vazia(p.TOPO) )
        printf("\n%c",retira(p));
}

int remove(TpPilha &p, char elemento)
{
	TpPilha p2;
	char elem;
	inicializa(p2);
	p2.TOPO = 0;	
	while(!vazia(p.TOPO) )
	{
		p2.PILHA[p2.TOPO]= p.PILHA[p.TOPO];
		p2.TOPO++;
		p.TOPO--;
	}
	while(!vazia(p.TOPO) )
		retira(p);
	while(!vazia(p2.TOPO) )
	{
		elem = retira(p2);
		if(elem != elemento)
			insere(p,elem);	
	}
}

char Exibir(char Mat[100][100],int MatI,int MatJ,TLab &Tl,Tpos &Tp, char Robo)
{
	int l,m;
	Sleep(100);
	clrscr();
	for(l=0;l<MatI;l++)
		{
			for(m=0;m<=MatJ;m++)
			{
				if(Mat[l][m]==Robo)
					textcolor(GREEN);
				else if(Mat[l][m]=='P')
					textcolor(YELLOW);
				else if(Mat[l][m]=='B')
					textcolor(RED);
				else 
					textcolor(WHITE);
				printf("%c",Mat[l][m]);
			}
					
		}
}

