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

void processFile() {

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
