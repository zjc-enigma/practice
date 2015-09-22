#include "readcsv.h"

int readData(const char *filePath, const char *dlim, char *res[][COLNUM]) {

  FILE *fp = fopen(filePath, "r");
  int lineNum = 0;
  ssize_t read = 0;
  char *line = NULL;
  size_t linecap = 0;


  char *brkt;
  int i = 0;
  int j = 0;
  while((read = getline(&line, &linecap, fp)) != -1) {


    while((res[i][j]=strtok_r(line, dlim, &brkt)) != NULL){
      j++;
      line = NULL;
    }
    i++;
    j=0;
  }

  fclose(fp);
  if(line) {free(line);}
  return 0;
}

/* int _main() { */
/*   const char *csvFile = "../data/binary.csv"; */
/*   char *seperator = ","; */
/*   char *res[LINENUM][COLNUM]; */

/*   readData(csvFile, seperator, res); */

/*   printf("%s\n", res[2][2]); */

/*   return 0; */
/* } */
