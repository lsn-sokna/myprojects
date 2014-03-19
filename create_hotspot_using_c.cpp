//this code was compile correctly by Borland C++ 5.02
//Coded by Sokna

#‎include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
int status;
void createHotspot(){
char ssid[32],key[32],command[100];
SSID:
clrscr();
printf("SSID: ");
gets(ssid);
if(strlen(ssid)<8){
printf("\nSSID must be more than 8 digits.");
getch();
goto SSID;
}else{
KEY:
printf("Key: ");
gets(key);
if(strlen(key)<8){
printf("\nKey must be more than 8 digits.");
getch();
clrscr();
printf("SSID: %s\n",ssid);
goto KEY;
}else{
strcpy(command,"netsh wlan set hostednetwork mode=allow ssid=");
strcat(command,ssid);
strcat(command," key=");
strcat(command,key);
status=1;
system(command);
}
}
}
void startHotspot(){
if(status==1){
system("netsh wlan start hostednetwork");
status=2;
}else if(status==0){
printf("\n\nHotspot hasn't been created yet. Please create Hotspot first!");
}
}
void stopHotspot(){
if(status==2){
system("netsh wlan stop hostednetwork");
status=3;
}else if(status==1){
printf("\nHotspot hasn't started yet.");
}else if(status==0){
printf("Please create Hotspot first!");
}
}
void resetHotspot(){
}
void main(){
do{
clrscr();
printf("1.Create Virtual Hotspot\n");
printf("2.Start Virtual Hotspot\n");
printf("3.Stop Virtual Hotspot\n");
printf("4.Exit\n");
switch(getch()){
case '1':createHotspot();break;
case '2':startHotspot();break;
case '3':stopHotspot();break;
}
}while(getch()!='4');
system("attrib config.ini +s +h");
}