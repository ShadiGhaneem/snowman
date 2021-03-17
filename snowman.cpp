
#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <array>

const int ten=10, four=4,two=2,three=3,zero=0,one =1,eight=8;

void checkthesnowmanum(int num){
    int subnum=num;
    int count=zero;
    while (subnum>zero)
    {
        count++;
        subnum=subnum/ten;
    }
    if(count != eight){
        throw std::out_of_range("the num length should be 8 \n");
    }
    subnum=num;
    while (subnum>zero)
    {
        int x=subnum%ten;
        if(x<one || x>four){
            throw std::out_of_range("each diget must be betwen 1 and 4 \n");
        }  
        subnum=subnum/ten; 
    }
}

string builthat(int h){
    if(h==one)
    {
        return "_===_";
    }
    if(h==two)
    {
        return " ___\n .....";
    }
    if(h==three)
    {
        return "  _\n  /_\\";
    }
    if(h==four)
    {
        return " ___\n (_*_)";
    }
    return "";
}

string bulitnose(int n){
    if(n==one){
        return ",";
    }
    if(n==two){
        return ".";
    }
    if(n==three){
        return "_";
    }
    if(n==four){
        return " ";
    }
    return "";
}

string builtlefteye(int e){
    if(e==one){
        return  ".";
    }
    if(e==two){
        return "o";
    }
    if(e==three){
        return "O";
    }
    if(e==four){
        return "-";
    }
    return "";
}

string bulitrighteye(int e){
    if(e==one){
        return  ".";
    }
    if(e==two){
        return "o";
    }
    if(e==three){
        return "O";
    }
    if(e==four){
        return "-";
    }
    return "";
}

string bulitleftarm(int a)
{
    if(a==one){
        return "<";
    }
    if(a==two){
        return "\\";
    }
    if(a==three)
    {
        return "/";
    }
    if(a==four)
    {
        return " ";
    }
    return "";
}

string bulitrightarm(int a)
{
    if(a==one){
        return ">";
    }
    if(a==two){
        return "/";
    }
    if(a==three)
    {
        return "\\";
    }
    if(a==four)
    {
        return " ";
    }
    return "";
}

string builttorso(int t)
{
    if(t==one){
        return " : ";
    }
    if(t==two){
        return "] [";
    }
    if(t==three){
        return "> <";
    }
    if(t==four){
        return "   ";
    }
    return "";
}

string bultbase(int b){
    if(b==one){
        return " : ";
    }
    if(b==two){
        return "\" \"";
    }
    if(b==three){
        return "___";
    }
    if(b==four){
        return "   ";
    }
    return "";
}

int swapnumber(int num){
    int swapnum=zero;
    while(num>zero){
        swapnum=swapnum*ten+num%ten;
        num=num/ten;
    }
    return swapnum;
}

string bultsnowman(int num){
    string theman;
    int number=zero;
    number=swapnumber(num);
    int hat=number%ten;
    int number1=number/ten;
    theman=builthat(hat)+'\n';
    int nose=number1%ten;
    int number2=number1/ten;
    int le=number2%ten;
    int number3=number2/ten;
    int re=number3%ten;
    int number4=number3/ten;
    int leftarm=number4%ten;
    int number5=number4/ten;
    int rightarm=number5%ten;
    int number6=number5/ten;
    int torso=number6%ten;
    int number7=number6/ten;
    if(leftarm==two&&rightarm!=two)
    {
         theman=theman+"\\"+"("+builtlefteye(le)+bulitnose(nose)+bulitrighteye(re)+")"+'\n';
         theman=theman+"("+builttorso(torso)+")"+bulitrightarm(rightarm)+'\n';
    }
    else if(leftarm!=two&&rightarm==two){
        theman=theman+"("+builtlefteye(le)+bulitnose(nose)+bulitrighteye(re)+")"+"/"+'\n';
        theman=theman+bulitleftarm(leftarm)+"("+builttorso(torso)+")"+'\n';
    }
    else if(leftarm==two&&rightarm==two){
        theman=theman+"\\"+"("+builtlefteye(le)+bulitnose(nose)+bulitrighteye(re)+")"+"/"+'\n';
        theman=theman+"("+builttorso(torso)+")"+'\n';
    }
    else
    {
        theman=theman+"("+builtlefteye(le)+bulitnose(nose)+bulitrighteye(re)+")"+'\n';
        theman=theman+bulitleftarm(leftarm)+"("+builttorso(torso)+")"+bulitrightarm(rightarm)+'\n';
    }
    int base=number7%ten;
    theman=theman+"("+bultbase(base)+")";
    return theman;

}

namespace ariel {

    string snowman(int str){      

        checkthesnowmanum(str);
        return bultsnowman(str);

    }
}