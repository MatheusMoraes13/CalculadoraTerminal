//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

//funcoes que serao utilizadas no metodo main

//Definindo os valores da teclas que serao utilizadas para controle do menu
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13
#define OPTmax 3
#define OPTmin 1

//declara as variaveis gerais para as operacoes
float ans, n1, n2;

//Definindo uma estrutura para controle de entrada e saida do teclado
struct Keyboard {
	int entrada;
	int saida;
};

//limpa o terminal e continua o codigo
void continua (){

	printf ("\n\n\n\tPRESSIONE QUALQUER TECLA PARA CONTINUAR");
	getch ();
	system ("cls || clear");
}

//realiza a operacao de soma
float soma (){

	printf ("\nInsira o primeiro numero: ");
	scanf ("%f", &n1);
	printf ("\nInsira o segundo numero: ");
	scanf ("%f", &n2);

	ans = n1 + n2;

	printf("\nResultado: %0.1f", ans);
	getch();

return ans;
}

//realiza a ooperacao de subtracao
float subtracao (){

	printf ("\nInsira o primeiro numero: ");
	scanf ("%f", &n1);
	printf ("\nInsira o segunso nï¿½mero: ");
	scanf ("%f", &n2);

	ans = n1 - n2;

	printf("\nResultado: %0.1f", ans);
	getch();

return ans;
}

//realiza a opreacao de multiplicaco
float multiplicacao (){

	printf ("\nInsira o primeiro numero: ");
	scanf ("%f", &n1);
	printf ("\nInsira o segunso numero: ");
	scanf ("%f", &n2);

	ans = n1 * n2;

	printf("\nResultado: %0.1f", ans);
	getch();

return ans;
}

//realiza a operacao de divisao
float divisao (){

	printf ("\nInsira o primeiro numero: ");
	scanf ("%f", &n1);
	printf ("\nInsira o segunso numero: ");
	scanf ("%f", &n2);

	ans = n1 / n2;

	printf("\nResultado: %0.1f", ans);
	getch();

return ans;
}

//realiza a operacao de raiz quadrada
float raiz (){

	printf ("Insira o numero o qual deseja a raiz quadrada: ");
	scanf ("%f", &n1);

	ans = sqrt(n1);

	printf("\n\nResultado: %0.1f", ans);
	getch ();

	return ans;
}

//realiza a operacao exponencial
float potencia (){

	printf ("\nInsira o valor da base:");
	scanf ("%f", &n1);
	printf ("\nInsira o expoente:");
	scanf ("%f", &n2);

	n2 = n2 - 1;
	while (n2 > 0){

	n1 = n1 * n1;

	n2 = n2 - 1;
	}

	ans = n1;
	printf("\nResultado: %0.1f", ans);
	getch();

	return ans;
}

//realiza a operacao de equacao do segundo grau
void segundograu (){
	float a,b, c, xl, xll, delt;

	printf("\ninsira o elemento ""A"" da equacao: ");
	scanf("%f", &a);

	printf("\ninsira o elemento ""B"" da equacao: ");
	scanf("%f", &b);

	printf("\ninsira o elemento ""C"" da equacao: ");
	scanf("%f", &c);

	delt = (b*b) - (4*a*c);

	xl = -b +sqrt(delt);
	xl = xl / (2*a);
	xll = -b -sqrt(delt); 
	xll = xll / (2*a);


	printf("\n\tRultados");
	printf("\n\nX': %0.1f", xl);
	printf("\nX'': %0.1f\n\n", xll);

}

//funcao que sera responsavel por executar a opcao selecionada pelo usuario
void opcoes (int choice){


	switch (choice){

		case 1:

			soma ();
			continua ();

		break;

		case 2:

			subtracao ();
			continua ();

		break;

		case 3:

			multiplicacao ();
			continua ();

		break;

		case 4:

			divisao ();
			continua ();

		break;

		case 5:

			raiz ();
			continua ();

		break;

		case 6:

			potencia ();
			continua ();

		break;

		case 7:

			segundograu ();
			continua ();

		break;

		}


}


//redefinindo a struct para "Keyboard
typedef struct Keyboard Keyboard;

//Funcao imprime o menun com a opcao destacada
void menu (int opcao)
{
	system ("cls");

	char *opcoes [] = {
		"\tOPCOES\n",
        "\n( 1 ) - SOMAR",
        "\n( 2 ) - SUBTRAIR",
        "\n( 3 ) - MULTIPLICAR",
        "\n( 4 ) - DIVIDIR",
        "\n( 5 ) - RAIZ QUADRADA",
        "\n( 6 ) - POTENCIA",
        "\n( 7 ) - EQUACAO DO SEGUNDO GRAU"
	};


		int i;
        for (i = 0; i < 8; i++)
        {
            if (i == opcao)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
                printf ("%s", opcoes [i]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }

            else
            {
                printf("%s", opcoes [i]);
            }
        }

	printf("\n\n( \"ESC\" )   SAIR");

}

int Teclado (int entrada,int saida)
{
	if (entrada == KEY_ENTER){
				system("cls");
				opcoes (saida);
			return saida;
			}

	if (entrada == KEY_ESC){
        printf("\n\nENCERRANDO O PROGRAMA");
        getch();
    	return 0;
    	}

	if (entrada == KEY_DOWN){
    	saida ++;
		}

	if (entrada == KEY_UP){
		saida --;
		}
		
	return saida;
}


//Funcao responsavel por ler o teclado e retornar o valor no qual a opï¿½ï¿½o estï¿½
void MenuCalculadora (){
	Keyboard teclado;

	teclado.saida = 1;


    while (teclado.saida >= 0){

		if (teclado.saida < 1){
    		teclado.saida = 1;
		}

		if (teclado.saida <= 7 && teclado.saida >= 1){
			
			menu (teclado.saida);
			teclado.entrada = getch();
			teclado.saida = Teclado (teclado.entrada, teclado.saida);
			
    	}

    	if (teclado.saida > 7){
    		teclado.saida = 7;
		}


    }
}



//metodo main da calculadora
int main(){
setlocale(LC_ALL, "Portuguese");


    printf("\t CALCULADORA\n\n");
    MenuCalculadora ();


return 0;
}
