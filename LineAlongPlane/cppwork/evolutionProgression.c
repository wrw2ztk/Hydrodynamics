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
    double f = x * exp(-0.5 * x * x) * sin(r * x) * cos(sqrt(GAMMA * x) * t);
    f *= -2.0;
    return f;
}


int main (){

    FILE *output;
        output = fopen("lineAlongPlane_t20.txt", "w");
    

    //GSL integration memory requirement allocation
    gsl_integration_workspace * w
        = gsl_integration_workspace_alloc (20000);

    double result, error;

    //r and t will evolve in loop
    //NOTE: HAVE FOUND THAT t = 0 OCCASIONALLY PRODUCES ERRORS,
    //      BUT t = 0.01 WORKS FINE
    double rCommaT[2] = {0.0, 20.0};

    gsl_function F;
    F.function = &f;
    F.params = &rCommaT;

    //General template for integration function:
    //Function, start of interval, absolute error max, relative error max,
    //size limit, workspace, result place, and error estimation place
    
    //Loop across space
    double maxEnd = 10.0;
    for(double x = -1.0 * maxEnd; x < maxEnd; x += 0.05){
        rCommaT[0] = x;
        double value = gsl_integration_qagiu(&F, 0, 0, 1e-4, 
                                1000, w, &result, &error);
        fprintf(output, "%lf %lf\n", x, result);
        //printf("%lf\n", error);
    }

    gsl_integration_workspace_free (w);

    fclose(output);
    return 0;

}