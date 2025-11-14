#include <stdio.h>

int main() {
    int records, i;
    
    printf("how many records you want to enter in the database table?");
    scanf("%d", &records);
    //////////Scan input///////////
    int id[records];
    for(i=1; i<=records; i++ ){
        printf("enter EMP ID of Record %d : ", i);
        scanf("%d", &id[i]);
    }
    
   //////////////////////
    char name[records][50];
    for(i=1; i<=records; i++ ){
       printf("enter Name of Record %d : ", i);
        scanf("%s", &name[i]);
    }

    /////////////////
    int basp[records];
    for(i=1; i<=records; i++ ){
        printf("enter Baic Pay of Record %d : ", i);
        scanf("%d", &basp[i]);
    }

       //////////
    int alow[records];
    for(i=1; i<=records; i++ ){
        printf("enter Allowances of Record %d : ", i);
        scanf("%d", &alow[i]);
    }
       //////////
    int ded[records];
    for(i=1; i<=records; i++ ){
        printf("enter Deductions of Record %d : ", i);
        scanf("%d", &ded[i]);
    }
     //////////
    int cl[records];
    for(i=1; i<=records; i++ ){
        printf("enter city allowances of Record %d : ", i);
        scanf("%d", &cl[i]);
    }


//////////////////table outputs////////////

    //main table - basic pay and net pay (in hand), total earning and total deuctions
    //there should be city allowance in the secondary table

    //net pay is the money we get in hand
    ///////
    printf("-------------------------------------------------------------------------------\n");
    printf("EMP ID\tName\tBasic Pay\tNet Pay\n");
    printf("-------------------------------------------------------------------------------\n");
    for(i = 1; i<=records; i++){
        printf("%-6d %-15s ₹%-15d ₹%-15d\n", id[i], name[i], basp[i], 
            basp[i]+ 0.58*basp[i]+ 0.16*basp[i] + cl[i] + alow[i] + 
                0.13*(basp[i]+ 0.58*basp[i]+ 0.16*basp[i] + cl[i] + alow[i]) +
                   0.03*(basp[i]+ 0.58*basp[i]+ 0.16*basp[i] + cl[i] + alow[i]) + 
                    0.05*(basp[i]+ 0.58*basp[i]+ 0.16*basp[i] + cl[i] + alow[i]));
    }
     printf("-------------------------------------------------------------------------------\n");
     printf("-------------------------------------------------------------------------------\n");
     printf("-------------------------------------------------------------------------------\n");
    printf("Enter the EMP ID for which the Detailed Pay slip you want to check : ");
    int n2;
    scanf("%d", &n2 );
    printf("-------------------------------------------------------------------------------\n");
    int da = 0.58*basp[n2];
    int hra =  0.16*basp[n2];
    int callow = cl[n2];
    int exallow = alow[n2];
    int te = basp[n2]+ 0.58*basp[n2]+ 0.16*basp[n2] + cl[n2] + alow[n2];
    printf("Earnings\t\tAmount\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Dearness Allowance\t₹%d\n", da);
    printf("House Rent Allowance\t₹%d\n",hra);
    printf("City Allowance\t\t₹%d\n", callow);
    printf("Extra Allowances\t₹%d\n", exallow);
    printf("-------------------------------------------------------------------------------\n");
    printf("Total Earnings : ₹%d\n", te);

    printf("-------------------------------------------------------------------------------\n");
    int pt = 0.13*te;
    int ins = 0.03*te;
    int tds =  0.05*te;
    int td = pt + ins + tds;
    printf("-------------------------------------------------------------------------------\n");
    printf("Deductions\t\tAmount\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Professional Tax\t₹%d\n", pt);
    printf("Insurance\t\t₹%d\n", ins);
    printf("Tax deducted at source\t₹%d\n", tds);
    printf("-------------------------------------------------------------------------------\n");
    printf("Total Deductions : ₹%d\n", td);
    printf("-------------------------------------------------------------------------------\n");

    printf("The Net pay of Employee is = ₹%d", te-td);
    
    return 0;
}

