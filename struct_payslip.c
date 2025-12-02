#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#define DB_FILE "employees.dat"

// Function to save record to database file
void saveEmployee(struct Employee e) {
    FILE *fp = fopen(DB_FILE, "ab");
    if (!fp) {
        printf("Error opening database file!\n");
        return;
    }
    fwrite(&e, sizeof(e), 1, fp);
    fclose(fp);
}

// Function to load all employees from file
int loadEmployees(struct Employee E[]) {
    FILE *fp = fopen(DB_FILE, "rb");
    if (!fp) return 0;

    int count = 0;
    while (fread(&E[count], sizeof(struct Employee), 1, fp)) {
        count++;
    }
    fclose(fp);
    return count;
}


int main(){

  int i, n;
  
  
  struct Employee E[100];
  int records = loadEmployees(E);
  printf("Database currently has %d stored records.\n", records);
  printf("how many NEW records you want to enter in the database table? : ");
  scanf("%d",&n);
    //you can see we are not using int float to define the array E, here we are usign our own made data type that was "employees"
    //basically its like we have defined a structure "Employees" that is our home and the variables(like basic pay, allowance, etc) we have declared is the 'room' in that "home" where we have made the array
  //////////Scan input///////////
  for(i=0;i<n;i++)
  {

    struct Employee temp;
     
    printf("Enter EMP ID of Record %d : ", i+1);
    scanf("%d",&temp.id); //when we mention E[i].id, then that means "hey computer whatever user has done input store it in the i index of array E then store it in the space of ID"
    printf("Enter the name of Record %d:", i+1);
    scanf("%49s",&temp.name);
    printf("Enter the Basic pay of Record %d:", i+1);
    scanf("%f",&temp.basic_pay);
    printf("Enter the extra allowance of Record %d:", i+1);
    scanf("%f",&temp.alow);
    printf("Enter the extra deductions of Record %d:", i+1);
    scanf("%f",&temp.ded);
    printf("Enter the city allowances of Record %d:", i+1);
    scanf("%f",&temp.cl);

    saveEmployee(temp);
    E[records++] = temp;
  } //after this its literally the same code guys with a little bit of changes

  //////////////////table outputs////////////
     //net pay is the money we get in hand and total earnings is the basic pay +allowances before deductions
    //

   printf("---------------------------------------------------------------------------------------\n");
    printf("EMP ID\tName\t\tBasic Pay\tNet Pay\n");
printf("---------------------------------------------------------------------------------------\n");
  for (i = 0; i<records; i++){
    //da = Dearness allowances, hra = house rent allowance, city = city allowance, extra is your extra allowances
    float da = 0.58 * E[i].basic_pay;
    float hra = 0.16 * E[i].basic_pay;
    float city = E[i].cl;
    float extra = E[i].alow;

    float te = E[i].basic_pay + da + hra + city + extra;
    float td = 0.13*te + 0.03*te + 0.05*te + E[i].ded;

    float net = te - td;

    printf("%-7d %-15s ₹%-12.2f ₹%-15.2f\n",E[i].id, E[i].name, E[i].basic_pay, net);}
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n");
  
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
    printf("\n");
    printf("---------------------------------------------------------------------------------------\n");
    
    float da = 0.58*E[idx].basic_pay;
    float hra =  0.16*E[idx].basic_pay;
    float callow = E[idx].cl;
    float exallow = E[idx].alow;
    float te = E[idx].basic_pay+ 0.58*E[idx].basic_pay+ 0.16*E[idx].basic_pay + E[idx].cl + E[idx].alow;
     float pt = 0.13*te;
    float ins = 0.03*te;
    float tds =  0.05*te;
    float td = pt + ins + tds+ E[idx].ded;

    printf("\t\t\tPayslip - November 2025 \nThe detailed payslip of the employee is\nName - %s \nEmployee ID - %d\n",E[idx].name, E[idx].id );
    printf("---------------------------------------------------------------------------------------\n");
    printf("Earnings\t\t  Amount\t|\tDeductions\t\tAmount\n");
    printf("---------------------------------------------------------------------------------------\n");
    
    printf("Basic Pay\t\t  ₹%-7.2f\t|\tProfessional Tax\t₹%.2f\n", E[idx].basic_pay, pt);
    printf("Dearness Allowance(DA)\t  ₹%-7.2f\t|\tInsurance\t\t₹%.2f\n", da, ins );
    
    printf("House Rent Allowance(HRA) ₹%-7.2f\t|\tTax deducted at source\t₹%.2f\n",hra, tds);
    printf("City Allowance(CA)\t  ₹%-7.2f\t|\tExtra deductions\t₹%.2f\n", callow, E[idx].ded);
    printf("Extra Allowances\t  ₹%-7.2f\t|\n", exallow );
    printf("---------------------------------------------------------------------------------------\n");
    printf("Total Earnings : \t  ₹%-7.2f\t|\tTotal Deductions : \t₹%.2f\n ", te, td);

    
   
   
    printf("---------------------------------------------------------------------------------------\n");

    printf("The Net pay of Employee is = ₹%.2f\n", te-td);
    printf("---------------------------------------------------------------------------------------\n");

    //we wil ask the user again and again if we want to ceck the payslip of another employe
    char again;
    printf("\nDo you want to check another payslip? (y/n): ");
    scanf(" %c", &again);

    if (again == 'y' || again == 'Y') {
        goto payslip_menu;
    }
    return 0;
}

