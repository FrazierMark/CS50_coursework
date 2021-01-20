#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void)
{

    int camcorder_total_owned = get_int("Camcorder_Total_Owned: ");
    int camcorder_ready_for_in = get_int("Camcorder_Ready_For_Inspection: ");
    int camcorder_boss_un = get_int("Camcorder_Boss_Un: ");
    int camcorder_accs_un = get_int("Camcorder_Accs_Un: ");
    int camcorder_already_in = get_int("Camcorder_Already_In: ");
    int camcorder_boss_in = get_int("Camcorder_Boss_In: ");
    int camcorder_accs_in = get_int("Camcorder_Accs_In: ");
    int camcorder_awaiting_return = get_int("Camcorder_Awaiting_Return: ");
    int camcorder_return_this_day = get_int("Camcorder_Return_This_Day: ");
    int camcorder_ship_this_day = get_int("Camcorder_Ship_This_Day: ");
    int total_camcorder_in_house = camcorder_ready_for_in + camcorder_already_in;
    int total_camcorder_boss_in_house = camcorder_boss_in + camcorder_boss_un;
    int total_camcorder_accs_in_house = camcorder_accs_in + camcorder_accs_un;

    int audio_total_owned = get_int("Audio_Total_Owned: ");
    int audio_ready_for_in = get_int("Audio_Ready_For_Inspection: ");
    int audio_boss_un = get_int("Audio_Boss(_Un: ");
    int audio_accs_un = get_int("Audio_Accs_Un: ");
    int audio_already_in = get_int("Audio_Already_In: ");
    int audio_boss_in = get_int("Audio_Boss_In: ");
    int audio_accs_in = get_int("Audio_Accs_In: ");
    int audio_awaiting_return = get_int("Audio_Awaiting_Return: ");
    int audio_return_this_day = get_int("Audio_Return_This_Day: ");
    int audio_ship_this_day = get_int("Audio_Ship_This_Day: ");
    int total_audio_in_house = audio_ready_for_in + audio_already_in;
    int total_audio_boss_in_house = audio_boss_in + audio_boss_un;
    int total_audio_accs_in_house = audio_accs_in + audio_accs_un;

    int monitoring_total_owned = get_int("Monitoring_Total_Owned: ");
    int monitoring_ready_for_in = get_int("Monitoring_Ready_For_Inspection: ");
    int monitoring_boss_un = get_int("Monitoring_Boss_Un: ");
    int monitoring_accs_un = get_int("Monitoring_Accs_Un: ");
    int monitoring_already_in = get_int("Monitoring_Already_In: ");
    int monitoring_boss_in = get_int("Monitoring_Boss_In: ");
    int monitoring_accs_in = get_int("Monitoring_Accs_In: ");
    int monitoring_awaiting_return = get_int("Monitoring_Awaiting_Return: ");
    int monitoring_return_this_day = get_int("Monitoring_Return_This_Day: ");
    int monitoring_ship_this_day = get_int("Monitoring_Ship_This_Day: ");
    int total_monitoring_in_house = monitoring_ready_for_in + monitoring_already_in;
    int total_monitoring_boss_in_house = monitoring_boss_in + monitoring_boss_un;
    int total_monitoring_accs_in_house = monitoring_accs_in + monitoring_accs_un;


    float percent_camcorder_un = (camcorder_ready_for_in / (float) total_camcorder_in_house) * 100;
    printf("%.2f%%\n", percent_camcorder_un);

    float percent_camcorder_boss_un = (camcorder_boss_un / (float) total_camcorder_boss_in_house) * 100;
    printf("%.2f%%\n", percent_camcorder_boss_un);

    float percent_camcorder_accs_un = (camcorder_accs_un / (float) total_camcorder_accs_in_house) * 100;
    printf("%.2f%%\n", percent_camcorder_accs_un);

    float percent_camcorder_awaiting_return = (camcorder_awaiting_return / (float) camcorder_total_owned) * 100;
    printf("%.2f%%\n", percent_camcorder_awaiting_return);

    float percent_camcorder_return_this_day = (camcorder_return_this_day / (float) camcorder_total_owned) * 100;
    printf("%.2f%%\n", percent_camcorder_return_this_day);

    float percent_camcorder_ship_this_day = (camcorder_ship_this_day / (float) total_camcorder_in_house) * 100;
    printf("%.2f%%\n", percent_camcorder_ship_this_day);

    float camcorder_movement = (percent_camcorder_un + percent_camcorder_boss_un + percent_camcorder_accs_un +
                        percent_camcorder_awaiting_return + percent_camcorder_return_this_day + percent_camcorder_ship_this_day ) / 6;
    printf("%.2f%% Camcorder Movement\n", camcorder_movement);




    float percent_audio_un = (audio_ready_for_in / (float) total_audio_in_house) * 100;
    printf("%.2f%%\n", percent_audio_un);

    float percent_audio_boss_un = (audio_boss_un / (float) total_audio_boss_in_house) * 100;
    printf("%.2f%%\n", percent_audio_boss_un);

    float percent_audio_accs_un = (audio_accs_un / (float) total_audio_accs_in_house) * 100;
    printf("%.2f%%\n", percent_audio_accs_un);

    float percent_audio_awaiting_return = (audio_awaiting_return / (float) audio_total_owned) * 100;
    printf("%.2f%%\n", percent_audio_awaiting_return);

    float percent_audio_return_this_day = (audio_return_this_day / (float) audio_total_owned) * 100;
    printf("%.2f%%\n", percent_audio_return_this_day);

    float percent_audio_ship_this_day = (audio_ship_this_day / (float) total_audio_in_house) * 100;
    printf("%.2f%%\n", percent_audio_ship_this_day);

    float audio_movement = (percent_audio_un + percent_audio_boss_un + percent_audio_accs_un +
                        percent_audio_awaiting_return + percent_audio_return_this_day + percent_audio_ship_this_day ) / 6;
    printf("%.2f%% \"Audio Movement\"\n", audio_movement);




    float percent_monitoring_un = (monitoring_ready_for_in / (float) total_monitoring_in_house) * 100;
    printf("%.2f%%\n", percent_monitoring_un);

    float percent_monitoring_boss_un = (monitoring_boss_un / (float) total_monitoring_boss_in_house) * 100;
    printf("%.2f%%\n", percent_monitoring_boss_un);

    float percent_monitoring_accs_un = (monitoring_accs_un / (float) total_monitoring_accs_in_house) * 100;
    printf("%.2f%%\n", percent_monitoring_accs_un);

    float percent_monitoring_awaiting_return = (monitoring_awaiting_return / (float) monitoring_total_owned) * 100;
    printf("%.2f%%\n", percent_monitoring_awaiting_return);

    float percent_monitoring_return_this_day = (monitoring_return_this_day / (float) monitoring_total_owned) * 100;
    printf("%.2f%%\n", percent_monitoring_return_this_day);

    float percent_monitoring_ship_this_day = (monitoring_ship_this_day / (float) total_monitoring_in_house) * 100;
    printf("%.2f%%\n", percent_monitoring_ship_this_day);

    float monitoring_movement = (percent_monitoring_un + percent_monitoring_boss_un + percent_monitoring_accs_un +
                        percent_monitoring_awaiting_return + percent_monitoring_return_this_day + percent_monitoring_ship_this_day ) / 6;
    printf("%.2f%% Monitoring Movement\n", monitoring_movement);



    if (camcorder_movement > audio_movement && camcorder_movement > monitoring_movement)
    printf("%.2f%% Camcorder Movement: Priority 1\n", camcorder_movement);

    else if (camcorder_movement > audio_movement && camcorder_movement < monitoring_movement)
    printf("%.2f%% Camcorder Movement: Priority 2\n", camcorder_movement);

    else if (camcorder_movement < audio_movement && camcorder_movement > monitoring_movement)
    printf("%.2f%% Camcorder Movement: Priority 2\n", camcorder_movement);

    else
    printf("%.2f%% Camcorder Movement: Priority 3\n", camcorder_movement);




    if (audio_movement > camcorder_movement && audio_movement > monitoring_movement)
    printf("%.2f%% Audio Movement: Priority 1\n", audio_movement);

    else if (audio_movement > camcorder_movement && audio_movement < monitoring_movement)
    printf("%.2f%% Audio Movement: Priority 2\n", audio_movement);

    else if (audio_movement < camcorder_movement && audio_movement > monitoring_movement)
    printf("%.2f%% Audio Movement: Priority 2\n", audio_movement);

    else
    printf("%.2f%% Audio Movement: Priority 3\n", audio_movement);



    if (monitoring_movement > camcorder_movement && monitoring_movement > audio_movement)
    printf("%.2f%% Monitoring Movement: Priority 1\n", monitoring_movement);

    else if (monitoring_movement > camcorder_movement && monitoring_movement < audio_movement)
    printf("%.2f%% Monitoring Movement: Priority 2\n", monitoring_movement);

    else if (monitoring_movement < camcorder_movement && monitoring_movement > audio_movement)
    printf("%.2f%% Monitoring Movement: Priority 2\n", monitoring_movement);

    else
    printf("%.2f%% Monitoring Movement: Priority 3\n", monitoring_movement);


//Save these ints in an array (maybe typdef struct:)

//Search array and increment Priority level

//print 3, 2, 1, array

}