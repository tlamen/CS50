#include<stdio.h>
#include<cs50.h>
#include<string.h>

//declare functions
char maiuscula(char  a, char b);
char minuscula(char a, char b);

int main(int argc, string argv[]) {

    //check if key is valid 1

    int tamanho = strlen(argv[1]);

    if (tamanho != 26) {
        printf("Invalid key\n");
        return 0;
    }

   //check if key is valid 2

    for (int i = 0; i < tamanho; i++) {
        if ((argv[1][i] > 64 & argv[1][i] < 91) | (argv[1][i] > 96 & argv[1][i] < 123)) {}
        else {
            printf("invalid key\n");
            return 0;
        }
    }

    //get a plaintext

    string pt = get_string("plaintext: ");

    int ptlength = strlen(pt);

    //run through the pt string

    for (int i = 0; i < ptlength; i++) {

        //creating aux1iliar variable "aux1"

        char aux1 = pt[i];
        char aux2 = pt[i];

        //'A'
        if (pt[i] == 65) {
            aux2 = maiuscula(argv[1][0], aux1);
        }
        //'B'
        if (pt[i] == 66) {
            aux2 = maiuscula(argv[1][1], aux1);
        }
        //'C'
        if (pt[i] == 67) {
            aux2 = maiuscula(argv[1][2], aux1);
        }
        //'D'
        if (pt[i] == 68) {
            aux2 = maiuscula(argv[1][3], aux1);
        }
        //'E'
        if (pt[i] == 69) {
            aux2 = maiuscula(argv[1][4], aux1);
        }
        //'F'
        if (pt[i] == 70) {
            aux2 = maiuscula(argv[1][5], aux1);
        }
        //'G'
        if (pt[i] == 71) {
            aux2 = maiuscula(argv[1][6], aux1);
        }
        //'H'
        if (pt[i] == 72) {
            aux2 = maiuscula(argv[1][7], aux1);
        }
        //'I'
        if (pt[i] == 73) {
            aux2 = maiuscula(argv[1][8], aux1);
        }
        //'J'
        if (pt[i] == 74) {
            aux2 = maiuscula(argv[1][9], aux1);
        }
        //'K'
        if (pt[i] == 75) {
            aux2 = maiuscula(argv[1][10], aux1);
        }
        //'L'
        if (pt[i] == 76) {
            aux2 = maiuscula(argv[1][11], aux1);
        }
        //'M'
        if (pt[i] == 77) {
            aux2 = maiuscula(argv[1][12], aux1);
        }
        //'N'
        if (pt[i] == 78) {
            aux2 = maiuscula(argv[1][13], aux1);
        }
        //'O'
        if (pt[i] == 79) {
            aux2 = maiuscula(argv[1][14], aux1);
        }
        //'P'
        if (pt[i] == 80) {
            aux2 = maiuscula(argv[1][15], aux1);
        }
        //'Q'
        if (pt[i] == 81) {
            aux2 = maiuscula(argv[1][16], aux1);
        }
        //'R'
        if (pt[i] == 82) {
            aux2 = maiuscula(argv[1][17], aux1);
        }
        //'S'
        if (pt[i] == 83) {
            aux2 = maiuscula(argv[1][18], aux1);
        }
        //'T'
        if (pt[i] == 84) {
            aux2 = maiuscula(argv[1][19], aux1);
        }
        //'U'
        if (pt[i] == 85) {
            aux2 = maiuscula(argv[1][20], aux1);
        }
        //'V'
        if (pt[i] == 86) {
            aux2 = maiuscula(argv[1][21], aux1);
        }
        //'W'
        if (pt[i] == 87) {
            aux2 = maiuscula(argv[1][22], aux1);
        }
        //'X'
        if (pt[i] == 88) {
            aux2 = maiuscula(argv[1][23], aux1);
        }
        //'Y'
        if (pt[i] == 89) {
            aux2 = maiuscula(argv[1][24], aux1);
        }
        //'Z'
        if (pt[i] == 90) {
            aux2 = maiuscula(argv[1][25], aux1);
        }

        //'a'
        if (pt[i] == 97) {
            aux2 = minuscula(argv[1][0], aux1);
        }
        //'b'
        if (pt[i] == 98) {
            aux2 = minuscula(argv[1][1], aux1);
        }
        //'c'
        if (pt[i] == 99) {
            aux2 = minuscula(argv[1][2], aux1);
        }
        //'d'
        if (pt[i] == 100) {
            aux2 = minuscula(argv[1][3], aux1);
        }
        //'e'
        if (pt[i] == 101) {
            aux2 = minuscula(argv[1][4], aux1);
        }
        //'f'
        if (pt[i] == 102) {
            aux2 = minuscula(argv[1][5], aux1);
        }
        //'g'
        if (pt[i] == 103) {
            aux2 = minuscula(argv[1][6], aux1);
        }
        //'h'
        if (pt[i] == 104) {
            aux2 = minuscula(argv[1][7], aux1);
        }
        //'i'
        if (pt[i] == 105) {
            aux2 = minuscula(argv[1][8], aux1);
        }
        //'j'
        if (pt[i] == 106) {
            aux2 = minuscula(argv[1][9], aux1);
        }
        //'k'
        if (pt[i] == 107) {
            aux2 = minuscula(argv[1][10], aux1);
        }
        //'l'
        if (pt[i] == 108) {
            aux2 = minuscula(argv[1][11], aux1);
        }
        //'m'
        if (pt[i] == 109) {
            aux2 = minuscula(argv[1][12], aux1);
        }
        //'n'
        if (pt[i] == 110) {
            aux2 = minuscula(argv[1][13], aux1);
        }
        //'o'
        if (pt[i] == 111) {
            aux2 = minuscula(argv[1][14], aux1);
        }
        //'p'
        if (pt[i] == 112) {
            aux2 = minuscula(argv[1][15], aux1);
        }
        //'q'
        if (pt[i] == 113) {
            aux2 = minuscula(argv[1][16], aux1);
        }
        //'r'
        if (pt[i] == 114) {
            aux2 = minuscula(argv[1][17], aux1);
        }
        //'s'
        if (pt[i] == 115) {
            aux2 = minuscula(argv[1][18], aux1);
        }
        //'t'
        if (pt[i] == 116) {
            aux2 = minuscula(argv[1][19], aux1);
        }
        //'u'
        if (pt[i] == 117) {
            aux2 = minuscula(argv[1][20], aux1);
        }
        //'v'
        if (pt[i] == 118) {
            aux2 = minuscula(argv[1][21], aux1);
        }
        //'w'
        if (pt[i] == 119) {
            aux2 = minuscula(argv[1][22], aux1);
        }
        //'x'
        if (pt[i] == 120) {
            aux2 = minuscula(argv[1][23], aux1);
        }
        //'y'
        if (pt[i] == 121) {
            aux2 = minuscula(argv[1][24], aux1);
        }
        //'z'
        if (pt[i] == 122) {
            aux2 = minuscula(argv[1][25], aux1);
        }

        pt[i] = aux2;

        printf("%c", pt[i]);

    }

    printf("\n");

}

char maiuscula(char a, char b) {
    if (a > 64 & a < 91) {
        b = a;
        return b;
    }
    else {
        b = a - 32;
        return b;
    }
}

char minuscula(char a, char b) {
    if (a > 96 & a < 123) {
        b = a;
        return b;
    }
    else {
        b = a + 32;
        return b;
    }
}