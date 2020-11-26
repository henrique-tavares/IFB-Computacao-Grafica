#include <stdio.h>

int main()
{
    double r,g,b,w,c,m,y,k,x,y2,z,x0,y20,z0,maior;

    printf ("\n\tR: ");
    scanf ("%lf", &r);
    printf ("\n\tG: ");
    scanf ("%lf", &g);
    printf ("\n\tB: ");
    scanf ("%lf", &b);

    if ((r==0)&&(b==0)&&(g==0))
    {
        c = 1;
        m = 1;
        y = 1;
        k = 1;
    }
    else
    {
        maior = r;
        if (g > maior)
            maior = g;
        
        if (b > maior)
            maior = b;
        
        w = maior/255;
        c = (w-(r/255))/w;
        m = (w-(g/255))/w;
        y = (w-(b/255))/w;
        k = 1-w;
    }

    x = (0.489989*r)+(0.310008*g)+(0.200003*b);
    y2 = (0.176962*r)+(0.812400*g)+(0.010638*b);
    z = (0.009999*g)+(0.990001*b);

    x0 = x/(x+y2+z);
    y20 = y2/(x+y2+z);
    z0 = z/(x+y2+z);

    printf ("\n\tC: %lf\n\tM: %lf\n\tY: %lf\n\tK: %lf\n\n\tX: %lf\n\tY: %lf\n\tZ: %lf\n\n", c,m,y,k,x0,y20,z0);

    return 0;
}