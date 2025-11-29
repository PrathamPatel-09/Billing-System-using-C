#include<stdio.h>
#include<string.h>

struct Items{
	
	int id;
	char name [50];
	float unit_price ;
	int gst;
	char category[15];
};


struct Billitem{
struct Items items;
	int quantity;
	float gstAmount;
	float total;
};


struct Items predefinedItems[53] = {
	{1,"Parle-G",10,8,"Food"},
	{2,"Jim-Jam",35,8,"Food"},
	{3,"Moneco",20,8,"Food"},
	{4, "Rice", 40.0, 5, "Grocery"},
    {5, "Wheat Flour", 55.0, 5, "Grocery"},
    {6, "Sugar", 45.0, 5, "Grocery"},
    {7, "Salt", 20.0, 5, "Grocery"},
    {8, "Milk", 28.0, 5, "Dairy"},
    {9, "Butter", 52.0, 12, "Dairy"},
    {10, "Cheese", 75.0, 12, "Dairy"},
    {11, "Paneer", 65.0, 12, "Dairy"},
    {12, "Bread", 30.0, 5, "Bakery"},
    {13, "Biscuit", 25.0, 18, "Bakery"},
    {14, "Tea Powder", 120.0, 5, "Grocery"},
    {15, "Coffee Powder", 150.0, 18, "Grocery"},
    {16, "Soap", 35.0, 18, "Personal Care"},
    {17, "Shampoo", 95.0, 18, "Personal Care"},
    {18, "Toothpaste", 55.0, 18, "Personal Care"},
    {19, "Toothbrush", 20.0, 18, "Personal Care"},
    {20, "Notebook", 35.0, 12, "Stationery"},
    {21, "Pen", 10.0, 12, "Stationery"},
    {22, "Pencil", 5.0, 12, "Stationery"},
    {23, "Eraser", 3.0, 12, "Stationery"},
    {24, "Sharpener", 5.0, 12, "Stationery"},
    {25, "Calculator", 250.0, 18, "Electronics"},
    {26, "Mobile Charger", 350.0, 18, "Electronics"},
    {27, "Earphones", 250.0, 18, "Electronics"},
    {28, "LED Bulb", 90.0, 12, "Electronics"},
    {29, "Extension Board", 220.0, 18, "Electronics"},
    {30, "Detergent Powder", 65.0, 18, "Household"},
    {31, "Dishwash Liquid", 45.0, 18, "Household"},
    {32, "Floor Cleaner", 85.0, 18, "Household"},
    {33, "Room Freshener", 110.0, 18, "Household"},
    {34, "Handwash", 55.0, 18, "Personal Care"},
    {35, "Hair Oil", 70.0, 18, "Personal Care"},
    {36, "Face Wash", 95.0, 18, "Personal Care"},
    {37, "Socks", 45.0, 5, "Clothing"},
    {38, "T-shirt", 250.0, 5, "Clothing"},
    {39, "Shirt", 450.0, 5, "Clothing"},
    {40, "Trousers", 650.0, 5, "Clothing"},
    {41, "Hat", 120.0, 12, "Clothing"},
    {42, "Water Bottle", 80.0, 12, "Plastic"},
    {43, "Lunch Box", 150.0, 12, "Plastic"},
    {44, "Steel Plate", 120.0, 18, "Kitchen"},
    {45, "Steel Glass", 60.0, 18, "Kitchen"},
    {46, "Pressure Cooker", 950.0, 18, "Kitchen"},
    {47, "Frying Pan", 550.0, 18, "Kitchen"},
    {48, "Kettle", 750.0, 18, "Kitchen"},
    {49, "Hand Towel", 45.0, 5, "Home"},
    {50, "Pillow Cover", 70.0, 5, "Home"},
    {51, "Bedsheet", 450.0, 5, "Home"},
    {52, "Curtain", 550.0, 5, "Home"},
    {53, "Bucket", 110.0, 12, "Plastic"}
};

int itemCount = sizeof(predefinedItems)/sizeof(predefinedItems[0]);

void displayItemDetails(struct Items predefinedItems[]){
	
	printf("\n*****************WELCOME TO PATEL SUPERMATKET*****************\n\n");
	
	printf("List Of All The Items Available : \n\n");
	printf("ID \t\t NAME \t\t     UNIT PRICE(Rs)     GST \tCATEGORY\n\n");
	
	
	for(int i=0;i<itemCount;i++){
	
	printf("%-4d \t\t %-15s \t %-7.2f       \t%-6.2d  %-12s",predefinedItems[i].id,predefinedItems[i].name,predefinedItems[i].unit_price,predefinedItems[i].gst,predefinedItems[i].category);
	printf("\n");	
	}
	
}

struct Items* findItemByCode(int id){
	
	for(int i=0;i<itemCount;i++){
		if(predefinedItems[i].id==id){
			return &predefinedItems[i];
		}
		
	}
	
	return NULL;
}

void printBill(struct Billitem billItems[], int count, float grandTotal){
	
	
	printf("\n\n\n                             THANK YOU FOR SHOPPING!\n");
	printf("===================================================================================\n");
	printf("Code | Item Name    | Qty | Price  | GST%% | GST Amt | Total\n");
	
	printf("-----------------------------------------------------------------------------------\n");
	
	for(int i=0; i<count;i++){
		
		printf("%-4d | %-13s| %-3d | %-6.2f |  %-3.2d |  %-6.2f | %-5.2f \n",billItems[i].items.id,
		                                                                       billItems[i].items.name,
																			   billItems[i].quantity,
																			   billItems[i].items.unit_price,
																			   billItems[i].items.gst,
																			   billItems[i].gstAmount,
																			   billItems[i].total);
		
		
	}
	
	printf("-----------------------------------------------------------------------------------\n");
	
	printf("Grand Total : %.2f\n",grandTotal);
	
	printf("===================================================================================\n");
}

void saveBillToFile(struct Billitem billItems[], int count, float grandTotal, char name[], char contNumber[]){
	
	
	FILE *fp = fopen("Bills\\bill.txt","a");
	if(fp == NULL){
		printf("Error saving bill file!\n");
		
			return ;
	}
	
	fprintf(fp,"\n\nName : %s \n",name);
	fprintf(fp,"Contact no. : %s \n\n",contNumber);
	
	fprintf(fp,"==================================BILL=====================================\n");
	
	fprintf(fp,"Code | Item Name     | Qty | Price | GST(%%) | GST Amt | Total\n");
	
	fprintf(fp,"---------------------------------------------------------------------------\n");
	
	for(int i = 0; i < count; i++){
		fprintf(fp,"%-4d | %-13s | %-3d |%-6.2f | %-6.2f | %-7.2f | %-7.2f\n",
												billItems[i].items.id,
												billItems[i].items.name,
												billItems[i].quantity,
												billItems[i].items.unit_price,
												billItems[i].items.gst,
												billItems[i].gstAmount,
												billItems[i].total);
												
	}
	
	fprintf(fp,"---------------------------------------------------------------------------\n");
	
	fprintf(fp,"Grand Total : %.2f\n",grandTotal);
	
	fprintf(fp,"===========================================================================\n");
	
	fclose(fp);

	
}




int main() {
	

	struct Billitem billItems[50];
   
int i,n;
float grandTotal = 0.0;


displayItemDetails(predefinedItems);

	char name[15];
	char contNumber[13];
	
	printf("\nEnter the name of the customer : ");
	gets(name);
	
	printf("\nEnter the contact number : ");
	gets(contNumber);
	
	
printf("\nEnter the number of items purchased: ");
scanf("%d",&n);

for(i=0;i<n;i++){
	int id,qty;
	
	printf("Enter the item ID : ");
	scanf("%d",&id);
	
	struct Items *found = findItemByCode(id);
	
	if(found==NULL){
		printf("Invalid ID! Try Again.\n");
		i--;
		continue;
	}
	
   printf("Enter the quantity of item %d : ",id);
   scanf("%d",&qty);
   
   float gstAmt = float(found->unit_price*qty*found->gst)/100;
   
   float total = (found->unit_price*qty)+gstAmt;
   
   billItems[i].items = *found;
   billItems[i].quantity = qty;
   billItems[i].gstAmount = gstAmt;
   billItems[i].total = total;
  
   grandTotal+=total;

}

 printBill(billItems,n,grandTotal);
 
 saveBillToFile(billItems, n, grandTotal, name, contNumber);
 
 printf("Bill Saved Successfully...\n\n\n");

    return 0;
}




