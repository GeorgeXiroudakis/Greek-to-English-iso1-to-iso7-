#include <stdio.h>

enum state{S1, S2, S3};

void initialize(int numTable[255][3], enum state (*StateFunctions[3])(int c, int numTable[255][3], int first_of_dif8ogos));
void initializeNumTable(int numTable[255][3]);
void initializeStateFunctions(enum state (*StateFunctions[3])(int c, int numTable[255][3], int first_of_dif8ogos));

void handleChar(int c, int numTable[255][3]);

enum state fun1(int c, int numTable[255][3], int first_of_dif8ogos);
enum state fun2(int c, int numTable[255][3], int first_of_dif8ogos);
enum state fun3(int c, int numTable[255][3], int first_of_dif8ogos);


int main(void){

    int numTable[255][3] = {0};
    enum state (*StateFunctions[3])(int c, int numTable[255][3], int first_of_dif8ogos);
    enum state currentState = S1;
    int c = ' ';
    int first_of_dif8ogos = ' ';

    initialize(numTable, StateFunctions);
    
    c = getchar();
    while(c != EOF){
        
        currentState = StateFunctions[currentState](c, numTable, first_of_dif8ogos);
        
        if(currentState == S2){first_of_dif8ogos = c;}

        c = getchar();
    }

    return 0;
}


void initialize(int numTable[255][3], enum state (*StateFunctions[3])(int c, int numTable[255][3], int first_of_dif8ogos)){

    initializeNumTable(numTable);

    initializeStateFunctions(StateFunctions);
}


void initializeNumTable(int numTable[255][3]){
    /*capital standard letters*/
    numTable[193][0] = 'A';
    numTable[194][0] = 'V';
    numTable[195][0] = 'G';
    numTable[196][0] = 'D';
    numTable[197][0] = 'E';
    numTable[198][0] = 'Z';
    numTable[199][0] = 'H';
    numTable[200][0] = '8';
    numTable[201][0] = 'I';
    numTable[202][0] = 'K';
    numTable[203][0] = 'L';
    numTable[204][0] = 'M';
    numTable[205][0] = 'N';

    numTable[206][0] = 'K';
    numTable[206][1] = 'S';

    numTable[207][0] = 'O';
    numTable[208][0] = 'P';
    numTable[209][0] = 'R';
    numTable[211][0] = 'S';
    numTable[212][0] = 'T';
    numTable[213][0] = 'Y';
    numTable[214][0] = 'F';
    numTable[215][0] = 'X';

    numTable[216][0] = 'P';
    numTable[216][1] = 'S';

    numTable[217][0] = 'W';

    /*lower case standard letters*/
    numTable[225][0] = 'a';
    numTable[226][0] = 'v';
    numTable[227][0] = 'g';
    numTable[228][0] = 'd';
    numTable[229][0] = 'e';
    numTable[230][0] = 'z';
    numTable[231][0] = 'h';
    numTable[232][0] = '8';
    numTable[233][0] = 'i';
    numTable[234][0] = 'k';
    numTable[235][0] = 'l';
    numTable[236][0] = 'm';
    numTable[237][0] = 'n';

    numTable[238][0] = 'k';
    numTable[238][1] = 's';

    numTable[239][0] = 'o';
    numTable[240][0] = 'p';
    numTable[241][0] = 'r';
    numTable[242][0] = 's';
    numTable[243][0] = 's';
    numTable[244][0] = 't';
    numTable[245][0] = 'y';
    numTable[246][0] = 'f';
    numTable[247][0] = 'x';

    numTable[248][0] = 'p';
    numTable[248][1] = 's';

    numTable[249][0] = 'w';

    /*capitals with accent*/
    numTable[182][0] = '\'';
    numTable[182][1] = 'A';

    numTable[184][0] = '\'';
    numTable[184][1] = 'E';

    numTable[185][0] = '\'';
    numTable[185][1] = 'H';

    numTable[186][0] = '\'';
    numTable[186][1] = 'I';

    numTable[188][0] = '\'';
    numTable[188][1] = 'O';

    numTable[190][0] = '\'';
    numTable[190][1] = 'Y';

    numTable[191][0] = '\'';
    numTable[191][1] = 'W';

    /*lower case with accent*/
    numTable[220][0] = 'a';
    numTable[220][1] = '\'';

    numTable[221][0] = 'e';
    numTable[221][1] = '\'';

    numTable[222][0] = 'h';
    numTable[222][1] = '\'';

    numTable[223][0] = 'i';
    numTable[223][1] = '\'';

    numTable[252][0] = 'o';
    numTable[252][1] = '\'';

    numTable[254][0] = 'w';
    numTable[254][1] = '\'';

    numTable[253][0] = 'y';
    numTable[253][1] = '\'';

    /*capital with diaeresis*/
    numTable[218][0] = 'I';
    numTable[218][1] = '\"';

    numTable[219][0] = 'Y';
    numTable[219][1] = '\"';

    /*lower case with diaeresis*/
    numTable[250][0] = 'i';
    numTable[250][1] = '\"';

    numTable[251][0] = 'y';
    numTable[251][1] = '\"';

    /*lower case with diaeresis and accent*/
    numTable[192][0] = 'i';
    numTable[192][1] = '\'';
    numTable[192][2] = '\"';

    numTable[224][0] = 'u';
    numTable[224][1] = '\'';
    numTable[224][2] = '\"';
}


void initializeStateFunctions(enum state (*StateFunctions[3])(int c, int numTable[255][3], int first_of_dif8ogos)){
    StateFunctions[S1] = fun1;
    StateFunctions[S2] = fun2;
    StateFunctions[S3] = fun3;
}


void handleChar(int c, int numTable[255][3]){
    if(c >= 182){
            putchar(numTable[c][0]);
            putchar(numTable[c][1]);
            putchar(numTable[c][2]);
        }else{
            putchar(c);
        }
}


enum state fun1(int c, int numTable[255][3], int first_of_dif8ogos){

    /*if it can't be the begining of mp or nt print it normally and stay(return) the same state(S1)*/
    if(c != 204 && c != 236 && c != 205 && c != 237){
        handleChar(c, numTable);
        return S1;
    }else{
        /*if a mp or nt is possible we print nothing and move to the next state(S2)*/
        return S2;
    }
}

enum state fun2(int c, int numTable[255][3], int first_of_dif8ogos){
    int toPrint;

	/*if we are in state 2 we have the first of a possible mp or nt
    so if we next fave the according p or t we conjoint the and print the char it produces
    and then we go to state 3*/
    if( ( (first_of_dif8ogos == 204 || first_of_dif8ogos == 236) && (c == 208 || c == 240) ) ||
        ( (first_of_dif8ogos == 205 || first_of_dif8ogos == 237) && (c == 212 || c == 244) ) 
        ){
        if(first_of_dif8ogos == 204)toPrint = 'B';
        if(first_of_dif8ogos == 236)toPrint = 'b';
        if(first_of_dif8ogos == 205)toPrint = 'D';
        if(first_of_dif8ogos == 237)toPrint = 'd';

        handleChar(toPrint, numTable);
        return S3;

	/*we we again get one of the first char of mp or nt then we  print the privious(first_of_dif8ogos) and we stay at state two
	and print the previous char*/
    }else if( ( (first_of_dif8ogos == 204 || first_of_dif8ogos == 236) && (c == 204 || c == 236) ) ||
             ( (first_of_dif8ogos == 205 || first_of_dif8ogos == 237) && (c == 205 || c == 237) )
      ){
        handleChar(first_of_dif8ogos, numTable);
        return S2;

	/*else if is not the correnct second char or not one that can be the firts char of a dif8ogkos
    we print the previous we saved and the current and return to state S1*/
      }else{
        handleChar(first_of_dif8ogos, numTable);
        handleChar(c, numTable);
        return S1;
      }

    return 0;
}

enum state fun3(int c, int numTable[255][3], int first_of_dif8ogos){
	/*if we are in S3 we just print a b or d so if we get anothe m or n we go to S2*/
    if( ( (first_of_dif8ogos == 204 || first_of_dif8ogos == 236) && (c == 204 || c == 236) ) ||
        ( (first_of_dif8ogos == 205 || first_of_dif8ogos == 237) && (c == 205 || c == 237) )
      ){
        return S2;
      }
	/*else we have nothing again so return to S1*/
    handleChar(c, numTable);
    return S1;
}

