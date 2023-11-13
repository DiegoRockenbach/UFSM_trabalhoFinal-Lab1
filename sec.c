#include <stdio.h>

int main(){

  int tabuleiro[6][6];
  int i, j, iAux, quantAdj, adj3[3], adj5[5], adj8[8];

  for (i = 0; i < 2; i++){
    for (j = 0; j < 6; j++){
      tabuleiro[i][j] = 21;
    }
  }
  for (i = 2; i < 4; i++){
    for (j = 0; j < 6; j++){
      tabuleiro[i][j] = 00;
    }
  }
  for (i = 4; i < 6; i++){
    for (j = 0; j < 6; j++){
      tabuleiro[i][j] = 11;
    }
  }


  for (i = 0; i < 6; i++){
    for (j = 0; j < 6; j++){
      if (tabuleiro[i][j] != 0){
        if (i == 0 && j == 0) {
          quantAdj = 3;
          adj3[0] = tabuleiro[i][j+1];
          adj3[1] = tabuleiro[i+1][j];
          adj3[2] = tabuleiro[i+1][j+1];

          printf("\nPEÇA %d DA LINHA %d, COLUNA %d", tabuleiro[i][j], i, j);
          printf("\nMOVIMENTOS POSSÍVEIS:\n");
          for (iAux = 0; iAux < quantAdj; iAux++){
            if (adj3[iAux] == 0){
              printf("%d-%d; ", i, j);
            } 
          }
          printf("\n\n");

        }

        else if (i == 0 && j == 5) {
          quantAdj = 3;
          adj3[0] = tabuleiro[i][j-1];
          adj3[1] = tabuleiro[i+1][j];
          adj3[2] = tabuleiro[i+1][j-1];

          printf("\nPEÇA %d DA LINHA %d, COLUNA %d", tabuleiro[i][j], i, j);
          printf("\nMOVIMENTOS POSSÍVEIS:\n");
          for (iAux = 0; iAux < quantAdj; iAux++){
            if (adj3[iAux] == 0){
              printf("%d-%d; ", i, j);
            }
          }
          printf("\n\n");

        }

        else if (i == 5 && j == 0) {
          quantAdj = 3;
          adj3[0] = tabuleiro[i-1][j];
          adj3[1] = tabuleiro[i][j+1];
          adj3[2] = tabuleiro[i-1][j+1];

          printf("\nPEÇA %d DA LINHA %d, COLUNA %d", tabuleiro[i][j], i, j);
          printf("\nMOVIMENTOS POSSÍVEIS:\n");
          for (iAux = 0; iAux < quantAdj; iAux++){
            if (adj3[iAux] == 0){
              printf("%d-%d; ", i, j);
            }
          }
          printf("\n\n");

        }

        else if (i == 5 && j == 5) {
          quantAdj = 3;
          adj3[0] = tabuleiro[i][j-1];
          adj3[1] = tabuleiro[i-1][j];
          adj3[2] = tabuleiro[i-1][j-1];

          printf("\nPEÇA %d DA LINHA %d, COLUNA %d", tabuleiro[i][j], i, j);
          printf("\nMOVIMENTOS POSSÍVEIS:\n");
          for (iAux = 0; iAux < quantAdj; iAux++){
            if (adj3[iAux] == 0){
              printf("%d-%d; ", i, j);
            }
          }
          printf("\n\n");

        }

        else if (i == 0 && j > 0 && j < 6){
          quantAdj = 5;
          adj5[0] = tabuleiro[i][j-1];
          adj5[1] = tabuleiro[i][j+1];
          adj5[2] = tabuleiro[i+1][j-1];
          adj5[3] = tabuleiro[i+1][j];
          adj5[4] = tabuleiro[i+1][j+1];

          printf("\nPEÇA %d DA LINHA %d, COLUNA %d", tabuleiro[i][j], i, j);
          printf("\nMOVIMENTOS POSSÍVEIS:\n");
          for (iAux = 0; iAux < quantAdj; iAux++){
            if (adj5[iAux] == 0){
              printf("%d-%d; ", i, j);
            }
          }
          printf("\n\n");

        }

        else if (i > 0 && i < 6 && j == 5){
          quantAdj = 5;
          adj5[0] = tabuleiro[i-1][j-1];
          adj5[1] = tabuleiro[i-1][j];
          adj5[2] = tabuleiro[i][j-1];
          adj5[3] = tabuleiro[i+1][j-1];
          adj5[4] = tabuleiro[i+1][j];

          printf("\nPEÇA %d DA LINHA %d, COLUNA %d", tabuleiro[i][j], i, j);
          printf("\nMOVIMENTOS POSSÍVEIS:\n");
          for (iAux = 0; iAux < quantAdj; iAux++){
            if (adj5[iAux] == 0){
              printf("%d-%d; ", i, j);
            }
          }
          printf("\n\n");

        }

        else if (i > 0 && i < 6 && j == 0){
          quantAdj = 5;
          adj5[0] = tabuleiro[i-1][j];
          adj5[1] = tabuleiro[i-1][j+1];
          adj5[2] = tabuleiro[i][j+1];
          adj5[3] = tabuleiro[i+1][j];
          adj5[4] = tabuleiro[i+1][j+1];

          printf("\nPEÇA %d DA LINHA %d, COLUNA %d", tabuleiro[i][j], i, j);
          printf("\nMOVIMENTOS POSSÍVEIS:\n");
          for (iAux = 0; iAux < quantAdj; iAux++){
            if (adj5[iAux] == 0){
              printf("%d-%d; ", i, j);
            }
          }
          printf("\n\n");

        }

        else if (i == 5 && j > 0 && j < 6){
          quantAdj = 5;
          adj5[0] = tabuleiro[i][j-1];
          adj5[1] = tabuleiro[i-1][j-1];
          adj5[2] = tabuleiro[i-1][j];
          adj5[3] = tabuleiro[i-1][j+1];
          adj5[4] = tabuleiro[i][j+1];

          printf("\nPEÇA %d DA LINHA %d, COLUNA %d", tabuleiro[i][j], i, j);
          printf("\nMOVIMENTOS POSSÍVEIS:\n");
          for (iAux = 0; iAux < quantAdj; iAux++){
            if (adj5[iAux] == 0){
              printf("%d-%d; ", i, j);
            }
          }
          printf("\n\n");

        }

        else if (i > 0 && i < 6 && j > 0 && j < 6) {
          quantAdj = 8;
          adj8[8] = tabuleiro[i-1][j-1];
          adj8[8] = tabuleiro[i-1][j];
          adj8[8] = tabuleiro[i-1][j+1];
          adj8[8] = tabuleiro[i][j-1];
          adj8[8] = tabuleiro[i][j+1];
          adj8[8] = tabuleiro[i+1][j-1];
          adj8[8] = tabuleiro[i+1][j];
          adj8[8] = tabuleiro[i+1][j+1];

          printf("\nPEÇA %d DA LINHA %d, COLUNA %d", tabuleiro[i][j], i, j);
          printf("\nMOVIMENTOS POSSÍVEIS:\n");
          for (iAux = 0; iAux < quantAdj; iAux++){
            if (adj8[iAux] == 0){
              printf("%d-%d; ", i, j);
            }
          }
          printf("\n\n");

        }    
      }
    }
  }


  for (i = 0; i < 6; i++){
    for (j = 0; j < 6; j++){
      printf("%02d ", tabuleiro[i][j]);
    }
    printf("\n");
  }
  

  system("pause");
  return 0;
}