#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "bankers.h"
#include "fifo.h"
#include "LRU.h"
#include "LFU.h"
using namespace std;

main()
{
	int ch,ch1;
	char choice;
	do
	{
		system("cls");
		cout<<"\nPROGRAM FOR BANKERS ALGORITHM AND PAGE REPLACEMENT ALGORITHMS";
		cout<<"\n\n1.Bankers Algorithm";
		cout<<"\n2.Page Replacement Algorithms";
		cout<<"\n\t\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				system("cls");
				cout<<"\nBANKERS ALGORITHM IMPLEMENTATION:\n\n";
				bankersalgo();
			break;
			case 2:
				cout<<"\nPAGE REPLACEMENT AGORITHMS IMPLEMENTATION:\n\n";
				cout<<"\n1.First In First Out (FIFO)";
				cout<<"\n2.Least Recently Used (LRU)";
				cout<<"\n3. Least Frequently Used (LFU)";
				cout<<"\n\nEnter Choice:";
				cin>>ch1;
				switch(ch1)
				{
					case 1:
						system("cls");
						cout<<"\nFIFO IMPLEMENTATION:\n\n";
						fifoalgorithm();
					break;		
					case 2:
						system("cls");
						cout<<"\nLRU IMPLEMENTATION:\n\n";
				 		LRUAlgo();
				 	break;
					case 3:
						system("cls");
						cout<<"\nLFU IMPLEMENTATION:\n\n";
						LFUalgo();
					break;
					default:
						cout<<"\n\nWrong Choice! ";
					break;	
				}
			break;
			default:
				cout<<"\n\nWrong Choice! ";
			break;	

		}
		cout<<"\nDo you want to continue? (y/n)";
		cin>>choice;
	}while(choice=='y'||choice=='Y');
	
}
