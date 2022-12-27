#include <stdio.h>
//統一發票對獎https://e-tutor.itsa.org.tw/e-Tutor/mod/programming/view.php?id=30778
int main(){
    int lott[4][8];
    for (int i=0; i<4; i++) {
        scanf("%1d%1d%1d%1d%1d%1d%1d%1d", &lott[i][0], &lott[i][1], &lott[i][2], &lott[i][3], &lott[i][4], &lott[i][5], &lott[i][6], &lott[i][7]);
    }
    int num;
    scanf("%d", &num);
    int check[num][8];
    for (int i=0; i<num; i++) {
        scanf("%1d%1d%1d%1d%1d%1d%1d%1d", &check[i][0], &check[i][1], &check[i][2], &check[i][3], &check[i][4], &check[i][5], &check[i][6], &check[i][7]);
    }
    int prize = 0;
    int big;
    int numprize[7] = {0};
    int same[4];
    for (int i=0; i<num; i++) {
        for (int j=0; j<4; j++) {
            same[j] = 0;
        }
        for (int j=7; j>=0; j--) {
            if (lott[0][j] == check[i][j]) {
                same[0] += 1;//numbers same with special number
            }
            else {
                break;
            }
        }
        for (int j=7; j>=0; j--) {
            if (lott[1][j] == check[i][j]){
                same[1] += 1;//numbers same with number1
            }
            else {
                break;
            }
        }
        for (int j=7; j>=0; j--) {
            if (lott[2][j] == check[i][j]){
                same[2] += 1;//numbers same with number2
            }
            else {
                break;
            }
        }
        for (int j=7; j>=0; j--) {
            if (lott[3][j] == check[i][j]){
                same[3] += 1;//numbers same with number3
            }
            else {
                break;
            }
        }
        
        if (same[0] == 8) {
            prize += 2000000;
            numprize[0] += 1;
        }
        else {
            big = same[1];//choose the biggest number same with number1, 2 or 3
            if (same[2] >big) {
                big = same[2];
            }
            if (same[3] >big) {
                big = same[3];
            }
            
            if (big == 8) {
                prize += 200000;
                numprize[1] += 1;
            }
            else if (big == 7) {
                prize += 40000;
                numprize[2] += 1;
            }
            else if (big == 6) {
                prize += 10000;
                numprize[3] += 1;
            }
            else if (big == 5) {
                prize += 4000;
                numprize[4] += 1;
            }
            else if (big == 4) {
                prize += 1000;
                numprize[5] += 1;
            }
            else if (big == 3) {
                prize += 200;
                numprize[6] += 1;
            }
        }
    }
    
    printf("%d %d %d %d %d %d %d\n", numprize[0], numprize[1], numprize[2], numprize[3], numprize[4], numprize[5], numprize[6]);
    printf("%d\n", prize);
    return 0;
}
