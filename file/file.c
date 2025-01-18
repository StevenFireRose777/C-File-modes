#include <stdio.h>
#include <string.h>

#define MAX_CHARS 10000

int main(int argc, char* argv[]) {

    if(argc == 0){
        perror("WHERE IS THE INPUT!?");
        return 1;
    }

    FILE* fptr;
    if(strcmp(argv[1], "file") == 0){
        fptr = fopen("newfile.txt", "w");
        fprintf(fptr, "Hello I am Steven and I like trains.\n");
        fclose(fptr);
    }else if(strcmp(argv[1],"delete") == 0){
        const char *file = "newfile.txt";
    
        if(strcmp(file, "newfile.txt") == 0){
            if(remove(file) == 0){
                printf("Bye bye\n");
            }else{
                perror("THERES AN ERROR, FILE STILL HERE!!!!");
            }
        }
    }else if(strcmp(argv[1], "append") == 0){
        fptr = fopen("newfile.txt", "a");
        char sentence[MAX_CHARS];
        printf("Please type in a sentence: ");
        fgets(sentence, sizeof(sentence), stdin);
        fprintf(fptr, "%s\n", sentence);
        fclose(fptr);

        
    }else{
        perror("PROGRAM AINT HAPPY");
        return 1;
    }   

    return 0;

}