#include "hashs.h"


#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286



float32 Decimal_LONG_LAT_CAL (uint8 degree,uint16 min,float32 second){

    return (float)degree + (float)min/60 + (float)second/3600;

}


float32 Distance_calc (float32 Long_new,float32 Lat_new,float32 Long_old,float32 Lat_old ){
    return       2 * 6371000 * asin(sqrt((sin((Lat_new*(PI/180)-Lat_old*(PI/180))/2))\
                                             * (sin((Lat_new * (PI/180)-Lat_old * (PI/180))/2)) + cos(Lat_new*(PI/180))\
                                             * cos(Lat_old * (PI/180)) * sin(((Long_new * (PI/180)-Long_old*(PI/180))/2))\
                                             * sin(((Long_new * (PI/180)-Long_old*(PI/180))/2))));

}


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
    uint8 distance_buffer=0;
    uint8 i=0;

    float32 decimal_longitude_new = 0, decimal_longitude_old = 0,decimal_latitude_new = 0, decimal_latitude_old = 0;
    float32 distance = 0, total_distance = 0;

   

    sint8 distance_str[10];


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

    decimal_longitude_new = Decimal_LONG_LAT_CAL(longitudeD_new, longitudeM_new, longitudeS_new);
    decimal_latitude_new = Decimal_LONG_LAT_CAL(latitudeD_new, latitudeM_new, latitudeS_new);

    while(1)
    {



        decimal_longitude_old = decimal_longitude_new;
        decimal_latitude_old = decimal_latitude_new;

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

        decimal_longitude_new = Decimal_LONG_LAT_CAL(longitudeD_new, longitudeM_new, longitudeS_new);
        decimal_latitude_new = Decimal_LONG_LAT_CAL(latitudeD_new, latitudeM_new, latitudeS_new);



        distance =    Distance_calc(decimal_longitude_new, decimal_latitude_new, decimal_longitude_old, decimal_latitude_old);

        ltoa((long)distance, distance_str, 10);



        distance_buffer += distance;
        total_distance += distance;


        if(distance_buffer>=2)
        {
            distance_buffer = 0;
            i++;

        }

        ltoa(total_distance, distance_str, 10);


        UART0_SendStr(distance_str);

    }




}

