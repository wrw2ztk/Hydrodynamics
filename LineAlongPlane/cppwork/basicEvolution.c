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
double f(double q, void * params) {
    double r = *(double *) params;
    double t = *((double *) params + 1);
    double f = q * exp(-0.5 * q * q) * sin(r * q) * cos(sqrt(GAMMA * q) * t);
    f *= 2.0;
    return f;
}


int main (){

    FILE *output_x;
        output_x = fopen("lineAlongPlane_FullEvolution_x.txt", "w");
    FILE *output_y;
        output_y = fopen("lineAlongPlane_FullEvolution_y.txt", "w");

    //GSL integration memory requirement allocation
    int allocationSize = 20000;
    gsl_integration_workspace * w
        = gsl_integration_workspace_alloc (allocationSize);

    double result, error;

    //r and t will evolve in loop
    //NOTE: HAVE FOUND THAT t = 0 OCCASIONALLY PRODUCES ERRORS,
    //      BUT t = 0.01 WORKS FINE
    double rCommaT[2] = {0.0, 0.01};

    gsl_function F;
    F.function = &f;
    F.params = &rCommaT;



    //General template for integration function:
    //Function, start of interval, absolute error max, relative error max,
    //size limit, workspace, result place, and error estimation place
    
    //Loop across space
    double maxEnd = 100.0;
    double distSteps = 1000;
    double maxT = 100.0;
    double timeSteps = 4000;

    for(double t = 0.0; t < maxT; t += maxT / timeSteps){
        printf("%lf \n",t);
        rCommaT[1] = t;
    
        for(double x = -1.0 * maxEnd; x < maxEnd; x += (2 * maxEnd) / distSteps){
            rCommaT[0] = x;
            double value = gsl_integration_qagiu(&F, 0, 0.000001, 1e-8, 
                                allocationSize, w, &result, &error);
            fprintf(output_x, "%lf\n", x);
            fprintf(output_y, "%lf\n", result);
            
        }

        //fprintf(output, "\n");

    }

    gsl_integration_workspace_free (w);

    fclose(output_x);
    fclose(output_y);
    return 0;

}