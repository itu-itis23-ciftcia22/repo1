#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void print_2D_array(int*** arr, int size,int value) 
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j][0] == 'X') { // Eğer 'X' ise bosluk olarak yaz
                printf("[  ]");
            } else { // Değilse normal değeri yaz
                printf("[%2d]", arr[i][j][value]);
            }
        }
        printf("\n");
    }
}
void createRandomList(int original_list[], int random_list[], int list_size, int max_duplicate) {
    int i, j, index;

    // Rastgele sayı üretmek için zamanı kullan
    srand(time(NULL));

    // Her elemanı iki kez kullanan random bir dizi oluştur
    for (i = 0; i < list_size; ++i) {
        for (j = 0; j < max_duplicate; ++j) {
            index = rand() % (list_size * max_duplicate);

            // Eğer index zaten dolu ise yeni bir index seç
            while (random_list[index] != 0) {
                index = rand() % (list_size * max_duplicate);
            }

            random_list[index] = original_list[i];
        }
    }
}

void make_a_table(int*** arr,int size,int* randomlist)
{
   
    int k = 0;
    for(int i = 0; i< size; i++){
        for(int j = 0; j < size; j++){
            arr[i][j][0] = (i*size) + j + 1;
            arr[i][j][1] = randomlist[k++];
        }
    }
    print_2D_array(arr,size,0);
}

void shuffle_a_table(int*** arr, int size) {
    // Fisher-Yates shuffle algoritması kullanarak kartları karıştır
    for (int i = size * size - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Rastgele bir index seç
        // Değiştir 
        int temp = arr[i / size][i % size][0];
        arr[i / size][i % size][0] = arr[j / size][j % size][0];
        arr[j / size][j % size][0] = temp;
        int temp2 = arr[i / size][i % size][1];
        arr[i / size][i % size][1] = arr[j / size][j % size][1];
        arr[j / size][j % size][1] = temp2;
    }
    print_2D_array(arr,size,0);
}

bool is_game_finish(int*** arr, int size){
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size;j++){
           if(arr[i][j][0]!='X'){
                return false;
           }
        }
    }
    return true;
}
int main() {
    srand(time(NULL));

    printf("--- Memory Game ---\n");
    printf("Welcome to the Memory Game! Test your memory skills by matching pairs of cards.\n");

    int size;
    do {
        printf("Please enter the size of the board (even) (e.g., 4 for 4x4): ");
        scanf("%d", &size);
    } while (size <= 0);

    int*** board = (int***) malloc(sizeof(int**) *  size);
    for (int i = 0; i< size;i++){
        *(board+i) = (int**) malloc(sizeof(int*)*size);
        for(int j = 0;j<size;j++){
            *(*(board+i)+j) = (int*) malloc(sizeof(int)*2); // her cardin 2 degeri olacak.
        }
    }

    int* olasi_degerler = (int*)malloc(sizeof(int)*(size*size/2));
    for(int i =0 ; i<size*size/2;i++){
        olasi_degerler[i]=i+1;
    }
    int* randomlist = (int*) malloc(sizeof(int)* (size*size));
    createRandomList(olasi_degerler,randomlist,size*size/2,2);


    printf("Creating a %dx%d Memory Card Board:\n",size,size);
    make_a_table(board,size,randomlist);
    print_2D_array(board,size,1);// degerleri kontrol edebilirsin
   
    puts("Press any key to shuffle cards...");
    getchar();
    getchar();
    puts("Shuffling the cards...\n");
    puts("Memory Card Board (After Shuffling):");
    shuffle_a_table(board,size);
    print_2D_array(board,size,1);// degerleri kontrol edebilirsin

    puts("Let's start the game! Match the pairs by entering the coordinates of the cards.\n");

    int moves = 0;
    while(1){
    char* choice1 = (char*) malloc( sizeof(char)*3);
    
    printf("Select a card (e.g., A1): ");
    scanf(" %s",choice1);

    int choice_row1 = choice1[0] - 'A' ;
    int choice_column1 = choice1[1] - '0' - 1;

    printf("The value of %s card %d\n",choice1,board[choice_row1][choice_column1][1]);

    char* choice2 = (char*) malloc( sizeof(char)*3);

    printf("Select a card (e.g., A1): ");
    scanf(" %s",choice2);

    int choice_row2= choice2[0] - 'A' ;
    int choice_column2 = choice2[1] - '0' - 1;

    printf("The value of %s card %d\n",choice2,board[choice_row2][choice_column2][1]);

    if(board[choice_row1][choice_column1][1]==board[choice_row2][choice_column2][1]){
        printf("Congratulations! You found a match! ...\n");
        board[choice_row1][choice_column1][0] = 'X';
        board[choice_row2][choice_column2][0] = 'X';
        
    } else {
        printf("No match! Try again. ...\n");
    }
    print_2D_array(board,size,0);
    moves++;

    if(is_game_finish(board,size)){
        break;
    }

    
    }

    printf("Congratulations! You've matched all the pairs!\n");
    printf("Total number of moves: %d\n", moves);

    return 0;
}


