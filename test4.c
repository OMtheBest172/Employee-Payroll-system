#include <stdio.h>

int main() {
    int records, i;
    
    printf("how many records you want to enter in the database table? : ");
    scanf("%d", &records);

    //////////Scan input///////////Every column in this table is a seperate array
    int id[records];
    for(i = 0; i < records; i++ ){
        printf("enter EMP ID of Record %d : ", i+1);
        scanf("%d", &id[i]);
    }
    
   //////////////////////
    char name[records][50];//here 50 is the number of characters the variable can store
    for(i = 0; i < records; i++ ){
        printf("enter Name of Record %d : ", i+1);
        scanf("%49s", name[i]);   // FIXED: removed &
    }

    /////////////////
    float basp[records];
    for(i = 0; i < records; i++ ){
        printf("enter Basic Pay of Record %d : ", i+1);
        scanf("%f", &basp[i]);
    }

       //////////
    float alow[records];
    for(i = 0; i < records; i++ ){
        printf("enter Extra Allowances of Record %d : ", i+1);
        scanf("%f", &alow[i]);
    }

       //////////
    float ded[records];
    for(i = 0; i < records; i++ ){
        printf("enter Deductions of Record %d : ", i+1);
        scanf("%f", &ded[i]);
    }

     //////////
    float cl[records];
    for(i = 0; i < records; i++ ){
        printf("enter city allowances of Record %d : ", i+1);
        scanf("%f", &cl[i]);
    }


//////////////////table outputs////////////
     //net pay is the money we get in hand and total earnings is the basic pay +allowances before deductions
    //

    printf("-------------------------------------------------------------------------------\n");
    printf("EMP ID\tName\t\tBasic Pay\tNet Pay\n");
    printf("-------------------------------------------------------------------------------\n");
//da = Dearness allowances, hra = house rent allowance, city = city allowance, extra is your extra allowances
        //chinmayee has already sent you all guys the formulas we are using to calculte the stuff like da, hra, taxes etc so please read that in whatsapp group
    for(i = 0; i < records; i++){
        float da = 0.58 * basp[i];
        float hra = 0.16 * basp[i];
        float city = cl[i];
        float extra = alow[i];

        float te = basp[i] + da + hra + city + extra;
        float td = 0.13*te + 0.03*te + 0.05*te + ded[i];

        float net = te - td;

        printf("%-6d %-15s ₹%-12f ₹%-15f\n", id[i], name[i], basp[i], net);
    }

    printf("-------------------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------------------\n");


    //since the primary table is displayed now we start with secondary payslip table for single employees
    
    int n2;

    //the payslip goto loop starts here
checker:
payslip_menu:

    printf("Enter the EMP ID for which the Detailed Pay slip you want to check : ");
    scanf("%d", &n2);

    // -------- FIX: Search EMP ID instead of using it as index ---------
    int foundIndex = -1;
    for(i = 0; i < records; i++){
        if(id[i] == n2){
            foundIndex = i;
            break;
        }
    }

    if(foundIndex == -1){
        printf("invalid number, please input a valid response\n");
        goto checker;
    }

    int idx = foundIndex;
    // --------------------------------------------------------------------

    printf("-------------------------------------------------------------------------------\n");

    float da = 0.58 * basp[idx];
    float hra = 0.16 * basp[idx];
    float callow = cl[idx];
    float exallow = alow[idx];
    float te = basp[idx] + da + hra + callow + exallow;

    printf("Earnings\t\tAmount\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Dearness Allowance\t₹%f\n", da);
    printf("House Rent Allowance\t₹%f\n", hra);
    printf("City Allowance\t\t₹%f\n", callow);
    printf("Extra Allowances\t₹%f\n", exallow);
    printf("-------------------------------------------------------------------------------\n");
    printf("Total Earnings : ₹%f\n", te);

    printf("-------------------------------------------------------------------------------\n");

    float pt = 0.13 * te;
    float ins = 0.03 * te;
    float tds = 0.05 * te;
    float td = pt + ins + tds + ded[idx];

    printf("-------------------------------------------------------------------------------\n");
    printf("Deductions\t\tAmount\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Professional Tax\t₹%f\n", pt);
    printf("Insurance\t\t₹%f\n", ins);
    printf("Tax deducted at source\t₹%f\n", tds);
    printf("Extra deductions\t₹%f\n", ded[idx]);
    printf("-------------------------------------------------------------------------------\n");
    printf("Total Deductions : ₹%f\n", td);
    printf("-------------------------------------------------------------------------------\n");

    printf("The Net pay of Employee is = ₹%f\n", te - td);
    printf("-------------------------------------------------------------------------------\n");

    char again;
    printf("\nDo you want to check another payslip? (y/n): ");
    scanf(" %c", &again);

    if(again == 'y' || again == 'Y'){
        goto payslip_menu;
    }

    return 0;
}


