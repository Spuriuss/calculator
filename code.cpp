#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
//#include <graphics.h>
#include <windows.h>
#include <math.h>

using namespace std;



int skadoosh(int, char[], int[], int[], int[], int, int, int[], int);
int justPlusingMaaaaaaaaan(char[], int[], int[], int[], int, int[], int, int);
int brackets(char[], int[], int[], int[], int[], int, int, int, int);





int skadoosh(int startingPoint, char charArray[], int numberArray[], int firstOrderOperators[], int secondOrderOperators[], int operatorsCounter, int skobkiPointsCounter, int skobkiPoints[], int NumberOfTheNumber0xD) {
	cout << "skadoosh!" << endl;
	
	int result = numberArray[startingPoint];
	int clusterCounter = 0; // how many operations have there been so far
	
	int firstSkobka;
	int bracketsValue;
	for (int i = startingPoint; firstOrderOperators[i] != 999999 && startingPoint + clusterCounter != operatorsCounter; i++) {
		firstSkobka = 999999;
		
		
		for (int d = 0; d < skobkiPointsCounter; d++) { // brackets 
			if (skobkiPoints[d] == i) {
				firstSkobka = d;
			}
		}

		if (firstSkobka != 999999) {
			bracketsValue = brackets(charArray, numberArray, firstOrderOperators, secondOrderOperators, skobkiPoints, firstSkobka, operatorsCounter, skobkiPointsCounter, NumberOfTheNumber0xD); //SUMMON!!1
			
			if (charArray[firstOrderOperators[i]] == '*') {
				result = result * bracketsValue;
			}
			if (charArray[firstOrderOperators[i]] == '/') {
				result = result / bracketsValue;
			}
			clusterCounter++;
		} else  {
		if (charArray[firstOrderOperators[i]] == '*') {
			result = result * numberArray[i+1];
		}
		if (charArray[firstOrderOperators[i]] == '/') {
			result = result / numberArray[i+1];
		}
		clusterCounter++;
	}
	}
cout << "result: " << result << endl;
return result;

}




















int justPlusingMaaaaaaaaan(char charArray[], int numberArray[], int firstOrderOperators[], int secondOrderOperators[], int operatorsCounter, int skobkiPoints[], int skobkiPointsCounter, int NumberOfTheNumber0xD) {
	cout << "justPlusingMaaaaaaaaan" << endl;
	cout << "just plusing firstOrderOperators: " << "\n";
for (int i = 0; i < operatorsCounter; i++) {
	cout << firstOrderOperators[i] << "\n";
}
	cout << "just plusing secondOrderOperators: " << "\n";
for (int i = 0; i < operatorsCounter; i++) {
	cout << secondOrderOperators[i] << "\n";
}
	int startingPoint; // for skadoosh
	//int result = numberArray[0];
	int justPlusingFirstNumber;
	for (int i = 0; i < operatorsCounter; i++) { // определяем первое число для result (при рекурсии оно не будет просто первым числом числового массива)
		if (secondOrderOperators[i] != 999999) {
			justPlusingFirstNumber = i;
			break;
		}
	}
	int result = numberArray[justPlusingFirstNumber];
	
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
		cout << "edge case" << endl;
		startingPoint = firstFirstOrderOperator;
		result = skadoosh(startingPoint, charArray, numberArray, firstOrderOperators, secondOrderOperators, operatorsCounter, skobkiPointsCounter, skobkiPoints, NumberOfTheNumber0xD);
	}
	
	

	
	int skadooshValue;
	int bracketsValue;
	
	int firstSkobka;
	for (int i = 0; i < operatorsCounter; i++) {
		cout << "i: " << i << endl;
		cout << "secondOrderOperators: " << secondOrderOperators[i] << endl;
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
			skadooshValue = skadoosh(startingPoint, charArray, numberArray, firstOrderOperators, secondOrderOperators, operatorsCounter, skobkiPointsCounter, skobkiPoints, NumberOfTheNumber0xD);
			// SUMMON!!1
			if (charArray[secondOrderOperators[i]] == '+') { // regular after skadoosh
				result = result + skadooshValue;
			}
			if (charArray[secondOrderOperators[i]] == '-') {
				result = result - skadooshValue;
			}
		} else
		if (secondOrderOperators[i] != 999999) { // regular
			if (charArray[secondOrderOperators[i]] == '+') { 
				
				result = result + numberArray[i+1];
			}
			if (charArray[secondOrderOperators[i]] == '-') {
				result = result - numberArray[i+1];
			}
		}
	}
	cout << "done: " << result << endl;
	return result;
}





int brackets(char charArray[], int numberArray[], int firstOrderOperators[], int secondOrderOperators[], int skobkiPoints[], int firstSkobka, int operatorsCounter, int skobkiPointsCounter, int NumberOfTheNumber0xD) {
	cout << "brackets" << endl;
	int result;
	
	
	int secondSkobka = skobkiPointsCounter-1-firstSkobka;
	int subOperatorCounter = skobkiPoints[secondSkobka]-skobkiPoints[firstSkobka];
	int subNumberCounter = subOperatorCounter + 1;
	
		cout << "firstSkobka: " << firstSkobka << endl;
		cout << "secondSkobka: " << secondSkobka << endl;
		cout << "operatorsCounter: " << operatorsCounter << endl;
		cout << "sub arrays work in progress..." << endl;
	int *subNumbers = new int[subNumberCounter];
	int *subFirstOrderOperators = new int[operatorsCounter];
	int *subSecondOrderOperators = new int[operatorsCounter];
	

	

	
	
	for (int g = 0; g < operatorsCounter; g++) { // подмассив "скобочных" операторов первого порядка
		
		
		
		if (g > skobkiPoints[firstSkobka] && g < (skobkiPoints[secondSkobka] + 1)) {
			subFirstOrderOperators[g] = firstOrderOperators[g];
			firstOrderOperators[g] = 999999;
		} else {
			subFirstOrderOperators[g] = 999999;
		}
	
	

	}
	
	//cout << "subSecondOrderOperators in progress..." << endl;
	for (int g = 0; g < operatorsCounter; g++) { // подмассив "скобочных" операторов второго порядка

		
		if (g > skobkiPoints[firstSkobka] && g < (skobkiPoints[skobkiPointsCounter-1-firstSkobka]) + 1) {
			subSecondOrderOperators[g] = secondOrderOperators[g];
			secondOrderOperators[g] = 999999;
		} else {
			subSecondOrderOperators[g] = 999999;
		}
		
	}
	
	
	skobkiPoints[firstSkobka] = 999999;
	skobkiPoints[secondSkobka] = 999999;
	
	

cout << "subFirstOrderOperators: " << endl;
for (int i = 0; i < operatorsCounter; i++) {
	cout << subFirstOrderOperators[i] << endl;
}
cout << "subSecondOrderOperators: " << endl;
for (int i = 0; i < operatorsCounter; i++) {
	cout << subSecondOrderOperators[i] << endl;
}
	
	result = justPlusingMaaaaaaaaan(charArray, numberArray, subFirstOrderOperators, subSecondOrderOperators, operatorsCounter, skobkiPoints, skobkiPointsCounter, NumberOfTheNumber0xD); // SUMMON!!1
	delete subNumbers;
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
		if (charArray[i] == '(') {skobkiPoints[skobkiPointsCounter] = (breakPointsCounter - 1);} // скобки отсылаются не на номера скобок в символьном массиве, а на порядковые номера операторов. Предыдущего - в случае, если скобка открывающая, и следующего - если закрывающая. Если счётчик имеет значение ноль - это не значит, что предыдущий оператор был "нулевой". Это значит, что никакого оператора ещё вообще не было. Hense "-1". А если счётчик равен 1, то последний оператор был нулевой, а следующий будет первый.
		if (charArray[i] == ')') {skobkiPoints[skobkiPointsCounter] = (breakPointsCounter-1);}
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


int *firstOrderOperators = new int[breakPointsCounter];
int *secondOrderOperators = new int[breakPointsCounter];
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