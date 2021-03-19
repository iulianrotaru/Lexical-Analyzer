#include <bits/stdc++.h>
using namespace std;

string Compound_assignment[] = {
    "+=",
    "-=",
    "*=",
    "/=",
    "%=",
    ">>=",
    "<<=",
    "&=",
    "^=",
    "|="
};

bool searchCompoundAssignment(string tokenName) {
    for(int i = 9; i >= 0 ; --i) {
        if(tokenName == Compound_assignment[i]) {
            return 1;
        }
    }
    return 0;
}

string Relational_and_comparison_operators[] = {
    "==",
    "!=",
    ">",
    "<",
    ">=",
    "<="
};

bool searchRelational_and_comparison_operators(string tokenName) {
    for(int i = 5; i >= 0 ; --i) {
        if(tokenName == Relational_and_comparison_operators[i]) {
            return 1;
        }
    }
    return 0;
}

string LogicalOperators[] = {
    "!",
    "&&",
    "||"
};

bool searchLogicalOperators(string tokenName) {
    for(int i = 2; i >= 0 ; --i) {
        if(tokenName == LogicalOperators[i]) {
            return 1;
        }
    }
    return 0;
}

string BitwiseOperators[] = {
    "&",
    "|",
    "^",
    "~",
    "<<",
    ">>"
};

bool searchBitwiseOperators(string tokenName) {
    for(int i = 5; i >= 0 ; --i) {
        if(tokenName == BitwiseOperators[i]) {
            return 1;
        }
    }
    return 0;
}


/// https://en.cppreference.com/w/cpp/keyword
string TokenKeyword[] = {
    "alignas",
    "alignof",
    "and",
    "and_eq",
    "asm",
    "atomic_cancel",
    "atomic_commit",
    "atomic_noexcept",
    "auto",
    "bitand",
    "bitor",
    "bool",
    "break",
    "case",
    "catch",
    "char",
    "char8_t",
    "char16_t",
    "char32_t",
    "class",
    "compl",
    "concept",
    "const",
    "consteval",
    "constexpr",
    "constinit",
    "const_cast",
    "continue",
    "co_await",
    "co_return",
    "co_yield",
    "decltype",
    "default",
    "delete",
    "do",
    "double",
    "dynamic_cast",
    "else",
    "enum",
    "explicit",
    "export",
    "extern",
    "false",
    "float",
    "for",
    "friend",
    "goto",
    "if",
    "inline",
    "int",
    "long",
    "mutable",
    "namespace",
    "new",
    "noexcept",
    "not",
    "not_eq",
    "nullptr",
    "operator",
    "or",
    "or_eq",
    "private",
    "protected",
    "public",
    "reflexpr",
    "register",
    "reinterpret_cast",
    "requires",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "static_assert",
    "static_cast",
    "struct",
    "switch",
    "synchronized",
    "template",
    "this",
    "thread_local",
    "throw",
    "true",
    "try",
    "typedef",
    "typeid",
    "typename",
    "union",
    "unsigned",
    "using",
    "virtual",
    "void",
    "volatile",
    "wchar_t",
    "while",
    "xor",
    "xor_eq",
    "main"
};

string searchRecognizedTokens(string tokenName) {
    for(int i = 97; i >= 0 ; --i) {
        if(tokenName == TokenKeyword[i]) {
            return tokenName;
        }
    }
    return "nu sa gasit";
}

void Print(string tokenName, string tip_token, int linie_fisier_token, int pozitie_in_linie_prima_litera_token, string posibila_eroare_lexicala) {
    int lungime_token = tokenName.size();
    cout << left << setw(25) << setfill(' ')<< tokenName << ' ' ;
    cout << left << setw(36) << tip_token << ' ' ;
    cout << left << setw(5) << lungime_token << ' ' ;
    cout << left << setw(5) << linie_fisier_token << ' ' ;
    cout << left << setw(5) << pozitie_in_linie_prima_litera_token << ' ';
    cout << posibila_eroare_lexicala << '\n';
}

bool searchIdentifier(string tokenName) {
    /// primul caracter trebuie sa fie litera sau _
    if( !(isalpha(tokenName[0]) || tokenName[0] == '_') )
        return 0;

    for(int i = 1; i < (int)tokenName.size(); ++i) {
        if( !(isalnum(tokenName[i]) || tokenName[i] == '_') )
            return 0;
    }
    return 1;
}

bool searchNumber(string tokenName) {
    int ind = 0;
    if(tokenName[ind] == '+')
        ind++;
    else if(tokenName[ind] == '-')
        ind++;

    int sfarsit = tokenName.size();

    /// prima cifra nu trebuie sa fie 0
    if(tokenName[ind] == '0' && ind + 1 < sfarsit)
        return 0;

    for(int i = ind; i < sfarsit; ++i)
        if(!isdigit(tokenName[i]))
            return 0;

    return 1;
}

bool searchIntConstant(string tokenName) {
    int ind = 0;
    int sign = 1;
    if(tokenName[ind] == '+') {
        ind++;
    }
    else if(tokenName[ind] == '-') {
        sign = -1;
        ind++;
    }
    int sfarsit = tokenName.size();
    int cifre = 0;
    for(int i = ind; i < sfarsit; ++i) {
        if(!isdigit(tokenName[i])) {
            return 0;
        }
        else {
            cifre += 1;
        }
    }

    if(cifre > 10) {
        return 0;
    }

    long long number = 0;
    for(int i = ind; i < sfarsit; ++i)
        number = number * 10 + tokenName[i] - '0';

    number *= sign;

    if(number > INT_MAX)
        return 0;

    if(number < INT_MIN)
        return 0;

    return 1;
}

bool searchShortConstant(string tokenName) {
    int ind = 0;
    int sign = 1;
    if(tokenName[ind] == '+') {
        ind++;
    }
    else if(tokenName[ind] == '-') {
        sign = -1;
        ind++;
    }
    int sfarsit = tokenName.size();
    int cifre = 0;
    for(int i = ind; i < sfarsit; ++i) {
        if(!isdigit(tokenName[i])) {
            return 0;
        }
        else {
            cifre += 1;
        }
    }

    if(cifre > 6) {
        return 0;
    }

    int number = 0;
    for(int i = ind; i < sfarsit; ++i)
        number = number * 10 + tokenName[i] - '0';

    number *= sign;

    if(number > SHRT_MAX)
        return 0;

    if(number < SHRT_MIN)
        return 0;

    return 1;
}

bool searchLonglongConstant(string tokenName) {
    int ind = 0;
    int sign = 1;
    if(tokenName[ind] == '+') {
        ind++;
    }
    else if(tokenName[ind] == '-') {
        sign = -1;
        ind++;
    }
    int sfarsit = tokenName.size();
    int cifre = 0;
    for(int i = ind; i < sfarsit; ++i) {
        if(!isdigit(tokenName[i])) {
            return 0;
        }
        else {
            cifre += 1;
        }
    }

    if(cifre > 19) {
        return 0;
    }

    unsigned long long number = 0;
    for(int i = ind; i < sfarsit; ++i)
        number = number * 10 + tokenName[i] - '0';

    if(number > LLONG_MAX)
        return 0;

    return 1;
}

bool searchNumberOctal(string tokenName) {
    /// trebuie sa fie de forma 0 [0-7]+
    if(tokenName[0] != '0') {
        return 0;
    }

    for(int i = 1; i < (int)tokenName.size(); ++i) {
        if(tokenName[i] > '7' || tokenName[i] < '0') {
            return 0;
        }
    }

    return 1;
}

bool searchNumberHexa(string tokenName) {
    /// trebuie sa fie de forma 0 [x|X] [1-9 | A-F | a-f] [0-9 | A-F | a-f]*
    if(tokenName[0] != '0') {
        return 0;
    }

    if(! (tokenName[1] == 'x' || tokenName[1] == 'X') )
        return 0;

    if(tokenName[2] == '0')
        return 0;

    string HexDigit = "0123456789ABCDEFabcdef";
    for(int i = 2; i < (int)tokenName.size(); ++i) {
        bool ok = 0;
        for(int j = 0; j < 22; ++j) {
            if(HexDigit[j] == tokenName[i]) {
                ok = 1;
                break;
            }
        }

        if(ok == 0) {
            return 0;
        }
    }

    return 1;
}

string searchNumberType(string tokenName,int linie_fisier_token,int pozitie_in_linie_prima_litera_token) {
    ///poate fi de tipul numar + tip (long,unsigned int,unsigned long,long long,unsigned long long)

    string ToateCifrele;
    int ind = 0;
    int sfarsit = tokenName.size();
    if(tokenName[ind] == '0') {
        ToateCifrele += tokenName[ind];
        ind += 1;

        if(tokenName[ind] == 'x' || tokenName[ind] == 'X') {
            ToateCifrele += tokenName[ind];
            ind += 1;
        }
    }

    while(isdigit(tokenName[ind]) && ind < sfarsit) {
        ToateCifrele += tokenName[ind];
        ind += 1;
    }

    string ToateCaracterele;
    while(ind < sfarsit) {
        ToateCaracterele += tokenName[ind];
        ind += 1;
    }

    ///cout<< " Toate Cifrele : " << ToateCifrele << " Toate Caracterele : " << ToateCaracterele << '\n';

    /// unsigned int
    if(ToateCaracterele == "u" || ToateCaracterele == "U") {
        if(searchNumber(ToateCifrele)) {
            if(searchIntConstant(ToateCifrele))
                Print(tokenName,"Unsigned int constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Number constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru unsigned int");
        }

        /// verific daca este numar octal
        else if(searchNumberOctal(ToateCifrele)) {
            if((int)ToateCifrele.size() <= 11)
                Print(tokenName,"Unsigned int octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru unsigned int");
        }

        ///verific daca este numar hexa
        else if(searchNumberHexa(ToateCifrele)) {
            if((int)ToateCifrele.size() <= 8)
                Print(tokenName,"Int hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru unsigned int");
        }

        return "gasit";
    }

    /// long
    else if(ToateCaracterele == "L" || ToateCaracterele == "l") {
        if(searchNumber(ToateCifrele)) {
            if(searchIntConstant(ToateCifrele))
                Print(tokenName,"Long constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Number constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru long");
        }

        /// verific daca este numar octal
        else if(searchNumberOctal(ToateCifrele)) {
            if((int)ToateCifrele.size() <= 11)
                Print(tokenName,"Long octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru long");
        }

        ///verific daca este numar hexa
        else if(searchNumberHexa(ToateCifrele)) {
            if((int)ToateCifrele.size() <= 8)
                Print(tokenName,"Long hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru long");
        }

        return "gasit";
    }

    /// unsigned long
    else if(ToateCaracterele == "ul" || ToateCaracterele == "lu" || ToateCaracterele == "LU" || ToateCaracterele == "UL" ||
            ToateCaracterele == "uL" || ToateCaracterele == "lU" || ToateCaracterele == "Lu" || ToateCaracterele == "Ul" ) {
        if(searchNumber(ToateCifrele)) {
            if(searchIntConstant(ToateCifrele))
                Print(tokenName,"Unsigned long constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Number constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru unsigned long");
        }

        /// verific daca este numar octal
        else if(searchNumberOctal(ToateCifrele)) {
            if((int)ToateCifrele.size() <= 11)
                Print(tokenName,"Unsigned long octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru unsigned long");
        }

        ///verific daca este numar hexa
        else if(searchNumberHexa(ToateCifrele)) {
            if((int)ToateCifrele.size() <= 8)
                Print(tokenName,"Unsigned long hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru unsigned long");
        }
        return "gasit";
    }

    /// long long
    else if(ToateCaracterele == "ll" || ToateCaracterele == "LL") {
        if(searchNumber(ToateCifrele)) {
            if(searchLonglongConstant(ToateCifrele))
                Print(tokenName,"Long long constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Number constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru Long long");
        }

        /// verific daca este numar octal
        else if(searchNumberOctal(ToateCifrele)) {
            if((int)ToateCifrele.size() <= 22)
                Print(tokenName,"Long long octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru long long");
        }

        ///verific daca este numar hexa
        else if(searchNumberHexa(ToateCifrele)) {
            if((int)ToateCifrele.size() <= 18)
                Print(tokenName,"Long long hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru long long");
        }

        return "gasit";
    }

    /// unsigned long long
    else if(ToateCaracterele == "ull" || ToateCaracterele == "llu" || ToateCaracterele == "ULL" || ToateCaracterele == "LLU" ||
            ToateCaracterele == "uLL" || ToateCaracterele == "llU" || ToateCaracterele == "Ull" || ToateCaracterele == "LLu") {
        if(searchNumber(ToateCifrele)) {
            if(searchLonglongConstant(ToateCifrele))
                Print(tokenName,"Unsigned long long constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Number constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru unsigned Long long");
        }

        /// verific daca este numar octal
        else if(searchNumberOctal(ToateCifrele)) {
            if((int)ToateCifrele.size() <= 22)
                Print(tokenName,"Unsigned long long octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru unsigned long long");
        }

        ///verific daca este numar hexa
        else if(searchNumberHexa(ToateCifrele)) {
            if((int)ToateCifrele.size() <= 18)
                Print(tokenName,"Unsigned long long hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
            else
                Print(tokenName,"Hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru unsigned long long");
        }

        return "gasit";
    }

    return "nu sa gasit";
}

bool isDoubleNumber(string tokenName,int linie_fisier_token, int pozitie_in_linie_prima_litera_token) {
    /// singurul moment cand nu este adevarat este cand avem prefixul .e
    ///cout<<tokenName<<'\n';
    if(tokenName[0] == '.' && tokenName[1] == 'e') {
        return 0;
    }

    string tipNumar = "Long double ";

    /// bag tot din tokenName fara sufixul f|F|L|l
    string PosibilNumber;
    for(int i = 0 ; i < (int)tokenName.size() ; ++i) {
        if(tokenName[i] != 'f' && tokenName[i] != 'F' && tokenName[i] != 'l' && tokenName[i] != 'L')
            PosibilNumber += tokenName[i];
        else if(tokenName[i] == 'F' || tokenName[i] == 'f')
            tipNumar = "Float ";
    }

    /// daca dupa e nu am numar iar e eroare
    int indice = 0;
    while(indice < (int)PosibilNumber.size()) {
        if(PosibilNumber[indice] != 'e')
            indice += 1;
        else
            break;
    }

    /// daca am e in numar ultimul caracter trebuie sa fie cifra
    if(PosibilNumber[indice] == 'e') {
        if(!isdigit(PosibilNumber[(int)PosibilNumber.size() - 1]) ) {
            return 0;
        }
    }

    Print(tokenName,tipNumar + "constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    return 1;
}

void verifyToken(string tokenName,int linie_fisier_token, int pozitie_in_linie_prima_litera_token) {
    if(tokenName.size() == 0)
        return;

    /// operatori
    else if(tokenName == "=")
        Print(tokenName,"Assignment operator",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "+")
        Print(tokenName,"Arithmetic operator addition",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "-")
        Print(tokenName,"Arithmetic operator subtraction",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "*")
        Print(tokenName,"Arithmetic operator multiplication",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "/")
        Print(tokenName,"Arithmetic operator division",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "%")
        Print(tokenName,"Arithmetic operator modulo",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(searchCompoundAssignment(tokenName))
        Print(tokenName,"Compound assignment operator",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "++")
        Print(tokenName,"Increment operator",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "--")
        Print(tokenName,"Decrecrement operator",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(searchRelational_and_comparison_operators(tokenName))
        Print(tokenName,"Relational and comparison operator",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(searchLogicalOperators(tokenName))
        Print(tokenName,"Logical operator",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(searchBitwiseOperators(tokenName))
        Print(tokenName,"Bitwise operator",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == ",")
        Print(tokenName,"Comma",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "?")
        Print(tokenName,"Conditional ternary operator",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");

    /// other signs
    else if(tokenName == "(")
        Print(tokenName,"Open paranthesis",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == ")")
        Print(tokenName,"Closed paranthesis",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "[")
        Print(tokenName,"Open square paranthesis",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "]")
        Print(tokenName,"Closed square paranthesis",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "{")
        Print(tokenName,"Open bracket",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == "}")
        Print(tokenName,"Closed bracket",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == ";")
        Print(tokenName,"Semicolon",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
    else if(tokenName == ".")
        Print(tokenName,"Point",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");

    /// verific daca este numar format doar din cifre
    else if(searchNumber(tokenName)) {
        if(searchShortConstant(tokenName))
            Print(tokenName,"Short constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
        else if(searchIntConstant(tokenName))
            Print(tokenName,"Int constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
        else if(searchLonglongConstant(tokenName))
            Print(tokenName,"Long long constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
        else
            Print(tokenName,"Number constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru Long long");
    }

    /// verific daca este numar octal
    else if(searchNumberOctal(tokenName)) {
        if((int)tokenName.size() <= 12)
            Print(tokenName,"Int octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
        else if((int)tokenName.size() <= 22)
            Print(tokenName,"Long long octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
        else
            Print(tokenName,"Octal constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru long long");
    }

    ///verific daca este numar hexa
    else if(searchNumberHexa(tokenName)) {
        if((int)tokenName.size() <= 10)
            Print(tokenName,"Int hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
        else if((int)tokenName.size() <= 18)
            Print(tokenName,"Long long hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");
        else
            Print(tokenName,"Hexa constant",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error prea mare pentru long long");
    }

    ///verific daca este numar precedat de tipul acestuia
    else if(searchNumberType(tokenName,linie_fisier_token,pozitie_in_linie_prima_litera_token) != "nu sa gasit") ;

    /// comentariul de tipul //
    else if(tokenName == "//")
        Print(tokenName,"Comment",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");

    /// comentariul de tipul /* reusit
    else if(tokenName == "/*")
        Print(tokenName,"Comment",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");

    /// un keyword este in lista
    else if(searchRecognizedTokens(tokenName) != "nu sa gasit")
        Print(tokenName,"Keyword",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");

    /// un identificator e de forma [Litera | _ ] + { cifra | litera | _ }*
    else if(searchIdentifier(tokenName))
        Print(tokenName,"Identifier",linie_fisier_token,pozitie_in_linie_prima_litera_token,"");

    else
        Print(tokenName,"Error",linie_fisier_token,pozitie_in_linie_prima_litera_token,"Error Nu sa putut identifica tokenul");
}

void scanner(const char* InputFile = "ProgramDeScanat.txt") {
    ifstream fInput(InputFile);

    if(!fInput.is_open()) {
		cout<<"nu sa putut deschide fisierul\n";
		return ;
	}

	string LinieCod;
	int numberLine = 0;
	bool multiLineComment = 0;
	string tokenCurent;
	int startLineMultiLineCommnet = 0;
	int startCaracterLinieMultiLineCommnet = 0;

	while( getline(fInput,LinieCod) ) {
	    LinieCod += '\n';
	    numberLine += 1;
	    int sfarsitLinie = LinieCod.size();

	    for(int caracterLinie = 0; caracterLinie < sfarsitLinie ; caracterLinie += 1) {
            /// daca caracterul curent este spatiu sfarsit linie sau tab atunci verific token-ul curent
            char chCurent = LinieCod[caracterLinie];
            if(multiLineComment == 1) {
                tokenCurent += chCurent;

                /// verific daca gasesc */
                /// si atunci am comentariu corect
                if(chCurent == '*') {
                    if(caracterLinie + 1 < sfarsitLinie) {
                        if(LinieCod[caracterLinie + 1] == '/') {
                            /// am gasit */

                            verifyToken("/*",startLineMultiLineCommnet,startCaracterLinieMultiLineCommnet);

                            tokenCurent += LinieCod[caracterLinie + 1];
                            cout << tokenCurent << '\n';
                            tokenCurent.clear();
                            multiLineComment = 0;
                            caracterLinie += 1;
                        }
                    }
                }
            }
            else if(chCurent == ' ' || chCurent == '\n' || chCurent == '\0') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();
            }
            /// daca prima parte este .numar e numar
            else if(chCurent == '.' && (int)tokenCurent.size() == 0) {
                /// putem avea [.] [0-9]* [e] maxim 1 [+|-] daca avem e [0-9]*
                int index = caracterLinie;
                tokenCurent += chCurent;

                while(caracterLinie + 1 < sfarsitLinie) {
                    caracterLinie += 1;
                    if(isdigit(LinieCod[caracterLinie]))
                        tokenCurent += LinieCod[caracterLinie];
                    else break;
                }

                if(caracterLinie < sfarsitLinie)
                    if(LinieCod[caracterLinie] == 'e') {
                        tokenCurent += LinieCod[caracterLinie];
                        caracterLinie += 1;

                        if(caracterLinie < sfarsitLinie)
                            if(LinieCod[caracterLinie] == '+' || LinieCod[caracterLinie] == '-') {
                                tokenCurent += LinieCod[caracterLinie];
                                caracterLinie += 1;
                            }
                    }

                caracterLinie -= 1;

                while(caracterLinie + 1 < sfarsitLinie) {
                    caracterLinie += 1;
                    if(isdigit(LinieCod[caracterLinie]))
                        tokenCurent += LinieCod[caracterLinie];
                    else break;
                }

                if(caracterLinie < sfarsitLinie)
                    if(LinieCod[caracterLinie] == 'F' || LinieCod[caracterLinie] == 'f' || LinieCod[caracterLinie] == 'L' || LinieCod[caracterLinie] == 'l') {
                        tokenCurent += LinieCod[caracterLinie];
                        caracterLinie += 1;
                    }

                if(caracterLinie < sfarsitLinie) {
                    if(isalnum(LinieCod[caracterLinie]) || LinieCod[caracterLinie] == '_' || LinieCod[caracterLinie] == '.') {
                        while(caracterLinie < sfarsitLinie) {
                            if(isalnum(LinieCod[caracterLinie]) || LinieCod[caracterLinie] == '_' || LinieCod[caracterLinie] == '.') {
                                tokenCurent += LinieCod[caracterLinie];
                                caracterLinie += 1;
                            }
                            else break;
                        }

                        Print(tokenCurent,"Error",numberLine,caracterLinie,"Error nu stiu ce e asta");

                        caracterLinie -= 1;
                        tokenCurent.clear();
                    }
                    else if(isDoubleNumber(tokenCurent,numberLine,caracterLinie - tokenCurent.size())) {

                        tokenCurent.clear();
                        caracterLinie -= 1;
                    }
                    else {
                        caracterLinie = index;
                        tokenCurent.clear();
                        tokenCurent += LinieCod[caracterLinie];

                        verifyToken(tokenCurent,numberLine,caracterLinie);
                        tokenCurent.clear();
                    }
                }
            }
            /// daca este prima cifra care trebuie introdusa in token
            else if(isdigit(chCurent) && (int)tokenCurent.size() == 0) {
                /// putem avea [0-9]* [.] maxim 1 [0-9]* [e] maxim 1 [+|-] daca avem e [0-9]*
                int index = caracterLinie;
                tokenCurent += chCurent;
                bool normalnumber = 1;

                while(caracterLinie + 1 < sfarsitLinie) {
                    caracterLinie += 1;
                    if(isdigit(LinieCod[caracterLinie]))
                        tokenCurent += LinieCod[caracterLinie];
                    else break;
                }

                if(caracterLinie < sfarsitLinie)
                    if(LinieCod[caracterLinie] == '.') {
                        tokenCurent += LinieCod[caracterLinie];
                        caracterLinie += 1;
                        normalnumber = 0;
                    }

                caracterLinie -= 1;

                while(caracterLinie + 1 < sfarsitLinie) {
                    caracterLinie += 1;
                    if(isdigit(LinieCod[caracterLinie]))
                        tokenCurent += LinieCod[caracterLinie];
                    else break;
                }

                if(caracterLinie < sfarsitLinie)
                    if(LinieCod[caracterLinie] == 'e') {
                        tokenCurent += LinieCod[caracterLinie];
                        caracterLinie += 1;
                        normalnumber = 0;

                        if(caracterLinie < sfarsitLinie)
                            if(LinieCod[caracterLinie] == '+' || LinieCod[caracterLinie] == '-') {
                                tokenCurent += LinieCod[caracterLinie];
                                caracterLinie += 1;
                            }
                    }

                caracterLinie -= 1;

                while(caracterLinie + 1 < sfarsitLinie) {
                    caracterLinie += 1;
                    if(isdigit(LinieCod[caracterLinie]))
                        tokenCurent += LinieCod[caracterLinie];
                    else break;
                }

                if(caracterLinie < sfarsitLinie)
                    if(LinieCod[caracterLinie] == 'F' || LinieCod[caracterLinie] == 'f' || LinieCod[caracterLinie] == 'L' || LinieCod[caracterLinie] == 'l') {
                        tokenCurent += LinieCod[caracterLinie];
                        caracterLinie += 1;
                        normalnumber = 0;
                    }

                if(caracterLinie < sfarsitLinie) {
                    ///daca urmeaza liteara cifra _ . e eroare
                    if(normalnumber == 1) {
                        caracterLinie = index;
                        tokenCurent.clear();
                        tokenCurent += LinieCod[caracterLinie];
                    }
                    else if(isalnum(LinieCod[caracterLinie]) || LinieCod[caracterLinie] == '_' || LinieCod[caracterLinie] == '.') {
                        while(caracterLinie < sfarsitLinie) {
                            if(isalnum(LinieCod[caracterLinie]) || LinieCod[caracterLinie] == '_' || LinieCod[caracterLinie] == '.') {
                                tokenCurent += LinieCod[caracterLinie];
                                caracterLinie += 1;
                            }
                            else break;
                        }

                        Print(tokenCurent,"Error",numberLine,caracterLinie,"Error nu stiu ce e asta");

                        caracterLinie -= 1;
                        tokenCurent.clear();
                    }
                    else if(isDoubleNumber(tokenCurent,numberLine,caracterLinie - tokenCurent.size())) {

                        tokenCurent.clear();
                        caracterLinie -= 1;
                    }
                    else {
                        caracterLinie = index;
                        tokenCurent.clear();
                        tokenCurent += LinieCod[caracterLinie];
                    }
                }
            }
            else if(isalnum(chCurent) || chCurent == '_') {
                tokenCurent += chCurent;
            }
            else if(chCurent == '\'') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                int firstPos = caracterLinie;

                /// daca am '\''
                bool caseExept = 0;
                tokenCurent += chCurent;
                if(caracterLinie + 3 < sfarsitLinie) {
                    if(LinieCod[caracterLinie + 1] == '\\' && LinieCod[caracterLinie + 2] == '\'' && LinieCod[caracterLinie + 3] == '\'' ) {
                        caseExept = 1;
                        tokenCurent += "\''";
                        Print(tokenCurent,"char constant",numberLine,caracterLinie,"");
                        tokenCurent.clear();
                        caracterLinie += 3;
                    }
                }

                if(caseExept == 0) {
                    /// pun in string totul pana gasesc '\''
                    bool GasitCaracter = 0;
                    while(caracterLinie + 1 < sfarsitLinie) {
                        caracterLinie += 1;
                        if(LinieCod[caracterLinie] != '\n')
                            tokenCurent += LinieCod[caracterLinie];
                        if(LinieCod[caracterLinie] == '\'') {
                            /// am gasit un posibil caracter
                            string goodCaracters[] = {
                                "'\\\''",
                                "'\\\"'",
                                "'\\\?'",
                                "'\\\\'",
                                "'\\a'",
                                "'\\b'",
                                "'\\f'",
                                "'\\n'",
                                "'\\r'",
                                "'\\t'",
                                "'\\v'",
                                //"'\c'",
                                //"'\unnnn'",
                                //"'\Unnnnnnnn'"
                            };

                            for(int i = 0 ; i < 11; ++i) {
                                if(goodCaracters[i] == tokenCurent) {
                                    GasitCaracter = 1;
                                    Print(tokenCurent,"char constant",numberLine,firstPos,"");
                                    tokenCurent.clear();
                                    break;
                                }
                            }

                            /// \nnn avem maxim 377
                            /// octal value
                            for(char a = '0'; a < '4' ; ++a)
                                for(char b = '0' ; b < '8' ; ++b)
                                    for(char c =  '0' ; c < '8' ; ++c) {
                                        string octalCode = "\'\\" ;
                                        octalCode += a;
                                        octalCode += b;
                                        octalCode += c;
                                        octalCode += "\'";
                                        if(octalCode == tokenCurent) {
                                            Print(tokenCurent,"char octal constant",numberLine,firstPos,"");
                                            tokenCurent.clear();
                                            GasitCaracter = 1;
                                        }
                                    }

                            /// \x[0-9|A-F|a-f][0-9|A-F|a-f]
                            string hexCaracters = "0123456789ABCDEFabcdef";
                            for(int i = 0; i < 22; ++i)
                                for(int j = 0; j < 22; ++j) {
                                    string hexCode = "\'\\x" ;
                                        hexCode += hexCaracters[i];
                                        hexCode += hexCaracters[j];
                                        hexCode += "\'";
                                        if(hexCode == tokenCurent) {
                                            Print(tokenCurent,"char hex constant",numberLine,firstPos,"");
                                            tokenCurent.clear();
                                            GasitCaracter = 1;
                                        }
                                }

                            /// normal sign char
                            for(int i = 32; i < 128; ++i)
                            if(i != 92 && i != 96)
                            {
                                string normalCode = "\'";
                                normalCode += char(i);
                                normalCode += "\'";
                                if(normalCode == tokenCurent) {
                                    Print(tokenCurent,"char constant",numberLine,firstPos,"");
                                    tokenCurent.clear();
                                    GasitCaracter = 1;
                                }
                            }


                            if(GasitCaracter == 1) {
                                break;
                            }
                            else {
                                Print(tokenCurent,"char posibil",numberLine,firstPos,"Error nu stiu ce e asta");
                                tokenCurent.clear();

                                break;
                            }
                        }
                    }
                }
            }
            else if(chCurent == '"') {
                /// gasesc un string
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;
                int startString = caracterLinie;
                bool StringError = 1;

                while(caracterLinie + 1 < sfarsitLinie) {
                    caracterLinie += 1;
                    if(LinieCod[caracterLinie] == (char)92) {
                        if(caracterLinie + 1 < sfarsitLinie) {
                            if(LinieCod[caracterLinie + 1] == '\n') {
                                string newLineCod;
                                if( getline(fInput,newLineCod) ) {
                                    newLineCod += '\n';
                                    numberLine += 1;
                                    LinieCod = newLineCod;
                                    caracterLinie = -1;
                                    sfarsitLinie = LinieCod.size();
                                    continue;
                                }
                            }
                            else if(LinieCod[caracterLinie + 1] == (char)92) {
                                caracterLinie += 1;
                                tokenCurent += LinieCod[caracterLinie];
                                continue;
                            }
                        }
                    }

                    if(LinieCod[caracterLinie] != '\n')
                        tokenCurent += LinieCod[caracterLinie];

                    if(LinieCod[caracterLinie] == '"') {
                        /// am terminat de gasit stringul
                        Print(tokenCurent,"String constant",numberLine,startString,"");
                        tokenCurent.clear();
                        StringError = 0;
                        break;
                    }
                }

                if(StringError == 1) {
                    Print(tokenCurent,"Error",numberLine,startString,"Stringul nu sa terminat");
                    tokenCurent.clear();
                }
            }
            else if(chCurent == '/') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '/') {
                        /// aici am comentariu //
                        tokenCurent += chCurent;

                        verifyToken(tokenCurent,numberLine,caracterLinie);
                        for(int j = caracterLinie+2; j < sfarsitLinie; ++j) {
                            tokenCurent += LinieCod[j];
                        }

                        cout << tokenCurent;

                        tokenCurent.clear();

                        break;
                    }
                    else if(LinieCod[caracterLinie+1] == '*') {
                        /// aici am comentariu de tipul /*  */
                        /// pana gasesc */ pun tot in tokenCurent
                        /// si daca nu gasesc afisez eroare
                        multiLineComment = 1;
                        tokenCurent += LinieCod[caracterLinie+1];

                        startLineMultiLineCommnet = numberLine;
                        startCaracterLinieMultiLineCommnet = caracterLinie;

                        caracterLinie += 1;

                        continue;
                    }
                    else if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit /=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                    else {
                        verifyToken(tokenCurent,numberLine,caracterLinie);
                        tokenCurent.clear();
                    }

                }
                else {
                    verifyToken(tokenCurent,numberLine,caracterLinie);
                    tokenCurent.clear();
                }
            }
            else if(chCurent == '=') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit ==
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else if(chCurent == '+') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit +=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                    else if(LinieCod[caracterLinie+1] == '+') {
                        /// am gasit ++
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else if(chCurent == '-') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit -=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                    else if(LinieCod[caracterLinie+1] == '-') {
                        /// am gasit --
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else if(chCurent == '%') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit %=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else if(chCurent == '*') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit *=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else if(chCurent == '!') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit !=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else if(chCurent == '^') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit ^=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else if(chCurent == '&') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit &=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                    else if(LinieCod[caracterLinie+1] == '&') {
                        /// am gasit &&
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else if(chCurent == '|') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit |=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                    else if(LinieCod[caracterLinie+1] == '|') {
                        /// am gasit ||
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else if(chCurent == '<') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit <=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                    else if(LinieCod[caracterLinie+1] == '<') {
                        /// am gasit <<
                        tokenCurent += LinieCod[caracterLinie+1];

                        if(caracterLinie + 2 < sfarsitLinie) {
                            if(LinieCod[caracterLinie+2] == '=') {
                                /// am gasit <<=
                                tokenCurent += LinieCod[caracterLinie+2];

                                verifyToken(tokenCurent,numberLine,caracterLinie);

                                caracterLinie += 2;
                                tokenCurent.clear();
                            }
                            else { /// <<
                                verifyToken(tokenCurent,numberLine,caracterLinie);

                                caracterLinie += 1;
                                tokenCurent.clear();
                            }
                        }
                        else { /// <<
                            verifyToken(tokenCurent,numberLine,caracterLinie);

                            caracterLinie += 1;
                            tokenCurent.clear();
                        }
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else if(chCurent == '>') {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;

                if(caracterLinie + 1 < sfarsitLinie) {
                    if(LinieCod[caracterLinie+1] == '=') {
                        /// am gasit >=
                        tokenCurent += LinieCod[caracterLinie+1];

                        verifyToken(tokenCurent,numberLine,caracterLinie);

                        caracterLinie += 1;
                        tokenCurent.clear();
                    }
                    else if(LinieCod[caracterLinie+1] == '>') {
                        /// am gasit >>
                        tokenCurent += LinieCod[caracterLinie+1];

                        if(caracterLinie + 2 < sfarsitLinie) {
                            if(LinieCod[caracterLinie+2] == '=') {
                                /// am gasit >>=
                                tokenCurent += LinieCod[caracterLinie+2];

                                verifyToken(tokenCurent,numberLine,caracterLinie);

                                caracterLinie += 2;
                                tokenCurent.clear();
                            }
                            else { /// >>
                                verifyToken(tokenCurent,numberLine,caracterLinie);

                                caracterLinie += 1;
                                tokenCurent.clear();
                            }
                        }
                        else { /// >>
                            verifyToken(tokenCurent,numberLine,caracterLinie);

                            caracterLinie += 1;
                            tokenCurent.clear();
                        }
                    }
                }

                verifyToken(tokenCurent,numberLine,caracterLinie);
                tokenCurent.clear();
            }
            else {
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size());
                tokenCurent.clear();

                tokenCurent += chCurent;
                verifyToken(tokenCurent,numberLine,caracterLinie - tokenCurent.size() + 1);
                tokenCurent.clear();
            }
	    }
	}

    /// daca multiLineComment == 1 atunci am un comentariu neterminat si am eroare
    if(multiLineComment == 1) {
        Print("/*","Error",startLineMultiLineCommnet,startCaracterLinieMultiLineCommnet,"Eroare Comentariul nu este inchis (lipsa */) :)");
        cout << tokenCurent;
    }
}

int main() {

    scanner();

    return 0;
}
