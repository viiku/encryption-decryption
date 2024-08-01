#include <iostream>
#include <fstream>
#include <string>

string encrypt() {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A';
            result += char((c - base + shift) % 26 + base);
        } else {
            result +=c;
        }
    }
    return result;
}

string decrypt(string text, int shift) {
    return encrypt(text, 26 - shift);
}

void processFile(const string& inputaFile, const string& outputFile, bool isEncrypt, int shift) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if(!inFile) {
        cout << "Error opening input file." << endl;
        return;
    }

    if(!outFile) {
        cout << "Error opening output file." << endl;
        return;
    }
    
    string line;
    while (getline(inFile, line)) {
        string processedLine = isEncrypt ? encrypt(line, shift) : decrypt(line, shift);
        outFile << processedLine << endl;
    }

    inFile.close();
    outFile.close();

    cout << (isEncrypt ? "Encryption" : "Decryption") << " completed." << endl;
}

int main() {
    string inputFile, outputFile;
    int shift;
    chat choice;

    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;
    
    cout << "Enter shift value(1-25): ";
    cin >> shift;

    cout << "Encrypt (e) or Decrypt (d)?: ";
    cin >> choice;

    if (choice == 'e') {
        processFile(inputFile, outputFile, true, shift);
    } else if (choice == 'd') {
        processFile(inputFile, outputFile, false, shift);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
