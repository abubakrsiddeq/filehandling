#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class FileManager
{
private:
	string fileName;
public:
	//create file
	void createFile(string fName)
	{
		ofstream outFile(fName);
		outFile.close();
		
	}
	//write to file
	void writeFile(string fName, string data)
	{
		ofstream outFile(fName);
		if (outFile.is_open()) {
			outFile << data << endl;
			outFile.close();
		} else
		{
			cout << "Error: File not found" << endl;
		}
	}

	//display file data
	void displayFile(string fName)
	{
		ifstream inFile(fName);
		string data;
		if (inFile.is_open())
		{
			while (getline(inFile, data))
			{
				cout << data << endl;
			}
			inFile.close();
		}
		else
		{
			cout << "Error: File not found" << endl;
		}
	}

	//count number of lines in file
	void countLines(string fName)
	{
		ifstream inFile(fName);
		string data;
		int lines = 0;
		if (inFile.is_open())
		{
			while (getline(inFile, data))
			{
				lines++;
			}
			cout << "Number of lines in file: " << lines << endl;
			inFile.close();
		}
		else
		{
			cout << "Error: File not found" << endl;
		}
	}

	//count number of words in file
	void countWords(string fName)
	{
		ifstream inFile(fName);
		string data;
		int words = 0;
		if (inFile.is_open())
		{
			while (inFile >> data)
			{
				words++;
			}
			cout << "Number of words in file: " << words << endl;
			inFile.close();
		}
		else
		{
			cout << "Error: File not found" << endl;
		}
	}

	//count number of characters in file
	void countCharacters(string fName)
	{
		ifstream inFile(fName);
		string data;
		int characters = 0;
		if (inFile.is_open())
		{
			while (inFile >> data)
			{
				characters += data.length();
			}
			cout << "Number of characters in file: " << characters << endl;
			inFile.close();
		}
		else
		{
			cout << "Error: File not found" << endl;
		}
	}

	//add new line (update) to file
	void addLine(string fName, string data)
	{
		ofstream outFile(fName, ios::app);
		if (outFile.is_open())
		{
			outFile << data << endl;
			outFile.close();
		}
		else
		{
			cout << "Error: File not found" << endl;
		}
	}

	//edit line in file
	void editLine(string fName, int lineNum, string data)
	{
		ifstream inFile(fName);
		string line;
		string fileData;
		int lines = 0;
		if (inFile.is_open())
		{
			while (getline(inFile, line))
			{
				lines++;
				if (lines == lineNum)
				{
					line = data;
				}
				fileData += line + "\n";
			}
			inFile.close();
			ofstream outFile(fName);
			outFile << fileData;
			outFile.close();
		}
		else
		{
			cout << "Error: File not found" << endl;
		}
	}

	//edit word in file
	void editWord(string fName, string oldWord, string newWord)
	{
		ifstream inFile(fName);
		string line;
		string fileData;
		if (inFile.is_open())
		{
			while (getline(inFile, line))
			{
				size_t pos = line.find(oldWord);
				if (pos != string::npos)
				{
					line.replace(pos, oldWord.length(), newWord);
				}
				fileData += line + "\n";
			}
			inFile.close();
			ofstream outFile(fName);
			outFile << fileData;
			outFile.close();
		}
		else
		{
			cout << "Error: File not found" << endl;
		}
	}

	//overwrite file data using ios:trunc
	void overwriteFile(string fName, string data)
	{
		ofstream outFile(fName, ios::trunc);
		if (outFile.is_open())
		{
			outFile << data << endl;
			outFile.close();
		}
		else
		{
			cout << "Error: File not found" << endl;
		}
	}

	//delete file data
	void deleteFile(string fName)
	{
		ofstream outFile(fName, ios::trunc);
		if (outFile.is_open())
		{
			outFile.close();
		}
		else
		{
			cout << "Error: File not found" << endl;
		}
	}

	//delete file
	void deleteFile(string fName, bool del)
	{
		if (del)
		{
			remove(fName.c_str());
		}
		else
		{
			cout << "Error: File not found" << endl;
		}
	}

};

//display menu
void displayMenu()
{
	cout << "1. Create file" << endl;
	cout << "2. Write to file" << endl;
	cout << "3. Display file data" << endl;
	cout << "4. Count number of lines in file" << endl;
	cout << "5. Count number of words in file" << endl;
	cout << "6. Count number of characters in file" << endl;
	cout << "7. Add new line to file" << endl;
	cout << "8. Edit line in file" << endl;
	cout << "9. Edit word in file" << endl;
	cout << "10. Overwrite file data" << endl;
	cout << "11. Delete file data" << endl;
	cout << "12. Delete file" << endl;
	cout << "13. Exit" << endl;
}

int main() {
	FileManager fileManager;
	string fileName;
	string data;
	int choice;
	int lineNum;
	string oldWord;
	string newWord;
	bool del;
	do
	{
		displayMenu();
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter file name: ";
			cin >> fileName;
			fileManager.createFile(fileName);
			break;
		case 2:
			cout << "Enter file name: ";
			cin >> fileName;
			cout << "Enter data: ";
			cin.ignore();
			getline(cin, data);
			fileManager.writeFile(fileName, data);
			break;
		case 3:
			cout << "Enter file name: ";
			cin >> fileName;
			fileManager.displayFile(fileName);
			break;
		case 4:
			cout << "Enter file name: ";
			cin >> fileName;
			fileManager.countLines(fileName);
			break;
		case 5:
			cout << "Enter file name: ";
			cin >> fileName;
			fileManager.countWords(fileName);
			break;
		case 6:
			cout << "Enter file name: ";
			cin >> fileName;
			fileManager.countCharacters(fileName);
			break;
		case 7:
			cout << "Enter file name: ";
			cin >> fileName;
			cout << "Enter data: ";
			cin.ignore();
			getline(cin, data);
			fileManager.addLine(fileName, data);
			break;
		case 8:
			cout << "Enter file name: ";
			cin >> fileName;
			cout << "Enter line number: ";
			cin >> lineNum;
			cout << "Enter data: ";
			cin.ignore();
			getline(cin, data);
			fileManager.editLine(fileName, lineNum, data);
			break;
		case 9:
			cout << "Enter file name: ";
			cin >> fileName;
			cout << "Enter old word: ";
			cin >> oldWord;
			cout << "Enter new word: ";
			cin >> newWord;
			fileManager.editWord(fileName, oldWord, newWord);
			break;
		case 10:
			cout << "Enter file name: ";
			cin >> fileName;
			cout << "Enter data: ";
			cin.ignore();
			getline(cin, data);
			fileManager.overwriteFile(fileName, data);
			break;
		case 11:
			cout << "Enter file name: ";
			cin >> fileName;
			fileManager.deleteFile(fileName);
			break;
		case 12:
			cout << "Enter file name: ";
			cin >> fileName;
			cout << "Are you sure you want to delete file? (1/0): ";
			cin >> del;
			fileManager.deleteFile(fileName, del);
			break;
		case 13:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (choice != 13);
	return 0;
}
