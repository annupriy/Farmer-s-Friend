#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Crops suitable for given croptype and season.
void intersect1(int croptype_arr[], int season_arr[], int n, int m, char crops[][20])
{
  
   
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (season_arr[j] == croptype_arr[i]){
            printf("| %s | ",crops[season_arr[j]]); count++;}
        }
    }
    if(count==0){printf("Sorry\nThere is no suitable crop for the given parameters. Try again.");}
}

//Crops suitable for given croptype and soil type.
void intersect2(int croptype_arr[], int soil_arr[], int n, int m, char crops[][20])
{
   
   
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (soil_arr[j] == croptype_arr[i]){
            printf("| %s | ",crops[soil_arr[j]]);
            count++;}

        }
    }
    if(count==0){printf("Sorry\nThere is no suitable crop for the given parameters. Try again.");}
}

//Crops suitable for given season and soil type
void intersect3(int season_arr[], int soil_arr[], int n, int m, char crops[][20])
{
   
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (soil_arr[j] == season_arr[i]){
            printf("| %s | ",crops[soil_arr[j]]);
            count++;}
        }
    }
    if(count==0){printf("Sorry\nThere is no suitable crop for the given parameters. Try again.");}
}

//Crops suitable for given crop type, soil type and season
void intersection(int croptype_arr[], int season_arr[], int soil_arr[], int n, int m, int l, char crops[][20])
{  

    //Nested for loop for giving the best suitable output for the given conditions
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for(int k=0; k<l; k++){
                if(croptype_arr[i]==season_arr[j] && season_arr[j]==soil_arr[k] && soil_arr[k]==croptype_arr[i]){
                    count++;
                    printf("| %s | ",crops[soil_arr[k]]);
                }
            }
        }
    }
    
}

//A function declared which gives the count of the no. of crops that can grow taking the intersection of all farmer's preferences.
int intersection_count(int croptype_arr[], int season_arr[], int soil_arr[], int n, int m, int l)
{   
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for(int k=0; k<l; k++){
                if(croptype_arr[i]==season_arr[j] && season_arr[j]==soil_arr[k] && soil_arr[k]==croptype_arr[i]){
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    int crop_type, soil, season; // interaction variables used-crop_type,soil,season
    
    printf("\nWELCOME TO FARMER'S FRIEND\nWe are here to assist you in selecting the crops according to your availability and preference.\n\n");
    printf("Enter your preferred crop-type\n");
    printf("Enter 1 for cash crop | 2 for food_crop\n");
    scanf("%d", &crop_type);
    printf("\nEnter your preferred soil\n");
    printf("Enter 1 for clayey soil | 2 for loamy | 3 for red | 4 for black | 5 for clayey_loam | 6 for sandy_loam | 7 for alluvial | 8 for laterite\n");
    scanf("%d", &soil);
    printf("\nEnter your preferred season\n");
    printf("Enter 1 for kharif season | 2 for rabi | 3 for zaid\n");
    scanf("%d", &season);


    char crops[23][20]; // storage of crops name in an array named crops by taking its indexes as the reference for further coding
    strcpy(crops[0], "rice");
    strcpy(crops[1], "wheat");
    strcpy(crops[2], "tea");
    strcpy(crops[3], "sugarcane");
    strcpy(crops[4], "maize");
    strcpy(crops[5], "cotton");
    strcpy(crops[6], "tobacco-biddi");
    strcpy(crops[7], "tobacco-cheroot");
    strcpy(crops[8], "tobacco-FCV");
    strcpy(crops[9], "tobacco-hookah");
    strcpy(crops[10], "jute");
    strcpy(crops[11], "jowar");
    strcpy(crops[12], "rubber");
    strcpy(crops[13], "ragi");
    strcpy(crops[14], "bajra");
    strcpy(crops[15], "coffee");
    strcpy(crops[16], "mustard");
    strcpy(crops[17], "sunflower");
    strcpy(crops[18], "groundnut");
    strcpy(crops[19], "bengal gram");
    strcpy(crops[20], "arhar");
    strcpy(crops[21], "moong daal");
    strcpy(crops[22], "masoor");
  


    //Storage of croptypes using previous indexes
    int cash_crop[13] = {2, 3, 5, 6, 7, 8, 9, 10, 12, 15, 16, 17, 18}; // crop types storage variables used-cash
    int food_crop[10] = {0, 1, 4, 11, 13, 14, 19, 20, 21, 22};
    int croptype_arr[13];
    int sizecrop;
    //Running the program according to the user's choice of crop type 
    if (crop_type == 1)
    {
        sizecrop = 13;
        for (int i = 0; i < 13; i++)
        {
            croptype_arr[i] = cash_crop[i];
        }
    }
    else if (crop_type == 2)
    {
        sizecrop = 10;
        for (int i = 0; i < 10; i++)
        {
            croptype_arr[i] = food_crop[i];
        }
    }
    //Storage of crops according to their season of yield using previous indexes
    int kharif[15] = {0, 2, 3, 4, 5, 10, 11, 12, 13, 14, 15, 18, 19, 20, 21};
    int rabi[6] = {1, 7, 8, 16, 17, 22};
    int zaid[2] = {6, 9};

    //Running the program according to the user's choice of season
    int season_arr[15];
    int sizeseason;
    if (season == 1)
    {
        sizeseason = 15;
        for (int i = 0; i < 15; i++)
        {
            season_arr[i] = kharif[i];
        }
    }

    else if (season == 2)
    {
        sizeseason = 6;
        for (int i = 0; i < 6; i++)
        {
            season_arr[i] = rabi[i];
        }
    }

    else if (season == 3)
    {
        sizeseason = 2;
        for (int i = 0; i < 2; i++)
        {
            season_arr[i] = zaid[i];
        }
    }

    int cropseason;
    //Storage of crops according to the soil type, using previous indexes
    int clayey[3] = {0, 1, 17}; //"clayey | loamy | red | black | clayey_loam | sandy_loam | alluvial | laterite | red_volcanic\n"
    int loamy[3] = {12, 13, 22};
    int red[4] = {3, 7, 13, 15};
    int black[4] = {5, 6, 8, 14};
    int clayey_loam[6] = {1, 4, 5, 6, 18, 19};
    int sandy_loam[10] = {7, 9, 10, 11, 13, 15, 17, 18, 19, 21};
    int alluvial[4] = {3, 6, 9, 10};
    int laterite[1] = {2};
    int red_volcanic[2] = {3, 15};
    int soil_arr[10];
    int sizesoil;

    //Running the program according to the user's choice of soil type
    switch (soil)
    {
    case 1:
        sizesoil = 3;
        for (int i = 0; i < 3; i++)
        {
            soil_arr[i] = clayey[i];
        }
        break;
    case 2:
        sizesoil = 3;
        for (int i = 0; i < 3; i++)
        {
            soil_arr[i] = loamy[i];
        }
        break;
    case 3:
        sizesoil = 4;
        for (int i = 0; i < 4; i++)
        {
            soil_arr[i] = red[i];
        }
        break;
    case 4:
        sizesoil = 4;
        for (int i = 0; i < 4; i++)
        {
            soil_arr[i] = black[i];
        }
        break;
    case 5:
        sizesoil = 6;
        for (int i = 0; i < 6; i++)
        {
            soil_arr[i] = clayey_loam[i];
        }
        break;
    case 6:
        sizesoil = 10;
        for (int i = 0; i < 10; i++)
        {
            soil_arr[i] = sandy_loam[i];
        }
        break;
    case 7:
        sizesoil = 4;
        for (int i = 0; i < 4; i++)
        {
            soil_arr[i] = alluvial[i];
        }
        break;
    case 8:
        sizesoil = 1;
        for (int i = 0; i < 1; i++)
        {
            soil_arr[i] = laterite[i];
        }
        break;
    case 9:
        sizesoil = 2;
        for (int i = 0; i < 2; i++)
        {
            soil_arr[i] = red_volcanic[i];
        }
        break;
    default:
    {
        printf("Wrong soil type");
    }
    }

    int countint = intersection_count(croptype_arr, season_arr, soil_arr, sizecrop, sizeseason, sizesoil); 
    //Compromising a parameter to choose best compatible crop.
    if(countint==0){
        int type;
        printf("\nSorry!\nNo crop is compatible with the options you choosed. Hence we will like you to drop one condition and choose only 2 parameters.\nEnter 1 for crop type and season. Enter 2 for season and soil. Enter 3 for soil and crop type.\n");
        scanf("%d",&type);
        if(type==1){
             intersect1(croptype_arr, season_arr, sizecrop, sizeseason, crops);
        }
        if(type==2){
             intersect1(season_arr, soil_arr, sizeseason, sizesoil, crops);
        }
        if(type==3){
             intersect1(soil_arr, croptype_arr, sizesoil, sizecrop, crops );
        }
    }
    else {intersection(croptype_arr, season_arr, soil_arr, sizecrop, sizeseason, sizesoil, crops);}
}