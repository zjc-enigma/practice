#include <stdio.h>
#include <math.h>
#include "readcsv.h"

#define TRUE 1
#define FALSE 0
#define LEARNINGRATE 0.1
#define ERRTOLERANCE 1
#define DATANUM 400
#define VECNUM 4
#define WEIGHTNUM 4
#define STEP 10000

double getNorm(double x[][VECNUM], int i, int col) {
  double max=x[0][col];
  double min=x[0][col];
  
  for(int j=0; j<DATANUM; j++) {
    
    if(x[j][col] > max) {
      max = x[j][col];
    }
    if(x[j][col] < min) {
      min = x[j][col];
    }
  }

  double res = (x[i][col] - min)/(max - min);
  return res;
}

double calcLogistic(double x[], double w[]){
  double wx = 0;

  for(int i=0; i<VECNUM; i++) {
    wx += w[i]*x[i];
  }
  double res = 1/(1 + exp(-wx));
  
  return res;
}


double calcError(double x[][VECNUM], int y[], double w[]) {
  
  double err = 0.0;

  for(int i=0; i<DATANUM; i++) {
      err += pow((y[i] - calcLogistic(x[i], w)), 2);

  }
  return err/DATANUM;
}


double updateWeight(double x[][VECNUM], int y[], double w[]) {

  double delta[VECNUM];
  memset(delta, 0, sizeof(double)*(VECNUM));
  
  int xj;

  for(int j=0; j<VECNUM; j++) {
    for(int i=0; i<DATANUM; i++) {

      xj = x[i][j];
      delta[j] += (y[i]- calcLogistic(x[i], w))*xj;
    }
  }

  for(int i=0; i<VECNUM; i++) {
    
    w[i] += LEARNINGRATE*delta[i]/DATANUM;
  }
  return 0;
}


int main() {
  // weight vector
  double W[VECNUM];
  memset(W, 0, sizeof(double)*(VECNUM));

  int step = 0;
  char *res[DATANUM+1][VECNUM];
  readData("../data/binary.csv", ",", res);

  double X[DATANUM][VECNUM];
  int Y[DATANUM];

  for(int i=0; i<DATANUM; i++){

    Y[i]=atoi(res[i+1][0]);
    X[i][0] = 1;
    
    for(int j=1; j<VECNUM; j++){
      X[i][j] = atof(res[i+1][j]);
    }
    
  }
  
  double XN[DATANUM][VECNUM];

  for(int m=0; m<DATANUM; m++){
    
    XN[m][0] = 1;
    for(int n=1; n<VECNUM; n++){
      XN[m][n] = getNorm(X, m, n);
    }
  }
  // check data
  /* for(int m=0; m<DATANUM; m++){ */
  /*   for(int n=0; n<VECNUM; n++){ */
  /*     printf("%f\t", XN[m][n]); */
  /*   } */
  /*   printf("\n%d\n", Y[m]); */
  /* } */

  while(step++ < STEP) {

    updateWeight(XN, Y, W);
     printf("%f\t%f\t%f\t%f\n", W[0], W[1], W[2], W[3]);
     printf("ERR : %f\n", calcError(XN, Y, W));
  }
  return 0;
}

