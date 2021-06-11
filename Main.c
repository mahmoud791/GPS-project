#include "hashs.h"


#define PI 3.1415926535897932


float32 Decimal_LONG_LAT_CAL (uint8 degree,uint16 min,float32 second){

    return (float)degree + (float)min/60 + (float)second/3600;

}


float32 Distance_calc (float32 Long_new,float32 Lat_new,float32 Long_old,float32 Lat_old ){
    return       2 * 6371000 * asin(sqrt((sin((Lat_new*(PI/180)-Lat_old*(PI/180))/2))\
                                         * (sin((Lat_new * (PI/180)-Lat_old * (PI/180))/2)) + cos(Lat_new*(PI/180))\
                                         * cos(Lat_old * (PI/180)) * sin(((Long_new * (PI/180)-Long_old*(PI/180))/2))\
                                         * sin(((Long_new * (PI/180)-Long_old*(PI/180))/2))));

}

sint8 coordinatesTime (uint8 *latitudeD,uint16 *latitudeM,float32 *latitudeS,\
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

    UART0_SendStr("Hours = ");
    UART0_SendStr(timeHStr);
    UART0_SendStr(space);
    UART0_SendStr("Mins = ");
    UART0_SendStr(timeMStr);
    UART0_SendStr(space);
    UART0_SendStr("Secs = ");
    UART0_SendStr(timeSStr);
    UART0_SendStr(space);


    LCD_displayStringRowColumn(1, 5, timeHStr);
    LCD_displayStringRowColumn(1, 9, timeMStr);
    LCD_displayStringRowColumn(1, 13, timeSStr);

    *latitudeD = atoi(latitudeDStr);
    *latitudeM = atoi(latitudeMStr);
    *latitudeS = atoi(latitudeSStr);
    *latitudeS = ((*latitudeS)*((float)60/(100000)));


    *longitudeD = atoi(longitudeDStr);
    *longitudeM = atoi(longitudeMStr);
    *longitudeS = atoi(longitudeSStr);
    *longitudeS = ((*longitudeS)*((float)60/(100000)));
    return 0;

}




//int main()
//{
//
//    Ports_clk_init();
//    systick_init();
//    Ports_clk_init();
//    LCD_init();
//    Led_port_init();
//
//    systick_wait_sec(20);
//
//
//    LCD_displayStringRowColumn(0, 0, "LCD WORKS");
//    LCD_displayStringRowColumn(1, 0, "LCD STILL WORKS");
//
//
//    led_flash_distance(101);
//
//
//}









int main (void){

    system_init();


    LCD_displayStringRowColumn(0,0 ,"Distance = 000M" );
    LCD_displayStringRowColumn(1, 0, "Time 00H:00M:00S");

    uint8 flag = 0;

    uint8 latitudeD_new = 0, longitudeD_new = 0;
    uint16 latitudeM_new= 0, longitudeM_new = 0;
    float32 latitudeS_new = 0, longitudeS_new = 0;
    uint8 distance_buffer=0;
    uint8 i=0;

    float32 decimal_longitude_new = 0, decimal_longitude_old = 0,decimal_latitude_new = 0, decimal_latitude_old = 0;
    float32 distance = 0, total_distance = 0;
    //  float32 decimal_long_arr [55] = {0}, decimal_lat_arr[55] = {0};



    sint8 GPGGA_checker [5];

    sint8 space[] = "\n\r";
    uint8 sign = 0;
    while (1)
    {
        if (UART2_ReceiveData() == '$')
        {
            UART2_ReceiveStr_len(5, GPGGA_checker);
            if(strcmp(GPGGA_checker,"GPGGA") == 0){
                sign =   coordinatesTime(&latitudeD_new,&latitudeM_new,&latitudeS_new,\
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




        if (flag == 0)
        {
            decimal_longitude_old = decimal_longitude_new;
            decimal_latitude_old = decimal_latitude_new;
        }

        flag = 0;

        while (1)
        {
            if (UART2_ReceiveData() == '$')
            {
                UART2_ReceiveStr_len(5, GPGGA_checker);
                if(strcmp(GPGGA_checker,"GPGGA") == 0){
                    sign =   coordinatesTime(&latitudeD_new,&latitudeM_new,&latitudeS_new,\
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

        distance = Distance_calc(decimal_longitude_new, decimal_latitude_new, decimal_longitude_old, decimal_latitude_old);

        if(distance < 1){
            distance = 0;
            flag = 1;
            continue;
        }
        else {

            //        ltoa((long)distance, distance_str, 10);
            //
            //        LCD_displayStringRowColumn(0, 0, distance_str);
            //
            //        UART0_SendStr("Distance =");
            //        UART0_SendStr(distance_str);
            //        UART0_SendStr(space);


            distance_buffer += distance;
            total_distance += distance;
            led_flash_distance(total_distance);


            if(distance_buffer>=1)
            {
                distance_buffer = 0;
                //          decimal_lat_arr[i] = decimal_latitude_new;
                //        decimal_long_arr[i] = decimal_longitude_new;
                i++;

            }

            //
            //        UART0_SendStr("Total Distance = ");
            //        UART0_SendStr(distance_str);
            //        UART0_SendStr(space);

            if(total_distance <10){
                LCD_goToRowColumn(0, 13);
                LCD_intgerToStringDisplay(total_distance);
            }
            else if (total_distance <100){
                LCD_goToRowColumn(0, 12);
                LCD_intgerToStringDisplay(total_distance);
            }
            else
            {
                LCD_goToRowColumn(0, 11);
                LCD_intgerToStringDisplay(total_distance);
            }

        }


    }




}











//int main (void)
//{
//    Ports_clk_init();
//    PortsUart_clk_init();
//    UART0_Init();
//    UART2_Init();
//    while(1)
//    {
//    UART0_SendData(UART2_ReceiveData());
//    }
//}
