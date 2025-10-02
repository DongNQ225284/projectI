#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <cstdlib>

using namespace std;

class Shell {
private:
    unordered_map<string, string> T2M = {
        // character
        {"a", ".-"  }, {"b", "-..."}, {"c", "-.-."}, {"d", "-.." }, {"e", "."   },
        {"f", "..-."}, {"g", "--." }, {"h", "...."}, {"i", ".."  }, {"j", ".---"},
        {"k", "-.-" }, {"l", ".-.."}, {"m", "--"  }, {"n", "-."  }, {"o", "---" },
        {"p", ".--."}, {"q", "--.-"}, {"r", ".-." }, {"s", "..." }, {"t", "-"   },
        {"u", "..-" }, {"v", "...-"}, {"w", ".--" }, {"x", "-..-"}, {"y", "-.--"},
        {"z", "--.."},
        // number
        {"0", "-----"}, {"1", ".----"}, {"2", "..---"}, {"3", "...--"}, {"4", "....-"},
        {"5", "....."}, {"6", "-...."}, {"7", "--..."}, {"8", "---.."}, {"9", "----."},
        // sign
        {".", ".-.-.-"},     
        {",", "--..--"},     
        {":", "---..."},     
        {"?", "..--.."},     
        {"-", "-....-"},  
        {" ", "/"},   
        {"error", "......."} 
    };
    unordered_map<string, string> M2T;
    
public:
    Shell() {
        for (auto &pair : T2M) {
            M2T[pair.second] = pair.first;
        }
    }

    bool is_exist_file(const string &file_name) {
        ifstream file(file_name);
        return file.good();
    }

    bool is_morse_file(const string &file_name) {
        ifstream file(file_name);
        if (!file) return false;
        char ch;
        while (file.get(ch)) {
            if (ch == '\n' || ch == '\r' || ch == ' ') continue;
            if (ch != '.' && ch != '-' && ch != '/') return false;
        }
        return true;
    }

    vector<string> parseCmd(string input, bool lower = true) {
        if (lower) {
            for (char &c : input) c = tolower(c);
        }
        vector<string> result;
        istringstream iss(input);
        string token;
        while (iss >> token) result.push_back(token);
        return result;
    }

    void morse_to_text(const string &input_file, const string &output_file) {
        ifstream in_file(input_file);
        ofstream out_file(output_file);
        if (!in_file || !out_file) {
            cerr << "Error: cannot open input/output file.\n";
            return;
        }

        string line, code;
        int line_num = 0;
        while(getline(in_file, line)) {
            line_num++;
            istringstream iss(line);
            while (iss >> code) {
                auto it = M2T.find(code);
                if (it != M2T.end()) {
                    out_file << it->second;
                } else {
                    out_file << "*";
                    cerr << "Error: Invalid Morse code " << code 
                         << " on line " << line_num << endl;
                }
            }
            out_file << '\n';
        }
    }

    void text_to_morse(const string &input_file, const string &output_file) {
        ifstream in_file(input_file);
        ofstream out_file(output_file);
        if (!in_file || !out_file) {
            cerr << "Error: cannot open input/output file.\n";
            return;
        }

        char ch;
        while (in_file.get(ch)) {
            string character(1, tolower(ch));
            auto it = T2M.find(character);
            if (it != T2M.end()) {
                out_file << it->second << " ";
            } else {
                out_file << "........ ";
                cerr << "Warning: Unsupported character '" << ch << "' replaced with ........\n";
            }
        }
    }

    void execute_command(const vector<string> &args) {
        if (args.empty()) return;

        if (args[0] == "exit") {
            exit(0);
        } 
        else if (args[0] == "clear") {
            system("cls");
        }
        else if (args[0] == "morse") {
            if (args.size() < 3) {
                cerr << "Usage: morse <input_file> <output_file>\n";
                return;
            }
            string input_file = args[1];
            string output_file = args[2];

            if (!is_exist_file(input_file)) {
                cerr << "Error: input file not found.\n";
                return;
            }

            if (is_exist_file(output_file)) {
                cerr << "Warning: " << output_file 
                     << " already exists. Overwrite (y/n)? ";
                char chr; cin >> chr;
                if (tolower(chr) != 'y') return;
            }

            if (is_morse_file(input_file)) {
                morse_to_text(input_file, output_file);
            } else {
                text_to_morse(input_file, output_file);
            }
            cerr << "Finished.\n";
        } 
        else {
            cerr << "Command not found!\n";
            cout << "Available commands:\n"
                 << "morse <input_file> <output_file> : convert Morse <-> text\n"
                 << "clear                            : clear screen\n"
                 << "exit                             : exit program\n";
        }
    }

    void run() {
        while(true) {
            cout << "> ";
            string cmd;
            if (cin.fail()) {                                       
                cin.clear();                                           
                cin.ignore(INT_MAX, '\n');                              
                cout << endl;
                continue;
            }
            getline(cin, cmd);
            if (cmd.empty()) continue;
            vector<string> args = parseCmd(cmd);
            execute_command(args);
        }
    }
};

int main() {
    Shell shell;
    shell.run();
    return 0;
}
