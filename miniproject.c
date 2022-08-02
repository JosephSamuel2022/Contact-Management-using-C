#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
struct contact
{
int number;
 char name[20];    
    char phone[15];  
    char email[20];         
    struct contact *next; } ;
struct contact *firstc,*currentc,*newc;
int c=0;
void add(){
 newc = (struct contact *)malloc(sizeof(struct contact)); 
 if (firstc==NULL)
 firstc=currentc=newc;
 else
 {
 currentc=firstc;
 while(currentc->next!=NULL)
 currentc=currentc->next;
 currentc->next=newc;
 currentc=newc;
 }
 c++;
 currentc->number=c;
 
 printf("Enter Contact Name : ");
 scanf("%s",currentc->name);
 printf("Enter Contact Phone Number : ");
 scanf("%s",currentc->phone);
 printf("Enter Contact Email : ");
 scanf("%s",currentc->email);
 
 currentc->next=NULL;
}

void display(){
if(firstc==NULL)
printf("No contacts to display\n");
else{
printf("%6s %-20s %-15s %-15s\n","Acct#","Name","Phone","Email");
printf("------ -------------------- ------------- -------------------\n");
currentc=firstc;
 do
        {
        
                printf("%6d: %-20s %-15s %-20s\n",
                currentc->number,
                currentc->name,
                currentc->phone,
                currentc->email); 
                
        }
        
        while((currentc=currentc->next) != NULL);

}}

void delete(){
int record;
struct contact *previous;
 if(firstc==NULL)
    {
        printf("There are no contacts to delete!");
	return;
    }
    display();
    printf("Enter contact account number to delete: ");
    scanf("%d",&record);
    currentc = firstc;
    
    while(currentc != NULL)
    {
        if(currentc->number == record)
	{
	    if(currentc == firstc)	
		firstc=currentc->next; 
	    else
		previous->next = currentc->next;
        free(currentc); 
	    printf("contact %d deleted!\n",record);
	    return;
	}
	
	else
	{
        previous = currentc;
	    currentc = currentc->next;
	}
    }
    printf("contact %d not found!\n",record);   
}

int find(int num){
currentc = firstc;
    while(currentc != NULL)
    {
                   
        if(currentc->number == num)
	     {
           return 1;
         }
         
	else
	{
	    currentc = currentc->next;
	}
    }
    return -1;  
}
int find2(char buff[]){

currentc = firstc;
    while(currentc != NULL)
    {
                   
        if (strcmp(currentc->name, buff) == 0)
	     {
           return 1;
         }
         
	else
	{
	    currentc = currentc->next;
	}
    }
    return -1;  
}
void update(){
int record, result;

    if(firstc==NULL)
    {
        printf("There are no contacts to modify!");
	return;
    }
    
    display();		
    printf("Enter contact account number to modify or change: ");
    scanf("%d",&record);  
    result = find(record);
    
    if( result >0 ){
	     currentc = firstc;
    
    while(currentc != NULL)
    {
        if(currentc->number == record)
	{
	printf("Enter Contact Name : ");
 scanf("%s",currentc->name);
 printf("Enter Contact Phone Number : ");
 scanf("%s",currentc->phone);
 printf("Enter Contact Email : ");
 scanf("%s",currentc->email);
 

	    return;
	}
	currentc=currentc->next;}}
    printf("contact %d was not found!\n",record);
}

void findcontact(void)
{
     char buff[20];
     
     if(firstc==NULL)
	{
        printf("There are no contacts to find!");
	 return;   
    }
    
    printf("Enter contact name: ");
   
    scanf("%s",buff);
    if(find2(buff)<0){
    printf("contact %s was not found!\n",buff);
    return;}
    currentc = firstc;
    
    printf("%6s %-20s %-15s %-15s\n","Acct#","Name","Phone","Email");
    printf("------ -------------------- ------------- -------------------\n");
    while(currentc != NULL)
    {
        if( strcmp(currentc->name, buff) == 0 )
	    {
			
			
            printf("%6d: %-20s %-15s %-20s\n",
            currentc->number,
            currentc->name,
            currentc->phone,
            currentc->email); 
           
			
			
	    }
		
			currentc = currentc->next;
		
    }
    
          
}   

void main(){
FILE *f,*f2;
firstc=NULL;
f=fopen("contacts.dat","r");
firstc = NULL;

    
    
    if(f)	 
    {
	    firstc = (struct contact *)malloc(sizeof(struct contact));
    
	    currentc = firstc;      
	    while(1) 
     	    {
		    newc = (struct contact *)malloc(sizeof(struct contact));
		    fread(currentc,sizeof(struct contact),1,f);
		    if(currentc->next == NULL)   
			    break;
		    currentc->next = newc;       
                  
		    currentc = newc;             
	    }
	    fclose(f);                
	    c = currentc->number;         
        
    }
 int ch;
printf("1.Add a Contact\n2.Delete a Contact\n3.Display all contacts\n4.Modify\n5.Find a Contact\n6.Exit\n");
while (ch!=6){
printf("Enter choice : ");
 scanf("%d",&ch); 
        switch(ch){

        case 1: 
        printf("Add a new Contact : \n");
        add();
        break;
        case 2: 
        printf("Delete a Contact : \n");
        
       delete();
        break;
        case 3:
        printf("All Contacts : \n");
        
       display();
        break;
        case 4:
       printf("Modify a Contact : \n");
       update();
        break;
        case 5:
        printf("Find a Contact : \n");
     
        findcontact();
        break;
        
       default:
       printf("---------------Thank You-----------------\n"); 
}}


currentc = firstc;
    
    if(!(currentc == NULL)){
	    		
				  
   f2 = fopen("contacts.dat","w");  
    
   
    				
    while(currentc != NULL)
    {
	    fwrite(currentc,sizeof(struct contact),1,f2);
	    currentc = currentc->next;
    }
    fclose(f2);            
   } 

}
