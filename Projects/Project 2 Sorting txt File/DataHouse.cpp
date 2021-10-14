#include "DataHouse.h"

//constructor
DataHouse::DataHouse() {
	this->elementNum = 1;
	this->BPointer = NULL; //NULL so it doesnt point at junk
	this->SPointer = NULL; //NULL so it doesnt point at junk
	this->IPointer = NULL; //NULL so it doesnt point at junk
}


//getters
int DataHouse::GETelementNum()
{
	return this->elementNum;
}

//setters
bool DataHouse::setelementNum(int new_elementNum)
{
	//Only accept the new Num if its not negative
	bool newValueAccepted = false;
	if (new_elementNum > 0) {
		this->elementNum = new_elementNum;
		newValueAccepted = true;
	}
	// return the bool if accepted =true, or false 
	return newValueAccepted;
}



//utility
void DataHouse::InitializeArray()
{
	//This will allocate the memory of the array
	this->BPointer = new int[GETelementNum()];
	this->SPointer = new int[GETelementNum()];
	this->IPointer = new int[GETelementNum()];
	}

void DataHouse::fillArray(int numbersArray, int i)
{
	//this fills the arrays and correct index from the driver
	this->BPointer[i] = numbersArray;
	this->SPointer[i] = numbersArray;
	this->IPointer[i] = numbersArray;
	
}

	void DataHouse::bubbleSort(){
		//bubble sorting algorithem 
		bool swap = true;
		while (swap == true) {
			swap = false;
			for (int i = 0; i <= GETelementNum() - 2; i++) {
				int j = i + 1;
				if (this->BPointer[i] > this->BPointer[j]) {
					int temp = this->BPointer[j];
					this->BPointer[j] = this->BPointer[i];
					this->BPointer[i] = temp;
					swap = true;
				}
			}
		}
		

	}

	void DataHouse::selectionSort(){
		//selection sorting alogrithem
		for (int i = 0; i < GETelementNum() - 1; i++) {
			int currentMin = i;
			for (int j = i + 1; j < GETelementNum(); j++) {
				if (this->SPointer[j] < this->SPointer[currentMin])
					currentMin = j;
			}

			int tempNum = this->SPointer[i];
			this->SPointer[i] = this->SPointer[currentMin];
			this->SPointer[currentMin] = tempNum;
		}
		
	}

	void DataHouse::insertionSort(){
		//insertion sorting alogrithem
		int currentValue;
		for (int i = 1; i < GETelementNum(); i++) {
			int j = i - 1;
			currentValue = this->IPointer[i];
			while (this->IPointer[j] > currentValue&& j >= 0) {
				this->IPointer[j + 1] = this->IPointer[j];
				j--;
			}
			this->IPointer[j + 1] = currentValue;
		}
		
	}
	void DataHouse::deallocate() {
		//function to deallocate memory
		delete[] this->BPointer;
		delete[] this->SPointer;
		delete[] this->IPointer;
	}