#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
//#include <graphics.h>
#include <windows.h>
#include <math.h>

using namespace std;



int skadoosh(int, char[], int[], int[], int[], int, int, int[], int, int);
int justPlusingMaaaaaaaaan(char[], int[], int[], int[], int, int[], int, int);
int brackets(char[], int[], int[], int[], int[], int, int, int, int);





int skadoosh(int startingPoint, char charArray[], int numberArray[], int firstOrderOperators[], int secondOrderOperators[], int operatorsCounter, int skobkiPointsCounter, int skobkiPoints[], int NumberOfTheNumber0xD, int fromBracketsStartingNumber) {
	cout << "skadoosh!" << endl;
	
	

	
	int result;
	if (fromBracketsStartingNumber != 999999) { // если отдаём skadoosh какое-то "первое" число, являющееся результатом скобок, используем его. Если нет - используем starting point
		result = fromBracketsStartingNumber;
	} else {
		result = numberArray[startingPoint];
	}
	cout << "I am skadooch, I picked up the result, and it is: " << result << endl;
	int clusterCounter = 0; // how many operations have there been so far
	int firstSkobka;
	int bracketsValue;
	cout << "skadoosh startingPoint: " << startingPoint << endl;
	for (int i = startingPoint; firstOrderOperators[i] != 999999 && startingPoint + clusterCounter != operatorsCounter; i++) {
		firstSkobka = 999999;
		cout << 333333333333 << endl;
		
		for (int d = 0; d < skobkiPointsCounter; d++) { // brackets 
			if (skobkiPoints[d] == i) {
				firstSkobka = d;
			}
		}

		if (firstSkobka != 999999) {
			//cout << 2222222222222222;
			bracketsValue = brackets(charArray, numberArray, firstOrderOperators, secondOrderOperators, skobkiPoints, firstSkobka, operatorsCounter, skobkiPointsCounter, NumberOfTheNumber0xD); //SUMMON!!1
			
			if (charArray[firstOrderOperators[i]] == '*') {
				result = result * bracketsValue;
			}
			if (charArray[firstOrderOperators[i]] == '/') {
				result = result / bracketsValue;
			}
			clusterCounter++;
		} else  {
			//cout << 111111111111111111;
			if (charArray[firstOrderOperators[i]] == '*') { // regular
				result = result * numberArray[i+1];
			}
			if (charArray[firstOrderOperators[i]] == '/') {
				result = result / numberArray[i+1];
			}
			clusterCounter++;
		}
		firstOrderOperators[i] = 999999;
	}
cout << "skadoosh result: " << result << endl;
return result;

}
























int justPlusingMaaaaaaaaan(char charArray[], int numberArray[], int firstOrderOperators[], int secondOrderOperators[], int operatorsCounter, int skobkiPoints[], int skobkiPointsCounter, int NumberOfTheNumber0xD) {
	cout << "justPlusingMaaaaaaaaan" << endl;


	int startingPoint; // for skadoosh
	int firstSkobka;
	int fromBracketsStartingNumber = 999999; // just plusing никогда не отдаёт skadoosh "первое число", только "starting Point". "Первое число" - только для brackets
	int justPlusingFirstNumber;
	for (int i = 0; i < operatorsCounter; i++) { // определяем первое число для result (при рекурсии оно не будет просто первым числом числового массива)
		if (secondOrderOperators[i] != 999999) {
			justPlusingFirstNumber = i;
			break;
		}
	}
	int result = numberArray[justPlusingFirstNumber];

	
	
	

		

		for (int i = 0; i < skobkiPointsCounter; i++) { // edge case если скобки идут сначала
		
		cout << 1111 << endl;
			if (skobkiPoints[i] != 999999) {
				cout << 2222 << endl;
				//cout << "firstOrderOperators[skobkiPoints[" << i << "]]: " << firstOrderOperators[skobkiPoints[i]] << endl;
				//cout << "secondOrderOperators[skobkiPoints[" << i << "]]: " << secondOrderOperators[skobkiPoints[i]] << endl;
				if ((firstOrderOperators[skobkiPoints[i]] == 999999 && secondOrderOperators[skobkiPoints[i]] == 999999) || skobkiPoints[i] == -1) {
					cout << "brackets edge case" << endl;
					firstSkobka = i;
					result = brackets(charArray, numberArray, firstOrderOperators, secondOrderOperators, skobkiPoints, firstSkobka, operatorsCounter, skobkiPointsCounter, NumberOfTheNumber0xD);
				}
			}
		}
	

	
	int firstFirstOrderOperator = 999999; // edge case если сначала стоит кластер умножения (при рекурсии оно не будет просто "если первое умножение не пустое", при рекурсии это "если первое умножение стоит раньше первого сложения")
	int firstSecondOrderOperator = 999999;
	for (int i = 0; i < operatorsCounter; i++) {
		if (firstOrderOperators[i] != 999999) {
			firstFirstOrderOperator = i;
			break;
		}
	}
	for (int i = 0; i < operatorsCounter; i++) {
		if (secondOrderOperators[i] != 999999) {
			firstSecondOrderOperator = i;
			break;
		}
	}
	if (firstFirstOrderOperator < firstSecondOrderOperator) {
		cout << "skadoosh edge case" << endl;
		startingPoint = firstFirstOrderOperator;
		result = skadoosh(startingPoint, charArray, numberArray, firstOrderOperators, secondOrderOperators, operatorsCounter, skobkiPointsCounter, skobkiPoints, NumberOfTheNumber0xD, fromBracketsStartingNumber);
	}
	
	
	
	
	int skadooshValue;
	int bracketsValue;
	
	
	for (int i = 0; i < operatorsCounter; i++) {
		cout << "i: " << i << endl;
		firstSkobka = 999999; // "очищаем" оператор "есть ли тут скобка"
		
		for (int d = 0; d < skobkiPointsCounter; d++) { // brackets 
			if (skobkiPoints[d] == i) {
				firstSkobka = d;
			}
		}
		if (secondOrderOperators[i] != 999999 && firstSkobka != 999999) {

			bracketsValue = brackets(charArray, numberArray, firstOrderOperators, secondOrderOperators, skobkiPoints, firstSkobka, operatorsCounter, skobkiPointsCounter, NumberOfTheNumber0xD); //SUMMON!!1
				if (charArray[secondOrderOperators[i]] == '+') { // regular after brackets
					result = result + bracketsValue;
				}
				if (charArray[secondOrderOperators[i]] == '-') {
					result = result - bracketsValue;
				}
		} else


		if (secondOrderOperators[i] != 999999 && firstOrderOperators[i+1] != 999999 && i != (operatorsCounter - 1)) { // SKADOOSH!!
			startingPoint = i + 1;
			skadooshValue = skadoosh(startingPoint, charArray, numberArray, firstOrderOperators, secondOrderOperators, operatorsCounter, skobkiPointsCounter, skobkiPoints, NumberOfTheNumber0xD, fromBracketsStartingNumber);
			// SUMMON!!1
			if (charArray[secondOrderOperators[i]] == '+') { // regular after skadoosh
				result = result + skadooshValue;
			}
			if (charArray[secondOrderOperators[i]] == '-') {
				result = result - skadooshValue;
			}
		} else
		if (secondOrderOperators[i] != 999999) { // regular
	cout << 11 << endl;
			if (charArray[secondOrderOperators[i]] == '+') { 
				
				result = result + numberArray[i+1];
			}
			if (charArray[secondOrderOperators[i]] == '-') {
				result = result - numberArray[i+1];
			}
		}
	}
	cout << "just plusing done: " << result << endl;
	return result;
}

























int brackets(char charArray[], int numberArray[], int firstOrderOperators[], int secondOrderOperators[], int skobkiPoints[], int firstSkobka, int operatorsCounter, int skobkiPointsCounter, int NumberOfTheNumber0xD) {
	cout << "brackets" << endl;
	int result;
	
	
	
	cout << "firstSkobka: " << firstSkobka << endl;
	
	int secondSkobka;
	int skip = 0;
	for (int i = firstSkobka + 1; i < skobkiPointsCounter; i++) {
		cout << "second skobka i: " << i << endl;

		if (skobkiPoints[i] == operatorsCounter) {
			secondSkobka = i;
			break;
		}
		if (secondOrderOperators[skobkiPoints[i]] != 999999) {
			
			if (charArray[secondOrderOperators[skobkiPoints[i]]-1] == ')') {
				if (skip != 0) {
					skip--;
				} else {
					secondSkobka = i;
					break;
				}
			}
			if (charArray[secondOrderOperators[skobkiPoints[i]]+1] == '(') {
				skip++;
			}
		}
		if (firstOrderOperators[skobkiPoints[i]] != 999999) {
			
			if (charArray[firstOrderOperators[skobkiPoints[i]]-1] == ')') {
				if (skip != 0) {
					skip--;
				} else {
					secondSkobka = i;
					break;
				}
			}
			if (charArray[firstOrderOperators[skobkiPoints[i]]+1] == '(') {
				skip++;
			}
		}
	
	}
		
		

		
	
	cout << "secondSkobka: " << secondSkobka << endl;	
	
	
	
	int subOperatorCounter = skobkiPoints[secondSkobka]-skobkiPoints[firstSkobka] - 1;

	
		


	int *subFirstOrderOperators = new int[operatorsCounter];
	int *subSecondOrderOperators = new int[operatorsCounter];
	int *subSkobkiPoints = new int[skobkiPointsCounter];
	
	for (int i = 0; i < skobkiPointsCounter; i++) {
		if (i > firstSkobka && i < secondSkobka) {
			subSkobkiPoints[i] = skobkiPoints[i];
		} else {
			subSkobkiPoints[i] = 999999;
		}
	}
	
	
	
	for (int g = 0; g < operatorsCounter; g++) { // подмассив "скобочных" операторов первого порядка
		
		
		
		if (g > skobkiPoints[firstSkobka] && g < (skobkiPoints[secondSkobka])) {
			subFirstOrderOperators[g] = firstOrderOperators[g];
			firstOrderOperators[g] = 999999;
		} else {
			subFirstOrderOperators[g] = 999999;
		}
	}
	for (int g = 0; g < operatorsCounter; g++) { // подмассив "скобочных" операторов второго порядка
	
	
		if (g > skobkiPoints[firstSkobka] && g < (skobkiPoints[secondSkobka])) {
			subSecondOrderOperators[g] = secondOrderOperators[g];
			secondOrderOperators[g] = 999999;
		} else {
			subSecondOrderOperators[g] = 999999;
		}
	}
	
	int secondSkobkaOperator = skobkiPoints[secondSkobka];
	skobkiPoints[firstSkobka] = 999999; 
	skobkiPoints[secondSkobka] = 999999;

	// we have to clear it before sending it down to just plusing, but we need to save the last operator to check if the one after it is multiplication, for skadoosh afetr plusing

	
	result = justPlusingMaaaaaaaaan(charArray, numberArray, subFirstOrderOperators, subSecondOrderOperators, operatorsCounter, subSkobkiPoints, skobkiPointsCounter, NumberOfTheNumber0xD); // SUMMON!!1
	
	
	


	
	

	if (firstOrderOperators[secondSkobkaOperator] != 999999 && secondSkobkaOperator != operatorsCounter) {
	
		cout << "skadoosh from brackets" << endl;
		int fromBracketsStartingNumber = result;
		cout << "fromBracketsStartingNumber: " << fromBracketsStartingNumber << endl;
		int startingPoint = secondSkobkaOperator;
		result = skadoosh(startingPoint, charArray, numberArray, firstOrderOperators, secondOrderOperators, operatorsCounter, skobkiPointsCounter, skobkiPoints, NumberOfTheNumber0xD, fromBracketsStartingNumber);
	}
	


	delete subFirstOrderOperators;
	delete subSecondOrderOperators;
	
	return result;
}







int main() {


// input
string inputThingy;


cout << "Input the thing okda: " << "\n";
cin >> inputThingy;


// into the array... and beyond!
int charArraySize = inputThingy.length();

char charArray[charArraySize];

strcpy(charArray,inputThingy.c_str());

// array operations
int breakPoints[100];
int breakPointsCounter = 0;

int numberPoints[100]; // разделили символы и цифры
int numberPointsCounter = 0;

int skobkiPoints[100];
int skobkiPointsCounter = 0;

int signChangePoints[100];
int signChangePointsCounter = 0;
for (int i = 0; i < charArraySize; i++) {
	if (charArray[i] == '+' || charArray[i] == '-' || charArray[i] == '*' || charArray[i] == '/') {
		if (charArray[i] == '-' && charArray[i-1] == '*' || charArray[i-1] == '/' || charArray[i-1] == '+' || charArray[i-1] == '-') {
			
			signChangePoints[signChangePointsCounter] = i;
			signChangePointsCounter++; 
			} else {
		breakPoints[breakPointsCounter] = i;
		breakPointsCounter++;
			}
	} else 
	if (charArray[i] == '(' || charArray[i] == ')') {
		if (charArray[i] == '(') {
			skobkiPoints[skobkiPointsCounter] = (breakPointsCounter - 1);
		}
		if (charArray[i] == ')') {
				skobkiPoints[skobkiPointsCounter] = (breakPointsCounter);
		}
		skobkiPointsCounter++;
	} else {
		numberPoints[numberPointsCounter] = i;
		numberPointsCounter++;
	}
}
cout << "numberPoints: " << "\n";
for (int i = 0; i < numberPointsCounter; i++) {
	cout << numberPoints[i] << "\n";
}
cout << "breakPoints: " << "\n";
for (int i = 0; i < breakPointsCounter; i++) {
	cout << breakPoints[i] << "\n";
}
if (skobkiPointsCounter != 0) {
cout << "skobkiPoints: " << "\n";
for (int i = 0; i < skobkiPointsCounter; i++) {
	cout << skobkiPoints[i] << "\n";
}
}
if (signChangePointsCounter != 0) {
cout << "signChangePoints: " << "\n";
for (int i = 0; i < signChangePointsCounter; i++) {
cout << signChangePoints[i] << "\n";
}
}
cout << "--------------------------------------" << "\n";








// number sorting system
int *numberArray = new int[numberPointsCounter];

int amountOfCharactersInThisNumber = 0;
int numberStartingPoint = 0;
int NumberOfTheNumber0xD = 0;
for (int i = 0; i < numberPointsCounter; i++) {
	if ((numberPoints[(i+1)] - numberPoints[i]) == 1) {
		amountOfCharactersInThisNumber++;
	} else {
		numberArray[NumberOfTheNumber0xD] = 0;
		for (int v = 0; v < (amountOfCharactersInThisNumber+1); v++) {
			numberArray[NumberOfTheNumber0xD] = numberArray[NumberOfTheNumber0xD] + (int(charArray[numberPoints[numberStartingPoint]]) - 48)*pow(10, (amountOfCharactersInThisNumber-v));
			numberStartingPoint++;
		}
		numberStartingPoint = (i+1);
		amountOfCharactersInThisNumber = 0;
		NumberOfTheNumber0xD++;
	}
} //numberArray done

cout << "Numbers: " << "\n";
for (int i = 0; i < NumberOfTheNumber0xD; i++) {
	cout << numberArray[i] << "\n";
}
cout << "--------------------------------------" << "\n";

// operators sorting system


int *firstOrderOperators = new int[breakPointsCounter+1];
int *secondOrderOperators = new int[breakPointsCounter+1];
int operatorsCounter = 0;
for (int i = 0; i < breakPointsCounter; i++) {
	if (charArray[breakPoints[i]] == '*' || charArray[breakPoints[i]] == '/') {
		firstOrderOperators[i] = breakPoints[i];
		secondOrderOperators[i] = 999999;
		operatorsCounter++;
	}
	if (charArray[breakPoints[i]] == '+' || charArray[breakPoints[i]] == '-') {
		secondOrderOperators[i] = breakPoints[i];
		firstOrderOperators[i] = 999999;
		operatorsCounter++;
	}
}


cout << "firstOrderOperators: " << "\n";
for (int i = 0; i < operatorsCounter; i++) {
	cout << firstOrderOperators[i] << "\n";
}
cout << "secondOrderOperators: " << "\n";
for (int i = 0; i < operatorsCounter; i++) {
	cout << secondOrderOperators[i] << "\n";
}
cout << "--------------------------------------" << "\n";







cout << "result: " << justPlusingMaaaaaaaaan(charArray, numberArray, firstOrderOperators, secondOrderOperators, operatorsCounter, skobkiPoints, skobkiPointsCounter, NumberOfTheNumber0xD);

cout << "\n";
system("pause");
return 0;
}