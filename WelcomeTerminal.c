#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*#include <unistd.h>
 * TODO : get the username automatically so that i can share this masterpiece with others or just get them with arguments
*/
int main(int argc, char *argv[]) {
    srand(time(0));

    char basepath[50];
    string homedir = getenv("HOME");
    string cmd = homedir + "WelcomeTerminal/greeting";

    strcpy(basepath, "/home/");
    strcat(basepath, argv[1]); 
    strcat(basepath, "/.WelcomeTerminal/arts/");
    
    char countpath[56]; strcpy(countpath, basepath); strcat(countpath, "count");

    /* Reads a char in ./arts/count to computer the number of available ascii patern*/
    FILE *fp; fp = fopen(countpath, "r");
    char c = fgetc(fp);
    fclose(fp);

    /*Choose a random number between 1 and the number read in ./arts/count; supports up to 9999 arts*/
    int selected = (rand() % (c - 31)) + 1;

    //printf("artc : %d\nselected : %d \n", artc, selected);

    /*Now display the greeting message.*/
    system(cmd.c_str());

    /*getting the good file for the art*/
    char buffer[5];
    sprintf(buffer, "%d", selected-1);


    char artfile[60];
    char artfilen[70];
    strcpy(artfile, basepath); 
    strcat(artfile, "/art_");
    strcat(artfile, buffer);

    strcpy(artfilen, artfile);
    strcat(artfilen, "_name");


    /*getting the art name*/
    fp = fopen(artfilen, "r");

    char artname[20] = "";

    char tmp[2] = {' ', '\0'};
    while((*tmp = fgetc(fp)) != '\n') {
        strcat(artname, tmp);
    }

    /*getting art color*/
    char color[3];
    fgets(color, 3, fp);
    fclose(fp);

    printf("Here's a \033[1m\033[4;%sm%s\033[0m to make you happy :3\n", color, artname);

    /*printing the art*/
    char cmd[60];
    printf("\033[%sm\n", color);
    sprintf(cmd, "cat %s", artfile);

    system(cmd);

    printf("\033[0m\n\n");

    return 0;
}
