#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {


//  設定  /////////////////////////////

	int n[]={2,12,3}; // 各層のニューロンの数
	
	int n_l = sizeof(n)/sizeof(n[0]); // 層の数(含in,out)

	int n_t = 121; // 教師信号の数

	// 教師信号(inとout)

	double in[][2] = {
/*
		{1,0},
		{0,1},
		{0.5,0.5}
*/
{	0	 , 	0	}	 , 
{	0.1	 , 	0	}	 , 
{	0.2	 , 	0	}	 , 
{	0.3	 , 	0	}	 , 
{	0.4	 , 	0	}	 , 
{	0.5	 , 	0	}	 , 
{	0.6	 , 	0	}	 , 
{	0.7	 , 	0	}	 , 
{	0.8	 , 	0	}	 , 
{	0.9	 , 	0	}	 , 
{	1	 , 	0	}	 , 
{	0	 , 	0.1	}	 , 
{	0.1	 , 	0.1	}	 , 
{	0.2	 , 	0.1	}	 , 
{	0.3	 , 	0.1	}	 , 
{	0.4	 , 	0.1	}	 , 
{	0.5	 , 	0.1	}	 , 
{	0.6	 , 	0.1	}	 , 
{	0.7	 , 	0.1	}	 , 
{	0.8	 , 	0.1	}	 , 
{	0.9	 , 	0.1	}	 , 
{	1	 , 	0.1	}	 , 
{	0	 , 	0.2	}	 , 
{	0.1	 , 	0.2	}	 , 
{	0.2	 , 	0.2	}	 , 
{	0.3	 , 	0.2	}	 , 
{	0.4	 , 	0.2	}	 , 
{	0.5	 , 	0.2	}	 , 
{	0.6	 , 	0.2	}	 , 
{	0.7	 , 	0.2	}	 , 
{	0.8	 , 	0.2	}	 , 
{	0.9	 , 	0.2	}	 , 
{	1	 , 	0.2	}	 , 
{	0	 , 	0.3	}	 , 
{	0.1	 , 	0.3	}	 , 
{	0.2	 , 	0.3	}	 , 
{	0.3	 , 	0.3	}	 , 
{	0.4	 , 	0.3	}	 , 
{	0.5	 , 	0.3	}	 , 
{	0.6	 , 	0.3	}	 , 
{	0.7	 , 	0.3	}	 , 
{	0.8	 , 	0.3	}	 , 
{	0.9	 , 	0.3	}	 , 
{	1	 , 	0.3	}	 , 
{	0	 , 	0.4	}	 , 
{	0.1	 , 	0.4	}	 , 
{	0.2	 , 	0.4	}	 , 
{	0.3	 , 	0.4	}	 , 
{	0.4	 , 	0.4	}	 , 
{	0.5	 , 	0.4	}	 , 
{	0.6	 , 	0.4	}	 , 
{	0.7	 , 	0.4	}	 , 
{	0.8	 , 	0.4	}	 , 
{	0.9	 , 	0.4	}	 , 
{	1	 , 	0.4	}	 , 
{	0	 , 	0.5	}	 , 
{	0.1	 , 	0.5	}	 , 
{	0.2	 , 	0.5	}	 , 
{	0.3	 , 	0.5	}	 , 
{	0.4	 , 	0.5	}	 , 
{	0.5	 , 	0.5	}	 , 
{	0.6	 , 	0.5	}	 , 
{	0.7	 , 	0.5	}	 , 
{	0.8	 , 	0.5	}	 , 
{	0.9	 , 	0.5	}	 , 
{	1	 , 	0.5	}	 , 
{	0	 , 	0.6	}	 , 
{	0.1	 , 	0.6	}	 , 
{	0.2	 , 	0.6	}	 , 
{	0.3	 , 	0.6	}	 , 
{	0.4	 , 	0.6	}	 , 
{	0.5	 , 	0.6	}	 , 
{	0.6	 , 	0.6	}	 , 
{	0.7	 , 	0.6	}	 , 
{	0.8	 , 	0.6	}	 , 
{	0.9	 , 	0.6	}	 , 
{	1	 , 	0.6	}	 , 
{	0	 , 	0.7	}	 , 
{	0.1	 , 	0.7	}	 , 
{	0.2	 , 	0.7	}	 , 
{	0.3	 , 	0.7	}	 , 
{	0.4	 , 	0.7	}	 , 
{	0.5	 , 	0.7	}	 , 
{	0.6	 , 	0.7	}	 , 
{	0.7	 , 	0.7	}	 , 
{	0.8	 , 	0.7	}	 , 
{	0.9	 , 	0.7	}	 , 
{	1	 , 	0.7	}	 , 
{	0	 , 	0.8	}	 , 
{	0.1	 , 	0.8	}	 , 
{	0.2	 , 	0.8	}	 , 
{	0.3	 , 	0.8	}	 , 
{	0.4	 , 	0.8	}	 , 
{	0.5	 , 	0.8	}	 , 
{	0.6	 , 	0.8	}	 , 
{	0.7	 , 	0.8	}	 , 
{	0.8	 , 	0.8	}	 , 
{	0.9	 , 	0.8	}	 , 
{	1	 , 	0.8	}	 , 
{	0	 , 	0.9	}	 , 
{	0.1	 , 	0.9	}	 , 
{	0.2	 , 	0.9	}	 , 
{	0.3	 , 	0.9	}	 , 
{	0.4	 , 	0.9	}	 , 
{	0.5	 , 	0.9	}	 , 
{	0.6	 , 	0.9	}	 , 
{	0.7	 , 	0.9	}	 , 
{	0.8	 , 	0.9	}	 , 
{	0.9	 , 	0.9	}	 , 
{	1	 , 	0.9	}	 , 
{	0	 , 	1	}	 , 
{	0.1	 , 	1	}	 , 
{	0.2	 , 	1	}	 , 
{	0.3	 , 	1	}	 , 
{	0.4	 , 	1	}	 , 
{	0.5	 , 	1	}	 , 
{	0.6	 , 	1	}	 , 
{	0.7	 , 	1	}	 , 
{	0.8	 , 	1	}	 , 
{	0.9	 , 	1	}	 , 
{	1	 , 	1	}	
	};

	double t[][3] = {
/*
		{0,1,0},
		{0,0,1},
		{1,0,0}
*/
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	0	 , 	0	 , 	1	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	1	 , 	0	 , 	0	}	 , 
{	0	 , 	1	 , 	0	}	

	};

	double v = 0.9;	// 最急降下法の速度パラメータ
	int max_step = 10000;

///////////////////////////////////////

// 変数の初期化


	int i,j,k,s,p,step;
	
	int n_max = 0;

	for (i = 0; i < n_l; i++) {
		if (n_max < n[i]) n_max = n[i];
	}



	double z;
	double y[n_max][n_l];
	double del[n_max][n_l];
	double dzdx = 0;


	// wの初期化
	
	srand(123);
	
	
	double w[n_max][n_max][n_l];
	double dEdw[n_max][n_max][n_l];

	for (s = 1; s < n_l; s++) {
	for (j = 0; j < n[s-1]; j++) {
	for (i = 0; i < n[s]; i++) {
		w[i][j][s] = ((double)rand()+1.0)/((double)RAND_MAX+2.0);
	}
	}
	}
	



// 結果の保存
	FILE *fp;
	fp = fopen("out.csv","w+");
	



///////////////反復計算
for (step = 1; step <= max_step; step++) {
	
	printf("- step %d ----------\n",step);

if (step == max_step) {
//	fprintf(fp,"step %d\n",step);
	fprintf(fp,"teacher No.");
	for (i=0; i<n[n_l-1]; i++) {
		fprintf(fp,",out%d",i);
	}
	fprintf(fp,"\n");
}

	// dE/dwの初期化
	for (s = 1; s < n_l; s++) {
	for (j = 0; j < n[s-1]; j++) {
	for (i = 0; i < n[s]; i++) {
		dEdw[i][j][s] = 0.0;
	}
	}
	}


///////////////////////// pの指定

//	int p = 0;


////////  各教師信号に対するdEp/dwの和をとるループ
	for (p = 0; p < n_t; p++) {

	printf("teacher No.%d\n",p);

	if (step == max_step) fprintf(fp,"%d",p);

	// input 
	for (i = 0; i < n[0]; i++) {
		y[i][0] = 1/(1+exp(-in[p][i]));
//		printf("y[%i][%i]=%f\n\n",i,0,y[i][0]);
	}



//// outputの計算
	for (s = 1; s < n_l; s++) {

	for (i = 0; i < n[s]; i++) {
		z = 0.0;
		for (j = 0; j < n[s-1]; j++) {
			z += w[i][j][s]*y[j][s-1];
//		printf("w = %f ", w[i][j][s]);
//		printf("y[%i][%i]=%f\n",j,s-1,y[j][s-1]);
		}
//		printf("z=%f\n",z);
		y[i][s] = 1/(1+exp(-z));
//		printf("y[%i][%i]=%f\n\n",i,s,y[i][s]);
	if (s == n_l-1) {
		 printf("  out%d = %f\n",i,y[i][s]);
		if (step == max_step) fprintf(fp,", %f",y[i][s]);
	}
	}

	}


	if (step == max_step) fprintf(fp,"\n");

//// BP

	// output層でのdel(ip)の計算
	
	s = n_l-1;
	for (i = 0; i < n[s]; i++) {
		// 入力zの計算
		z = 0.0;
		for (j = 0; j < n[s-1]; j++) {
			z += w[i][j][s]*y[j][s-1];
//		printf("w = %f ", w[i][j][s]);
//		printf("y[%i][%i]=%f\n",j,s-1,y[j][s-1]);
		}
		
		del[i][s] = -(y[i][s] - t[p][i])*exp(-z)/pow((1+exp(-z)),2); // out層によるdelta(ip)の計算
		
//		printf("del[%i][%i] = %f\n\n",i,s,del[i][s]);
	}
	
	// hidden層でのdelta(ip)の計算
	
	
	for (s = n_l-2; s > 0; s--) {
	for (i = 0; i < n[s]; i++) {
		// 入力zの計算
		z = 0.0;
		for (j = 0; j < n[s-1]; j++) {
			z += w[i][j][s]*y[j][s-1];
		}
//		printf("z = %f\n", z);
		// dzdxの計算
		dzdx = 0;
		for (k = 0; k < n[s+1]; k++) {
			dzdx += del[k][s+1]*w[k][i][s+1];
		}
		
//		printf("dz/dx = %f\n",dzdx);
		del[i][s] = exp(-z)/pow((1+exp(-z)),2)*dzdx;
		
//		printf("del[%i][%i] = %f\n\n",i,s,del[i][s]);
	}
	}
	
	
	// dE/dw(ij)の更新

	
	for (s = 1; s < n_l; s++) {
	for (j = 0; j < n[s-1]; j++) {
	for (i = 0; i < n[s]; i++) {
//		w[i][j][s] += del[i][s] * y[j][s-1];
		dEdw[i][j][s] += -del[i][s] * y[j][s-1];
//		printf("dE/dw[%i][%i][%i] = %f\n",i,j,s,dEdw[i][j][s]);
	}
	}
	}



	}
///////教師信号ループ終了
	
	
///*	
	// wの更新
	for (s = 1; s < n_l; s++) {
	for (j = 0; j < n[s-1]; j++) {
	for (i = 0; i < n[s]; i++) {
//		printf("dE/dw[%i][%i][%i] = %f\n",i,j,s,dEdw[i][j][s]);
		w[i][j][s] -= dEdw[i][j][s]*v;
	}
	}
	}
/*
	for (s = 1; s < n_l; s++) {
	for (j = 0; j < n[s-1]; j++) {
	for (i = 0; i < n[s]; i++) {
//		printf("w[%i][%i][%i] = %f\n",i,j,s,w[i][j][s]);
	}
	}
	}
*/	
	
	printf("\n");
//	fprintf(fp,"\n");
	
}
//反復計算ループ終了


// 結果保存用ファイルを閉じる
	fclose(fp);
	
	
// 最後の結果のみのファイル
/*
	fopen("out.csv","w+");
	
	s = n_l-1;
	for (i = 0; i < n[s]; i++) {
		fprintf(fp,",%f",y[i][s]);
	}

	fclose(fp)
*/

	return 0;
}