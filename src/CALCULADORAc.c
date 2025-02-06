//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

//fun��es que ser�o utilizadas no metodo main

//Definindo os valores da teclas que ser�o utilizadas para controle do menu
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13
#define OPTmax 3
#define OPTmin 1

//Definindo uma estrutura para controle de entrada e saida do teclado
struct Keyboard {
	int entrada;
	int saida;
};

//redefinindo a struct para "Keyboard
typedef struct Keyboard Keyboard;

//Fun��o para a apresenta��o do menu e destacar a op��o selecionada
void menu (int opcao)
{
	system ("cls");

	char *opcoes [] = {
		"\tOP��ES\n",
        "\n( 1 ) - SOMAR",
        "\n( 2 ) - SUBTRAIR",
        "\n( 3 ) - MULTIPLICAR",
        "\n( 4 ) - DIVIDIR",
        "\n( 5 ) - RAIZ QUADRADA",
        "\n( 6 ) - POTENCIA",
        "\n( 7 ) - EQUA��O DO SEGUNDO GRAU"
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


//fun��o respons�vel por ler o teclado e retornar o valor no qual de qual op��o est� selecionada
int MenuCalculadora (){
	Keyboard teclado;

	teclado.saida = 1;


    while (teclado.saida > 0){

		if (teclado.saida <= 1){
    		teclado.saida = 1;
		}

		if (teclado.saida == 1){
			
			menu (teclado.saida);
			teclado.entrada = getch();
			teclado.saida = Teclado (teclado.entrada, teclado.saida);
			
    	}

    	if (teclado.saida == 2){
			
			menu (teclado.saida);
			teclado.entrada = getch();
			teclado.saida = Teclado (teclado.entrada, teclado.saida);
			
    	}

    	if (teclado.saida == 3){
			
			menu (teclado.saida);
			teclado.entrada = getch();
			teclado.saida = Teclado (teclado.entrada, teclado.saida);
			
    	}

    	if (teclado.saida == 4){
			
			menu (teclado.saida);
			teclado.entrada = getch();
			teclado.saida = Teclado (teclado.entrada, teclado.saida);
			
    	}


    	if (teclado.saida == 5){
			
			menu (teclado.saida);
			teclado.entrada = getch();
			teclado.saida = Teclado (teclado.entrada, teclado.saida);
			
    	}

    	if (teclado.saida == 6){
			
			menu (teclado.saida);
			teclado.entrada = getch();
			teclado.saida = Teclado (teclado.entrada, teclado.saida);
			
    	}

    	if (teclado.saida == 7){
			
			menu (teclado.saida);
			teclado.entrada = getch();
			teclado.saida = Teclado (teclado.entrada, teclado.saida);
			
    	}

    	if (teclado.saida > 7){
    		teclado.saida = 7;
		}


    }
}



//limpa o terminal e continua o c�digo
void continua (){

	printf ("\n\n\n\tPRESSIONE QUALQUER TECLA PARA CONTINUAR");
	getch ();
	system ("cls || clear");
}

//declara as vari�veis gerais para as opera��es
float ans, n1, n2;


//realiza a opera��o de soma
float soma (){

	printf ("\nInsira o primeiro n�mero: ");
	scanf ("%f", &n1);
	printf ("\nInsira o segundo n�mero: ");
	scanf ("%f", &n2);

	ans = n1 + n2;

	printf("\nResultado: %0.1f", ans);
	getch();

return ans;
}

//realiza a opera��o de subtra��o
float subtracao (){

	printf ("\nInsira o primeiro n�mero: ");
	scanf ("%f", &n1);
	printf ("\nInsira o segunso n�mero: ");
	scanf ("%f", &n2);

	ans = n1 - n2;

	printf("\nResultado: %0.1f", ans);
	getch();

return ans;
}

//realiza a opera��o de multiplica��o
float multiplicacao (){

	printf ("\nInsira o primeiro n�mero: ");
	scanf ("%f", &n1);
	printf ("\nInsira o segunso n�mero: ");
	scanf ("%f", &n2);

	ans = n1 * n2;

	printf("\nResultado: %0.1f", ans);
	getch();

return ans;
}

//realiza a opera��o de divis�o
float divisao (){

	printf ("\nInsira o primeiro n�mero: ");
	scanf ("%f", &n1);
	printf ("\nInsira o segunso n�mero: ");
	scanf ("%f", &n2);

	ans = n1 / n2;

	printf("\nResultado: %0.1f", ans);
	getch();

return ans;
}

//realiza a opera��o de raiz quadrada
float raiz (){

	printf ("Insira o n�mero o qual deseja a raiz quadrada: ");
	scanf ("%f", &n1);

	ans = sqrt(n1);

	printf("\n\nResultado: %0.1f", ans);
	getch ();

	return ans;
}

//realiza a opera��o exponencial
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

//realiza a opera��o de segundo grau
void segundograu (){
	float a,b, c, xl, xll, delt;

	printf("\ninsira o elemento ""A"" da equa��o: ");
	scanf("%f", &a);

	printf("\ninsira o elemento ""B"" da equa��o: ");
	scanf("%f", &b);

	printf("\ninsira o elemento ""C"" da equa��o: ");
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

//fun��o respons�vel por executar a op��o selecionada pelo usu�rio
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


//metodo main da calculadora
int main(){
setlocale(LC_ALL, "Portuguese");

//imprimir o menu inicial para o usu�rio
    int option = 0;

    printf("\t CALCULADORA\n\n");
    
	option = MenuCalculadora ();

//chama a fun��o respons�vel por executar a op��o selecionada pelo usu�rio
    opcoes(option);

return 0;
}
