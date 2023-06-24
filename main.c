/********************************************************************************************
 * Descripcion: El programa genera muestra el funcionamiento de varias funciones adicionadas
 *              en la libreria Nokia5110
 * Coneccion:   ADC-PD0 (marron), RST-PA7 (blanco), CE-PA3 (gris), DC-PA6 (morado),
 *              DIN-PA5 (azul), CLK-PA2 (rojo), VCC-3.3V (rojo), GND-GND (negro)
 * Autor :      Valentin Sarmiento
********************************************************************************************/

#include <stdint.h>
#include "POT.h"
#include "TivaES.h"
#include "tm4c123gh6pm.h"
#include "Nokia5110.h"
#include "bitmapPhotos.h"


int main(void) {
    //unsigned char* frames[] = {R_02, R_02, R_02, R_02, R_02, R_02, R_02, R_02, R_02, BACKGROUND};
    //unsigned char* frames[] = {nave ,nave ,nave ,nave ,nave ,nave ,nave ,nave ,nave ,BACKGROUND};
    unsigned char* Nave[] = {nave,vidas, enemigo, cursor, lvl1, lvl2, lvl3, gameover};
    Nokia5110_Init();
    Nokia5110_Clear();
    TivaES_Inicializa();
    POT_InicializaPD0();
    //cursor x & y
    int xc=23;
    int yc=5, yc1=5, yc2=19, yc3=33;
    int h;
    while(1){
        //Funcion inicio de juego
        while(1){
            Nokia5110_DrawFullImage((char*)invaders_logo);
            //Musica de juego

            if(TivaES_EsperaPulsadores() == 1 || TivaES_EsperaPulsadores() == 2){
                clearBuffer();
                break;
            }
        }

        //Funcion seleccionar nivel
        while(1){
            //Nokia5110_DrawFullImage((char*)niveles);
            //x = 23 && Y = (5,19,33)
            drawBitmap(xc, yc, Nave[3],3,3);
            drawBitmap(29, 5, Nave[4],22,22);
            drawBitmap(29, 19, Nave[5],23,23);
            drawBitmap(29, 33, Nave[6],24,24);
            if(TivaES_LeePulsador(SW1) == PRESIONADO && yc==yc1){
                yc= yc3;
            }
            else if(TivaES_LeePulsador(SW1) == PRESIONADO && yc==yc3){
                yc= yc2;
            }
            else if(TivaES_LeePulsador(SW1) == PRESIONADO && yc==yc2){
                yc= yc1;
            }
            else if(TivaES_LeePulsador(SW2) == PRESIONADO && yc==yc1){
                yc= yc2;
            }
            else if(TivaES_LeePulsador(SW2) == PRESIONADO && yc==yc2){
                yc= yc3;
            }
            else if(TivaES_LeePulsador(SW2) == PRESIONADO && yc==yc3){
                yc= yc1;
            }

            copyToScreen();
            clearBuffer();
            for(h=0; h<300000; h++){}

            if(TivaES_LeePulsador(SW1) == PRESIONADO && TivaES_LeePulsador(SW2) == PRESIONADO){
                break;
            }
        }

        //lvl1
        if(yc==yc1){
            EyN_mov(Nave,7,3,42,40,120);
        }
        //lvl2
        else if(yc==yc2){
            EyN_mov(Nave,7,3,42,40,60);
        }
        //lvl3
        else if(yc==yc3){
            EyN_mov(Nave,7,3,42,40,15);
        }

        while(1){
            drawBitmap(0, 0, Nave[7],504,504);
            copyToScreen();
            clearBuffer();
        }

        //EyN_mov(Nave,7,3,42,40,120);
    }

  // return 0;
} // fin de main




