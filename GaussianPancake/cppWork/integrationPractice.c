#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_sf_bessel.h>


//Defining a and gamma in integral expression
#define littleA 1.0
#define GAMMA 1.0

//GSL's function definitions, requiring parameters and x
//Parameters are passed as a generalized array, then the parameters
//are dereferenced from said array
double f(double x, void * params) {
    double r = *(double *) params;
    double t = *((double *) params + 1);
    double f = x * gsl_sf_bessel_J0(x * r) * 
        exp(-1.0 * littleA * littleA * x * x / 2.0) *
        cos(sqrt(GAMMA * x) * t);
    return f;
}


int main (){

    FILE *output;
        output = fopen("InitialProfile.txt", "w");
    

    //GSL integration memory requirement allocation
    gsl_integration_workspace * w
        = gsl_integration_workspace_alloc (1000);

    double result, error;

    //r and t will evolve in loop
    double rCommaT[2] = {0.0, 0.0};

    gsl_function F;
    F.function = &f;
    F.params = &rCommaT;

    //General template for integration function:
    //Function, start of interval, absolute error max, relative error max,
    //size limit, workspace, result place, and error estimation place
    
    //Loop across space
    for(double t = 0; t < 40.0; t += 0.05){
        rCommaT[1] = t;
        double value = gsl_integration_qagiu(&F, 0, 0, 1e-4, 
                                1000, w, &result, &error);
        fprintf(output, "%lf %lf\n", t, result);
        printf("%lf\n", error);
    }

    gsl_integration_workspace_free (w);

    fclose(output);
    return 0;

}