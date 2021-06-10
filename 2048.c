#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define N 5

int cell[N][N];

void set_cell(int a[N][N]){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            a[i][j] = 0;
        }
    }

}

void print_board(int cell[N][N]) {
    char ans[N][N];

    printf("+-----------------------------------------------+\r\n|\t\t\t\t\t\t|\r\n");
    
    for(int i = 0; i < N; i++){
        printf("|\t");
        for(int j = 0; j < N; j++){
            if(cell[i][j] == 0){
                ans[i][j] = '-';
                printf("\x1b[39m%c\t\x1b[m", ans[i][j]);
            }
            else if(cell[i][j] == 2){
                printf("\x1b[36m%d\t\x1b[m", cell[i][j]);
            }
            else if(cell[i][j] == 4){
                printf("\x1b[36m%d\t\x1b[m", cell[i][j]);
            }
            else if(cell[i][j] == 8){
                printf("\x1b[36m%d\t\x1b[m", cell[i][j]);
            }
            else if(cell[i][j] == 16){
                printf("\x1b[35m%d\t\x1b[m", cell[i][j]);
            }
            else if(cell[i][j] == 32){
                printf("\x1b[35m%d\t\x1b[m", cell[i][j]);
            }
            else if(cell[i][j] == 64){
                printf("\x1b[35m%d\t\x1b[m", cell[i][j]);
            }
            else if(cell[i][j] == 128){
                printf("\x1b[33m%d\t\x1b[m", cell[i][j]);
            }
            else if(cell[i][j] == 256){
                printf("\x1b[33m%d\t\x1b[m", cell[i][j]);
            }
            else if(cell[i][j] == 512){
                printf("\x1b[33m%d\t\x1b[m", cell[i][j]);
            }
            else if(cell[i][j] == 1024){
                printf("\x1b[32m%d\t\x1b[m", cell[i][j]);
            }
            else if(cell[i][j] == 2048){
                printf("\x1b[31m%d\t\x1b[m", cell[i][j]);
            }
            else{
                printf("\x1b[39m%d\t\x1b[m", cell[i][j]);
            }
            
        }
        printf("|\r\n");
        printf("|\t\t\t\t\t\t|\r\n");
    }

    printf("+-----------------------------------------------+\r\n");
    
}

void congrats(){

    for(int i = 0; i < 3; i++){
        system("clear");
        printf("+-----------------------------------------------+\r\n");
        printf("|    *                                      *   |\r\n");
        printf("|   *                                        *  |\r\n");
        printf("|         ####    ####        #      ####       |\r\n");
        printf("|        #    #  #    #      # #    #    #      |\r\n");
        printf("|        #   #   #    #     #  #    #    #      |\r\n");
        printf("|           #    #    #    #   #      ###       |\r\n");
        printf("|          #     #    #   #######   #     #     |\r\n");
        printf("|         #      #    #	       #    #     #     |\r\n");
        printf("|        ######   ####         #     #####      |\r\n");
        printf("|   *                                        *  |\r\n");
        printf("|    *	                                    *   |\r\n");
        printf("+-----------------------------------------------+\r\n");

        sleep(1);
        system("clear");

        printf("+-----------------------------------------------+\r\n");
        printf("|  *                                         *  |\r\n");
        printf("|   *                                       *   |\r\n");
        printf("|         ####    ####        #      ####       |\r\n");
        printf("|        #    #  #    #      # #    #    #      |\r\n");
        printf("|        #   #   #    #     #  #    #    #      |\r\n");
        printf("|           #    #    #    #   #      ###       |\r\n");
        printf("|          #     #    #   #######   #     #     |\r\n");
        printf("|         #      #    #	       #    #     #     |\r\n");
        printf("|        ######   ####         #     #####      |\r\n");
        printf("|   *                                       *   |\r\n");
        printf("|  *                                         *  |\r\n");
        printf("+-----------------------------------------------+\r\n");

        sleep(1);


    }
    system("clear");

}

void print_gameover(){
    system("clear");
    printf("+-----------------------------------------------+\r\n");
    printf("|     #####       ##      #      #   ######     |\r\n");
    printf("|    #           #  #     # #   # #  #          |\r\n");
    printf("|    #   ###    ######    #   #   #  #####      |\r\n");
    printf("|    #     #   #      #   #       #  #          |\r\n");
    printf("|     #####   #        #  #       #  ######     |\r\n");
    printf("|                                               |\r\n");
    printf("|     #####   #        #   ######   #####       |\r\n");
    printf("|    #     #   #      #    #        #    #      |\r\n");
    printf("|    #     #    #    #     #####    #####       |\r\n");
    printf("|    #	   #     #  #      #        #    #      |\r\n");
    printf("|     #####       ##       ######   #     #     |\r\n");
    printf("+-----------------------------------------------+\r\n");

    sleep(3);
    system("clear");
}

void move_right(int a[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = (N - 1); j >= 0; j--){
            if((cell[i][j + 1] == 0) && (cell[i][j] != 0)){
                for(int k = j; k < (N - 1); k++){
                    if(cell[i][k + 1] == 0){
                        cell[i][k + 1] = cell[i][k];
                        cell[i][k] = 0;
                    }
                        
                }
            }
        }
    }
}

void move_left(int a[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 1; j < N; j++){
            if((cell[i][j - 1] == 0) && (cell[i][j] != 0)){
                for(int k = j; k > 0; k--){
                    if(cell[i][k - 1] == 0){
                        cell[i][k - 1] = cell[i][k];
                        cell[i][k] = 0;  
                    }
                }
            }
        }
    }

}

void move_up(int a[N][N]){
    for(int j = 0; j < N; j++){
        for(int i = 1; i < N; i++){
            if((cell[i - 1][j] == 0) && (cell[i][j] != 0)){
                for(int k = i; k > 0; k--){
                    if(cell[k - 1][j] == 0){
                        cell[k - 1][j] = cell[k][j];
                        cell[k][j] = 0;   
                    }
                }
            }
        }
    }
}
void move_down(int a[N][N]){
    for(int j = 0; j < N; j++){
        for(int i = (N - 1); i >= 0; i--){
            if((cell[i + 1][j] == 0) && (cell[i][j] != 0)){
                for(int k = i; k < (N - 1); k++){
                    if(cell[k + 1][j] == 0){
                        cell[k + 1][j] = cell[k][j];
                        cell[k][j] = 0;
                    }
                }
            }
        }
    }
}

void add_right(int cell[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = (N - 1); j > 0; j--){
            if(cell[i][j] == cell[i][j - 1]){
                cell[i][j] = 2 * cell[i][j];
                cell[i][j - 1] = 0;
                j -= 1;
            }
        }
    }
}

void add_left(int cell[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < (N - 1); j++){
            if(cell[i][j] == cell[i][j + 1]){
                cell[i][j] = 2 * cell[i][j];
                cell[i][j + 1] = 0;
                j += 1;
            }
        }
    }
}

void add_up(int cell[N][N]){
    for(int j = 0; j < N; j++){
        for(int i = 0; i < (N - 1); i++){
            if(cell[i][j] == cell[i + 1][j]){
                cell[i][j] = 2 * cell[i][j];
                cell[i + 1][j] = 0;
                i += 1;
            }
        }
    }
}

void add_down(int cell[N][N]){
    for(int j = 0; j < N; j++){
        for(int i = (N - 1); i > 0; i--){
            if(cell[i][j] == cell[i - 1][j]){
                cell[i][j] = 2 * cell[i][j];
                cell[i - 1][j] = 0;
                i -= 1;
            }
        }
    }
}

void generate_number(int cell[N][N]){
    int gen;
    int flag = 0;

    int a;
    int b;

    a = rand() % 5;
    b = rand() % 5;

    if(rand() % 2 == 0){
        gen = 2;
    }
    else{
        gen = 4;
    }

    if(cell[a][b] == 0){
        cell[a][b] = gen;
        flag = 1;
    }
    else{
        for(int j = b; j < N; j++){
            for(int i = a; i < N; i++){
                if((cell[i][j] == 0) && (flag == 0)){
                    cell[i][j] = gen;
                    flag = 1;
                }
            }
        }

        for(int j = b; j < N; j++){
            for(int i = 0; i < a; i++){
                if((cell[i][j] == 0) && (flag == 0)){
                    cell[i][j] = gen;
                    flag = 1;
                }
            }
        }

        for(int j = 0; j < b; j++){
            for(int i = 0; i < a; i++){
                if((cell[i][j] == 0) && (flag == 0)){
                    cell[i][j] = gen;
                    flag = 1;
                }
            } 
        }

        for(int j = 0; j < b; j++){
            for(int i = a; i < N; i++){
                if((cell[i][j] == 0) && (flag == 0)){
                    cell[i][j] = gen;
                    flag = 1;
                }
            } 
        }
    }

}

void copy_cell(int cell[N][N], int copy[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            copy[i][j] = cell[i][j];
        }
    }
}

int count_gameover(int cell[N][N]){
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < (N - 1); j++){
            if(cell[i][j] == cell[i][j + 1]){
                count += 1;
            }
        }
    }
    for(int j = 0; j < N; j++){
        for(int i = 0; i < (N - 1); i++){
            if(cell[i][j] == cell[i + 1][j]){
                count += 1;
            }
        }
    }
    return count;
    count = 0;
}

int main (int argc, char *argv[]){
    printf("Press any key to conitnue\n");
    int c;
    set_cell(cell);
    int copy[N][N];
    int count = 0;
    int count_2 = 0;
    int count_3 = 0;
    int level = 1;
    int turn = 0;

    srand(time(NULL));

    system("/bin/stty raw onlcr");  // enterを押さなくてもキー入力を受け付けるようになる

    while((c = getchar()) != '.') {
        copy_cell(cell, copy); //copyを作っておく
        system("clear");
        printf("k: → , j: ← , i: ↑ , m: ↓ \r\n");
        printf("Press '.' to close\r\n");

        if(c == 'k'){ //右移動
            move_right(cell); //数字の移動
            add_right(cell); //たしあわせ
            move_right(cell);
        }

        else if(c == 'j'){
            move_left(cell);
            add_left(cell);
            move_left(cell);
        }
        
        else if(c == 'i'){
            move_up(cell);
            add_up(cell);
            move_up(cell);
        }
        
        else if(c == 'm'){
            move_down(cell);
            add_down(cell);
            move_down(cell);
        }

        else if(c == 'q'){
            level += 1;
        }
        
        for(int i = 0; i < N; i++){ 
            for(int j = 0; j < N; j++){
                if(cell[i][j] == 2048){
                    count_2 += 1; //2048ができたか調べる
                }
                else if(cell[i][j] != copy[i][j]){
                    count += 1; //変化があるか調べる
                }
                else if(cell[i][j] == 0){
                    count_3 += 1; //空きがあるか
                }
            }
        }

        if((count != 0) || (turn == 0)){
            turn += 1;
            for(int i = 0; i < level; i++){
                generate_number(cell);
            }
        }
        if(count_2 == 1){
            congrats();
        }
        if((count_3 == 0) && (count_gameover(cell) == 0)){
            print_gameover();
        }
        
        count = 0;
        count_3 =0;

        print_board(cell);
        printf("You pressed '%c'\r\n", c);
        printf("turn: %d\r\n", turn);
        printf("If you press 'q', game level will be up;\r\n");
        printf("level: %d\r\n", level);
    }

    system("/bin/stty cooked");  // 後始末

    return 0;
}
