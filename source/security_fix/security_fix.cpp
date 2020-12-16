//============================================================================
// Name        : SecurityFix.cpp
// Author      : Jim Maroulis
// Version     : 1.0
// Description : Removal of security threats.
//============================================================================

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Customer {
    char FirstName[20];
    char MiddleName[20];
    char LastName[20];
    char Address[20];
    char City[20];
    char State[3];
    char ZIP[6];
    int CustomerID;
};

FILE *fp1;
void SaveCustomerObject(Customer* customer);
void LoadCustomerObject(
    Customer* customer, char *fName, char *mName,char *lName, char*aName, char *cName, char *sName, char *zName, int ID);

int main() {
    int dummy;
    int count;
    int counter;
    char tempFirst[30];
    char tempMiddle[30];
    char tempLast[30];
    char tempAddress[30];
    char tempCity[30];
    char tempState[10];
    char tempZIP[10];
    int theID;
    Customer *pCust;

    puts("Enter the number of customer objects you wish to enter");
    scanf("%d",&count);
    fflush(stdin);

    if(count>0) {
        fp1=fopen("CustomerData.txt","a");
        if(fp1==NULL) {
            puts("Cannot open file of customer data");
            return 0;
        }
    }

    puts("Successfully opened file");
    counter=0;
    while(counter<count) {
        puts("Enter the value of the first name");
        gets(tempFirst);
        puts("Enter the value of the middle name");
        gets(tempMiddle);
        puts("Enter the value of the last name");
        gets(tempLast);
        puts("Enter the value of the address");
        gets(tempAddress);
        puts("Enter the value of the city");
        gets(tempCity);
        puts("Enter the value of the state");
        gets(tempState);
        puts("Enter the value of the postal code");
        gets(tempZIP);
        puts("Enter the value of the customer ID");
        scanf("%d",&theID);
        pCust=(Customer *)malloc(sizeof(Customer));
        LoadCustomerObject(pCust, tempFirst, tempMiddle, tempLast, tempAddress, tempCity, tempState, tempZIP, theID);
        SaveCustomerObject(pCust);
        counter++;
    }

    puts("Done adding customers to the database");
    fclose(fp1);
    scanf("%d",&dummy);
}

void LoadCustomerObject(
    Customer *theCust, char *fName,char *mName,char *lName, char*aName, char *cName,char *sName,char *zName,int ID) {
    strcpy(theCust->FirstName,fName);
    strcpy(theCust->MiddleName,mName);
    strcpy(theCust->LastName,lName);
    strcpy(theCust->Address,aName);
    strcpy(theCust->City,cName);
    strcpy(theCust->State,sName);
    strcpy(theCust->ZIP,zName);
    theCust->CustomerID=ID;
}

void SaveCustomerObject(Customer *theCust) {
    char writeString[200];
    char IDString[8];
    sprintf(IDString,"%d",theCust->CustomerID);
    strcpy(writeString,theCust->FirstName);
    strcat(writeString,",");
    strcat(writeString,theCust->MiddleName);
    strcat(writeString,",");
    strcat(writeString,theCust->LastName);
    strcat(writeString,",");
    strcat(writeString,theCust->Address);
    strcat(writeString,",");
    strcat(writeString,theCust->City);
    strcat(writeString,",");
    strcat(writeString,theCust->State);
    strcat(writeString,",");
    strcat(writeString,theCust->ZIP);
    strcat(writeString,",");
    strcat(writeString,IDString);
    strcat(writeString,"\n");
    fputs(writeString,fp1);
}
