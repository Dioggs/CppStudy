#include <cstddef>
#include <cstdio>
#include <fstream> // read and write to files
#include <ios>
#include <iostream> // read and write to console
#include <vector>

using std::cout, std::endl, std::string, std::vector, std::cin;

void writeToFile() {
  std::fstream file;

  file.open("./file_handling/samba.txt",
            std::ios::out); // why is this path so weird?

  if (file.is_open()) {
    file << "caralho ein\n";        // this is actually quite easy
    file << "my name is lelaila\n"; // this is going to overwrite everything on
                                    // the file
    file.close();
  }
}

void appendToFile() {
  std::fstream file;

  file.open("./file_handling/samba.txt", std::ios::app);

  if (file.is_open()) {
    file << "caralho ein\n";
    file << "my name is lelaila\n";
    file.close();
  }
}

void readFromFile() {
  std::fstream file;

  file.open("./file_handling/samba.txt", std::ios::in);

  if (file.is_open()) {

    std::string content;

    while (getline(file, content)) {
      // when eof if reached, content is empty
      cout << content << endl;
    }

    file.close();
  }
}

void readFromEntireFile() {
  std::fstream file;

  file.open("./file_handling/samba.txt", std::ios::in);

  if (file.is_open()) {
    std::vector<std::string> content;

    std::string line;

    // wtf is going on
    while (!file.eof()) {
      getline(file, line);
      content.push_back(line);
    }

    file.close();

    for (const auto &entry : content) {
      cout << entry << endl;
    }
  }
}

void cypher() {
  cout << "Tell me what happened in your day: ";

  string content;

  getline(cin, content);

  // cypher the string using ASCII table
  int contSize = content.length();

  std::fstream file;

  file.open("./file_handling/diary.txt", std::ios::out);

  if (file.is_open()) {
    for (int i = 0; i < contSize; i++) {
      file << (int)content[i] << " ";
    }
  }

  file.close();
}

int main() {
  cypher();
  cout << "done" << endl;
}
