#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_sf_bessel.h>

//For this, want to integrate a function that I numerically integrated already


//Defining a and gamma in integral expression
#define littleA 1.0
#define GAMMA 1.0


//Some things must be declared globally for ease of use
int allocationSize = 20000;
gsl_integration_workspace * w_n;
gsl_integration_workspace * w_net;
gsl_function F_n;

//GSL's function definitions, requiring parameters and x
//Parameters are passed as a generalized array, then the parameters
//are dereferenced from said array
double n(double q, void * params) {
    double x = *(double *) params;
    double t = *((double *) params + 1);
    return q * exp(-0.5 * q * q) * sin(x * q) * cos(sqrt(GAMMA * q) * t);
}

//Function is evaluating the integral of n over x > 0
//t is frozen, but charge distribution varies with x
//Change x, but still let the thing end up integrating over q
double net_charge(double x, void * params) {
    //Set r = x, t stays the same
    *(double *) params = x;
    double result;
    double error;
    gsl_integration_qagiu(&F_n, 0, 0.00001, 1e-5, 
                    allocationSize, w_n, &result, &error);
    return result;
}


int main (){

    FILE *output;
        output = fopen("netChargeEvolution.txt", "w");

    //GSL integration memory requirement allocation
    w_n = gsl_integration_workspace_alloc (allocationSize);
    w_net = gsl_integration_workspace_alloc (allocationSize);
    

    double result_n, error_n;
    double result_net, error_net;

    double rCommaT[2] = {0.0, 0.0};
    double x = 0.0;

    //GSL function of n, which uses numerical integration
    F_n.function = &n;
    F_n.params = &rCommaT;

    //GSL function of charge distribution, which numerically
    //integrates over the previous integration
    gsl_function F_net;
    F_net.function = &net_charge;
    F_net.params = &rCommaT;

    
    //Loop across time
    double maxT = 1000.0;
    double timeSteps = 100;

    for(double t = 0.0; t < maxT; t += maxT / timeSteps){

        rCommaT[0] = x;
        rCommaT[1] = t;
        //At a particular t, what is the net charge?
        gsl_integration_qag(&F_net, 0, 1000, 0.001, 1e-4, allocationSize,
                                GSL_INTEG_GAUSS31, w_net, &result_net, &error_net);
        fprintf(output, "%lf %lf\n", t, result_net);

    }

    gsl_integration_workspace_free (w_net);
    gsl_integration_workspace_free (w_n);

    fclose(output);

    return 0;

}