#include <stdio.h>
#include <math.h>


double area(double x0, double y0, double x1, double y1, double x2, double y2){
    double area_triangle;
    double a, b, c, s;

    a=sqrt(((x0-x1)*(x0-x1)-(y0-y1)*(y0-y1)));
    b=sqrt(((x1-x2)*(x1-x2)-(y1-y2)*(y1-y2)));
    c=sqrt(((x0-x2)*(x0-x2)-(y0-y2)*(y0-y2)));

    s=(a+b+c)/2;

    area_triangle=sqrt((s*(s-a)*(s-b)*(s-c)));

    return area_triangle;

}


int verifica(int xp, int yp, double x[], double y[]){
   double A, A1, A2, A3;
   A = area(x[0], y[0], x[1], y[1], x[2], y[2]); 
   A1 = area(xp, yp, x[1], y[1], x[2], y[2]);
   A2 = area(x[0], y[0], xp, yp, x[2], y[2]);  
   A3 = area(x[0], y[0], x[1], y[1], xp, yp);
   return (A == A1 + A2 + A3);
}

int main(){
	int i, j;
	double x[3], y[3];
	
	for(i=0;i<3;i++){
		printf("Digite x%d", i+1);
		scanf("%lf", &x[i]);
		printf("Digite y%d", i+1);
		scanf("%lf", &y[i]); 
	}
	for(i=0;i<30;i++){
		for(j=0;j<30;j++){
			if(verifica(i, j, x, y))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
