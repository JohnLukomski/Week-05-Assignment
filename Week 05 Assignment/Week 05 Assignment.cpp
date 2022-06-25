//******************************************************//
// Program Week 05 Assignment - Point Break Surf Shop	//
//														//
//		Author:		John Lukomski						//
//		Created:	6/24/2022							//
//******************************************************//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//declare the function protypes
void ShowUsage();
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXSmall);
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, int iTotalXXXSmall);
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, int iTotalXXXSmall);


int main() {

	//declare variables
	int totXXXSma = 0,
		totSma = 0, 
		totMed = 0, 
		totLar = 0;
	char menuOpt = ' ';
	
	//initial display of title and menu
	ShowUsage();

	do
	{
		//prompt the user for a menu option
		cout << "Please enter selection: ";
		cin >> menuOpt;
		//call a function based on the user input
		if (menuOpt == 'S' || menuOpt == 's')
		{
			ShowUsage();				// this option displays program choices
		}
		else if (menuOpt == 'P' || menuOpt == 'p')
		{
			MakePurchase(totSma, totMed, totLar, totXXXSma); // this option calls the purchase function
		}
		else if (menuOpt == 'C' || menuOpt == 'c')
		{
			DisplayPurchase(totSma, totMed, totLar, totXXXSma);	// this option displays total current purchases
		}
		else if (menuOpt == 'T' || menuOpt == 't')
		{
			DisplayTotal(totSma, totMed, totLar, totXXXSma);		// this option the total costs and purchases
		}
		else if (menuOpt == 'Q' || menuOpt == 'q')
		{
			cout << "Thank you";													// this option quits the menu				
		}

	} while (menuOpt != 'Q' && menuOpt != 'q');										// loops until "quit" option selected

	cout << endl;

	system("pause");

	return 0;
}


void ShowUsage()			//function to clear the screen and display the title and menu

{
	//variables and fixed constants used for creation of the title
	const int TITLE_SIZE = 60;
	const char TITLE_CHAR = '*';
	const string TITLE_WORDS = " Welcome to my Johnny Utah's PointBreak Surf Shop ";
	int titleBorderSize = 0;

	//display title
	titleBorderSize = (TITLE_SIZE - TITLE_WORDS.length()) / 2;
	system("cls");
	cout << setfill(TITLE_CHAR);
	cout << setw(TITLE_SIZE) << TITLE_CHAR << endl;
	cout << setw(titleBorderSize) << TITLE_CHAR;
	cout << TITLE_WORDS;
	cout << setw(titleBorderSize) << TITLE_CHAR << endl;
	cout << setw(TITLE_SIZE) << TITLE_CHAR << endl << endl << endl;

	//display menu intructions
	cout << "To show program usage 'S'" << endl;
	cout << "To purchase a surfboard press 'P'" << endl;
	cout << "To display current purchases press 'C'" << endl;
	cout << "To display total amount due press 'T'" << endl;
	cout << "To quit the program press 'Q'" << endl<< endl;
}

void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXSmall)		
								//function that allows the user to select an amount of a particular sized surfboard 
{
	int surfAmount;
	char surfSize;

	//prompt the user for the amount and size of the surfboards they wish to purchase
	cout << "Please enter the quantity and type (X=xxxsmall, S=small, M=medium, L=large) of surfboard you would like to purchase:";
	cin >> surfAmount >> surfSize;
	cout << endl;

	//assigns and adds the amount of the selected surfboard size to correct size totals
	if (surfSize == 'x' || surfSize == 'X')
	{
		iTotalXXXSmall += surfAmount;
	}
	if (surfSize == 's' || surfSize == 'S')
	{
		iTotalSmall += surfAmount;
	}
	if (surfSize == 'm' || surfSize == 'M')
	{
		iTotalMedium += surfAmount;
	}
	if (surfSize == 'l' || surfSize == 'L')
	{
		iTotalLarge += surfAmount;
	}
	cout << endl;
}

void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXSmall) 	//function to display the items purchased
{
	//test if there are any purchases so far and outputs them appropriately
	if (iTotalXXXSmall != 0)
	{
		cout << "The total number of xxxsmall surfboards is " << iTotalXXXSmall << endl;
	}
	if (iTotalSmall != 0)
	{
		cout << "The total number of small surfboards is " << iTotalSmall << endl;
	}
	if (iTotalMedium != 0)
	{
		cout << "The total number of medium surfboards is " << iTotalMedium << endl;
	}
	if (iTotalLarge != 0)
	{
		cout << "The total number of large surfboards is " << iTotalLarge << endl;
	}
	if (iTotalXXXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
	{
		cout << "No purchases made yet." << endl;
	}
	cout << endl;
}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXSmall)
		//function to calculate and display the total cost of each size of surfboard as well as the total cost of all purchases 
{
	//prices of each size of surfboard
	const double LG_PRICE = 200.0,
				MD_PRICE = 190.0,
				SM_PRICE = 175.0,
				XS_PRICE = 20.0;

	//multiply the amount of each size of surfboard by the its price and display accordingly
	if (iTotalXXXSmall != 0)
	{
		cout << "The total number of xxxsmall surfboards is " << iTotalXXXSmall
			<< " at a total of $" << fixed << showpoint << setprecision(2) << iTotalXXXSmall * XS_PRICE << endl;
	}
	if (iTotalSmall != 0)
	{
		cout << "The total number of small surfboards is " << iTotalSmall 
			<< " at a total of $" << fixed << showpoint << setprecision(2) << iTotalSmall * SM_PRICE << endl;
	}
	if (iTotalMedium != 0)
	{
		cout << "The total number of medium surfboards is " << iTotalMedium
			<< " at a total of $" << fixed << showpoint << setprecision(2) << iTotalMedium * MD_PRICE << endl;
	}
	if (iTotalLarge != 0)
	{
		cout << "The total number of large surfboards is "<< iTotalLarge 
			<< " at a total of $" << fixed << showpoint << setprecision(2) << iTotalLarge * LG_PRICE << endl;
	}
	if (iTotalLarge != 0 || iTotalMedium != 0 || iTotalSmall != 0 || iTotalXXXSmall != 0)
	{
		cout << "Amount due: $" << fixed << showpoint << setprecision(2) 
			<< (iTotalXXXSmall * XS_PRICE) + (iTotalSmall * SM_PRICE) + (iTotalMedium * MD_PRICE) + (iTotalLarge * LG_PRICE)<< endl;
	}
	if (iTotalXXXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
	{
		cout << "No purchases made yet." << endl;
	}
	cout << endl;

}

//there was no code that I didn't use