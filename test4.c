#include <stdio.h>

int main() {
    int records, i;
    
    printf("how many records you want to enter in the database table?");
    scanf("%d", &records);
    //////////Scan input///////////Every column in this table is a seperate array
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

   

    //net pay is the money we get in hand and total earnings is the basic pay +allowances before deductions
    ///////
    printf("-------------------------------------------------------------------------------\n");
    printf("EMP ID\tName\tBasic Pay\tNet Pay\n");
    printf("-------------------------------------------------------------------------------\n");
    for(i = 1; i<=records; i++){
        //da = Dearness allowances, hra = house rent allowance, city = city allowance, extra is your extra allowances
        //professor chinmayee has already sent you all guys the formulas we are using to calculte the stuff like da, hra, taxes etc so please read that in whatsapp group
    int da = 0.58 * basp[i];
    int hra = 0.16 * basp[i];
    int city = cl[i];
    int extra = alow[i];

    int te = basp[i] + da + hra + city + extra;
    int td = 0.13*te + 0.03*te + 0.05*te;

    int net = te - td;
        printf("%-6d %-15s ₹%-12d ₹%-15d\n", id[i], name[i], basp[i], net);
    }
     printf("-------------------------------------------------------------------------------\n");
     printf("-------------------------------------------------------------------------------\n");
     printf("-------------------------------------------------------------------------------\n");

    //since the primary table is displayed now we start with secondary payslip table for single employees
    
    int n2;
    //the payslip goto loop starts here
    payslip_menu:
    printf("Enter the EMP ID for which the Detailed Pay slip you want to check : ");

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

    printf("The Net pay of Employee is = ₹%d\n", te-td);
    printf("-------------------------------------------------------------------------------\n");

    //we wil ask the user again and again if we want to ceck the payslip of another employe
    char again;
    printf("\nDo you want to check another payslip? (y/n): ");
    scanf(" %c", &again);

    if (again == 'y' || again == 'Y') {
        goto payslip_menu;
    }
    return 0;
}

