#include <8051.h>

void main()
{
char mas [5][5] = {{'A','B','C','D','E'},{'F','G','H', 'I', 'J'},{'K', 'L', 'M', 'N', 'O'},{'P', 'Q', 'R','S', 'T'},{'U', 'V', 'W', 'X', 'Y'}};
char shift = '5';
unsigned char y[24];
unsigned char y1[24];
bool proverka = false;
int i = 0;
P0 = 0x38;
P2 = 0x1;
P2 = 0x0;
P0 = 0x80;
P2 = 0x1;
P2 = 0x0;

while (1)
{
P10=0;
if(P15 == 0){y[0]=1;} else{y[0]=0;} // Обработка клавиши, 1 - нажата, 0 - не нажата
if(P16 == 0){y[1]=1;} else{y[1]=0;}
if(P17 == 0){y[2]=1;} else{y[2]=0;}
if(P30 == 0){y[3]=1;} else{y[3]=0;}
if(P31 == 0){y[4]=1;} else{y[4]=0;}
P10=1;

P11=0;
if(P15 == 0){y[5]=1;} else{y[5]=0;}
if(P16 == 0){y[6]=1;} else{y[6]=0;}
if(P17 == 0){y[7]=1;} else{y[7]=0;}
if(P30 == 0){y[8]=1;} else{y[8]=0;}
if(P31 == 0){y[9]=1;} else{y[9]=0;}
P11=1;

P12=0;
if(P15 == 0){y[10]=1;} else{y[10]=0;}
if(P16 == 0){y[11]=1;} else{y[11]=0;}
if(P17 == 0){y[12]=1;} else{y[12]=0;}
if(P30 == 0){y[13]=1;} else{y[13]=0;}
if(P31 == 0){y[14]=1;} else{y[14]=0;}
P12=1;

P13=0;
if(P15 == 0){y[15]=1;} else{y[15]=0;}
if(P16 == 0){y[16]=1;} else{y[16]=0;}
if(P17 == 0){y[17]=1;} else{y[17]=0;}
if(P30 == 0){y[18]=1;} else{y[18]=0;}
if(P31 == 0){y[19]=1;} else{y[19]=0;}
P13=1;

P14=0;
if(P15 == 0){y[20]=1;} else{y[20]=0;}
if(P16 == 0){y[21]=1;} else{y[21]=0;}
if(P17 == 0){y[22]=1;} else{y[22]=0;}
if(P30 == 0){y[23]=1;} else{y[23]=0;}
if(P31 == 0){y[24]=1;} else{y[24]=0;} // обработка клавиши Shift
P14=1;

if (i == 0) // При первой итерации просто передаем символы в масcив y1
{
	for (int a=0;a<24;a++)
	{
		y1[a] = y[a];
	}
}
else // При следующих итерациях сравниваем символы, если они неизменны, то нет смысла трогать экран
{
	for (int a=0;a<=24;a++)
	{
		if (y1[a] == y[a]) {proverka = true;}
		else {proverka = false;}
	}
}

if (proverka == false)// Символ изменился  - очищаем экран
{
	P0 = 0x01; P2 = 0x1; P2 = 0x0;
	for (int a=0;a<24;a++)// Вывод данных на экран
	{
		if (y1[a] == 1) 
		{
			if(a == 0)
			{
				if (y1[24] == 1)// Если нажат Shift (Y) - выводим заготовленный символ (5)
				{
					P0 = shift; P2 = 0x3; P2 = 0x2;
				}
				else {P0 = mas[0][4]; P2 = 0x3; P2 = 0x2;}
			}
			if(a == 1){P0 = mas[0][3]; P2 = 0x3; P2 = 0x2;}
			if(a == 2){P0 = mas[0][2]; P2 = 0x3; P2 = 0x2;}
			if(a == 3){P0 = mas[0][1]; P2 = 0x3; P2 = 0x2;}
			if(a == 4){P0 = mas[0][0]; P2 = 0x3; P2 = 0x2;}
			if(a == 5){P0 = mas[1][4]; P2 = 0x3; P2 = 0x2;}
			if(a == 6){P0 = mas[1][3]; P2 = 0x3; P2 = 0x2;}
			if(a == 7){P0 = mas[1][2]; P2 = 0x3; P2 = 0x2;}
			if(a == 8){P0 = mas[1][1]; P2 = 0x3; P2 = 0x2;}
			if(a == 9){P0 = mas[1][0]; P2 = 0x3; P2 = 0x2;}
			if(a == 10){P0 = mas[2][4]; P2 = 0x3; P2 = 0x2;}
			if(a == 11){P0 = mas[2][3]; P2 = 0x3; P2 = 0x2;}
			if(a == 12){P0 = mas[2][2]; P2 = 0x3; P2 = 0x2;}
			if(a == 13){P0 = mas[2][1]; P2 = 0x3; P2 = 0x2;}
			if(a == 14){P0 = mas[2][0]; P2 = 0x3; P2 = 0x2;}
			if(a == 15){P0 = mas[3][4]; P2 = 0x3; P2 = 0x2;}
			if(a == 16){P0 = mas[3][3]; P2 = 0x3; P2 = 0x2;}
			if(a == 17){P0 = mas[3][2]; P2 = 0x3; P2 = 0x2;}
			if(a == 18){P0 = mas[3][1]; P2 = 0x3; P2 = 0x2;}
			if(a == 19){P0 = mas[3][0]; P2 = 0x3; P2 = 0x2;}
			if(a == 20){P0 = mas[4][4]; P2 = 0x3; P2 = 0x2;}
			if(a == 21){P0 = mas[4][3]; P2 = 0x3; P2 = 0x2;}
			if(a == 22){P0 = mas[4][2]; P2 = 0x3; P2 = 0x2;}
			if(a == 23){P0 = mas[4][1]; P2 = 0x3; P2 = 0x2;}
		}
	}
}
	


//P0 = 0x01;
//P2 = 0x1;
//P2 = 0x0;
i++;
}

}
