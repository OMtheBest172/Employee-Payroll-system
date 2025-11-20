#include <stdio.h>


//so basically structures is way to define a composite data type(that is defined by us) that can have multiple of data types in a single name


struct Employee
{
    int id;
    char name[50];
    float basic_pay;
    float alow;
    float ded;
    float cl;

    
};

int main(){

  int records,i;
  printf("how many records you want to enter in the database table? : ");
  scanf("%d",&records);
  struct Employee E[records];
    //you can see we are not using int float to define the array E, here we are usign our own made data type that was "employees"
    //basically its like we have defined a structure "Employees" that is our home and the variables(like basic pay, allowance, etc) we have declared is the 'room' in that "home" where we have made the array
  //////////Scan input///////////
  for(i=0;i<records;i++)
  {
     
    printf("Enter EMP ID of Record %d : ", i+1);
    scanf("%d",&E[i].id); //when we mention E[i].id, then that means "hey computer whatever user has done input store it in the i index of array E then store it in the space of ID"
    printf("Enter the name of Record %d:", i+1);
    scanf("%s",&E[i].name);
    printf("Enter the Basic pay of Record %d:", i+1);
    scanf("%f",&E[i].basic_pay);
    printf("Enter the extra allowance of Record %d:", i+1);
    scanf("%f",&E[i].alow);
    printf("Enter the extra deductions of Record %d:", i+1);
    scanf("%f",&E[i].ded);
    printf("Enter the city allowances of Record %d:", i+1);
    scanf("%f",&E[i].cl);
  } //after this its literally the same code guys with a little bit of changes

  //////////////////table outputs////////////
     //net pay is the money we get in hand and total earnings is the basic pay +allowances before deductions
    //

   printf("-------------------------------------------------------------------------------\n");
    printf("EMP ID\tName\t\tBasic Pay\tNet Pay\n");
printf("-------------------------------------------------------------------------------\n");
  for (i = 0; i<records; i++){
    //da = Dearness allowances, hra = house rent allowance, city = city allowance, extra is your extra allowances
    float da = 0.58 * E[i].basic_pay;
    float hra = 0.16 * E[i].basic_pay;
    float city = E[i].cl;
    float extra = E[i].alow;

    float te = E[i].basic_pay + da + hra + city + extra;
    float td = 0.13*te + 0.03*te + 0.05*te + E[i].ded;

    float net = te - td;

    printf("%-6d %-15s ₹%-12f ₹%-15f\n",E[i].id, E[i].name, E[i].basic_pay, net);}
    printf("-------------------------------------------------------------------------------\n");
     printf("-------------------------------------------------------------------------------\n");
     printf("-------------------------------------------------------------------------------\n");
  
    int n2;
    
    //the payslip goto loop starts here
    checker:
payslip_menu:

    printf("Enter the EMP ID for which the Detailed Pay slip you want to check : ");
    scanf("%d", &n2);

   //doing linear search
    int foundIndex = -1;
    for(i = 0; i < records; i++){
        if(E[i].id == n2){
            foundIndex = i;
            break;
        }
    }

    if(foundIndex == -1){
        printf("invalid number, please input a valid response\n");
        goto checker;
    }

    int idx = foundIndex;
    printf("-------------------------------------------------------------------------------\n");
    float da = 0.58*E[idx].basic_pay;
    float hra =  0.16*E[idx].basic_pay;
    float callow = E[idx].cl;
    float exallow = E[idx].alow;
    float te = E[idx].basic_pay+ 0.58*E[idx].basic_pay+ 0.16*E[idx].basic_pay + E[idx].cl + E[idx].alow;
    
    printf("November Month For 2025 Year \n The detailed payslip of the employee is\n Name - %s \n Emp id - %d\n",E[idx].name, E[idx].id );
    printf("Earnings\t\tAmount\n");
    printf("-------------------------------------------------------------------------------\n");
    
    printf("Basic Pay\t\t₹%f\n", E[idx].basic_pay);
    printf("Dearness Allowance\t₹%f\n", da);
    
    printf("House Rent Allowance\t₹%f\n",hra);
    printf("City Allowance\t\t₹%f\n", callow);
    printf("Extra Allowances\t₹%f\n", exallow);
    printf("-------------------------------------------------------------------------------\n");
    printf("Total Earnings : ₹%f\n", te);

    
    float pt = 0.13*te;
    float ins = 0.03*te;
    float tds =  0.05*te;
    float td = pt + ins + tds+ E[idx].ded;
    printf("-------------------------------------------------------------------------------\n");
    printf("Deductions\t\tAmount\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Professional Tax\t₹%f\n", pt);
    printf("Insurance\t\t₹%f\n", ins);
    printf("Tax deducted at source\t₹%f\n", tds);
    printf("Extra deductions\t₹%f\n", E[idx].ded);
    printf("-------------------------------------------------------------------------------\n");
    printf("Total Deductions : ₹%f\n", td);
    printf("-------------------------------------------------------------------------------\n");

    printf("The Net pay of Employee is = ₹%f\n", te-td);
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
