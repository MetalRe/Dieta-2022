#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include<string.h>
#include <time.h>


void creatinaPorDia();
void loading_cem();
void proteinaPorpeso();
struct nutri
{
    char nome[30];
    char uni[5];
    float mult[5];
};

int main()
{

    typedef struct nutri Dados;
    Dados ali[14] =
    {
        {
            //Frango, Carne, Peixe, Leite, Ovos
            "Proteinas", "g", {1/3.125,0.22,0.0215,5.99}
        },
        {
            "Gorduras", "kcal",{0.14,0.035,0.12,0.0065,4.28}
        },
        {
            "Calorias", "kcal",{0.418,1.43,2.06,0.27,65.70}
        },
        {
            "S�dio", "mg",{0.82,0.57,0.61,0.14,65.70}
        },
        {
            "Pot�ssio", "mg",{2.23,4.21,3.84,0.95,63.0}
        },
        {
            "Vitamina C", "mg",{0.0,0.0,0.037,0.0,0.0}
        },
        {
            "Ferro", "mg",{0.013,0.012,0.003,0.0,0.6}
        },
        {
            "Vitamina B6", "mg",{0.004,0.007,0.006,0.0,0.55}
        },
        {
            "Magn�sio", "mg",{0.23,0.29,0.30,0.0,5.0}
        },
        {
            "C�lcio", "mg",{0.15,0.06,0.15,0.795,25.0}
        },
        {
            "Vitamina D ", "IU",{0.02,0.10,0.0,0.0065,43.5}
        },
        {
            "Cobalamina", "�g",{0.003,0.006,0.028,0.00295,0.55}
        },
        {
            "Colesterol", "mg",{0.88,0.73,0.63,0.003,186.5}
        },
        {
            "Carboidratos", "mg",{0.0319,02.7}
        },
    };
    setlocale(LC_ALL,"Portuguese");
    /*USE O GITHUB � EXCELENTE*/
    /*Dividir e conquistar*/
    int op,escolha;
    char op2[10];
    char nome[50], resp;
    float ValorNut[15]= {0};
    float imc = 0, alt = 0, peso = 0;
    float valor, man , woman, idade, carbo, p, lip;
    //loading_cem();
    do
    {
        printf("\n\t\t\t:**************************Informa��o Nutricional*************************: ");
        printf("\n\t\t\t:***********************************MENU**********************************: ");
        printf("\n\n\t\t\t\t    1 - Informa��o Nutricional - Frango, Carne e Peixe: ");
        printf("\n\t\t\t\t     \t2 - |_Calcular quantidade Prote�na por peso:_|");
        printf("\n\t\t\t\t\t #################  IMC  ################## ");
        printf("\n\t\t\t\t     \t     _________________________________________");
        printf("\n\t\t\t\t     \t3 - |_Calcular Indice de Massa Corporal(IMC):_|");
        printf("\n\t\t\t\t     \t     _______________________________________");
        printf("\n\t\t\t\t     \t4 - |_Calcular quantidade CREATINA por dia:_|");
        printf("\n\n\t\t\t\t\t################ GAIN WEIGHT ################ ");
        printf("\n\t\t\t\t      ________________________________________________________");
        printf("\n\t\t\t     \t 5 - |_Calcular a quantidade de calorias baseado no seu peso:_| ");
        printf("\n\t\t\t\t _______________________________________________________________");
        printf("\n\t\t\t    6 - |_Calcular a quantidade de Calorias para obter o Peso desejado:_|");
        printf("\n\n\t\t\t\t\t################## LOSE WEIGHT ############### ");
        printf("\n\t\t\t\t      _____________________________________________________");
        printf("\n\t\t\t     \t 7 - |_Calcular a quantidade de Calorias para perder Peso:_|");
        printf("\n\t\t\t      ___________________________________________________________________");
        printf("\n\t\t\t 8 - |_Calcular a qt de calorias necess�rias por dia para manter o peso:_|");
        printf("\n\t\t\t     \t\t\t 0 - Digite zero para Sair: \n");
        printf("\n\t\t\t\t\t\t   => Escolha uma op��o: ");
        scanf("%d",&op);
        system("cls");
        switch(op)
        {
        case 1:
            printf("\nOp��o: 1 - Informa��o Nutricional :");
            printf("\nPor favor Informe seu nome: ");
            fflush(stdin);
            gets(nome);
            fflush(stdin);
            printf("< Por favor Informe seu peso (kg) > ");
            scanf("%f",&peso);
            printf("< Por favor Informe sua altura (metro e cm) Ex: ( 1,78 > ");
            scanf("%f",&alt);
            system("cls");

            imc = peso/(alt*alt);
            if( imc > 18.05 && imc < 24.9)
                printf("\n# %s voc� est� com IMC %.2f, Peso Ideal Parab�ns!!!\n",nome,imc);
            if( imc < 18.05)
                printf("\n# %s voc� est� com IMC %.2f MAGREZA, e precisa se Alimentar melhor ",nome,imc);
            if( imc >= 25.0 && imc <= 29.99)
                printf("# %s voc� est� com IMC %.2f Sobre Peso, e est� com Circunfer�ncia Abdominal Larga \n",nome,imc);
            if( imc > 30.0 && imc < 39.0)
                printf("\n# %s voc� est� com IMC %.2f OBESIDADE TIPO II,\ne continua com Circunfer�ncia Abdominal Larga",nome,imc);
            if( imc > 40.0)
                printf("# %s voc� est� com IMC %.2f OBESIDADE GRAVE TIPO III,\ne precisa mudar sua Dieta e praticar Esporte ou Caminhada:\n",nome,imc);

            /*Calcular o quantide de proteina e vitaminas, carne, frango e peixe*/
            /*Colocar na ordem , , ; - <, <, <; - ++, ++, ++(no final n�o precisa de ; */
            do
            {

                /*1 Op��o Dentro do MENU*/
                printf("\nPor favor informe o alimento que quer calcular: ");
                printf("\nDigite:   \n( 1 ) Para Frango\n( 2 ) Para Carne\n( 3 ) Para Peixe\n( 0 ) Para sair:\n");
                printf("Escolha: ");
                scanf("%d",&escolha);
                switch(escolha)
                {
                case 1 :
                    //system("cls");
                    printf("\n=> Informa��o Nutricional - Prote�na de Frango: ");
                    printf("\n# Digite quantas gramas voc� comeu de frango: ");
                    scanf("%f",&valor);

                    for(int x = 0; x < 13; x++)
                    {
                        printf("\n=> %s %.1f%s ", ali[x].nome, valor * ali[x].mult[0], ali[x].uni);
                        /*Lista das Somas de cada amino�cidos e prot�inas*/
                        ValorNut[x] += valor * ali[x].mult[0];
                    }
                    break;
                /*2 Op��o Dentro do MENU*/
                case 2:
                    system("cls");
                    printf("\n=> Informa��o Nutricional - Prote�na da Carne: ");
                    printf("\n# Digite quantas gramas voc� comeu de Carne: ");
                    scanf("%f",&valor);
                    for(int x = 0; x < 13; x++)
                    {
                        printf("\n=> %s %.1f%s ", ali[x].nome, valor * ali[x].mult[1], ali[x].uni);
                        /*Lista das Somas de cada amino�cidos e prot�inas*/
                        ValorNut[x] += valor * ali[x].mult[0];
                    }
                    break;

                /*3 Op��o Dentro do MENU*/
                case 3:
                    system("cls");
                    printf("\n=> Informa��o Nutricional - Prote�na do Peixe: ");
                    printf("\n# Digite quantas gramas voc� comeu de Peixe: ");
                    scanf("%f",&valor);
                    for(int x = 0; x < 13; x++)
                    {
                        printf("\n=> %s %.1f%s ", ali[x].nome, valor * ali[x].mult[2], ali[x].uni);
                        /*Lista das Somas de cada amino�cidos e prot�inas*/
                        ValorNut[x] += valor * ali[x].mult[0];
                    }
                    break;
                }

                //final do for
            }
            while(escolha != 0 );

            /*Impres�o da somas*/
            printf("\n\nLista Soma Total de Amino�cidos, Vitaminas e Prote�nas. \n=> Foi de aproxidamente %.1fg de Prote�na ",ValorNut[0]);
            printf("\n=> Tem aproxidamente %.2fg de Gorduras \n=> Tem aproxidamente %.2fg Calorias: ",ValorNut[1],ValorNut[2]);
            printf("\n=> Tem aproxidamente %.2fg de S�dio\n=> Tem aproxidamente %.2fg de Pot�ssio: ",ValorNut[3],ValorNut[4]);
            printf("\n=> Tem aproxidamente %.2fg de Vitamina C\n=> Tem aproxidamente %.2fg de Ferro: ",ValorNut[5],ValorNut[6]);
            printf("\n=> Tem aproxidamente %.2fg de Vitamina B6\n=> Tem aproxidamente %.2fg de Magn�sio: ",ValorNut[7],ValorNut[8]);
            printf("\n=> Tem aproxidamente %.2fg de C�lcio \n=> Tem aproxidamente %.2f IU Vitamina D: ",ValorNut[9],ValorNut[10]);
            printf("\n=> Tem aproxidamente %.2f IU Cobalamina: ",ValorNut[11]);
            printf("\n=> Tem aproxidamente %.2fmg de Colesterol: ",ValorNut[12]);

            /*Soma das Proteinas*/
            printf("\n\n# Resultado Total da quantidade de Prote�nas foram de %.2fg ",ValorNut[0]);
            if(ValorNut[0] > 60 && ValorNut[0] < 75)
                printf("\n# %s voc� est� consumindo %.2fg por dia, � o Ideal para se manter Saudavel.",nome,ValorNut[0]);
            if(ValorNut[0] < 60)
                printf("\n# %s Sinto muito informar que voc� est� consumindo pouca Prote�na pode dia! no total de %.2f\n� necess�rio consumir entre 60g e 75g de Prote�nas por dia.",nome,ValorNut[0]);
            if(ValorNut[0] > 75 )
                printf("\n# %s voc� est� consumindo %.2f por dia, Parab�ns!!! est� Ganhando Massa magra \ne assim vai ficar com um Corpo Estetico e Lindamente Sim�trico e Definido.",nome,ValorNut[0]);

            if(op != 0 )
            {
                printf("\n\nOp��o: Aperte 1 para Voltar ao MENU.\nOp��o: Digite Zero para sair: ");
                scanf("%d",&op);
                if(op == 1)
                {
                    printf("Voltando ao MENU");
                    Sleep(250);
                    printf(".");
                    Sleep(250);
                    printf(".");
                    Sleep(250);
                    printf(".");
                    Sleep(250);
                }
                /*Prote��o contra Usu�rio indevidos/inconvenientes*/
                if(op2 == gets(nome))
                    if(op >= 2 )
                    {
                        printf("Op��o Invalida!!! Boa tentativa!!! ");
                        Sleep(2000);
                    }
                if(op < 0)
                {
                    printf("Op��o Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!! ");
                    Sleep(2000);
                }
                if(op <= 0)
                {
                    printf("Saindo");
                    Sleep(250);
                    printf(".");
                    Sleep(250);
                    printf(".");
                    Sleep(250);
                    printf(".");
                    Sleep(250);
                }
                system("cls");

            }
            break;
        case 2:
            proteinaPorpeso();

            break;

        case 3:
            printf("\nOp��o: 3 - Calcular �ndice de Massa Corporal(IMC): ");
                printf("\n\nPor favor Informe seu nome: ");
                fflush(stdin);
                gets(nome);
                fflush(stdin);
                printf("< Por favor Informe seu peso atual (kg) > ");
                scanf("%f",&peso);
                printf("< Por favor Informe sua altura (metro e cm) Ex: 1,78 > ");
                scanf("%f",&alt);
                imc = peso/(alt*alt);
                if( imc > 18.05 && imc < 24.9)
                    printf("# %s voc� est� com IMC %.2f, Peso Ideal Parab�ns!!!\n",nome,imc);
                if( imc < 18.05)
                    printf("\n# %s voc� est� com IMC %.2f MAGREZA, e precisa se Alimentar melhor ",nome,imc);
                if( imc >= 25.0 && imc <= 29.99)
                    printf("# %s voc� est� com IMC %.2f Sobre Peso, com Circunfer�ncia Abdominal Larga \n",nome,imc);
                if( imc > 30.0 && imc < 39.0)
                    printf("\n# %s voc� est� com IMC %.2f OBESIDADE TIPO II,\ne continua com Circunfer�ncia Abdominal Larga",nome,imc);
                if( imc > 40.0)
                    printf("# %s voc� est� com IMC %.2f OBESIDADE GRAVE TIPO III,\ne precisa mudar sua Dieta e praticar Esporte ou Caminhada:\n",nome,imc);
                if(op != 0)
                {
                    printf("\n\nOp��o: Aperte 3 para Voltar ao MENU.\nOp��o: Digite Zero para sair: ");
                    scanf("%d",&op);
                    if(op == 3)
                    {
                        printf("Voltando ao MENU");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    /*Prote��o contra Usu�rio indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 3)
                        {
                            printf("Op��o Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Op��o Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
                        Sleep(2000);
                    }
                    if(op <= 0)
                    {
                        printf("Saindo");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    system("cls");
                }/*Fechamento do CASE*/

            break;

        case 5:
            printf("\nOp��o: 5 - Calcular a quantidade de calorias necess�rias por dia: ");
                printf("\n\nPor favor Informe seu nome: ");
                fflush(stdin);
                gets(nome);
                fflush(stdin);
                printf("< Por Favor Informe sua a sua Idade > ");
                fflush(stdin);
                scanf("%f",&idade);
                printf("< Por Favor Informe seu peso (kg) > ");
                fflush(stdin);
                scanf("%f",&peso);
                printf("< Por Favor Informe sua altura (metro e cm) Ex: 1,78 > ");
                scanf("%f",&alt);
                fflush(stdin);
                printf("\nPor Favor Informe se � Mulher ou Homem :\n<m> Para Mulher ou <h> Para Homem: ");
                fflush(stdin);
                scanf("%c",&resp);
                man = (13.75 * peso) + (5 * alt) - (6.75 * idade)+ 655;
                woman = (9.56 * peso) + (1.85 * alt) - (4.68 * idade)+ 655;
                if(resp == 'h')
                    printf("\n%s voc� precisa consumir %.2f  por dia para se manter saud�vel.",nome,man);
                else
                    printf("\n%s voc� precisa consumir %.2f por dia para se manter saud�vel.",nome,woman);
                /* } Fechando no lugar errado*/
                if(op != 0)
                {
                    printf("\n\nOp��o: Aperte 5 para Voltar ao MENU.\nOp��o: Digite Zero para sair: ");
                    scanf("%d",&op);
                    if(op == 5)
                    {
                        printf("Voltando ao MENU");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    /*Prote��o contra Usu�rio indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 5)
                        {
                            printf("Op��o Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Op��o Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
                        Sleep(2000);
                    }
                    if(op <= 0)
                    {
                        printf("Saindo");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    system("cls");
                }
            break;
        case 6:
            printf("\nOp��o: 6 - Calcular a quantidade de Calorias para obter o Peso desejado: \n ");
                printf("\n< Por Favor Informe sua a sua Idade > ");
                fflush(stdin);
                scanf("%f",&idade);
                printf("< Por Favor Informe o peso desajado que pretende obter (kg) > ");
                fflush(stdin);
                scanf("%f",&peso);
                printf("< Por Favor Informe sua altura (metro e cm) Ex: 1,78 > ");
                scanf("%f",&alt);
                fflush(stdin);
                printf("Por Favor Informe se � Mulher ou Homem :\n< M > Para Mulher ou < H > Para Homem: ");
                fflush(stdin);
                scanf("%c",&resp);
                /*40-50 kcal por kilograma de peso corporal,*/
                man = (peso * 40)+ 450;
                woman = (peso * 40)+ 450;
                carbo = man - 1950;
                p = (man * 0.15)+ 450;
                lip = man - 3262.5;
                /*15% de PROTE�NA = 562kcal  25% de LIP�DIOS = 937,5kcal*/
                if(resp == 'h' || resp == 'H')
                    printf("\nVoc� precisa consumir %.2fkcal  por dia para obter o peso desejado.\n60%% de Carboidratos = %.2fkcal\n15%% de Prote�na = %.2fkcal\n25%% de Lip�dios = %.2fkcal\n10%% de Gorduras Saturadas",man,carbo,p,lip);
                else
                    printf("\nVoc� precisa consumir %.2fkcal  por dia para obter o peso desejado.\n60%% de Carboidratos = %.2fkcal\n15%% de Prote�na = %.2fkcal\n25%% de Lip�dios = %.2fkcal\n10%% de Gorduras Saturadas",woman,carbo,p,lip);
                printf("\nAten��o - Foram adicionado 450kcal de Prote�naa para manter a sua Massa Magra. ");
                if(op != 0)
                {
                    printf("\n\nOp��o: Aperte 6 para Voltar ao MENU.\nOp��o: Digite Zero para sair: ");
                    scanf("%d",&op);
                    if(op == 6)
                    {
                        printf("Voltando ao MENU");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    /*Prote��o contra Usu�rio indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 6)
                        {
                            printf("Op��o Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Op��o Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
                        Sleep(2000);
                    }
                    if(op <= 0)
                    {
                        printf("Saindo");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    system("cls");
                }

            break;
        case 7:
            printf("\nOp��o: 7 - Calcular a quantidade de Calorias para perder Peso:\n ");
                printf("\n < Por Favor Informe sua a sua Idade > ");
                fflush(stdin);
                scanf("%f",&idade);
                printf("\n< Por Favor Informe sua altura (metro e cm) Ex: 1,78 > ");
                scanf("%f",&alt);
                printf("< Por Favor Informe seu peso para calcular a quantidade de Calorias que deve consumir por dia (kg) > ");
                fflush(stdin);
                scanf("%f",&peso);
                fflush(stdin);
                printf("\nPor Favor Informe se � Mulher ou Homem :\n< M > Para Mulher ou < H > Para Homem: ");
                fflush(stdin);
                scanf("%c",&resp);
                man = (13.75 * peso) + (5 * alt) - (6.75 * idade)+ (655 - 250);
                woman = (9.56 * peso) + (1.85 * alt) - (4.68 * idade)+ (655 - 250);
                carbo = man * 0.60;
                p = (man * 0.15) + 450;
                lip = man * 0.25;
                if(resp == 'h' || resp == 'H')
                    printf("\nVoc� precisa consumir %.2fkcal  por dia para perder o peso.\n60%% de Carboidratos = %.2fkcal\n15%% de Prote�na = %.2fkcal\n25%% de Lip�dios = %.2fkcal\n10%% de Gorduras Saturadas",man,carbo,p,lip);
                else
                    printf("\nVoc� precisa consumir %.2fkcal  por dia para perder o peso.\n60%% de Carboidratos = %.2fkcal\n15%% de Prote�na = %.2fkcal\n25%% de Lip�dios = %.2fkcal\n10%% de Gorduras Saturadas",woman,carbo,p,lip);
                printf("\nAten��o - Foram adicionado 450kcal de Prote�naa para manter a sua Massa Magra. ");
                if(op != 0)
                {
                    printf("\n\nOp��o: Aperte 7 para Voltar ao MENU.\nOp��o: Digite Zero para sair: ");
                    scanf("%d",&op);
                    if(op == 7)
                    {
                        printf("Voltando ao MENU");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    /*Prote��o contra Usu�rio indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 7)
                        {
                            printf("Op��o Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Op��o Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
                        Sleep(2000);
                    }
                    if(op <= 0)
                    {
                        printf("Saindo");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    system("cls");
                }

            break;
        case 8:
            printf("\nOp��o: 8 - Calcular a qt de calorias necess�rias por dia para manter o peso: ");
                printf("\n< Por Favor Informe sua a sua Idade > ");
                fflush(stdin);
                scanf("%f",&idade);
                printf("< Por Favor Informe seu peso atual (kg) > ");
                fflush(stdin);
                scanf("%f",&peso);
                printf("< Por Favor Informe sua altura (metro e cm) Ex: 1,78 > ");
                scanf("%f",&alt);
                fflush(stdin);
                printf("\nPor Favor Informe se � Mulher ou Homem :\n< M > Para Mulher ou < H > Para Homem: ");
                fflush(stdin);
                scanf("%c",&resp);
                /*Calculo para manter o peso desejado*/
                man = (13.75 * peso) + (5 * alt) - (6.75 * idade)+ 655;
                woman = (9.56 * peso) + (1.85 * alt) - (4.68 * idade)+ 655;
                carbo = man * 0.60;
                p = (man * 0.15) + 450;
                lip = man * 0.25;
                if(resp == 'h' || resp == 'H')
                    printf("\nVoc� precisa consumir %.2fkcal  por dia para manter o peso desejado.\n60%% de Carboidratos = %.2fkcal\n15%% de Prote�na = %.2fkcal\n25%% de Lip�dios = %.2fkcal\n10%% de Gorduras Saturadas",man,carbo,p,lip);
                else
                    printf("\nVoc� precisa consumir %.2fkcal  por dia para manter o peso desejado.\n60%% de Carboidratos = %.2fkcal\n15%% de Prote�na = %.2fkcal\n25%% de Lip�dios = %.2fkcal\n10%% de Gorduras Saturadas",woman,carbo,p,lip);
                printf("\nAten��o - Foram adicionado 450kcal de Prote�na para manter a sua Massa Magra. ");
                if(op != 0)
                {
                    printf("\n\nOp��o: Aperte 8 para Voltar ao MENU.\nOp��o: Digite Zero para sair: ");
                    scanf("%d",&op);
                    if(op == 8)
                    {
                        printf("Voltando ao MENU");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    /*Prote��o contra Usu�rio indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 8)
                        {
                            printf("Op��o Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Op��o Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
                        Sleep(2000);
                    }
                    if(op <= 0)
                    {
                        printf("Saindo");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    system("cls");
                }
            break;
            case 4:
            creatinaPorDia();
            break;

        default:
            /*Prote��o contra Usu�rio indevidos/inconvenientes*/
            if(op2 == gets(nome))
            {
            }
            if(op != 0 )
            {
                printf("Op��o Invalida Aperte Enter novamente para sair...");
            }else
                printf("Aberte Enter novamente para sair\n");
            return 0;
        }
    }while(op != 0);
}

void loading_cem()
{

 for( int x = 0; x < 10; x++){
        printf("\t\t\t\t\t\t Microsoft Windows 98 \n");
        printf("\t\t\t\t\t\t     Seja Bem Vindo");
        printf("\n\t\t\t\t\t\t    C");
        Sleep(50);
        printf("a");
        Sleep(50);
        printf("r");
        Sleep(50);
        printf("r");
        Sleep(50);
        printf("e");
        Sleep(50);
        printf("g");
        Sleep(50);
        printf("a");
        Sleep(50);
        printf("n");
        Sleep(50);
        printf("d");
        Sleep(50);
        printf("o");
        Sleep(50);
        printf(".");
        Sleep(75);
        printf(".");
        Sleep(75);
        printf(".");
        Sleep(75);
        printf("%d",(x+1)*10);
        Sleep(75);
        printf("%%");
        Sleep(75);
        system("cls");
        }

}
void creatinaPorDia()
{
                float peso;
                int op;
                char op2[10],nova;
                char nome[50];

                printf("\nOp��o: 4 - Calcular quantidade CREATINA por dia: ");
                do{
                printf("\n\n< Por Favor Informe seu peso atual (kg) > ");
                scanf("%f",&peso);
                peso *= 00.06;
                printf("\n ________________________________________________");
                printf("\n|____________Baseado no seu peso atual___________|");
                printf("\n\n A quantidade de CREATINA por dia � %.1fg: ",peso);

                printf("\n\nGostaria de Calcular novamente ? < s > and < n > ");
                fflush(stdin);
                scanf("%c",&nova);
                }while(nova == 's' || nova == 'S');

                if(op != 0)
                {
                    printf("\n\nOp��o: Aperte 4 para Voltar ao MENU.\nOp��o: Digite Zero para sair: ");
                    scanf("%d",&op);
                    if(op == 4)
                    {
                        printf("Voltando ao MENU");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    /*Prote��o contra Usu�rio indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 4)
                        {
                            printf("Op��o Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Op��o Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
                        Sleep(2000);
                    }
                    if(op <= 0)
                    {
                        printf("Saindo");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    system("cls");
                }

}
void proteinaPorpeso()
{

                float peso;
                int op;
                char op2[10],nova;
                char nome[50];

                printf("\nOp��o: 2 - Calcular quantidade Prote�na por Peso : ");
                do{
                printf("\n\n< Por Favor Informe seu peso atual (kg) > ");
                scanf("%f",&peso);
                peso *= 1.60;
                printf("\n ________________________________________________");
                printf("\n|____________Baseado no seu peso atual___________|");
                printf("\n\n A quantidade de Prote�na por dia � %.1fg: ",peso);

                printf("\n\nGostaria de Calcular novamente ? < s > and < n > ");
                fflush(stdin);
                scanf("%c",&nova);
                }while(nova == 's' || nova == 'S');

                if(op != 0)
                {
                    printf("\n\nOp��o: Aperte 2 para Voltar ao MENU.\nOp��o: Digite Zero para sair: ");
                    scanf("%d",&op);
                    if(op == 4)
                    {
                        printf("Voltando ao MENU");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    /*Prote��o contra Usu�rio indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 2)
                        {
                            printf("Op��o Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Op��o Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
                        Sleep(2000);
                    }
                    if(op <= 0)
                    {
                        printf("Saindo");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                        printf(".");
                        Sleep(250);
                    }
                    system("cls");


                }
}
