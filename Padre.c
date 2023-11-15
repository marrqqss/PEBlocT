#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(NULL)); // Semilla para la generación de números aleatorios
    int contador_C = 0;
    int contador_Cpp = 0;
    for (int i = 0; i < 80; ++i) {
        int ret = fork();
        if (ret == 0) { //fill
            int random = rand()%2;
            if (random == 0) { //Caso C
                ++contador_C;
                char buff[150];
                sprintf(buff, "C%d.txt", contador_C);
                FILE *archivo = freopen(buff, "w", stdout);
                dup2(fileno(archivo), STDOUT_FILENO);
                int new_ret = fork();
                if (new_ret == 0) {
                    execlp("time", "time", "./C.x", (char *)NULL);
                }
                else {
                    waitpid(-1, NULL, 0);
                    fclose(archivo);
                }
            }
            else if (random == 1) { //Caso  C++
                ++contador_Cpp;
                char buff[150];
                sprintf(buff, "C++%d.txt", contador_Cpp);
                FILE *archivo = freopen(buff, "w", stdout);
                dup2(fileno(archivo), STDOUT_FILENO);
                int new_ret = fork();
                if (new_ret == 0) {
                    execlp("time", "time", "./C++.x", (char *)NULL);
                }
                else {
                    waitpid(-1, NULL, 0);
                    fclose(archivo);
                }
            }
        }
        else if (ret > 0) { //pare
            waitpid(-1, NULL, 0);
        }
        else if (ret < 0) printf("ERROR fork\n");
    } 
    exit(0);
}
//hacer un sigint (Ctrl + C) para finalizar la ejecución