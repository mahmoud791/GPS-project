#include "hashs.h"




sint8 coordinatesTime (uint8 *timeH,uint8 *timeM,uint8 *timeS,\
                       uint8 *latitudeD,uint16 *latitudeM,float32 *latitudeS,\
                       uint8 *longitudeD,uint16 *longitudeM,float32 *longitudeS )
{

    sint8 space [] = "\n\r";

    sint8 latitudeDStr [3];
    sint8 latitudeMStr [3];
    sint8 latitudeSStr [6];

    sint8 longitudeDStr[4];
    sint8 longitudeMStr[3];
    sint8 longitudeSStr[6];

    sint8 timeHStr [3];
    sint8 timeMStr [3];
    sint8 timeSStr [3];


    UART2_ReceiveData();

    UART2_ReceiveStr_len(2, timeHStr);
    if (timeHStr [0] ==','){
        return 2;

    }
    UART2_ReceiveStr_len(2, timeMStr);
    UART2_ReceiveStr_len(2, timeSStr);

    UART2_ReceiveData();
    UART2_ReceiveData();
    UART2_ReceiveData();
    UART2_ReceiveData();

    UART2_ReceiveStr_len(2, latitudeDStr);
    if (latitudeDStr [1] == ',')
    {
        return 2;
    }

    UART2_ReceiveStr_len(2, latitudeMStr);
    UART2_ReceiveData();
    UART2_ReceiveStr_SpecialChar(',', latitudeSStr);

    UART2_ReceiveData();
    UART2_ReceiveData();


    UART2_ReceiveStr_len(3, longitudeDStr);
    UART2_ReceiveStr_len(2, longitudeMStr);
    UART2_ReceiveData();
    UART2_ReceiveStr_SpecialChar(',', longitudeSStr);




    //    UART0_SendStr("LAT DEG = ");
    //    UART0_SendStr(latitudeDStr);
    //    UART0_SendStr(space);
    //    UART0_SendStr("LAT MIN = ");
    //    UART0_SendStr(latitudeMStr);
    //    UART0_SendStr(space);
    //    UART0_SendStr("LAT SEC = ");
    //    UART0_SendStr(latitudeSStr);
    //    UART0_SendStr(space);
    //
    //    UART0_SendStr("LONG DEG = ");
    //    UART0_SendStr(longitudeDStr);
    //    UART0_SendStr(space);
    //    UART0_SendStr("LONG MIN = ");
    //    UART0_SendStr(longitudeMStr);
    //    UART0_SendStr(space);
    //    UART0_SendStr("LONG SEC = ");
    //    UART0_SendStr(longitudeSStr);
    //    UART0_SendStr(space);

    *timeH = atoi(timeHStr);
    *timeM = atoi(timeMStr);
    *timeS = atoi(timeSStr);

    *latitudeD = atoi(latitudeDStr);
    *latitudeM = atoi(latitudeMStr);
    *latitudeS = atoi(latitudeSStr);
    *latitudeS = ((*latitudeS)*(60/(100000)));


    *longitudeD = atoi(longitudeDStr);
    *longitudeM = atoi(longitudeMStr);
    *longitudeS = atoi(longitudeSStr);
    *longitudeS = ((*longitudeS)*(60/(100000)));
    return 0;

}







int main (void){




    UART2_Init();
    UART0_Init();


    uint8 timeH_new = 0, timeM_new=0, timeS_new = 0;
    uint8 latitudeD_new = 0, longitudeD_new = 0;
    uint16 latitudeM_new= 0, longitudeM_new = 0;
    float32 latitudeS_new = 0, longitudeS_new = 0;


    sint8 GPGGA_checker [5];

    sint8 space[] = "\n\r";
    uint8 sign = 0;
    while (1)
    {
        if (UART2_ReceiveData() == '$')
        {
            UART2_ReceiveStr_len(5, GPGGA_checker);
            if(strcmp(GPGGA_checker,"GPGGA") == 0){
                sign =   coordinatesTime(&timeH_new,&timeM_new,&timeS_new,\
                                         &latitudeD_new,&latitudeM_new,&latitudeS_new,\
                                         &longitudeD_new,&longitudeM_new,&longitudeS_new);

                if (sign == 0)
                {
                    break;
                }

                UART0_SendStr("Stuck");
                UART0_SendStr(space);
            }
        }
    }


    while(1)
    {


        while (1)
        {
            if (UART2_ReceiveData() == '$')
            {
                UART2_ReceiveStr_len(5, GPGGA_checker);
                if(strcmp(GPGGA_checker,"GPGGA") == 0){
                    sign =   coordinatesTime(&timeH_new,&timeM_new,&timeS_new,\
                                             &latitudeD_new,&latitudeM_new,&latitudeS_new,\
                                             &longitudeD_new,&longitudeM_new,&longitudeS_new);

                    if (sign == 0)
                    {
                        break;
                    }

                    UART0_SendStr("Stuck");
                    UART0_SendStr(space);
                }
            }
        }
    }
}