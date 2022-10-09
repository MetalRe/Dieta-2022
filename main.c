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
            "Sódio", "mg",{0.82,0.57,0.61,0.14,65.70}
        },
        {
            "Potássio", "mg",{2.23,4.21,3.84,0.95,63.0}
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
            "Magnésio", "mg",{0.23,0.29,0.30,0.0,5.0}
        },
        {
            "Cálcio", "mg",{0.15,0.06,0.15,0.795,25.0}
        },
        {
            "Vitamina D ", "IU",{0.02,0.10,0.0,0.0065,43.5}
        },
        {
            "Cobalamina", "µg",{0.003,0.006,0.028,0.00295,0.55}
        },
        {
            "Colesterol", "mg",{0.88,0.73,0.63,0.003,186.5}
        },
        {
            "Carboidratos", "mg",{0.0319,02.7}
        },
    };
    setlocale(LC_ALL,"Portuguese");
    /*USE O GITHUB É EXCELENTE*/
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
        printf("\n\t\t\t:**************************Informação Nutricional*************************: ");
        printf("\n\t\t\t:***********************************MENU**********************************: ");
        printf("\n\n\t\t\t\t    1 - Informação Nutricional - Frango, Carne e Peixe: ");
        printf("\n\t\t\t\t     \t2 - |_Calcular quantidade Proteína por peso:_|");
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
        printf("\n\t\t\t 8 - |_Calcular a qt de calorias necessárias por dia para manter o peso:_|");
        printf("\n\t\t\t     \t\t\t 0 - Digite zero para Sair: \n");
        printf("\n\t\t\t\t\t\t   => Escolha uma opção: ");
        scanf("%d",&op);
        system("cls");
        switch(op)
        {
        case 1:
            printf("\nOpção: 1 - Informação Nutricional :");
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
                printf("\n# %s você está com IMC %.2f, Peso Ideal Parabêns!!!\n",nome,imc);
            if( imc < 18.05)
                printf("\n# %s você está com IMC %.2f MAGREZA, e precisa se Alimentar melhor ",nome,imc);
            if( imc >= 25.0 && imc <= 29.99)
                printf("# %s você está com IMC %.2f Sobre Peso, e está com Circunferência Abdominal Larga \n",nome,imc);
            if( imc > 30.0 && imc < 39.0)
                printf("\n# %s você está com IMC %.2f OBESIDADE TIPO II,\ne continua com Circunferência Abdominal Larga",nome,imc);
            if( imc > 40.0)
                printf("# %s você está com IMC %.2f OBESIDADE GRAVE TIPO III,\ne precisa mudar sua Dieta e praticar Esporte ou Caminhada:\n",nome,imc);

            /*Calcular o quantide de proteina e vitaminas, carne, frango e peixe*/
            /*Colocar na ordem , , ; - <, <, <; - ++, ++, ++(no final não precisa de ; */
            do
            {

                /*1 Opção Dentro do MENU*/
                printf("\nPor favor informe o alimento que quer calcular: ");
                printf("\nDigite:   \n( 1 ) Para Frango\n( 2 ) Para Carne\n( 3 ) Para Peixe\n( 0 ) Para sair:\n");
                printf("Escolha: ");
                scanf("%d",&escolha);
                switch(escolha)
                {
                case 1 :
                    //system("cls");
                    printf("\n=> Informação Nutricional - Proteína de Frango: ");
                    printf("\n# Digite quantas gramas você comeu de frango: ");
                    scanf("%f",&valor);

                    for(int x = 0; x < 13; x++)
                    {
                        printf("\n=> %s %.1f%s ", ali[x].nome, valor * ali[x].mult[0], ali[x].uni);
                        /*Lista das Somas de cada aminoácidos e protéinas*/
                        ValorNut[x] += valor * ali[x].mult[0];
                    }
                    break;
                /*2 Opção Dentro do MENU*/
                case 2:
                    system("cls");
                    printf("\n=> Informação Nutricional - Proteína da Carne: ");
                    printf("\n# Digite quantas gramas você comeu de Carne: ");
                    scanf("%f",&valor);
                    for(int x = 0; x < 13; x++)
                    {
                        printf("\n=> %s %.1f%s ", ali[x].nome, valor * ali[x].mult[1], ali[x].uni);
                        /*Lista das Somas de cada aminoácidos e protéinas*/
                        ValorNut[x] += valor * ali[x].mult[0];
                    }
                    break;

                /*3 Opção Dentro do MENU*/
                case 3:
                    system("cls");
                    printf("\n=> Informação Nutricional - Proteína do Peixe: ");
                    printf("\n# Digite quantas gramas você comeu de Peixe: ");
                    scanf("%f",&valor);
                    for(int x = 0; x < 13; x++)
                    {
                        printf("\n=> %s %.1f%s ", ali[x].nome, valor * ali[x].mult[2], ali[x].uni);
                        /*Lista das Somas de cada aminoácidos e protéinas*/
                        ValorNut[x] += valor * ali[x].mult[0];
                    }
                    break;
                }

                //final do for
            }
            while(escolha != 0 );

            /*Impresão da somas*/
            printf("\n\nLista Soma Total de Aminoácidos, Vitaminas e Proteínas. \n=> Foi de aproxidamente %.1fg de Proteína ",ValorNut[0]);
            printf("\n=> Tem aproxidamente %.2fg de Gorduras \n=> Tem aproxidamente %.2fg Calorias: ",ValorNut[1],ValorNut[2]);
            printf("\n=> Tem aproxidamente %.2fg de Sódio\n=> Tem aproxidamente %.2fg de Potássio: ",ValorNut[3],ValorNut[4]);
            printf("\n=> Tem aproxidamente %.2fg de Vitamina C\n=> Tem aproxidamente %.2fg de Ferro: ",ValorNut[5],ValorNut[6]);
            printf("\n=> Tem aproxidamente %.2fg de Vitamina B6\n=> Tem aproxidamente %.2fg de Magnésio: ",ValorNut[7],ValorNut[8]);
            printf("\n=> Tem aproxidamente %.2fg de Cálcio \n=> Tem aproxidamente %.2f IU Vitamina D: ",ValorNut[9],ValorNut[10]);
            printf("\n=> Tem aproxidamente %.2f IU Cobalamina: ",ValorNut[11]);
            printf("\n=> Tem aproxidamente %.2fmg de Colesterol: ",ValorNut[12]);

            /*Soma das Proteinas*/
            printf("\n\n# Resultado Total da quantidade de Proteínas foram de %.2fg ",ValorNut[0]);
            if(ValorNut[0] > 60 && ValorNut[0] < 75)
                printf("\n# %s você está consumindo %.2fg por dia, é o Ideal para se manter Saudavel.",nome,ValorNut[0]);
            if(ValorNut[0] < 60)
                printf("\n# %s Sinto muito informar que você está consumindo pouca Proteína pode dia! no total de %.2f\nÉ necessário consumir entre 60g e 75g de Proteínas por dia.",nome,ValorNut[0]);
            if(ValorNut[0] > 75 )
                printf("\n# %s você está consumindo %.2f por dia, Parabêns!!! está Ganhando Massa magra \ne assim vai ficar com um Corpo Estetico e Lindamente Simétrico e Definido.",nome,ValorNut[0]);

            if(op != 0 )
            {
                printf("\n\nOpção: Aperte 1 para Voltar ao MENU.\nOpção: Digite Zero para sair: ");
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
                /*Proteção contra Usuário indevidos/inconvenientes*/
                if(op2 == gets(nome))
                    if(op >= 2 )
                    {
                        printf("Opção Invalida!!! Boa tentativa!!! ");
                        Sleep(2000);
                    }
                if(op < 0)
                {
                    printf("Opção Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!! ");
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
            printf("\nOpção: 3 - Calcular Índice de Massa Corporal(IMC): ");
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
                    printf("# %s você está com IMC %.2f, Peso Ideal Parabêns!!!\n",nome,imc);
                if( imc < 18.05)
                    printf("\n# %s você está com IMC %.2f MAGREZA, e precisa se Alimentar melhor ",nome,imc);
                if( imc >= 25.0 && imc <= 29.99)
                    printf("# %s você está com IMC %.2f Sobre Peso, com Circunferência Abdominal Larga \n",nome,imc);
                if( imc > 30.0 && imc < 39.0)
                    printf("\n# %s você está com IMC %.2f OBESIDADE TIPO II,\ne continua com Circunferência Abdominal Larga",nome,imc);
                if( imc > 40.0)
                    printf("# %s você está com IMC %.2f OBESIDADE GRAVE TIPO III,\ne precisa mudar sua Dieta e praticar Esporte ou Caminhada:\n",nome,imc);
                if(op != 0)
                {
                    printf("\n\nOpção: Aperte 3 para Voltar ao MENU.\nOpção: Digite Zero para sair: ");
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
                    /*Proteção contra Usuário indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 3)
                        {
                            printf("Opção Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Opção Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
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
            printf("\nOpção: 5 - Calcular a quantidade de calorias necessárias por dia: ");
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
                printf("\nPor Favor Informe se é Mulher ou Homem :\n<m> Para Mulher ou <h> Para Homem: ");
                fflush(stdin);
                scanf("%c",&resp);
                man = (13.75 * peso) + (5 * alt) - (6.75 * idade)+ 655;
                woman = (9.56 * peso) + (1.85 * alt) - (4.68 * idade)+ 655;
                if(resp == 'h')
                    printf("\n%s você precisa consumir %.2f  por dia para se manter saudável.",nome,man);
                else
                    printf("\n%s você precisa consumir %.2f por dia para se manter saudável.",nome,woman);
                /* } Fechando no lugar errado*/
                if(op != 0)
                {
                    printf("\n\nOpção: Aperte 5 para Voltar ao MENU.\nOpção: Digite Zero para sair: ");
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
                    /*Proteção contra Usuário indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 5)
                        {
                            printf("Opção Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Opção Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
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
            printf("\nOpção: 6 - Calcular a quantidade de Calorias para obter o Peso desejado: \n ");
                printf("\n< Por Favor Informe sua a sua Idade > ");
                fflush(stdin);
                scanf("%f",&idade);
                printf("< Por Favor Informe o peso desajado que pretende obter (kg) > ");
                fflush(stdin);
                scanf("%f",&peso);
                printf("< Por Favor Informe sua altura (metro e cm) Ex: 1,78 > ");
                scanf("%f",&alt);
                fflush(stdin);
                printf("Por Favor Informe se é Mulher ou Homem :\n< M > Para Mulher ou < H > Para Homem: ");
                fflush(stdin);
                scanf("%c",&resp);
                /*40-50 kcal por kilograma de peso corporal,*/
                man = (peso * 40)+ 450;
                woman = (peso * 40)+ 450;
                carbo = man - 1950;
                p = (man * 0.15)+ 450;
                lip = man - 3262.5;
                /*15% de PROTEÍNA = 562kcal  25% de LIPÍDIOS = 937,5kcal*/
                if(resp == 'h' || resp == 'H')
                    printf("\nVocê precisa consumir %.2fkcal  por dia para obter o peso desejado.\n60%% de Carboidratos = %.2fkcal\n15%% de Proteína = %.2fkcal\n25%% de Lipídios = %.2fkcal\n10%% de Gorduras Saturadas",man,carbo,p,lip);
                else
                    printf("\nVocê precisa consumir %.2fkcal  por dia para obter o peso desejado.\n60%% de Carboidratos = %.2fkcal\n15%% de Proteína = %.2fkcal\n25%% de Lipídios = %.2fkcal\n10%% de Gorduras Saturadas",woman,carbo,p,lip);
                printf("\nAtenção - Foram adicionado 450kcal de Proteínaa para manter a sua Massa Magra. ");
                if(op != 0)
                {
                    printf("\n\nOpção: Aperte 6 para Voltar ao MENU.\nOpção: Digite Zero para sair: ");
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
                    /*Proteção contra Usuário indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 6)
                        {
                            printf("Opção Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Opção Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
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
            printf("\nOpção: 7 - Calcular a quantidade de Calorias para perder Peso:\n ");
                printf("\n < Por Favor Informe sua a sua Idade > ");
                fflush(stdin);
                scanf("%f",&idade);
                printf("\n< Por Favor Informe sua altura (metro e cm) Ex: 1,78 > ");
                scanf("%f",&alt);
                printf("< Por Favor Informe seu peso para calcular a quantidade de Calorias que deve consumir por dia (kg) > ");
                fflush(stdin);
                scanf("%f",&peso);
                fflush(stdin);
                printf("\nPor Favor Informe se é Mulher ou Homem :\n< M > Para Mulher ou < H > Para Homem: ");
                fflush(stdin);
                scanf("%c",&resp);
                man = (13.75 * peso) + (5 * alt) - (6.75 * idade)+ (655 - 250);
                woman = (9.56 * peso) + (1.85 * alt) - (4.68 * idade)+ (655 - 250);
                carbo = man * 0.60;
                p = (man * 0.15) + 450;
                lip = man * 0.25;
                if(resp == 'h' || resp == 'H')
                    printf("\nVocê precisa consumir %.2fkcal  por dia para perder o peso.\n60%% de Carboidratos = %.2fkcal\n15%% de Proteína = %.2fkcal\n25%% de Lipídios = %.2fkcal\n10%% de Gorduras Saturadas",man,carbo,p,lip);
                else
                    printf("\nVocê precisa consumir %.2fkcal  por dia para perder o peso.\n60%% de Carboidratos = %.2fkcal\n15%% de Proteína = %.2fkcal\n25%% de Lipídios = %.2fkcal\n10%% de Gorduras Saturadas",woman,carbo,p,lip);
                printf("\nAtenção - Foram adicionado 450kcal de Proteínaa para manter a sua Massa Magra. ");
                if(op != 0)
                {
                    printf("\n\nOpção: Aperte 7 para Voltar ao MENU.\nOpção: Digite Zero para sair: ");
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
                    /*Proteção contra Usuário indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 7)
                        {
                            printf("Opção Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Opção Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
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
            printf("\nOpção: 8 - Calcular a qt de calorias necessárias por dia para manter o peso: ");
                printf("\n< Por Favor Informe sua a sua Idade > ");
                fflush(stdin);
                scanf("%f",&idade);
                printf("< Por Favor Informe seu peso atual (kg) > ");
                fflush(stdin);
                scanf("%f",&peso);
                printf("< Por Favor Informe sua altura (metro e cm) Ex: 1,78 > ");
                scanf("%f",&alt);
                fflush(stdin);
                printf("\nPor Favor Informe se é Mulher ou Homem :\n< M > Para Mulher ou < H > Para Homem: ");
                fflush(stdin);
                scanf("%c",&resp);
                /*Calculo para manter o peso desejado*/
                man = (13.75 * peso) + (5 * alt) - (6.75 * idade)+ 655;
                woman = (9.56 * peso) + (1.85 * alt) - (4.68 * idade)+ 655;
                carbo = man * 0.60;
                p = (man * 0.15) + 450;
                lip = man * 0.25;
                if(resp == 'h' || resp == 'H')
                    printf("\nVocê precisa consumir %.2fkcal  por dia para manter o peso desejado.\n60%% de Carboidratos = %.2fkcal\n15%% de Proteína = %.2fkcal\n25%% de Lipídios = %.2fkcal\n10%% de Gorduras Saturadas",man,carbo,p,lip);
                else
                    printf("\nVocê precisa consumir %.2fkcal  por dia para manter o peso desejado.\n60%% de Carboidratos = %.2fkcal\n15%% de Proteína = %.2fkcal\n25%% de Lipídios = %.2fkcal\n10%% de Gorduras Saturadas",woman,carbo,p,lip);
                printf("\nAtenção - Foram adicionado 450kcal de Proteína para manter a sua Massa Magra. ");
                if(op != 0)
                {
                    printf("\n\nOpção: Aperte 8 para Voltar ao MENU.\nOpção: Digite Zero para sair: ");
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
                    /*Proteção contra Usuário indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 8)
                        {
                            printf("Opção Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Opção Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
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
            /*Proteção contra Usuário indevidos/inconvenientes*/
            if(op2 == gets(nome))
            {
            }
            if(op != 0 )
            {
                printf("Opção Invalida Aperte Enter novamente para sair...");
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

                printf("\nOpção: 4 - Calcular quantidade CREATINA por dia: ");
                do{
                printf("\n\n< Por Favor Informe seu peso atual (kg) > ");
                scanf("%f",&peso);
                peso *= 00.06;
                printf("\n ________________________________________________");
                printf("\n|____________Baseado no seu peso atual___________|");
                printf("\n\n A quantidade de CREATINA por dia é %.1fg: ",peso);

                printf("\n\nGostaria de Calcular novamente ? < s > and < n > ");
                fflush(stdin);
                scanf("%c",&nova);
                }while(nova == 's' || nova == 'S');

                if(op != 0)
                {
                    printf("\n\nOpção: Aperte 4 para Voltar ao MENU.\nOpção: Digite Zero para sair: ");
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
                    /*Proteção contra Usuário indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 4)
                        {
                            printf("Opção Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Opção Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
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

                printf("\nOpção: 2 - Calcular quantidade Proteína por Peso : ");
                do{
                printf("\n\n< Por Favor Informe seu peso atual (kg) > ");
                scanf("%f",&peso);
                peso *= 1.60;
                printf("\n ________________________________________________");
                printf("\n|____________Baseado no seu peso atual___________|");
                printf("\n\n A quantidade de Proteína por dia é %.1fg: ",peso);

                printf("\n\nGostaria de Calcular novamente ? < s > and < n > ");
                fflush(stdin);
                scanf("%c",&nova);
                }while(nova == 's' || nova == 'S');

                if(op != 0)
                {
                    printf("\n\nOpção: Aperte 2 para Voltar ao MENU.\nOpção: Digite Zero para sair: ");
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
                    /*Proteção contra Usuário indevidos/inconvenientes*/
                    if(op2 == gets(nome))
                        if(op >= 2)
                        {
                            printf("Opção Invalida!!! Boa tentativa!!! ");
                            Sleep(2000);
                        }
                    if(op < 0)
                    {
                        printf("Opção Invalida!!! Digitou errado Denovo? Boa sorte na proxima.!!!  ");
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
