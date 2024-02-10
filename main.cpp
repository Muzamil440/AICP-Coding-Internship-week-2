#include<iostream>
#include<string>
using namespace std;

int main (){

    int hireOfCoach, 
        noOfSeniorCitizens, 
        noOfCarers=2, 
        noOfPeople;
    double costOfMeal,
           costOfTheatreTicket, 
           totalCost, 
           costPerSeniorCitizen,
           totalMoneyCollected = 0,
           profit;
           
    
    //inputting the no of interested senior citizens in the outing
    cout<<"Note: There should be at least 10 and maximum 36 senior citizens interested in the outing. Otherwise we cannot organize outings.\n\n";
    do{
        cout<<"How many senior citizens are interested in the outing?"<<endl;
        cin>>noOfSeniorCitizens;
        
        if(noOfSeniorCitizens >= 10 && noOfSeniorCitizens <= 36){
        
            if(noOfSeniorCitizens > 24){
            noOfCarers = 3;
            }
            noOfPeople = noOfSeniorCitizens + noOfCarers;
            
        }else if(noOfSeniorCitizens < 10){
            cout<<"Number of senior citizens you've entered is less than 10. It should be greater than or equals to 10, and less than or equals 36. Enter the Number of citizens who are interested in the outing.\n\n";
        }else if(noOfSeniorCitizens > 36){
            cout<<"Number of senior citizens you've entered is greater than 36. It should be greater than or equals to 10, and less than or equals 36. Enter the Number of citizens who are interested in the outing.\n\n";
        }
    }while(noOfSeniorCitizens < 10 || noOfSeniorCitizens > 36);
    
    
    double *amountPaid = new double[noOfSeniorCitizens];
    string *namesOfSeniorCitizens = new string[noOfSeniorCitizens];
    string *namesOfCarers = new string[noOfCarers];
    
        
        
        
    
    
    
    //initializing some variables required to calculate total cost
    if(noOfPeople >= 12 && noOfPeople <= 16){
    
        hireOfCoach = 150;
        costOfMeal = 14.00;
        costOfTheatreTicket = 21.00;
        
    } else if(noOfPeople >= 17 && noOfPeople <= 26){
    
        hireOfCoach = 190;
        costOfMeal = 13.50;
        costOfTheatreTicket = 20.00;
        
    } else if(noOfPeople >= 27 && noOfPeople <= 39){
    
        hireOfCoach = 225;
        costOfMeal = 13.00;
        costOfTheatreTicket = 19.00;
        
    }
    
    //Calculating total cost
    totalCost = hireOfCoach + costOfMeal + costOfTheatreTicket;
    
    //Calculating cost per senior citizen
    costPerSeniorCitizen = totalCost / noOfPeople;
    
    //Inputting the names of carers
    cout<<"Enter the names of carers:\n\n";
    for(int i=0; i<noOfCarers; i++){
    
        cout<<"Name of Carer no "<<i+1<<":";
        cin>>namesOfCarers[i];
    }
    //Inputting the names and amounts paid by the senior citizens and also calculating total money collected.
    cout<<"\nInputting the names and amounts paid by the senior citizen. And keep in mind that the amounts should not be negative.\n\n";
    for(int i=0; i<noOfSeniorCitizens; i++){
    
        cout<<"Name of Senior citizen no "<<i+1<<":";
        cin>>namesOfSeniorCitizens[i];
        
        do{
            cout<<"Amount paid:";
            cin>>amountPaid[i];
        
            if(amountPaid[i] < 0){
                cout<<"\nYou have entered a negative amount value which is not acceptable. Please again enter the amount correctly.\n";
            }
        }while(amountPaid[i] < 0);
        totalMoneyCollected += amountPaid[i];
    }
    
    //Printing the list of people on the outing
    //Printing Carers
    for(int i=0; i<noOfCarers; i++){
    
        cout<<"\nCarer no "<<i+1<<": "<<namesOfCarers[i]<<endl;
    }
    //Printing Senior citizens
    for(int i=0; i<noOfSeniorCitizens; i++){
    
        cout<<"\nSenior citizen no "<<i+1<<": "<<namesOfSeniorCitizens[i]<<endl;
    }
    
    //Calculating Profit and displaying it
    profit = totalMoneyCollected - totalCost;
    if(profit<0){
        cout<<"\nYou have losed in the outing. And the loss amount is "<<(-1 * profit)<<" $.\n";
    } else {
        cout<<"\nThe profit from this outing is "<<profit<<" $.\n";
    }
    
    delete[] namesOfSeniorCitizens;
    delete[] namesOfCarers;
    delete[] amountPaid;
    
return 0;
}
